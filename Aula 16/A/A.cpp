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
    lli test_cases, i, j, rt, cases = 1;

    cin >> test_cases;
    scanf(" ");

    while (test_cases > 0) {
        cout << "Case #" << cases <<":" << endl;
        cases++;
        string frase, frase_limpa;
        getline (cin, frase);
        for (i = 0; i < frase.size(); i++) {
            if (frase[i] >= 'a' && frase[i] <= 'z') {
                frase_limpa.push_back(frase[i]);
            }
        }

        rt = 1;
        while (rt * rt < frase_limpa.size()) {
            rt++;
        }
        if (rt*rt == frase_limpa.size()) {
            vector <string> palindrome;
            i = 0;
            while (i != frase_limpa.size()) {
                string aux;
                for (j = 0; j < rt; j++, i++) {
                    aux.push_back(frase_limpa[i]);
                }
                palindrome.push_back(aux);
            }

            string jeito1, jeito2, jeito3, jeito4;

            for (i = 0; i < palindrome[0].size(); i++)
                jeito1.push_back(palindrome[0][i]);

            for (i = rt- 1; i >= 0; i--)
                jeito2.push_back(palindrome[rt-1][i]);

            for (i = 0; i < rt; i++)
                jeito3.push_back(palindrome[i][0]);

            for (i = rt - 1; i >= 0; i--)
                jeito4.push_back(palindrome[i][rt - 1]);

            if (jeito1.compare(jeito2) == 0 && jeito1.compare(jeito3) == 0 && jeito1.compare(jeito4) == 0)
                cout << rt << endl;
            else
                cout << "No magic :(" << endl;

        } else {
            cout << "No magic :(" << endl;
        }
        test_cases--;
    }

    return 0;
}
