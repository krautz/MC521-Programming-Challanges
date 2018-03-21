#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <map>

using namespace std;

void acha_maior_cadeia (vector<vector<int> > &relacoes, int criatura, int num_criaturas, vector<int> &criaturas_visitadas, long long int *tamanho_cadeia) {
	int i;
	
	if (criaturas_visitadas[criatura] == 1) {
		return;
	}
	criaturas_visitadas[criatura] = 1;
	(*tamanho_cadeia)++;
	
	for (i = 0; i < num_criaturas; i++) {
		if (relacoes[criatura][i] == 1) {
			acha_maior_cadeia (relacoes, i, num_criaturas, criaturas_visitadas, tamanho_cadeia);
		}
	}

	return;
}
	

int main () {
	int num_criaturas, num_relacoes, i, j, flag;
	long long int tam, maior;
	string presa, predador;
	
	cin >> num_criaturas;
	cin >> num_relacoes;
	
	while (num_criaturas != 0 || num_relacoes != 0) {
	
		vector <vector <int> > relacoes;
		for (i = 0; i < num_criaturas; i++) {
			vector<int> vet (num_criaturas, 0);
			relacoes.push_back (vet);
		}
		
		map <string, int> mapa;
		for (i = 0; i < num_criaturas; i++) {
			cin >> presa;
			mapa.insert (pair<string, int> (presa, i));
		}
		
		for (i = 0; i < num_relacoes; i++) {
			cin >> presa;
			cin >> predador;
			relacoes[mapa.find(predador)->second][mapa.find(presa)->second] = 1;
			relacoes[mapa.find(presa)->second][mapa.find(predador)->second] = 1;
		}
	
		maior = 0;
		vector<int> criaturas_visitadas (num_criaturas, 0);
		for (i = 0, tam = 0; i < num_criaturas; i++) {
			if (criaturas_visitadas[i] == 0) {
				tam = 0;
				acha_maior_cadeia (relacoes, i, num_criaturas, criaturas_visitadas, &tam);
				if (tam > maior) {
					maior = tam;
				}
			}
		}
		
		cout << maior << "\n";
		
		
		
		cin >> num_criaturas;
		cin >> num_relacoes;
			
	}
	
	return 0;
}
