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
    lli k, i;
    vetor A (46, 0);
    vetor B (46, 0);

    A[0] = 1;
    B[1] = 1;

    cin >> k;

    for (i = 2; i <= k; i++) {
        A[i] = B[i-1];
        B[i] = B[i-1] + A[i-1];
    }

    cout << A[k] << " " << B[k] << endl;

    return 0;
}
