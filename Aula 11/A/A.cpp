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
    lli test_cases, pos;
    bool check, ja_achei;

    cin >> test_cases;

    scanf(" ");

    while (test_cases > 0) {
        dialogo.clear();
        getline (cin, dialogo);
        pos = 0;
        ja_achei = true;
        while (ja_achei && pos < dialogo.size()) {
            ja_achei = false;

            if (dialogo[pos] == 'o' && ja_achei == false)
                if (pos + 1 < dialogo.size() && dialogo[pos+1] == 'u')
                    if (pos + 2 < dialogo.size() && dialogo[pos+2] == 't')
                        if (pos + 3 < dialogo.size() && dialogo[pos+3] == 'p')
                            if (pos + 4 < dialogo.size() && dialogo[pos+4] == 'u')
                                if (pos + 5 < dialogo.size() && dialogo[pos+5] == 't')
                                    if (pos + 6 < dialogo.size() && dialogo[pos+6] == 'o') {
                                        if (pos + 7 < dialogo.size() && dialogo[pos+7] == 'n') {
                                            if (pos + 8 < dialogo.size() && dialogo[pos+8] == 'e') {
                                                ja_achei = true;
                                                pos += 9;
                                                //cout << "entrei output one" << endl;
                                            } else {
                                                ja_achei = true;
                                                pos += 8;
                                                //cout << "entrei out puton" << endl;
                                            }
                                        } else {
                                            ja_achei = true;
                                            pos += 6;
                                            //cout << "entrei output" << endl;
                                        }
                                    } else {
                                        ja_achei = true;
                                        pos += 6;
                                        //cout << "entrei output" << endl;
                                    }

            if (dialogo[pos] == 'i' && ja_achei == false)
                if (pos + 1 < dialogo.size() && dialogo[pos+1] == 'n')
                    if (pos + 2 < dialogo.size() && dialogo[pos+2] == 'p')
                        if (pos + 3 < dialogo.size() && dialogo[pos+3] == 'u')
                            if (pos + 4 < dialogo.size() && dialogo[pos+4] == 't')
                                if (pos + 5 < dialogo.size() && dialogo[pos+5] == 'o') {
                                    if (pos + 6 < dialogo.size() && dialogo[pos+6] == 'n') {
                                        if (pos + 7 < dialogo.size() && dialogo[pos+7] == 'e') {
                                            ja_achei = true;
                                            pos += 8;
                                            //cout << "entrei input one" << endl;
                                        } else {
                                            ja_achei = true;
                                            pos += 7;
                                            //cout << "entrei in puton" << endl;
                                        }
                                    } else {
                                        ja_achei = true;
                                        pos += 5;
                                        //cout << "entrei input" << endl;
                                    }
                                } else {
                                    ja_achei = true;
                                    pos += 5;
                                    //cout << "entrei input" << endl;
                                }

            if (dialogo[pos] == 'i' && ja_achei == false)
                if (pos + 1 < dialogo.size() && dialogo[pos+1] == 'n') {
                    ja_achei = true;
                    pos += 2;
                    //cout << "entrei in" << endl;
                }

            if (dialogo[pos] == 'o' && ja_achei == false)
                if (pos + 1 < dialogo.size() && dialogo[pos+1] == 'u')
                    if (pos + 2 < dialogo.size() && dialogo[pos+2] == 't') {
                        ja_achei = true;
                        pos += 3;
                        //cout << "entrei out" << endl;
                    }

            if (dialogo[pos] == 'o' && ja_achei == false)
                if (pos + 1 < dialogo.size() && dialogo[pos+1] == 'n')
                    if (pos + 2 < dialogo.size() && dialogo[pos+2] == 'e') {
                        ja_achei = true;
                        pos += 3;
                        //cout << "entrei one" << endl;
                    }

            if (dialogo[pos] == 'p' && ja_achei == false)
                if (pos + 1 < dialogo.size() && dialogo[pos+1] == 'u')
                    if (pos + 2 < dialogo.size() && dialogo[pos+2] == 't')
                        if (pos + 3 < dialogo.size() && dialogo[pos+3] == 'o')
                            if (pos + 4 < dialogo.size() && dialogo[pos+4] == 'n') {
                                ja_achei = true;
                                pos += 5;
                                //cout << "entrei puton" << endl;
                            }
        }
        if (ja_achei)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        test_cases--;
    }
    return 0;
}
