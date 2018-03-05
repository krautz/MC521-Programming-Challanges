#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	char **matriz;
	int  linhas, colunas, i, j, k = 0, n_campos, count, flag, isF;
	scanf("%d", &n_campos);
	while (k != n_campos) {
	
		scanf("%d", &linhas);
		scanf("%d", &colunas);
		scanf(" ");
		
		matriz = malloc(linhas * sizeof(char *));
		for (i = 0; i < linhas; i++)
			matriz[i] = malloc(colunas * sizeof(char));
			
		for (i = 0; i < linhas; i++) {
			for (j = 0; j < colunas; j++) {
				scanf("%c", &matriz[i][j]);
			}
			if (i != linhas - 1)
				scanf(" ");	
		}
		
		for (i = 0, flag = 1; i < linhas && flag; i++) {
			for (j = 0; j < colunas && flag; j++) {
				if (matriz[i][j] != 'F') {
					count = 0;
					if (i > 0 && j > 0 && matriz[i - 1][j - 1] == 'F') {
						count++;
					}
					if (i > 0 && matriz[i - 1][j] == 'F') {
						count++;
					}
					if (i > 0 && j < colunas - 1 && matriz[i - 1][j + 1] == 'F') {
						count++;
					}
					if (j < colunas - 1 && matriz[i][j + 1] == 'F') {
						count++;
					}
					if (i < linhas - 1 && j < colunas - 1 && matriz[i + 1][j + 1] == 'F') {
						count++;
					}
					if (i < linhas - 1 && matriz[i + 1][j] == 'F') {
						count++;
					}
					if (i < linhas - 1 && j > 0 && matriz[i + 1][j - 1] == 'F') {
						count++;
					}
					if (j > 0 && matriz[i][j - 1] == 'F') {
						count++;
					}
					if (count != matriz[i][j] - 48) {
						printf("Please sweep the mine again!\n");
						flag = 0;
					}

				} else {
                                        isF = 1;
                                        if (i > 0 && j > 0 && matriz[i - 1][j - 1] != 'F') {
						isF = 0;
					}
					if (i > 0 && matriz[i - 1][j] != 'F') {
						isF = 0;
					}
					if (i > 0 && j < colunas - 1 && matriz[i - 1][j + 1] != 'F') {
						isF = 0;
					}
					if (j < colunas - 1 && matriz[i][j + 1] != 'F') {
						isF = 0;
					}
					if (i < linhas - 1 && j < colunas - 1 && matriz[i + 1][j + 1] != 'F') {
						isF = 0;
					}
					if (i < linhas - 1 && matriz[i + 1][j] != 'F') {
						isF = 0;
					}
					if (i < linhas - 1 && j > 0 && matriz[i + 1][j - 1] != 'F') {
						isF = 0;
					}
					if (j > 0 && matriz[i][j - 1] != 'F') {
						isF = 0;
					}
					if (isF) {
						printf("Please sweep the mine again!\n");
						flag = 0;
					}
                                }
			}
		}
		if (flag)
			printf("Well done Clark!\n");
			
		
		for (i = 0; i < linhas; i++)
			free(matriz[i]);
		free(matriz);
		k++;
	}
	return 0;
}
