#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

void acha_numero_triangulos (vector <long long int> &dinamic, long long int n) {
	long long int i, sum_pa;
	
	i = floor(n/2);
	sum_pa = i * (i - 1);
	if (n % 2 == 0) {
		sum_pa -= (i - 1);
	}
	dinamic[n] = sum_pa + dinamic[n-1];
	return;
}
	

int main () {
	long long int test_cases;
	long long int n, i;
	vector <long long int> dinamic(1000001, 0);
	
	cin >> test_cases;
	
	while (test_cases) {
		cin >> n;
		for (i = 4; i <= n; i++) {
			if (dinamic[i] == 0) {
				acha_numero_triangulos(dinamic, i);
			}
		}
		cout << dinamic[n] << "\n";
		test_cases--;
	}
	return 0;
}
