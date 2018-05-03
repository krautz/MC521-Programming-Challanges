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
	lli N, M, i;
	
	cin >> N >> M;
	vetor alturas (N);
	matriz caminhos;
	for (i = 0; i < N; i++) {
		caminhos.pushback (vetor aux (N, -1));
	}
	cin >> alturas[0];
	for (i = 1; i < N; i++) {
		cin >> alturas[i];
		if (alturas[i] > alturas[i-1])
			caminhos[i-1][i] = 1;
		else
			caminhos[i-1][i] = 0;
	
	
	return 0;
}
