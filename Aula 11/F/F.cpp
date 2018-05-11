#include <stdio.h>
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

bool anda_labirinto (vector < vector <char> > &labirinto, lli x_ini, lli y_ini, lli x, lli y, lli x_pos, lli y_pos, lli k) {
    if (x_pos < 0 || x_pos == x || y_pos < 0 || y_pos == y)
        return false;
    if (k <= 0 && x_pos == x_ini && y_pos == y_ini)
        return true;
    if (labirinto[x_pos][y_pos] == '*')
        return false;
    labirinto[x_pos][y_pos] = '*';

    bool check;
    check = anda_labirinto (labirinto, x_ini, y_ini, x, y, x_pos + 1, y_pos, k - 1);
    if (check == false)
        check = anda_labirinto (labirinto, x_ini, y_ini, x, y, x_pos - 1, y_pos, k - 1);
    if (check == false)
        check = anda_labirinto (labirinto, x_ini, y_ini, x, y, x_pos, y_pos + 1, k - 1);
    if (check == false)
        check = anda_labirinto (labirinto, x_ini, y_ini, x, y, x_pos, y_pos - 1, k - 1);

    labirinto[x_pos][y_pos] = '.';
    return check;
}

int main () {

    lli x, y, k, x_ini, y_ini, i , j;

    cin >> x >> y >> k >> x_ini >> y_ini;
    scanf (" ");

    vector < vector <char> > labirinto;
    for (i = 0; i < x; i++) {
        vector <char> linha;
        for (j = 0; j < y; j++) {
            char aux;
            scanf("%c", &aux);
            linha.push_back(aux);
            if (j != y - 1)
                scanf (" ");
            //cout << linha[j] << " ";
        }
        if (i != x - 1)
            scanf (" ");

        //cout << endl << endl;
        labirinto.push_back(linha);
    }

    if (anda_labirinto (labirinto, x_ini - 1, y_ini - 1, x, y, x_ini - 1, y_ini - 1, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

/*
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            cout << labirinto[i][j] << " ";
        }
        cout << endl;
    }
*/

    return 0;
}
