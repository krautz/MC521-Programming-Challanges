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
  lli gols_red, gols_blue, gols_green, test_cases, gols, i;
  char marcou, tomou;
  cin >> test_cases;

  while (test_cases > 0) {
    cin >> gols;
    gols_red = 0;
    gols_blue = 0;
    gols_green = 0;
    for (i = 0; i < gols; i++) {
      cin >> marcou >> tomou;
      if (marcou == 'G')
        if (tomou == 'B')
          gols_green += 2;
        else
          gols_green += 1;

        if (marcou == 'B')
          if (tomou == 'R')
            gols_blue += 2;
          else
            gols_blue += 1;
        if (marcou == 'R')
          if (tomou == 'G')
            gols_red += 2;
          else
            gols_red += 1;
    }
    if (gols_blue > gols_red && gols_blue > gols_green)
      cout << "blue" << endl;
    else if (gols_red > gols_blue && gols_red > gols_green)
      cout << "red" << endl;
    else if (gols_green > gols_blue && gols_green > gols_red)
      cout << "green" << endl;
    else if (gols_red == gols_blue && gols_red == gols_green)
      cout << "trempate" << endl;
    else if (gols_red == gols_blue || gols_blue == gols_green || gols_red == gols_green)
      cout << "empate" << endl;
    test_cases--;
  }

  return 0;
}
