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

lli resolve (matriz &tabuleiro, lli n, lli coluna_atual) {
    


}

int main () {
    lli n;

    cin >> n;

    while (n > 0) {
        matriz tabuleiro;
        for (lli i = 0; i < 3; i++) {
            vetor aux (n, 0);
            tabuleiro.push_back(aux);
        }
        cout << resolve (tabuleiro, n, 0) << endl;
        cin >> n;
    }

    return 0;


}
