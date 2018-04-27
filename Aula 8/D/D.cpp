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

lli mmc (lli num1, lli num2) {

	lli i, troca;    
	
	if (num1 > num2) {
		troca = num2;
		num2 = num1;
		num1 = troca;
	}

    for (i = num1; i <= num2*num1; i++) {
        if ((i % num2) == 0 && (i % num1 == 0)) {
            return i;
        }
    }
    return num1*num2;
}

int main () {

	lli x, y, a, b, inicio, num = 0, i, prim, ult, m;
	cin >> x >> y >> a >> b;
	
	m = mmc(x,y);
	//cout << m << endl;
	if (a % m == 0) {
		prim = a;
	} else if (m >= a) {
		prim = m;
	} else {
		prim = (m - (a%m)) + a;
	}
	
	ult = b - (b%m);
	
	//cout << prim << " " << ult << endl;
	
	num = ((ult-prim) / m) + 1;
	
	cout << num << endl;
		
	
	return 0;
}
