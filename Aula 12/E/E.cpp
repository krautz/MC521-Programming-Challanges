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

bool is_tabuleiro_clear (vector<string> tabuleiro) {

    lli i, j;

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (tabuleiro[i][j] == '#')
                return true;
        }
    }
    return false;

}

int main () {
    lli i, j, k, numero_torres, pos_i_hash, pos_j_hash, num_hash, maior_num_hash;
    string linha;
    vector <string> tabuleiro;

    getline (cin, linha);

    while (linha.compare("END") != 0) {
        numero_torres = 0;
        vector <string> tabuleiro;
        tabuleiro.push_back (linha);
        for (i = 0; i < 14; i++) {
            getline (cin, linha);
            tabuleiro.push_back(linha);
        }

        while (is_tabuleiro_clear (tabuleiro)) {
            maior_num_hash = 0;
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    num_hash = 0;
                    for (k = i; k >= 0; k--) {
                        if (tabuleiro[k][j] == '#')
                            num_hash++;
                    }
                    for (k = i+1; k <15; k++) {
                        if (tabuleiro[k][j] == '#')
                            num_hash++;
                    }
                    for (k = j - 1; k >= 0; k--) {
                        if (tabuleiro[i][k] == '#')
                            num_hash++;
                    }
                    for (k = j+1; k < 15; k++) {
                        if (tabuleiro[i][k] == '#')
                            num_hash++;
                    }
                    if (num_hash > maior_num_hash || (num_hash == maior_num_hash && tabuleiro[i][j] == '#')) {
                        maior_num_hash = num_hash;
                        pos_i_hash = i;
                        pos_j_hash = j;
                    }
                }
            }



            for (k = pos_i_hash; k >= 0; k--) {
                if (tabuleiro[k][pos_j_hash] == '#')
                    tabuleiro[k][pos_j_hash] = '.';
            }
            for (k = pos_i_hash+1; k <15; k++) {
                if (tabuleiro[k][pos_j_hash] == '#')
                    tabuleiro[k][pos_j_hash] = '.';
            }
            for (k = pos_j_hash - 1; k >= 0; k--) {
                if (tabuleiro[pos_i_hash][k] == '#')
                    tabuleiro[pos_i_hash][k] = '.';
            }
            for (k = pos_j_hash+1; k < 15; k++) {
                if (tabuleiro[pos_i_hash][k] == '#')
                    tabuleiro[pos_i_hash][k] = '.';
            }

            numero_torres++;
        }

        cout << numero_torres << endl;
        getline(cin, linha);

    }


    return 0;

}
