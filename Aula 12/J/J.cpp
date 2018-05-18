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

    lli i, n;

    cin >> n;

    vetor fat (13);
    vetor chapeus (13);

    fat[0] = 0;
    fat[1] = 1;
    fat[2] = 2;
    fat[3] = 6;

    chapeus[2] = 1;
    chapeus[3] = 2;

    for (i = 4; i <= 12; i++) {
        chapeus[i] = (i-1)*(chapeus[i-1] + chapeus[i-2]);
        fat[i] = i*fat[i-1];
    }

    while (n) {
        cin >> i;
        cout << chapeus[i] << "/" << fat[i] << endl;
        n--;
    }
    return 0;
}
