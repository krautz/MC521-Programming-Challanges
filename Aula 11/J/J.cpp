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

lli resolve (lli n, vetor &solucoes) {

    lli sum = 0;

    if (solucoes[n] != 0)
        return solucoes[n];

    for (lli i = 2; i <= n; i+=2) {
        if (i == 2) {
            sum += 3*resolve (n - i, solucoes);
        } else {
            sum += 2*resolve(n-i, solucoes);
        }
    }

    return sum;
}

int main () {
    lli n;

    cin >> n;
    vetor respostas (31, 0);

    respostas[0] = 1;
    for (lli i = 2; i <= 30; i+=2) {
        respostas[i] = resolve (i, respostas);
    }


    while (n != -1) {
        cout << respostas[n] << endl;
        cin >> n;
    }

    return 0;


}
