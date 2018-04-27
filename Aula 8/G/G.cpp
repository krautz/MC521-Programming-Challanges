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
typedef vector <lli> vetor;
typedef vector <vector <lli> > matriz;

int main () {
	lli m, n, i, j, cor, flag, new_cor, old_cor, l, k;
	char aux;
	cin >> m >> n;
	while (m != 0) {
		
		cor = 0;
		matriz oil;
		scanf (" ");
		for (i = 0; i < m; i++) {
			vetor linha (n);
			for (j = 0; j < n; j++) {
				scanf("%c", &aux);
				if (aux == '*')
					linha[j] = -2;
				if (aux == '@')
					linha[j] = -1;
			}
			if (i != m - 1)
				scanf (" ");
			oil.push_back(linha);
		}
		
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (oil[i][j] == -1) {
					if (i > 0 && j > 0 && oil[i-1][j-1] != -1 && oil[i-1][j-1] != -2) {
					  oil[i][j] = oil[i-1][j-1];
					} else if (i > 0 && oil[i-1][j] != -1 && oil[i-1][j] != -2) {
					  oil[i][j] = oil[i-1][j];
					} else if (i > 0 && j < n - 1 && oil[i-1][j+1] != -1 && oil[i-1][j+1] != -2) {
					  oil[i][j] = oil[i-1][j+1];
					} else if (j < n - 1 && oil[i][j+1] != -1 && oil[i][j+1] != -2) {
					  oil[i][j] = oil[i][j+1];
					} else if (i < m - 1 && j < n - 1 && oil[i+1][j+1] != -1 && oil[i+1][j+1] != -2) {
					  oil[i][j] = oil[i+1][j+1];
					} else if (i < m - 1 && oil[i+1][j] != -1 && oil[i+1][j] != -2) {
					  oil[i][j] = oil[i+1][j];
					} else if (i < m - 1 && j > 0 && oil[i+1][j-1] != -1 && oil[i+1][j-1] != -2) {
					  oil[i][j] = oil[i+1][j-1];
					} else if (j > 0 && oil[i][j-1] != -1 && oil[i][j-1] != -2) {
						oil[i][j] = oil[i][j-1];
					} else {
						oil[i][j] = cor;
						cor++;
					}
				}
			}
		}
		
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				flag = 0;
				if (oil[i][j] != -2) {
					if (i > 0 && j > 0 && oil[i-1][j-1] != -2 && oil[i-1][j-1] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i-1][j-1];
					  cor--;
					  flag = 1;
					} else if (i > 0 && oil[i-1][j] != -2 && oil[i-1][j] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i-1][j];
					  cor--;
					  flag = 1;
					} else if (i > 0 && j < n - 1 && oil[i-1][j+1] != -2 && oil[i-1][j+1] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i-1][j+1];
					  cor--;
					  flag = 1;
					} else if (j < n - 1 && oil[i][j+1] != -2 && oil[i][j+1] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i][j+1];
					  cor--;
					  flag = 1;
					} else if (i < m - 1 && j < n - 1 && oil[i+1][j+1] != -2 && oil[i+1][j+1] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i+1][j+1];
					  cor--;
					  flag = 1;
					} else if (i < m - 1 && oil[i+1][j] != -2 && oil[i+1][j] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i+1][j];
					  cor--;
					  flag = 1;
					} else if (i < m - 1 && j > 0 && oil[i+1][j-1] != -2 && oil[i+1][j-1] != oil[i][j]) {
					  new_cor = oil[i][j];
					  old_cor = oil[i+1][j-1];
					  cor--;
					  flag = 1;
					} else if (j > 0 && oil[i][j-1] != -2 && oil[i][j-1] != oil[i][j]) {
						new_cor = oil[i][j];
					  	old_cor = oil[i][j-1];
					  	cor--;
					  	flag = 1;
					}
				}
				if (flag == 1) {
					for (k = 0; k < m; k++) {
						for (l = 0; l < n; l++) {
							if (oil[k][l] == old_cor)
								oil[k][l] = new_cor;
						}
					}
				}
			}
		}
							
		/*
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				cout << oil[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << cor << endl;
		cin >> m >> n;
	}
		
	return 0;
		
}
	
