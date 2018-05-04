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

int main () {
	lli n, sum, meio, num_sol, num_menor, num_maior, flag, i;
	
	cin >> n;
	while (n != -1) {
		meio = n/2;
		sum = 0;
		num_sol = 0;
		vetor numeros(n-1);
		for (i = 0; i < n - 1; i++) {
			cin >> numeros[i];
			sum += numeros[i];
		}
		
		sort (numeros.begin(), numeros.end());
		/*for (i = 0; i < n-1; i++) {
			cout << numeros[i] << " ";
		} 
		cout << endl;
		*/
		
		num_menor = ((numeros[meio-1] * n) - sum);
		if (num_menor < numeros[meio-1]) {
			for (i = 0, flag = 1; i < meio - 1 && flag; i++) {
				if (num_menor == numeros[i])
					flag = 0;
			}
			if (flag == 1) {
				num_sol++;
			}
		}
		
		if (sum/(n-1) > numeros[meio-1] && sum/(n-1) < numeros[meio] && sum % (n-1) == 0)
			num_sol++;
			
		num_maior = ((numeros[meio] * n) - sum);
		if (num_maior > numeros[meio]) {
			for (i = meio + 1, flag = 1; i < n - 1 && flag; i++) {
				if (num_maior == numeros[i])
					flag = 0;
			}
			if (flag == 1) {
				num_sol++;
			}
		}
		//cout << "num_menor: " << num_menor << endl << "num_meio :" << sum/(n-1) << endl << "num_maior :" << num_maior << endl;
		cout << num_sol << endl;
		cin >> n;
	}
	return 0;
}
		
		
