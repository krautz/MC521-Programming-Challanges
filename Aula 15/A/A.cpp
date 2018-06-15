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

lli min_antena (vector<string> &suecia, lli h, lli w, lli i, lli j) {
    if (i < 0 || i >= h || j < 0 || j >= w)
        return 0;

}

int main () {
    lli n, i, j, h, w, antenas;

    cin >> n;
    while (n > 0) {
        cin >> h >> w;
        scanf (" ");
        vector <string> suecia;
        for (i = 0; i < h; i++) {
            string aux;
            getline (cin, aux);
            suecia.push_back(aux);
        }
        antenas = 0;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                if (suecia[i][j] == "*") {
                    antenas += min_antena (suecia, i, j, h, w);
                }
            }
        }
        /*for (i = 0; i < h; i++)
            cout << suecia[i] << endl;
        cout << endl;
        */
        cout << antenas << endl;
        n--;
    }
    return 0;
}
