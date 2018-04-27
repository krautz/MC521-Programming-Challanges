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
	lli test_cases, n, diff;
	
	cin >> test_cases;
	
	while (test_cases > 0) {
		
		lli menor = 1000000001, i;
		cin >> n >> diff;
		diff--;
		vetor alturas(n);
		for (i = 0; i < n; i++)
			cin >> alturas[i];
		sort  (alturas.begin(), alturas.end());
		
		for (i = 0; i < n - diff; i++) {
			if (alturas[i+diff] - alturas[i] < menor) {
				menor = alturas[i+diff] - alturas[i];
			}
		}		 
		
		cout << menor << endl;
		test_cases--;
	}
	return 0;
}
