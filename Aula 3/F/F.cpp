#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <string>

using namespace std;

long long int acha_menor (int p, int q) {
	long long int i, pot = pow (2, q), conversao, j;
	
	string numero (p, '1');
	numero[p-1] = '2';
	
	for (i = 0; i < pow (2, p-1); i++) {
		conversao = stoll (numero);
		if (conversao % pot == 0) {
			return conversao;
		}
		
		j = p - 2;
		while (j >= 0) {
			if (numero[j] == '1') {
				numero[j] = '2';
				j = -1;
			} else {
				numero[j] = '1';
				j--;
			}
		}
	}
	return -1;
}

long long int acha_maior (int p, int q) {
	long long int i, pot = pow (2, q), conversao, j;
	
	string numero (p, '2');
	
	for (i = 0; i < pow (2, p-1); i++) {
		conversao = stoll (numero);
		if (conversao % pot == 0) {
			return conversao;
		}
		
		j = p - 2;
		while (j >= 0) {
			if (numero[j] == '2') {
				numero[j] = '1';
				j = -1;
			} else {
				numero[j] = '2';
				j--;
			}
		}
	}
	return -1;
}
				

int main () {
	int num_casos, p, q, caso = 1;
	
	long long int first, last;
	
	cin >> num_casos;
	
	while (num_casos != 0) {
	
		cin >> p;
		cin >> q;
		
		cout << "Case " << caso << ": ";
		caso++;
		
		first = acha_menor (p, q);
		
		if (first == -1) {
			cout << "impossible\n";
		} else {
			last = acha_maior (p, q);
			if (last == first) {
				cout << first << "\n";
			} else {
				cout << first << " " << last << "\n";
			}
		}
		num_casos--;
	}
	
	return 0;
}
