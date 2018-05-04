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
typedef vector <string> vetor_string;
typedef vector <lli> vetor;
typedef vector <vector <lli> > matriz;


void percorre_cidade (vetor_string &cidade, matriz &cidade_aux, lli i, lli j, lli cor, lli *caminho) {
	
	if (cidade_aux[i][j] == -1) {
		cidade_aux[i][j] = cor;
		if (cidade[i][j] == 'N') {
			percorre_cidade (cidade, cidade_aux, i - 1, j, cor, caminho);
		} else if (cidade[i][j] == 'S') {
			percorre_cidade (cidade, cidade_aux, i + 1, j, cor, caminho);
		} else if (cidade[i][j] == 'E') {
			percorre_cidade (cidade, cidade_aux, i, j + 1, cor, caminho);
		} else if (cidade[i][j] == 'W') {
			percorre_cidade (cidade, cidade_aux, i, j - 1, cor, caminho);
		}
	} else if (cidade_aux[i][j] != cor) {
		(*caminho)--;
	}
		
}
	

int main () {
	lli linhas, colunas, i, j, caminho = 0, cor = 0;
		
	cin >> linhas >> colunas;
	
	vetor_string cidade;
	scanf (" ");
	for (i = 0; i < linhas; i++) {
		string aux;
		getline (cin, aux);
		cidade.push_back(aux);
	}
	
	matriz cidade_aux;
	for (i = 0; i < linhas; i++) {
		vetor aux (colunas, -1);
		cidade_aux.push_back(aux);	
	}
	
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (cidade_aux[i][j] == -1) {
				caminho++;
				cor++;
				percorre_cidade (cidade, cidade_aux, i, j, cor, &caminho);
			}
		}
	}
	
	cout << caminho << endl;
	
	/*
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			cout << cidade_aux[i][j];
		}
		cout << endl;
	}
	*/
	return 0;
}
