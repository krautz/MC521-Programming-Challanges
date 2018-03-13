#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>

using namespace std;

struct campo {
    long int valor;
    long int qtd;
    long int prim_pos;
    
    bool operator< (campo &b) const{
        if (this->qtd > b.qtd) {
            return true;
        } else if (this->qtd == b.qtd) {
            if (this->prim_pos < b.prim_pos) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};


int main () {
    int n, task, aux, flag, j;
    campo inserir;
    vector<campo> vetor;
    cin >> n;
    cin >> task;
    
    for (int i = 0; i < n; i++) {
        cin >> aux;
        for (flag = 1, j = 0; j < vetor.size() && flag; j++) {
                if (vetor[j].valor == aux) {
                    vetor[j].qtd++;
                    flag = 0;
                }
        }
        if (flag) {
            inserir.valor = aux;
            inserir.qtd = 1;
            inserir.prim_pos = i;
            vetor.push_back(inserir);
        }
    }
    
    sort (vetor.begin(), vetor.end());
    
    for(int i = 0; i < vetor.size(); i++) {
        for (int j = 0; j < vetor[i].qtd; j++) {
            cout << vetor[i].valor << " ";
        }
    }
    cout << "\n";
    
    
    return 0;
}
