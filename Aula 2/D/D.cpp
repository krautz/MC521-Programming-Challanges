#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

void tem_ciclo (vector < vector <int> > &conexoes, vector < vector <int> > &caminho, vector <int> &vertices_visitados, long int *qtd_arestas, long int *qtd_vertices, int vertice, int num_vertices) {
	
	int i;
	
	if (vertices_visitados[vertice] == 1)
		return;
	
	vertices_visitados[vertice] = 1;
	(*qtd_vertices)++;
	for (i = 1; i <= num_vertices; i++) {
		if (conexoes[vertice][i] == 1 && caminho[vertice][i] == 0) {
			caminho[vertice][i] = 1;
			caminho[i][vertice] = 1;
			(*qtd_arestas)++;
			tem_ciclo (conexoes, caminho, vertices_visitados, qtd_arestas, qtd_vertices, i, num_vertices);
		}
	}
	return;
}
	

int main () {
	int num_vertices, num_arestas, i, j, v1, v2;
	long int qtd_arestas, qtd_vertices, qtd_arvores, caso = 1;
	
	cin >> num_vertices;
	cin >> num_arestas;
	
	while (num_vertices != 0 || num_arestas != 0) {
		vector <vector <int> > conexoes;
		for (i = 0; i <= num_vertices; i++) {
			vector <int> adc_linha (num_vertices + 1, 0);
			conexoes.push_back (adc_linha);
		}
		for (i = 0; i < num_arestas; i++) {
			cin >> v1;
			cin >> v2;
			conexoes[v1][v2] = 1;
			conexoes[v2][v1] = 1;
		}
		
		vector <int> vertices_visitados (num_vertices + 1, 0);
		
		vector <vector <int> > caminho;
		for (i = 0; i <= num_vertices; i++) {
			vector <int> adc_linha (num_vertices + 1, 0);
			caminho.push_back (adc_linha);
		}
		
		qtd_arvores = 0;
		
		for (i = 1; i <= num_vertices; i++) {
			if (vertices_visitados[i] == 0) {
				qtd_arestas = 0;
				qtd_vertices = 0;
				tem_ciclo (conexoes, caminho, vertices_visitados, &qtd_arestas, &qtd_vertices, i, num_vertices);
				if (qtd_vertices - 1 == qtd_arestas) {
					qtd_arvores++;
				}
			}
		}
		
		cout << "Case " << caso << ": ";
		caso++;
		if (qtd_arvores == 0) {
			cout << "No trees.\n";
		} else if (qtd_arvores == 1) {
			cout << "There is one tree.\n";
		} else {
			cout << "A forest of " << qtd_arvores << " trees.\n";
		}
		
		/*
		for (i = 1; i <= num_vertices; i++) {
			for (j = 1; j <= num_vertices; j++) {
				cout << conexoes[i][j] << " ";
			}
			cout << "\n";
		}
		
		cout << "\n";
		
		for (i = 1; i <= num_vertices; i++) {
			cout << vertices_visitados[i] << " ";
		}
		cout << "\n";
		*/
		
		cin >> num_vertices;
		cin >> num_arestas;
		
	}
	return 0;
}
			
