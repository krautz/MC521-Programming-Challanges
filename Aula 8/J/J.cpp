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

void soma_mascara (vetor &mascara, lli n) {
	lli i = 0;
	while (i < n) {
		if (mascara[i] == 0) {
			mascara[i] = 1;
			i = n+1;
		} else {
			mascara[i] = 0;
			i++;
		}
	}
}

lli acha_solucao (vetor &pesos, vetor &mascara, lli n, lli w) {
	
	lli soma = 0, numeros_1 = 0;
	
	for (lli i = 0; i < n; i++) {
		if (mascara[i] == 1) {
			soma += pesos[i];
			numeros_1++;
		}
	}
	
	if (soma == w)
		return numeros_1;
	return 10001;
}

int main () {
	lli	test_cases, n, w, i, num_elementos, aux;
	
	cin >> test_cases;
	
	while (test_cases > 0) {
		cin >> n >> w;
		num_elementos = 10000;
		vetor pesos (n);
		vetor mascara (n, 0);
		for (i = 0; i < n; i++) {
			cin >> pesos[i];
		}
				
		for (i = 0; i < pow(2,n); i++) {
			soma_mascara (mascara, n);
			aux = acha_solucao (pesos, mascara, n, w);
			if (aux < num_elementos)
				num_elementos = aux;
		}
		
		if (num_elementos == 10000)
			cout << "impossible";
		else
			cout << num_elementos;
		if (test_cases > 0)
			cout << endl;
		
		test_cases--;
	}		
	
	return 0;
}
