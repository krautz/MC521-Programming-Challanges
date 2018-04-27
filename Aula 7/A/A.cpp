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
	long long int N, M, i, C_i, total;
	
	cin >> N >> M;
	
	while (N != -1 && M != -1) {
		total = 0;
		for (i = N; i > 0; i--) {
			cin >> C_i;
			total += C_i * i;
		}
		total = total * M;
		cout << total << "\n";
		cin >> N >> M;
	}

	return 0;
}
