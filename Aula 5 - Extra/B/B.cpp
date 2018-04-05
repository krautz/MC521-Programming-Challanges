#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main () {
	int n, i;
	long long int count = 0;
	
	cin >> n;
	
	vector <int> medalhas(n);
	
	for (i = 0; i < n; i++) {
		cin >> medalhas[i];
	}
	
	sort(medalhas.begin(), medalhas.end());
	
	for (i = 1; i < n; i++) {
		while (medalhas[i-1] >= medalhas[i]) {
			medalhas[i]++;
			count++;
		}
	}
	
	cout << count << "\n";
	
	return 0;
}
