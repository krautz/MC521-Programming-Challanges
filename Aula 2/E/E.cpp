#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

void acha_possibilidades (vector< vector<int> > &eventos, int evento_atual, long int *qtd_possibilidades) {
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
	long int num_eventos, num_escolhas, i, j, qtd;
	
	cin >> num_eventos;
	while (!cin.eof()) {
		vector< vector<int> > eventos;
		qtd = 0;
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
		cin >> num_eventos;
	}
	/* in this code as de cin is right before the condition check of the while I can leave the condition in the while
		in the version T on this folder as the cin is right after de condition check of the while it would exec the loop
		one more time until it checks the condition, that's why the if with break is required! */
	
	return 0;
}
