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
	string c;
	
	while (getline(cin, c)) {
		for (lli i = 0; i < c.size(); i++) {
			cout << char(c[i]-7);
		}
		cout << endl;
	}
	
	return 0;
}
