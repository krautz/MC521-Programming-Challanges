#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>

using namespace std;

int main () {
    int N;
    long int custo, inserir;
    
    cin >> N;
    
    while(N != 0) {
        deque<long int> valores(N);
        custo = 0;
        for (int i = 0; i < N ; i++) {
            cin >> valores[i];
        }
        while (N != 1) {
            sort (valores.begin(), valores.end());
            inserir = valores[0] + valores[1];
            custo += inserir;
            valores.pop_front();
            valores.pop_front();
            valores.push_front(inserir);
            N--;
        }
        cout << custo << "\n";
        cin >> N;
    }
    
    return 0;
}
