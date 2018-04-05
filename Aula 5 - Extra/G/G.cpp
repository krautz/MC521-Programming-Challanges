#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main () {
	long long int i, j, k, m, l, resi, resj, resk, resm, flag, n;
	vector <long long int> numeros(5);
	vector <long long int> op(4);
	
	for (i = 0; i < 5; i++) {
		cin >> numeros[i];
	}
	while (numeros[0] != 0 || numeros[1] != 0 || numeros[2] != 0 || numeros[3] != 0 || numeros[4] != 0) {
		sort (numeros.begin(), numeros.end());
		flag = 1;
		for (l = 0; l < 120 && flag; l++) {
			for (i = 0; i < 3 && flag; i++) {
				if (i == 0) {
					resi = numeros[0] + numeros[1];
				} else if (i == 1) {
					resi = numeros[0] - numeros[1];	
				} else if (i == 2) {
					resi = numeros[0] * numeros[1];
				}
				for (j = 0; j < 3 && flag; j++) {
					if (j == 0) {
						resj = resi + numeros[2];
					} else if (j == 1) {
						resj = resi - numeros[2];
					} else if (j == 2) {
						resj = resi * numeros[2];
					}
					for (k = 0; k < 3 && flag; k++) {
						if (k == 0) {
							resk = resj + numeros[3];
						} else if (k == 1) {
							resk = resj - numeros[3];
						} else if (k == 2) {
							resk = resj * numeros[3];
						}
						for (m = 0; m < 3 && flag; m++) {
							if (m == 0) {
								resm = resk + numeros[4];
							} else if (m == 1) {
								resm = resk - numeros[4];
							} else if (m == 2) {
								resm = resk * numeros[4];
							}
						
							if (resm == 23) {
								flag = 0;
								cout << "Possible\n";
							}
						}
					}
				}
			}
			next_permutation (numeros.begin(), numeros.end());
		}
		
		if (flag)
			cout << "Impossible\n";
		
		for (i = 0; i < 5; i++) {
			cin >> numeros[i];
		}
	}

	return 0;
}
