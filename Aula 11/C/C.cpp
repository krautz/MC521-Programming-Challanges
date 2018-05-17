#include <stdio.h>
#include <string.h>
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

lli BFS (vector <list  <int> > &grafo, lli initial_vertex) {

    lli vertex, i;
    queue <int> fila;
    fila.push(initial_vertex);
    std::list<int>::iterator it;

    while (!fila.empty()) {
        vertex = fila.front();
        fila.pop();
        if (fila.empty())
            return vertex;
        for (it = grafo[vertex].begin(); it != grafo[vertex].end(); it++) {
            if (*it != vertex) {
                fila.push (*it);
            }
        }
    }
}

lli BFS_2 (vector <list  <int> > &grafo, lli initial_vertex) {

    lli vertex, i, tam = 0;
    queue <int> fila;
    fila.push(initial_vertex);
    std::list<int>::iterator it;

    while (!fila.empty()) {
        vertex = fila.front();
        fila.pop();
        tam++;
        for (it = grafo[vertex].begin(); it != grafo[vertex].end(); it++) {
            if (*it != vertex) {
                fila.push (*it);
            }
        }
    }
}


int main () {
    lli n, u, v;

    vector <list <int> > grafo(n+1);

    for (i = 0; i < n - 1; i++) {
        cin >> u >> v;
        grafo[u].push_back (v);
        grafo[v].push_back (u);
    }

    for (i = 1; i <= n; i++) {
        grafo[i].unique();
    }

    cout << BFS_2 (grafo, BFS(grafo, 1)) << endl;;

    return 0;
}
