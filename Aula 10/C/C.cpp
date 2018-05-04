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
	lli test_cases, n, maior, i , j, flag, success;
	
	cin >> test_cases;
	
	while(test_cases > 0) {
		cin >> n;
		vetor qtd (n);
		vetor menor_qtd (n);
		vetor qtd_final (n);
		maior = 0;
		for (i = 0; i < n; i++) {
			cin >> qtd[i];
			if (qtd[i] > maior)
				maior = qtd[i];
		}
		
		for (i = 1, success = 0; i <= maior; i++) {
			for (j = 0, flag = 1; j < n && flag; j++) {
				if (qtd[j] % i == 0) {
					menor_qtd[j] = qtd[j] / i;
				} else {
					flag = 0;
				}
			}
			if (flag == 1) {
				success = 1;
				for (j = 0; j < n; j++) {
					qtd_final[j] = menor_qtd[j];
				}
			}
		}
		
		for (j = 0; j < n - 1; j++)
			cout << qtd_final[j] << " ";
		cout << qtd_final[n-1] << endl;		
		
		test_cases--;
	}
	
	return 0;
}
