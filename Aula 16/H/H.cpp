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
    lli test_cases, m, n, i, j;

    cin >> test_cases;

    matriz recursao;

    while (test_cases > 0) {
        cin >> n >> m;
        test_cases--;

        if (((n-m) & ((m-1)/2)) == 0)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}
