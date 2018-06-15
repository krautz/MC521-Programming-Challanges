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

void solve (vector <string> &grid_1, vector <string> &grid_2, lli *k, lli j, string &res, vector<string> &all_res) {

    if (j == 5) {
        all_res.push_back(res);
        (*k)--;
        return;
    }

    lli a = 0;
    lli b = 0;
    for (a = 0; a < 6; a++) {
        for (b = 0; b < 6; b++) {
            if (grid_1[a][j] == grid_2[b][j]) {
                res[j] = grid_1[a][j];
                solve (grid_1, grid_2, k, j + 1, res, all_res);
            }
        }
    }
}

int main () {
    lli test_cases, k, i, j;

    cin >> test_cases;

    vector <string> grid_1;
    vector <string> grid_2;
    vector <string> transp_1;
    vector <string> transp_2;

    for (i = 0; i < 6; i++) {
        string aux = "AAAAAA";
        grid_1.push_back(aux);
        grid_2.push_back(aux);
        transp_1.push_back(aux);
        transp_2.push_back(aux);
    }

    while (test_cases > 0) {
        cin >> k;
        scanf (" ");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                cin >> grid_1[j][i];
            }
        }
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                cin >> grid_2[j][i];
            }
        }


        for (i = 0; i < 5; i++) {
            sort(grid_1[i].begin(), grid_1[i].end());
        }

        for (i = 0; i < 5; i++) {
            sort(grid_2[i].begin(), grid_2[i].end());
        }


        for (i = 0; i < 5; i++) {
            for (j = 0; j < 6; j++) {
                transp_1[j][i] = grid_1[i][j];
                transp_2[j][i] = grid_2[i][j];
            }
        }

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                grid_1[i][j] = transp_1[i][j];
                grid_2[i][j] = transp_2[i][j];
            }
        }

        /*
        cout << endl << endl;

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                cout << grid_1[i][j];
            }
            cout << endl;
        }
        cout << endl << endl;

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 5; j++) {
                cout << grid_2[i][j];
            }
            cout << endl;

        }
        cout << endl << endl;*/

        vector<string> all_res;
        string res = "AAAAA";
        lli save = k;
        solve (grid_1, grid_2, &k, 0, res, all_res);
        sort (all_res.begin(), all_res.end());
        lli count = 0;
        //cout << k << endl;
        for (i = 0; i < all_res.size() && count != save; i++) {
            if (i > 0 && all_res[i].compare(all_res[i-1]) != 0){
                count++;
                //cout << all_res[i] << endl;
            } else if (i == 0) {
                //cout << all_res[i] << endl;
                count++;
            }
        }


        if (count == save)
            cout << all_res[i-1] << endl;
        else
            cout << "NO" << endl;


        test_cases--;
    }

    return 0;
}
