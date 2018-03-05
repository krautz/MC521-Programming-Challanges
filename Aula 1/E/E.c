#include <stdio.h>
#include <stdlib.h>

int main () {
	int numero_retangulos;
	long int *retangulos, maior,i , k, menor_alt;
	
	scanf("%d", &numero_retangulos);
	
	while (numero_retangulos != 0) {
		retangulos = malloc (numero_retangulos * sizeof (long int));
		for (i = 0; i < numero_retangulos; i++) {
			scanf("%ld", &retangulos[i]);
		}
		maior = 0;
		for (i = 0; i < numero_retangulos; i++) {
			if (retangulos[i] > maior)
				maior = retangulos[i];
			k = i + 1;
			menor_alt = i;
			while (k < numero_retangulos && retangulos[k] > 0) {
				if (retangulos[menor_alt] <= retangulos [k]) {
					if (retangulos[menor_alt] * (k - i + 1) > maior)
						maior = retangulos[menor_alt] * (k - i + 1);
				}
				if (retangulos[menor_alt] > retangulos [k]) {
					menor_alt = k;
					if (retangulos[k] * (k - i + 1) > maior) {
						maior = retangulos[k] * (k - i + 1);
					}
				}
				k++;
			}
		}
		printf("%ld\n", maior);
		free (retangulos);
		scanf("%d", &numero_retangulos);
	}
	return 0;
}
