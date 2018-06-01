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

bool explosao (vector <string> &tabuleiro, lli i, lli j, lli n, lli m) {
    bool a, b, c, d;
    if (i >= 0 && i < n && j >= 0 && j < m) {
        if (tabuleiro[i][j] == '#')
            return false;
        if (tabuleiro[i][j] == '.')
            return true;
        tabuleiro[i][j] = '.';
        a = explosao (tabuleiro, i-1, j, n, m);
        b = explosao (tabuleiro, i+1, j, n, m);
        c = explosao (tabuleiro, i, j-1, n, m);
        d = explosao (tabuleiro, i, j+1, n, m);
        return a && b && c && d;
    } else {
        return true;
    }
}

int main () {
    vector <string> tabuleiro;
    lli m, n, i, tiros, tiro_i, tiro_j, explosoes = 0, j;

    cin >> n;
    cin >> m;
    scanf (" ");

    for (i = 0; i < n; i++) {
        string aux;
        getline (cin, aux);
        tabuleiro.push_back (aux);
    }

    /*for (i = 0; i < n; i++) {
        cout << tabuleiro[i] << endl;
    }*/

    cin >> tiros;

    for (i = 0; i < tiros; i++) {
        cin >> tiro_i;
        cin >> tiro_j;
        if (tabuleiro[tiro_i-1][tiro_j-1] == '#')
            tabuleiro[tiro_i-1][tiro_j-1] = '*';
    }


    /*for (i = 0; i < n; i++) {
        cout << tabuleiro[i] << endl;
    }*/

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (tabuleiro[i][j] == '*') {
                //cout << i << " " << j << endl;
                if (explosao (tabuleiro, i, j, n, m))
                    explosoes++;
            }
        }
    }
    cout << explosoes << endl;


    return 0;

}
