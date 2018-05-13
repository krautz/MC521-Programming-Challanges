#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <queue>

using namespace std;

typedef long long int lli;
typedef vector <lli> vetor;
typedef vector <vector <lli> > matriz;

struct posto {
    lli distancia;
    lli gasolina_disp;
};

bool posto_compare (posto a, posto b) {
    return a.distancia < b.distancia;
}

bool posto_compare_gas (posto a, posto b) {
    return a.gasolina_disp < b.gasolina_disp;
}



int main () {
    lli test_cases, numero_postos, distancia_cidade, gasolina_caminhao, i, flag, pos_caminhao, paradas;

    cin >> test_cases;

    while (test_cases > 0) {
        pos_caminhao = 0;
        paradas = 0;

        cin >> numero_postos;
        vector <posto> postos (numero_postos);
        vector <posto> postos_heap;
        make_heap (postos_heap.begin(), postos_heap.end(), posto_compare_gas);

        for (i = 0; i < numero_postos; i++) {
            cin >> postos[i].distancia >> postos[i].gasolina_disp;
        }

        cin >> distancia_cidade >> gasolina_caminhao;

        for (i = 0; i < numero_postos; i++) {
            postos[i].distancia = distancia_cidade - postos[i].distancia;
        }
        sort (postos.begin(), postos.end(), posto_compare);

        /*for (i = 0; i < numero_postos; i++) {
            cout << postos[i].distancia << " " << postos[i].gasolina_disp << endl;
        }*/

        flag = 1;
        i = 0;
        while (flag == 1) {
            while (i < numero_postos && postos[i].distancia <= (gasolina_caminhao + pos_caminhao)) {
                posto aux;
                aux = postos[i];
                postos_heap.push_back(aux);
                push_heap (postos_heap.begin(), postos_heap.end(), posto_compare_gas);
                i++;
            }

            /*cout << "pos_caminhao: " << pos_caminhao << " gas_caminhao: " << gasolina_caminhao << endl << "heap" << endl;

            for (lli j = 0; j < postos_heap.size(); j++) {
                cout << postos_heap[j].distancia << " " << postos_heap[j].gasolina_disp << endl;
            }
            cout << endl << endl;*/

            if (pos_caminhao + gasolina_caminhao >= distancia_cidade) {
                flag = 0;
            } else if (postos_heap.size() > 0) {
                paradas++;
                if (pos_caminhao < postos_heap.front().distancia) {
                    gasolina_caminhao = gasolina_caminhao - (postos_heap.front().distancia - pos_caminhao) + postos_heap.front().gasolina_disp;
                    pos_caminhao = postos_heap.front().distancia;
                } else {
                    gasolina_caminhao += postos_heap.front().gasolina_disp;
                }
                pop_heap (postos_heap.begin(), postos_heap.end(), posto_compare_gas);
                postos_heap.pop_back();
            } else {
                flag = -1;
            }

        }
        if (flag == 0) {
            cout << paradas << endl;
        } else if (flag == -1) {
            cout << "-1" << endl;
        }
        test_cases--;

    }

    return 0;
}
