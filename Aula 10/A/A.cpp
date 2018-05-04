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
	lli x1, x2, x3, x4, x5, x6, sum, div;
	
	cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
	
	while (x1 != 0 || x2 != 0 || x3 != 0 || x4 != 0 || x5 != 0 || x6 != 0) {
		x2 *= 4;
		x3 *= 9;
		x4 *= 16;
		x5 *= 25;
		x6 *= 36;
		sum = x1 + x2 + x3 + x4 + x5 + x6;
		div = sum / 36;
		if (sum % 36 != 0)
			div++;
		
		cout << div;
		cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
		if (x1 != 0 || x2 != 0 || x3 != 0 || x4 != 0 || x5 != 0 || x6 != 0) 
			cout << endl;
	}
	
	return 0;
}
		
