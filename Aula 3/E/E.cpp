#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct moeda {
	char peso;
	int qtd;
};

int main () {
	
	int num_casos, i, save, j;
	string esquerda, direita, comp;
	
	cin >> num_casos;
	
	while (num_casos != 0) {
		vector<moeda> moedas (12);
		for (i = 0; i < 12; i++) {
			moedas[i].peso = '-';
			moedas[i].qtd = 0;
		}
		
		for (j = 0; j < 3; j++) {
		
			cin >> esquerda;
			cin >> direita;
			cin >> comp;
		
			if (comp.compare("even") == 0) {
				for (i = 0; i < esquerda.size(); i++) {
					if (moedas[esquerda[i] - 65].peso != 'R') {
						moedas[esquerda[i] - 65].peso = 'R';
						moedas[esquerda[i] - 65].qtd = 0;
					}
				}
				for (i = 0; i < direita.size(); i++) {
					if (moedas[direita[i] - 65].peso != 'R') {
						moedas[direita[i] - 65].peso = 'R';
						moedas[direita[i] - 65].qtd = 0;
					}
				}
			} else if (comp.compare("up") == 0) {
				for (i = 0; i < esquerda.size(); i++) {
					if (moedas[esquerda[i] - 65].peso == '-') {
						moedas[esquerda[i] - 65].peso = 'P';
						moedas[esquerda[i] - 65].qtd++;
					} else if (moedas[esquerda[i] - 65].peso == 'P') {
						moedas[esquerda[i] - 65].qtd++;
					} else if (moedas[esquerda[i] - 65].peso == 'L') {
						moedas[esquerda[i] - 65].peso = 'R';
						moedas[esquerda[i] - 65].qtd = 0;
					}
				}
			
				for (i = 0; i < direita.size(); i++) {
					if (moedas[direita[i] - 65].peso == '-') {
						moedas[direita[i] - 65].peso = 'L';
						moedas[direita[i] - 65].qtd++;
					} else if (moedas[direita[i] - 65].peso == 'L') {
						moedas[direita[i] - 65].qtd++;
					} else if (moedas[direita[i] - 65].peso == 'P') {
						moedas[direita[i] - 65].peso = 'R';
						moedas[direita[i] - 65].qtd = 0;
					}
				}
			} else if (comp.compare("down") == 0) {
				for (i = 0; i < esquerda.size(); i++) {
					if (moedas[esquerda[i] - 65].peso == '-') {
						moedas[esquerda[i] - 65].peso = 'L';
						moedas[esquerda[i] - 65].qtd++;
					} else if (moedas[esquerda[i] - 65].peso == 'L') {
						moedas[esquerda[i] - 65].qtd++;
					} else if (moedas[esquerda[i] - 65].peso == 'P') {
						moedas[esquerda[i] - 65].peso = 'R';
						moedas[esquerda[i] - 65].qtd = 0;
					}
				}
			
				for (i = 0; i < direita.size(); i++) {
					if (moedas[direita[i] - 65].peso == '-') {
						moedas[direita[i] - 65].peso = 'P';
						moedas[direita[i] - 65].qtd++;
					} else if (moedas[direita[i] - 65].peso == 'P') {
						moedas[direita[i] - 65].qtd++;
					} else if (moedas[direita[i] - 65].peso == 'L') {
						moedas[direita[i] - 65].peso = 'R';
						moedas[direita[i] - 65].qtd = 0;
					}
				}
			}
		}
		
		for (i = 1, save = 0; i < 12; i++) {
			if (moedas[i].qtd > moedas[save].qtd) {
				save = i;
			}
		}
		
		if (moedas[save].peso == 'P') {
			cout << (char) (save + 65) << " is the counterfeit coin and it is heavy.\n";
		} else if (moedas[save].peso == 'L') {
			cout << (char) (save + 65) << " is the counterfeit coin and it is light.\n";
		} 
		num_casos--;
	}
	
	return 0;
}
