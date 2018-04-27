#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

int main () {
	long long int test_cases, N, coins, i, j = 1;
	
	cin >> test_cases;
	
		
	while (test_cases != 0) {
		cin >> N;
		if (N == 0) {
			cout << "Case " << j << ": 0" << "\n";
			j++;
		} if (N == 1) {
			cin >> coins;
			cout << "Case " << j << ": " << coins << "\n";
			j++;
		} else {
			vector <long long int> gold(2*N);
			gold[0] = 0;
			cin >> gold[1];
			for (i = 2; i <= N; i++) {
				cin >> coins;
				if (coins + gold[i-2] > gold[i-1]) {
					gold[i] = coins + gold[i-2];
				} else {
					gold[i] = gold[i-1];
				}
			}
			cout << "Case " << j << ": " << gold[N] << "\n";
			j++;
		}
		test_cases--;
	}
	return 0;
}
