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
	lli fat = 1, n, i;
	
	cin >> n;
	
	for (i = 1; i < n; i++) {
		fat *= i;
	}
	
	cout << fat << endl;
	
	return 0;
}
