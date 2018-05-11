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

void rotate2 (vector <string> &m, lli n) {
    vector <string> m_aux;

    for (lli i = 0; i < n; i++) {
        string aux;
        for (lli j = 0; j < n; j++) {
            aux[j] = '#';
        }
        m_aux.push_back(aux);
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            m_aux[i][j] = m[i][j];
        }
    }

    for (lli i = 0; i < n; i++) {
        for (lli j = 0; j < n; j++) {
            m[j][n-i-1] = m_aux[i][j];
        }
    }


}

void rotate (vector <string> &m, lli n) {
    char temp;
    for(lli i=0; i<n/2; i++)
        for(lli j=0; j<(n+1)/2; j++) {
            temp = m[i][j];
            m[i][j] = m[n-1-j][i];
            m[n-1-j][i] = m[n-1-i][n-1-j];
            m[n-1-i][n-1-j] = m[j][n-1-i];
            m[j][n-1-i] = temp;
        }
}

int main () {
    lli n, i, j , k;

    cin >> n;
    while (n != 0) {
        vector <string> grid;
        vector <string> text;
        scanf (" ");
        for (i = 0; i < n; i++) {
            string aux;
            getline (cin, aux);
            grid.push_back(aux);
        }
        for (i = 0; i < n; i++) {
            string aux;
            getline (cin, aux);
            text.push_back(aux);
        }
        k = 4;
        while (k > 0) {

            /* for (i = 0; i < n; i++)
                cout << grid[i] << endl;
            cout << endl << endl; */

            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (grid[i][j] == 'O')
                        cout << text[i][j];
                }
            }
            k--;
            rotate(grid, n);
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}
