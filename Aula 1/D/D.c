#include <stdio.h>
#include <math.h>

int main () {
	long int numero_selos, i;
	
	scanf("%ld", &numero_selos);
	
	for (i = 2; i < sqrt(numero_selos); i++) {
		if (numero_selos % i == 0) {
			printf("S\n");
			return 0;
		}
	}
	printf("N\n");
	return 0;

}
