#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main () {
	int num_casos, linhas, colunas, i, j, flag;
	
	cin >> num_casos;
	
	while (num_casos != 0) {
		cin >> linhas;
		cin >> colunas;
		vector <vector <char> > tabuleiro;
		for (i = 0; i < linhas; i++) {
			vector<char> aux (colunas);
			tabuleiro.push_back(aux);
		}
		for (i = 0; i < linhas; i++) {
			for (j = 0; j < colunas; j++) {
				cin >> tabuleiro[i][j];
			}
		}
		flag = 0;
		while (flag == 0) {
			for (i = 0, flag = 1; i < linhas; i++) {
				for (j = 0; j < colunas; j++) {
					if (tabuleiro[i][j] >= 97 && tabuleiro[i][j] <= 122) {
						if (i > 0 && tabuleiro[i - 1][j] == '.') {
							flag = 0;
							tabuleiro[i - 1][j] = tabuleiro[i][j] - 32;
						} else if (i > 0 && tabuleiro[i - 1][j] >= 65 && tabuleiro[i - 1][j] <= 90 && tabuleiro[i - 1][j] != tabuleiro[i][j] - 32) {
							flag = 0;
							tabuleiro[i - 1][j] = '*';
						} 
						if (j < (colunas - 1) && tabuleiro[i][j + 1] == '.') {
							flag = 0;
							tabuleiro[i][j + 1] = tabuleiro[i][j] - 32;
						} else if (j < (colunas - 1) && tabuleiro[i][j + 1] >= 65 && tabuleiro[i][j + 1] <= 90 && tabuleiro[i][j + 1] != tabuleiro[i][j] - 32) {
							flag = 0;
							tabuleiro[i][j + 1] = '*';
						} 
						if (i < (linhas - 1) && tabuleiro[i + 1][j] == '.') {
							flag = 0;
							tabuleiro[i + 1][j] = tabuleiro[i][j] - 32;
						} else if (i < (linhas - 1) && tabuleiro[i + 1][j] >= 65 && tabuleiro[i + 1][j] <= 90 && tabuleiro[i + 1][j] != tabuleiro[i][j] - 32) {
							flag = 0;
							tabuleiro[i + 1][j] = '*';
						}
						if (j > 0 && tabuleiro[i][j - 1] == '.') {
							flag = 0;
							tabuleiro[i][j - 1] = tabuleiro[i][j] - 32;
						} else if (j > 0 && tabuleiro[i][j - 1] >= 65 && tabuleiro[i][j - 1] <= 90 && tabuleiro[i][j - 1] != tabuleiro[i][j] - 32) {
							flag = 0; 
							tabuleiro[i][j - 1] = '*';
						}
					}
				}
			}
			
			for (i = 0; i < linhas; i++) {
				for (j = 0; j < colunas; j++) {
					if (tabuleiro[i][j] >= 65 && tabuleiro[i][j] <= 90) {
						tabuleiro[i][j] += 32;
					}
				}
			}
		}
		for (i = 0; i < linhas; i++) {
			for (j = 0; j < colunas; j++) {
				cout << tabuleiro[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
		num_casos--;
	}
	
	return 0;
}
