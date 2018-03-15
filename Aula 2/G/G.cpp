#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main () {
	int numero_casos, i, j, k, l, caso = 1, tam, pos, impar, flag;
	long int qtd = 0, abc[27];
	char palavra[1002], subpalavra[1002];
	
	cin >> numero_casos;
	
	while (numero_casos != 0) {
		cin >> palavra;
		qtd = 0;
		for (i = 0; i < strlen(palavra); i++) {
			for (k = 0; k < 27; k++) {
				abc[k] = 0;
			}
			for (j = i; j < strlen(palavra); j++) {
				abc[palavra[j] - 97]++;
				for (k = 0, impar = 0, flag = 1; k < 27 && flag; k++) {
					if (abc[k] % 2 == 1) {
						if (impar == 0) {
							impar = 1;
						} else {
							flag = 0;
						}
					}
				}
				if (flag) {
					qtd++;
				}	
			}
		}
		
		cout << "Case " << caso << ": " << qtd << "\n";
		caso++;
		numero_casos--;
	}
	
	return 0;
}
