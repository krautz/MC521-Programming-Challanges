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

lli solve (lli n) {
    lli i, sum = 0;

    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    for (i = 1; i <= 3; i++) {
        if (i == 1)
            sum += 2*solve (n-i);
        else
            sum += solve(n-i);
    }

    //cout << "n: " << n  << " sum: " << sum << endl;

    return sum;


}

int main () {

    lli n;

    cin >> n;

    while (!cin.eof()) {
        cout << solve (n) << endl;
        cin >> n;
    }
    return 0;
}
