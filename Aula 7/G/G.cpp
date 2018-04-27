#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

using namespace std;

long long int acha_sub ( string decode, long long int inicio, long long int fim, vector <vector <long long int> > &numero_substrings) {
	long long int aux_int;
	string aux;
	
	if (inicio > fim) {
		return 1;
	}
	
	if (numero_substrings[inicio][fim] != 0) {
		return numero_substrings[inicio][fim];
	}
	
	if (inicio == fim) {
		numero_substrings[inicio][fim] = 1;
		return 1;
	}
	
	aux[0] = decode[inicio];
	aux[1] = decode[inicio + 1];

	if (stoll(aux) <= 26 && aux[1] == '0' ) {
		numero_substrings[inicio][fim] = acha_sub (decode, inicio + 2, fim, numero_substrings);
	} else  {
		if (inicio + 2 <= fim) {
			if (stoll(aux) <= 26 && decode[inicio+2] != '0') {
				numero_substrings[inicio][fim] = acha_sub (decode, inicio + 1, fim, numero_substrings) + acha_sub (decode, inicio + 2, fim, numero_substrings);
			}
		}	
		} if (stoll(aux) >= 27) {	
			numero_substrings[inicio][fim] = acha_sub (decode, inicio + 1, fim, numero_substrings);
		}
	
	return numero_substrings[inicio][fim];
}	

int main () {

	long long int i, aux;

	string decode;
	
	getline(cin, decode);
	aux = stoll(decode);
	
	while (aux != 0) {
		vector <vector <long long int> > numero_substrings;
		for (i = 0; i < decode.size(); i++) {
			vector< long long int> aux (decode.size(), 0);
			numero_substrings.push_back (aux);
		}
		cout << acha_sub (decode, 0, decode.size() -1,  numero_substrings) << "\n";
		getline(cin, decode);
		aux = stoll(decode);
	}
	
	return 0;
}

