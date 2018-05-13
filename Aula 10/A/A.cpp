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
		div = x6;
		x6 = 0;

		while (x5 > 0) {
			div++;
			x5--;
			x1 -= 11;
		}
		while (x4 > 0) {
			div++;
			x4--;
			if (x2 >= 5) {
				x2 -= 5;
			} else if (x2 == 4) {
				x2 = 0;
				x1 -= 4;
			} else if (x2 == 3) {
				x2 = 0;
				x1 -= 8;
			} else if (x2 == 2) {
				x2 = 0;
				x1 -= 12;
			} else if (x2 == 1) {
				x2 = 0;
				x1 -= 16;
			} else {
				x1 -= 20;
			}
		}

		while (x3 > 0) {
			div++;
			if (x3 >= 4) {
				x3 -= 4;
			} else if (x3 == 3) {
				x3 = 0;
				if (x2 >= 1) {
					x2--;
					x1 -= 5;
				} else {
					x1 -= 9;
				}
			} else if (x3 == 2) {
				x3 = 0;
				if (x2 >= 3) {
					x2 -= 3;
					x1 -= 6;
				} else if (x2 == 2) {
					x2 = 0;
					x1 -= 10;
				} else if (x2 == 1) {
					x2 = 0;
					x1 -= 14;
				} else {
					x1 -= 18;
				}
			} else if (x3 == 1) {
				x3 = 0;
				if (x2 >= 5) {
					x2 -= 5;
					x1 -= 7;
				} else if (x2 == 4) {
					x2 = 0;
					x1 -= 11;
				} else if (x2 == 3) {
					x2 = 0;
					x1 -= 15;
				} else if (x2 == 2) {
					x2 = 0;
					x1 -= 19;
				} else if (x2 == 1) {
					x2 = 0;
					x1 -= 23;
				} else {
					x1 -= 27;
				}
			}
		}

		while (x2 > 0) {
			div++;
			if (x2 >= 9) {
				x2 -= 9;
			} else if (x2 == 8) {
				x2 = 0;
				x1 -= 4;
			} else if (x2 == 7) {
				x2 = 0;
				x1 -= 8;
			} else if (x2 == 6) {
				x2 = 0;
				x1 -= 12;
			} else if (x2 == 5) {
				x2 = 0;
				x1 -= 16;
			} else if (x2 == 4) {
				x2 = 0;
				x1 -= 20;
			} else if (x2 == 3) {
				x2 = 0;
				x1 -= 24;
			} else if (x2 == 2) {
				x2 = 0;
				x1 -= 28;
			} else if (x2 == 1) {
				x2 = 0;
				x1 -= 32;
			}
		}

		while (x1 > 0) {
			div++;
			x1 -= 36;
		}

		cout << div << endl;
		cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
	}

	return 0;
}
