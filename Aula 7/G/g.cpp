#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

int main () {
	long long int i, num, I;

	string decode, aux;
	
	getline(cin, decode);
	num = stoll(decode);
	
	while (num != 0) {
		vector <long long int> numero_substrings (1000000, 0);
		if (decode.size() == 1) {
			numero_substrings[0] = 1;
		} else {
			aux[0] = decode[0];
			aux[1] = decode[1];
			if (stoll(aux) <= 26 && aux[1] != '0') {
				numero_substrings[0] = 1;
				numero_substrings[1] = 2;
			} else {
				numero_substrings[0] = 1;
				numero_substrings[1] = 1;
			}
			if (aux[1] == '0') {
				I = 2;
				numero_substrings[2] = 1;
			} else {
				I = 1;
			}
			for (i = I; i < decode.size() - 1; i++) {
				string aux;
				aux[0] = decode[i];
				aux[1] = decode[i+1];
				/*cout << aux[0] << aux[1] << endl;
				cout << "pos atual: " << i << endl;*/
				if (aux[0] == '0') {
					numero_substrings[i+1] = numero_substrings[i];
				} else if (stoll(aux) <= 26 && aux[1] != '0') {
					numero_substrings[i+1] = numero_substrings[i] + numero_substrings[i-1];
				} else if (aux[1] == '0') {
					numero_substrings[i+1] = numero_substrings[i-1];
					numero_substrings[i+2] = numero_substrings[i+1];
				} else {
					numero_substrings[i+1] = numero_substrings[i];
				}
				if (aux[1] == '0')
					i++;
			}
			/*
			for (i = 0; i < decode.size(); i++) {
				cout << numero_substrings[i] << " ";
			}
			cout << endl;*/
		}
		cout << numero_substrings[decode.size() -1] << "\n";
		getline(cin, decode);
		num = stoll(decode);
	}
	
	return 0;
}

