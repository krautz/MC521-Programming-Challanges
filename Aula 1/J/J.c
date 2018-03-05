#include <stdio.h>
#include <stdlib.h>

int main () {
    long int **matriz, count = 0;
    int numero_linhas, i, j, k, m;
    
    scanf("%d", &numero_linhas);
    
    matriz = malloc(numero_linhas * sizeof(long int *));
    for (i = 0; i < numero_linhas; i++)
        matriz[i] = malloc(4 * sizeof(long int));
    
    for (i = 0; i < numero_linhas; i++) {
        scanf("%ld %ld %ld %ld", &matriz[i][0], &matriz[i][1], &matriz[i][2], &matriz[i][3]);
    }
    
    for (i = 0; i < numero_linhas; i++) {
        for (j = 0; j < numero_linhas; j++) {
            for (k = 0; k < numero_linhas; k++) {
                for (m = 0; m < numero_linhas; m++) {
                    if (matriz[i][0] + matriz[j][1] + matriz[k][2] + matriz[m][3] == 0) {
                            count++;
                    }
                }
            }
        }
    }
    
    printf("%ld\n", count);
    
    return 0;
    
}