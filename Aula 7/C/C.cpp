#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

bool e_primo (int i, vector <int> &primos) {
	int j;
	for (j = 0; j < 12; j++) {
		if (primos[j] == i)
			return true;
	}
	return false;
}

bool atual_vazio (vector <int> &atual, int n) {
	int i;
	for (i = 0; i < n; i++)
		if (atual[i] != 0)
			return false;
	return true;
}

void solve_it (vector<int> &atual, int n, vector <int> &primos, vector <int> &sol) {
	
	if (atual_vazio(atual, n)) {
		if (e_primo (sol[n-1] + 1, primos)) {
			for (int i = 0; i < n-1; i++) {
				cout << sol[i] << " ";
			}
			cout << sol[n-1] << "\n";
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (atual[i] != 0) {
				if (e_primo(sol.back() + atual[i], primos)) {
					sol.push_back(atual[i]);
					atual[i] = 0;
					solve_it (atual, n, primos, sol);
					atual[i] = i+1;
					sol.pop_back();
				}
			}
		}
	}
}
		

int main () {
	int n, i, caso = 1;
	
	// 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31
	vector <int> primos (12);
	primos[0] = 1;
	primos[1] = 2;
	primos[2] = 3;
	primos[3] = 5;
	primos[4] = 7;
	primos[5] = 11;
	primos[6] = 13;
	primos[7] = 17;
	primos[8] = 19;
	primos[9] = 23;
	primos[10] = 29;
	primos[11] = 31;
	
	vector <int> sol;
	sol.push_back(1);
	
	cin >> n;
	while (!cin.eof()) {
		vector <int> atual(n);
	
		atual[0] = 0;
		for (i = 1; i < n; i++) {
			atual[i] = i+1;
		}
	
		cout << "Case " << caso << ":\n";
		caso++;
		solve_it (atual, n, primos, sol);
		cin >> n;
		if (!cin.eof())
			cout << "\n";
	}
	return 0;
	
}
