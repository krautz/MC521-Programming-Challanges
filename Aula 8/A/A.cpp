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

	lli test_cases;
	
	cin >> test_cases;
	
	while (test_cases > 0) {

		map <int, int> mapa;
		map<int ,int>::iterator it;
		lli inicio = 0, maior = 0, n, i, aux;
		cin >> n;
		for (i = 0; i < n; i++) {
			//cout << "inicio: " << inicio << " fim " << i << endl;
			cin >> aux;
			it = mapa.find(aux);
			if (it == mapa.end()) {
				mapa[aux] = i;
			} else {
				if (it->second >= inicio) {
					if (i-inicio > maior)
						maior = i-inicio;
					inicio = it->second + 1;
					it->second = i;
				} else {
					it->second = i;
				}
			}
		}
		if (i-inicio > maior)
			maior = i-inicio;
		cout << maior << endl;
		test_cases--;
	}
	
	
	return 0;
}
