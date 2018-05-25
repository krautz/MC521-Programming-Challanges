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
    lli i, j, k, n, amizades_local, amizades_globais, indice;

    cin >> n;

    scanf(" ");

    while (n > 0) {
        vector <string> amizades;
        string aux;
        getline(cin, aux);
        amizades.push_back(aux);
        for (i= 1; i < aux.size(); i++) {
            getline (cin, aux);
            amizades.push_back(aux);
        }

        /*for (i = 0; i < amizades[0].size(); i++) {
            cout << amizades[i] << endl;
        }
        cout << endl << endl;
        */
        indice = 0;
        amizades_globais = 0;
        for (i = 0; i < amizades[0].size(); i++) {
            amizades_local = 0;
            for (j = 0; j < amizades[0].size(); j++) {
                if (amizades[i][j] == 'Y') {
                    for (k = 0; k < amizades[0].size(); k++) {
                        if (amizades[j][k] == 'Y' && k != i && amizades[i][k] == 'N')
                            amizades_local++;
                    }
                }
            }
            if (amizades_local > amizades_globais) {
                indice = i;
                amizades_globais = amizades_local;
            }
        }
        cout << indice << " " << amizades_globais << endl;
        n--;
    }
    cout << endl;
    return 0;
}
