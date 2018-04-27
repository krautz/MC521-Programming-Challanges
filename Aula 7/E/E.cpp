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

	long long int n, maior, i;
	
	cin >> n;
	
	maior = 0;
	vector <long long int> a(999999 + 10);
	a[0] = 0;
	a[1] = 1;
	for (i = 1; i <= 49999; i++) {
		a[2*i] = a[i];
		a[(2*i) + 1] = a[i] + a[i+1];
	}
	
	while (n != 0) {
		maior = 0;
		for (i = 0; i <= n; i++) {
			if (a[i] > maior)
				maior = a[i];
		}		

		cout << maior << "\n";
		cin >> n;
	}
	return 0;
}
