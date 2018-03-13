#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

int main () {
	int n;
	long int total_price, day_price, n_times;
	
	cin >> n;
	
	while (n != -1) {
		total_price = 0;
		n_times = 0;
		for (int i = 0; i < n; i++) {
			cin >> day_price;
			total_price += day_price;
			if (total_price % 100 == 0) {
				total_price = 0;
				n_times++;
			}
		}
		cout << n_times << "\n";
		cin >> n;
	}
	return 0;
}
