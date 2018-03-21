#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

long int acha_maior_soma (vector <long int> &vetor, long int pos) {
	long int i, a, b;
	
	if (pos >= vetor.size()) {
		return -1;
	} else if (pos + 1 == vetor.size() || pos + 2 == vetor.size()) {
		return vetor[pos];
	}
	
	a = acha_maior_soma (vetor, pos + 2);
	b = acha_maior_soma (vetor, pos + 3);
	if (a > b) {
		return a + vetor[pos];
	} else {
		return b + vetor[pos];
	}
} 

int main () {

	long int linhas, colunas, a, b, i, j;
	
	cin >> linhas;
	cin >> colunas;
	
	while (linhas != 0 && colunas != 0) {
		vector <long int> maiores (linhas);
		
		for (i = 0; i < linhas; i++) {
			vector <long int> linha_atual (colunas);
			for (j = 0; j < colunas; j++) {
				cin >> linha_atual[j];
			}
			a = acha_maior_soma (linha_atual, 0);
			b = acha_maior_soma (linha_atual, 1);
			if (a > b) {
				maiores[i] = a;
			} else {
				maiores[i] = b;
			}
		}
		
		a = acha_maior_soma (maiores, 0);
		b = acha_maior_soma (maiores, 1);
		if (a > b) {
			cout << a << "\n";
		} else {
			cout << b << "\n";
		}
		cin >> linhas;
		cin >> colunas;
	}

	return 0;
}
