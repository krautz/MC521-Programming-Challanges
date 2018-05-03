#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <queue>

using namespace std;

typedef long long int lli;
typedef vector <lli> vetor;
typedef vector <vector <lli> > matriz;


typedef struct {
	int value;
	int index;	
} Tipo_V;

typedef struct {
	int soma;
	vector<int> lista;
} Tipo_dp;

bool compare( Tipo_V lhs, Tipo_V rhs) { 
	return lhs.value < rhs.value; 
}

bool busca_bin(vector<Tipo_dp> &dp, int value, int tam){
	int l=0,r=tam-1;
	while (l <= r)
    {
        int m = l + (r-l)/2;
 
        // Check if x is present at mid
        if (dp[m].soma == value)
            return true;
 
        // If x greater, ignore left half
        if (dp[m].soma < value)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return false;
}

int main () {
	
	
	int c,n;
	
	cin >> c >> n;
	
	vector <Tipo_dp> dp;
	dp.reserve(1000000);
	while(c!=0 && n!= 0){
		Tipo_V v[100000];
		
		dp.clear();
 		for(int i=0;i<n;i++){
			cin >> v[i].value;
			v[i].index = i+1;
		}
		
		sort(v, v+n, compare);
		
		int tam_dp_real=0;
		bool achou = false;
		for(int i=0;i<n&& !achou;i++){
			if(v[i].value % c == 0){
				cout << v[i].index; 
				achou = true;
				break;
			}
			
			int tam_dp_prov = tam_dp_real;
			if(!busca_bin(dp,v[i].value,tam_dp_prov)){
				Tipo_dp aux;
				aux.soma = v[i].value;
				aux.lista.push_back(v[i].index);
				dp.push_back(aux);
				tam_dp_real++;
			}
			
			for(int j=0;j<tam_dp_prov;j++){
				int valor = v[i].value + dp[j].soma;
				if(valor % c == 0){
					for(int aux=0;aux < (int)dp[j].lista.size();aux++){
						cout << dp[j].lista[aux] << " ";
					}
					cout << v[i].index << " " << endl;
					achou = true;
					break;
				}
				
				if(!busca_bin(dp,valor,tam_dp_real) ){
					Tipo_dp aux;
					aux.soma = valor;
					aux.lista = dp[j].lista;
					aux.lista.push_back(v[i].index);
					dp.push_back(aux);
					tam_dp_real++;
				
				}
			
			
			}
		
		
		}
		
		if(!achou)
			cout << "no sweets" << endl;
	
	
		cin >> c >> n;
	}


	return 0;
}
