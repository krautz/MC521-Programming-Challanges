#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main () {
	int num_casos, p, q, caso = 1, first, flag, num, j, prox;
	
	long long int i, pot, maior, primeiro, copia;
	
	cin >> num_casos;
	
	while (num_casos != 0) {
	
		cin >> p;
		cin >> q;
		
		cout << "Case " << caso << ": ";
		caso++;
		
		
		pot = pow (2, q);
		vector<int> bin (p, 0);
		bin[0] = 1;
		for (first = 1, i = 0; i < pow(2, p-1); i++) {
			
			num = 0;
			for (j = 0; j < bin.size(); j++) {
				if (bin[j] == 0) {
					num += 1*pow(10,j);
				} else if (bin[j] == 1) {
					num += 2*pow(10,j);
				}
			}

			j = 0;
			flag = 1;
			while (flag != 0) {
				if (j == bin.size() - 1) {
					prox = 0;
				} else {
					prox = j + 1;
				}
				if (bin[prox] == 1) {
					bin[prox] = 0;
					j++;
				} else {
					bin[prox] = 1;
					flag--;
				}
			}
	
			if (num % pot == 0) {
				if (first == 1) {
					cout << num;
					first = 0;
					primeiro = num;
				} 
				maior = num;
			}
		}
		
		if (first == 1) {
			cout << "impossible\n";
		} else if (maior != primeiro) {
			cout << " " << maior << "\n";
		} else  if (maior == primeiro) {
			cout << "\n";	
		}
		num_casos--;
	}
	
	return 0;
}
		
