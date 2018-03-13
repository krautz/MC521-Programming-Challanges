#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

void acha_possibilidades (vector< vector<int> > &eventos, int evento_atual, int *qtd_possibilidades) {
	int i;
	if (eventos[evento_atual][0] == 0) {
		(*qtd_possibilidades)++;
		return;
	}
	
	for (i = 0; i < eventos[evento_atual].size(); i++) {
		acha_possibilidades (eventos, eventos[evento_atual][i], qtd_possibilidades);
	}
	return;
}

int main () {
	int num_eventos, num_escolhas, i, j, qtd;
	vector< vector<int> > eventos;
	
	while (true) {
		qtd = 0;
		cin >> num_eventos;
		if (cin.eof()) 												// HOW TO READ UNTIL EOF (Ctrl D)
			break;													// here it checks the last cin read, so must have this break
		for (i = 0; i < num_eventos; i++) {
			cin >> num_escolhas;
			if (num_escolhas == 0) {
				vector<int> evento_atual (1);
				evento_atual[0] = 0;
				eventos.push_back(evento_atual);
			} else {
				vector<int> evento_atual (num_escolhas);
				for (j = 0; j < num_escolhas; j++) {
					cin >> evento_atual[j];
				}
				eventos.push_back(evento_atual);
			}
		}
	
		acha_possibilidades (eventos, 0, &qtd);
		cout << qtd << "\n";
	}
	
	return 0;
}
