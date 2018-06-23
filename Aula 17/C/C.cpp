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
  lli test_cases, i, j, limite_hash, numero_entradas, num;

  cin >> test_cases;

  while (test_cases > 0){
    cin >> limite_hash >> numero_entradas;
    matriz hash;
    for (i = 0; i < limite_hash + 1; i++){
      vector <lli> aux (numero_entradas + 10, -1);
      hash.push_back(aux);
    }
    for(i = 0; i < numero_entradas; i++) {
      cin >> num;
      //cout << num << "    " << num%limite_hash;
      j = 0;
      while (hash[num%limite_hash][j] != -1) {
        j++;
      }
      hash[num%limite_hash][j] = num;
    }
    for (i = 0; i < limite_hash; i++) {
      cout << i << " -> ";
      j = 0;
      while (hash[i][j] != -1) {
        cout << hash[i][j] << " -> ";
        j++;
      }
      cout << "\\" << endl;
    }
    test_cases--;
    if (test_cases != 0)
      cout << endl;
  }

  return 0;
}
