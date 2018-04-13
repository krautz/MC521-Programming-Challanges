#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

bool rescue (vector < vector <char> > &map, long int oxigenio, long int rows, long int columns, long int i, long int j, vector <vector <int> > &map_oxigenio) {
	bool retorno;
	
	if (i >= 0 && i < rows && j >= 0 && j < columns) {
	
		
			if (oxigenio == -1)
				return false;
			if (map[i][j] == '#')
				return false;
			if (map[i][j] == 'T')
				return true;
	
			map[i][j] = '#';	
	
			retorno = rescue (map, oxigenio - 1, rows, columns, i - 1, j - 1, map_oxigenio);
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i - 1, j, map_oxigenio);
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i - 1, j + 1, map_oxigenio);
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i, j + 1, map_oxigenio);
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i + 1, j + 1, map_oxigenio);
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i + 1, j, map_oxigenio);	
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i + 1, j - 1, map_oxigenio);
			if (retorno == false)
				retorno = rescue (map, oxigenio - 1, rows, columns, i, j - 1, map_oxigenio);	

			map[i][j] = ' ';
		
			return retorno;
	}
	return false;
}
	

int main () {
	long int test_cases, rows, columns, inicio_linha, inicio_coluna, i, j, oxigenio;
	char c;
	
	cin >> test_cases;
	
	while (test_cases) {
		cin >> oxigenio;
		cin >> rows;
		cin >> columns;
		vector < vector <char> > map;
		vector < vector <int> > map_oxigenio;
		scanf (" ");
		for (i = 0; i < rows; i++) {
			vector <char> linha(columns);
			for (j = 0; j < columns; j++) {
				scanf("%c", &linha[j]);
				if (linha[j] == 'S') {
					inicio_linha = i;
					inicio_coluna = j;
				}	
			}
			scanf("%c", &c);
			map.push_back(linha);
		}
		
		for (i = 0; i < rows; i++) {
			vector <int> linha(columns, -2);
			map_oxigenio.push_back(linha);
		}
		
		cout << "aq\n";
		
		if (rescue (map, oxigenio, rows, columns, inicio_linha, inicio_coluna, map_oxigenio)) {
			cout << "Possible\n";
		} else {
			cout << "Impossible\n";
		}
		
		test_cases--;
	}
	
	return 0;
}
