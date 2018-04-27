#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

int main () {
	long long int linhas, i, j = 1;
	
	cin >> linhas;
	while (linhas != 0) {
		vector <vector <long long int> > matriz;
		for (i = 0; i < linhas; i++) {
			vector <long long int> linha(3);
			cin >> linha[0] >> linha[1] >> linha[2];
			matriz.push_back(linha);
		}
		vector <vector <long long int> > matriz_aux;
		for (i = 0; i < linhas; i++) {
			vector <long long int> linha(3);
			matriz_aux.push_back(linha);
		}
		
		matriz_aux[0][0] = matriz[0][1] + 1;
		matriz_aux[0][1] = matriz[0][1];
		matriz_aux[0][2] = matriz[0][1] + matriz[0][2];
		for (i = 1; i < linhas; i++) {
			matriz_aux[i][0] = matriz[i][0] + min(matriz_aux[i-1][0], matriz_aux[i-1][1]);
			matriz_aux[i][1] = matriz[i][1] + min(min(min(matriz_aux[i][0],matriz_aux[i-1][0]), matriz_aux[i-1][1]),matriz_aux[i-1][2]);
			matriz_aux[i][2] = matriz[i][2] + min(min(matriz_aux[i][1],matriz_aux[i-1][1]), matriz_aux[i-1][2]);
		}
	
		
		cout << j << ". " << matriz_aux[linhas-1][1] << "\n";
		j++;
		cin >> linhas;
	}
	
	return 0;
}
