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

int main () {
    lli m, n, u, d, l, r, i, j, k, y;

    cin >> m >> n >> u >> l >> r >> d;

    scanf (" ");

    vector <string> palavras;
    for (i = 0; i < m; i++) {
        string aux;
        getline (cin, aux);
        palavras.push_back (aux);
    }

    // for (i = 0; i < m; i++)
    //     cout << palavras[i] << endl;

    string linha_par;
    for (i = 0; i < n + l + r; i++) {
        if (i % 2 == 0)
            linha_par.push_back ('#');
        else
            linha_par.push_back ('.');
    }

    string linha_impar;
    for (i = 0; i < n + l + r; i++) {
        if (i % 2 == 1)
            linha_impar.push_back ('#');
        else
            linha_impar.push_back ('.');
    }

    vector <string> frame;

    for (i = 0; i  < m + u + d; i++) {
        if (i % 2 == 0)
            frame.push_back (linha_par);
        else
            frame.push_back (linha_impar);
    }

    /*for (i = 0; i  < m + u + d; i++) {
        cout << frame[i] << endl;
    }

    k = 0;
    y = 0;
    for (i = u; i <= u + m; i++) {
        for (j = l; j < n; j++) {
            frame[i][j] = palavras[k][y];
            y++;
        }
        k++;
        y = 0;
    }*/

    for (i = 0; i < m + u + d; i++) {
        for (j = 0; j < n + l + r; j++) {
            if (i >= u && i < u+m && j == l) {
                cout << palavras[i - u];
                j += n;
                j--;
            } else {
                cout << frame[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
