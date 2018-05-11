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

lli inverte (lli numero) {

    lli numero_output = 0, i;

    vetor digitos;
    while (numero != 0) {
        digitos.push_back (numero%10);
        numero = numero/10;
    }
    
    for (i = 0; i < digitos.size(); i++) {
        numero_output +=digitos[i] * (pow (10, digitos.size() - i - 1));
    }

    return numero_output;

}

int main () {
    lli n, numero1, numero2;

    cin >> n;

    while (n > 0) {
        cin >> numero1 >> numero2;
        cout << inverte(inverte(numero1) + inverte(numero2)) << endl;
        n--;
    }
    return 0;
}
