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
    lli n, i, centena, dezena, unidade;

    cin >> n;
    scanf(" ");

    vector <string> palavras;
    for (i = 0; i < n; i++) {
        string aux;
        getline (cin, aux);
        palavras.push_back(aux);
    }

    vector <string> oq_falta (1000, 0);
    for (centena = 0; centena <= 9; centena++) {
        for (dezena = 0; dezena <= 9; dezena++) {
            for (unidade = 0; unidade <= 10; unidade++) {
                string aux;
                
            }
        }
    }


    return 0;
}
