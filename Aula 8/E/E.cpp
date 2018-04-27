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
	lli n, i, j, k, num = 0;
	cin >> n;
	for (j = 1; j <= n/2; j++) {
		i = j;
		for (k = i; k * i <= n; k++) {
			num ++;
		}
	}
	if (n == 1) {
		cout << "1" << endl;
	} else {
		cout << num << endl;
	}
	return 0;
		
}
	
