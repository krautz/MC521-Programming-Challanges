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
    lli n, i, tam;

    cin >> n;
    scanf (" ");

    while (n > 0) {
        string frase;
        getline (cin, frase);
        i = 0;
        while (i < frase.size()) {
            tam = 1;
            while (i < frase.size() - 1 && frase[i] == frase[i+1]) {
                i++;
                tam++;
            }
            cout << tam;
            cout << frase[i];
            i++;
        }
        cout << endl;
        n--;
    }
    return 0;
}
