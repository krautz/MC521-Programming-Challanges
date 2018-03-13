#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string.h>

using namespace std;


int main () {
	int numero_times, numero_participantes, i, j, l, m, participante, flag, count_scenario = 1;
	char operacao[9];
	
	cin >> numero_times;
	
	while (numero_times != 0) {
	
		deque< deque<int> > fila;
		vector< vector<int> > times;
	
		for (i = 0; i < numero_times; i++) {
			cin >> numero_participantes;
			vector <int> time (numero_participantes);
			for (j = 0; j < numero_participantes; j++) {
				cin >> time[j];
			}
			times.push_back(time);
		}
	
		cin >> operacao;
	
		cout << "Scenario #" << count_scenario << "\n";
		
		while (strcmp (operacao, "STOP") != 0) {
			if (strcmp (operacao, "ENQUEUE") == 0) {
				cin >> participante;
				flag = 1;
				for (i = 0; i < times.size() && flag; i++) {
					for (j = 0; j < times[i].size() && flag; j++) {
						if (times[i][j] == participante)
							flag = 0;
					}
				}
				i--;
				flag = 1;
				for (l = 0; l < fila.size() && flag; l++) {
					for (j = 0; j < times[i].size() && flag; j++) {
						if (fila[l].front() == times[i][j])
							flag = 0;
					}
					if (flag == 0)
						fila[l].push_back(participante);
			
				}
				if (flag == 1) {
					deque<int>  novo_grupo;
					novo_grupo.push_back(participante);
					fila.push_back(novo_grupo);
				}	
			} else { // DEQUEUE
				cout << fila.front().front() << "\n";
				fila.front().pop_front();
				if (fila.front().size() == 0)
					fila.pop_front();
			}
			cin >> operacao;
		}
		cout << "\n";
		cin >> numero_times;
		count_scenario++;
	}
	
	
	return 0;
}
