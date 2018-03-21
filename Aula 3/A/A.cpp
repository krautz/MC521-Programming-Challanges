#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main () {
	char frase [5000], letra, check;
	long long int i, flag;

	cin.getline (frase, 5000);
	
	while (strcmp (frase, "*") != 0) {
		letra = frase[0];
		if (letra >= 97 && letra <= 122) {
			letra = letra - 32;
		}
		for (i = 1, flag = 1; i < strlen(frase) && flag; i++) {
			while (frase[i] != ' ') {
				i++;
			}
			i++;
			if (i < strlen(frase)) {
				check = frase[i];
				if (check >= 97 && check <= 122) {
					check = check - 32;
				}
				if (check != letra) {
					flag = 0;
				}
			}
		}
		
		if (flag == 1) {
			cout << "Y\n";
		} else {
			cout << "N\n";
		}

		cin.getline (frase, 5000);
	}	
	return 0;
}		
