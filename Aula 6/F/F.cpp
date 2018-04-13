#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

bool checa_se_cabe (long long int cows, vector <long long int> &stalls, long long int tam_stalls, long long int espacamento) {
	long long int i, ultimo_visitado = stalls[0], count = 1;

	for (i = 1; i < tam_stalls; i++) {
		if (stalls[i] - ultimo_visitado >= espacamento) {
			count++;
			ultimo_visitado = stalls[i];
		}
	}
	if (cows <= count)
		return true;
	return false;
}

int main () {
	long long int test_cases, s, cows, i, high, low, mid, pos;
	
	cin >> test_cases;
	
	while (test_cases > 0) {
		high = 1000000000;
	 	low = 0;
		cin >> s >> cows;
		vector <long long int> stalls (s);
		for (i = 0; i < s; i++) {
			cin >> stalls[i];
		}
		sort (stalls.begin(), stalls.end());
		
		while (low <= high) {
			mid = (high+low)/2;
			
			if (checa_se_cabe (cows, stalls, s, mid)) {
				low = mid + 1;
				pos = mid;
			} else {
				high = mid - 1;
			}
		}
		
		cout << pos << "\n";
		test_cases--;
	}
	
	return 0;
}
