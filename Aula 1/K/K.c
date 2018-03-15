/* not correct, it only works for simple polygons*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto {
    double x;
    double y;
} ponto;

typedef struct Saida {
    int esq;
    int dir;
    int sup;
    int inf;
} saida;

int main () {
    int numero_pontos, i;
    ponto *poligono, p;
    saida resultado;

    scanf("%d", &numero_pontos);

    while (numero_pontos != 0) {

        resultado.esq = 0;
        resultado.dir = 0;
        resultado.sup = 0;
        resultado.inf = 0;

        poligono = malloc (numero_pontos * sizeof (ponto));

        for (i = 0; i < numero_pontos; i++) {
            scanf("%lf %lf", &poligono[i].x, &poligono[i].y);
        }
        
        scanf("%lf %lf", &p.x, &p.y);

        for (i = 0; i < numero_pontos - 1; i++) {
            if (poligono[i].x == poligono[i + 1].x) {
                if ((poligono[i].y < p.y && poligono[i + 1].y > p.y) || (poligono[i].y > p.y && poligono[i + 1].y < p.y)) {
                    if (poligono[i].x > p.x) {
                        resultado.dir = 1;
                    } else {
                        resultado.esq = 1;
                    }
                }
            } else if (poligono[i].y == poligono[i + 1].y) {
                if ((poligono[i].x < p.x && poligono[i + 1].x > p.x) || (poligono[i].x > p.x && poligono[i + 1].x < p.x)) {
                    if (poligono[i].y > p.y) {
                        resultado.sup = 1;
                    } else {
                        resultado.inf = 1;
                    }
                }
            }
        }
        
        if (poligono[0].x == poligono[numero_pontos - 1].x) {
            if ((poligono[0].y < p.y && poligono[numero_pontos - 1].y > p.y) || (poligono[0].y > p.y && poligono[numero_pontos - 1].y < p.y)) {
                if (poligono[0].x > p.x) {
                    resultado.dir = 1;
                } else {
                    resultado.esq = 1;
                }
            }
        } else if (poligono[0].y == poligono[numero_pontos - 1].y) {
            if ((poligono[0].x < p.x && poligono[numero_pontos - 1].x > p.x) || (poligono[0].x > p.x && poligono[numero_pontos - 1].x < p.x)) {
                if (poligono[0].y > p.y) {
                    resultado.sup = 1;
                } else {
                    resultado.inf = 1;
                }
            }
        }

        if (resultado.esq && resultado.dir && resultado.sup && resultado.inf) {
            printf("T\n");
        } else {
            printf("F\n");
        }
        
        free (poligono);
        scanf("%d", &numero_pontos);
    }
    
    return 0;
}
