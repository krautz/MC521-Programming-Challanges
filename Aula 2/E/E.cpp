/* Worked on UVA's debugging site but not accepted on the contest page :( */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

long long int acha_possibilidades (vector< vector<long long int> > &eventos, long long int evento_atual, vector <long long int> &custo_eventos) {
	long long int i, qtd_evento_atual = 0;
	if (custo_eventos[evento_atual] != 0) {
		return custo_eventos[evento_atual];
	}
	
	for (i = 0; i < eventos[evento_atual].size(); i++) {
		qtd_evento_atual += acha_possibilidades (eventos, eventos[evento_atual][i], custo_eventos);
	}
	custo_eventos[evento_atual] = qtd_evento_atual;
	return qtd_evento_atual;
}

int main () {
	long long int num_eventos, num_escolhas, i, j;
	
	cin >> num_eventos;
	while (!cin.eof()) {
		if (num_eventos == 0) {
			cout << "0";
		} else {
			vector< vector<long long int> > eventos;
			vector <long long int> custo_eventos (num_eventos); 
			for (i = 0; i < num_eventos; i++) {
				cin >> num_escolhas;
				if (num_escolhas == 0) {
					vector<long long int> evento_atual (1);
					evento_atual[0] = 0;
					eventos.push_back(evento_atual);
					custo_eventos[i] = 1;
				} else {
					vector<long long int> evento_atual (num_escolhas);
					for (j = 0; j < num_escolhas; j++) {
						cin >> evento_atual[j];
					}
					eventos.push_back(evento_atual);
					custo_eventos[i] = 0;
				}
			}
			cout << acha_possibilidades (eventos, 0, custo_eventos);
		}
		cin >> num_eventos;
		if (!cin.eof()) {
			cout << "\n";
		}
	}
	/* in this code as de cin is right before the condition check of the while I can leave the condition in the while
		in the version T on this folder as the cin is right after de condition check of the while it would exec the loop
		one more time until it checks the condition, that's why the if with break is required! */
	
	return 0;
}
