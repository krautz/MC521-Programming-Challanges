#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>
#include <iomanip>

using namespace std;

int main () {
	int p, r, q, s, t, u;
	double res_low, res_high, res_mid;
	
	cin >> p;
	if (!cin.eof()) {
		cin >> q;
		cin >> r;
		cin >> s;
		cin >> t;
		cin >> u;
	}
	
	while (!(cin.eof())) {
		res_low = p*pow(M_E, 0) + q*sin(0) + r*cos(0) + s*tan(0) + t * pow(0, 2) + u;
		res_high = p*pow(M_E, -1) + q*sin(1) + r*cos(1) + s*tan(1) + t + u;
		if ((res_high > 0 && res_low > 0) || (res_high < 0 && res_low < 0)) {
			cout << "No solution\n";
		} else {
			int resp = 1;
			double high = 1;
			double low = 0;
			double mid;
			if (fabs(res_low) < 0.000001) {
				mid = low;
				resp = 0;
			} else if (fabs(res_high) < 0.000001) {
				mid = high;
				resp = 0;
			}
			while (resp) {
				mid = (high + low)/2;
				res_mid = p*pow(M_E, -mid) + q*sin(mid) + r*cos(mid) + s*tan(mid) + t*pow(mid, 2) + u;
				
				if (fabs(res_mid) < 0.0000001) {
					resp = 0;
				} else if ((res_mid < 0 && res_low < 0) || (res_mid > 0 && res_low > 0)) {
					low = mid;
					res_low = res_mid;
				} else {
					high = mid;
					res_high = res_mid;
				}
			}
			cout << fixed << setprecision(4) << mid << "\n";
		}
		cin >> p;
		if (!cin.eof()) {
			cin >> q;
			cin >> r;
			cin >> s;
			cin >> t;
			cin >> u;
		}
	}
	
	return 0;
}
				
