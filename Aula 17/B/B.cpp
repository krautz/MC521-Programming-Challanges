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
#include <iomanip>

using namespace std;

typedef long long int lli;
typedef vector <lli> vetor;
typedef vector <vector <lli> > matriz;

int main () {

    lli coelhos = 0, sapos = 0, ratos = 0, test_cases, total = 0, now;
    float coelho, sapo, rato;
    char animal;

    cin >> test_cases;

    while (test_cases > 0) {
      cin >> now >> animal;
      if (animal == 'C') {
        coelhos += now;
        total += now;
      } else if (animal == 'R') {
        ratos += now;
        total += now;
      } else if (animal == 'S') {
        sapos += now;
        total += now;
      }
      test_cases--;
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "Total: " << total <<" cobaias" << endl;
    cout << "Total de coelhos: " << coelhos << endl;
    cout << "Total de ratos: " << ratos << endl;
    cout << "Total de sapos: " << sapos << endl;
    coelho = float (coelhos)/total;
    sapo = float (sapos)/total;
    rato = float (ratos)/total;
    coelho *= 100;
    sapo *= 100;
    rato *= 100;
    cout << "Percentual de coelhos: " << coelho << " %" << endl;
    cout << "Percentual de ratos: " << rato << " %" << endl;
    cout << "Percentual de sapos: " << sapo << " %" << endl;

    return 0;

  }
