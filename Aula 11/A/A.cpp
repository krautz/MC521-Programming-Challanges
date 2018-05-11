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

string dialogo;
lli pos;

bool e_dialogo () {

    if (pos >= dialogo.size())
        return true;

    bool check = false;

    if (dialogo[pos] == 'i')
        if (dialogo[pos+1] == 'n') {
            pos += 2;
            check = e_dialogo ();
            pos -= 2;
        }

    if (dialogo[pos] == 'o')
        if (dialogo[pos+1] == 'u')
            if (dialogo[pos+2] == 't')
                if (check == false) {
                    pos += 3;
                    check = e_dialogo ();
                    pos -= 3;
                }

    if (dialogo[pos] == 'o')
        if (dialogo[pos+1] == 'n')
            if (dialogo[pos+2] == 'e')
                if (check == false) {
                    pos += 3;
                    check = e_dialogo ();
                    pos -= 3;
                }

    if (dialogo[pos] == 'i')
        if (dialogo[pos+1] == 'n')
            if (dialogo[pos+2] == 'p')
                if (dialogo[pos+3] == 'u')
                    if (dialogo[pos+4] == 't')
                        if (check == false){
                            pos += 5;
                            check = e_dialogo ();
                            pos -= 5;
                        }

    if (dialogo[pos] == 'p')
        if (dialogo[pos+1] == 'u')
            if (dialogo[pos+2] == 't')
                if (dialogo[pos+3] == 'o')
                    if (dialogo[pos+4] == 'n')
                        if (check == false){
                            pos += 5;
                            check = e_dialogo ();
                            pos -= 5;
                        }

    if (dialogo[pos] == 'o')
        if (dialogo[pos+1] == 'u')
            if (dialogo[pos+2] == 't')
                if (dialogo[pos+3] == 'p')
                    if (dialogo[pos+4] == 'u')
                        if (dialogo[pos+5] == 't')
                            if (check == false){
                                pos += 6;
                                check = e_dialogo ();
                                pos -= 6;
                            }

    return check;

}

int main () {
    lli test_cases;

    cin >> test_cases;

    scanf(" ");

    while (test_cases > 0) {
        dialogo.clear();
        getline (cin, dialogo);
        pos = 0;
        if (e_dialogo())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        test_cases--;
    }
    return 0;
}
