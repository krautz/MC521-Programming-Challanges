#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

void acha_maior_linha (vector <long long int> &linha, long long int colunas) {
	long long int k;
	if (colunas == 2) {
		if (linha[1] > linha[0]) {
			linha[0] = linha[1];
		}
	} else if (colunas > 2) {
		if (linha[colunas - 1] > linha[colunas - 2]) {
			linha[colunas - 2] = linha[colunas - 1];
		}
		for (k = colunas - 3; k >= 0; k--) {
			if (linha[k] + linha[k + 2] > linha[k + 1]) {
				linha[k] = linha[k] + linha[k + 2];
			} else {
				linha[k] = linha[k + 1];
			}
	
		}
	}
}
	

int main () {

	long long int linhas, colunas, a, b, i, j;
	
	cin >> linhas;
	cin >> colunas;
	
	while (linhas != 0 && colunas != 0) {
		vector <long long int> maiores (linhas);
		
		for (i = 0; i < linhas; i++) {
			vector <long long int> linha_atual (colunas);
			for (j = 0; j < colunas; j++) {
				cin >> linha_atual[j];
			}
			acha_maior_linha (linha_atual, colunas);
			maiores[i] = linha_atual[0];
		}
		
		acha_maior_linha (maiores, linhas);
		
		cout << maiores[0] << "\n";
		
		cin >> linhas;
		cin >> colunas;
	}

	return 0;
}
