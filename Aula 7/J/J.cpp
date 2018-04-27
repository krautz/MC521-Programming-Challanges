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
	long long int N, total = 0;
	
	cin >> N;
	
	if (N <= 0) {
		for (long long int i = N; i != 2; i++) {
			total += i;
		}
	} else {
		 for (long long int i = 1; i != (N + 1); i++) {
			total += i;
		}
	}
	
	cout << total << "\n";
	
	return 0;
}
