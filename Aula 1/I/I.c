#include <stdio.h>
#include <stdlib.h>

typedef struct Fila {
	int prioridade;
	char impressao_desejada;
	struct Fila *next;
} fila;

int main () {
    int numero_casos, numero_impressoes, posicao_impressao, i, count_impressoes, flag;
    fila *cabeca, *aux, *imprimir;
    cabeca = malloc (sizeof (fila));
    cabeca->prioridade = -1;
    cabeca->next = NULL;
    
    scanf("%d", &numero_casos);
    while (numero_casos != 0) {
        scanf("%d %d", &numero_impressoes, &posicao_impressao);
        for (i = 0; i < numero_impressoes; i++) {
            fila *no;
            no = malloc (sizeof(fila));
            scanf("%d", &no->prioridade);
            if (posicao_impressao == 0) {
                    no->impressao_desejada = 'T';
            } else {
                    no->impressao_desejada = 'F';
            }
            posicao_impressao--;
            no->next = NULL;
            
            aux = cabeca;
            while (aux->next != NULL) {
                    aux = aux->next;
            }
            aux->next = no;
        }
        
        count_impressoes = 0;
        flag = 1;
        while (flag) {
            aux = cabeca->next;
            imprimir = cabeca->next;
            while (aux != NULL) {
                    if (imprimir->prioridade < aux->prioridade) {
                        imprimir = aux;
                    }
                    aux = aux->next;
            }
            
            aux = cabeca->next;
            while (aux->prioridade != imprimir->prioridade) {
                fila *fim, *aux2;
                fim = aux;
                while (fim->next != NULL) {
                    fim = fim->next;
                }
                fim->next = aux;
                aux2 = aux;
                aux = aux->next;
                aux2->next = NULL;
                cabeca->next = aux;
            }
            cabeca->next = aux->next;
            count_impressoes++;
            if (aux->impressao_desejada == 'T') {
                printf("%d\n", count_impressoes);
                flag = 0;
            }
            free(aux);
        }
        
        aux = cabeca->next;
        while (aux != NULL) {
            fila *aux2;
            aux2 = aux;
            aux = aux->next;
            free (aux2);
        }
        cabeca->next = NULL;
        numero_casos--;
    }
    return 0;
}