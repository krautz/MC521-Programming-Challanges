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
	lli n, m, i, j, sum, k, l;
	
	cin >> n >> m;
	
	while (!cin.eof()) {
		matriz img;
		for (i = 0; i < n; i++) {
			vetor aux (n);
			for (j = 0; j < n; j++) {
				cin >> aux[j];
			}
			img.push_back(aux);
		}
		
		matriz blur;
		for (i = 0; i < n - m + 1; i++) {
			vetor aux (n - m + 1);
			blur.push_back(aux);
		}
		
		for (i = 0; i < n - m + 1; i++) {
			for (j = 0; j < n - m + 1; j++) {
				sum = 0;
				for (l = i; l < i + m; l++) {
					for (k = j; k < j + m; k++) {
						sum +=img[l][k];
					}
				}
				blur[i][j] = sum;
			}
		}
		sum = 0;
		for (i = 0; i < n - m + 1; i++) {
			for (j = 0; j < n - m + 1; j++) {
				cout << blur[i][j] << endl;
				sum += blur[i][j];
				
			}
		}
		cout << sum << endl;
		
		cin >> n >> m;
		if (!cin.eof())
			cout << endl;
	}
	
	return 0;
}
					
			
			
