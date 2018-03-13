#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

typedef struct Qtd {
	long int qtd_a;
	long int qtd_b;
} qtd;

typedef struct fatorizacao {
	long int fator;
	long int qtd_vezes;
    
    bool operator< (struct fatorizacao &b) const{
        if (this->fator > b.fator) {
            return false;
        } else {
            return true;
        }
    }
    
} fat;

int primo (long int p) {
    for (int i = 2; i <= sqrt(p); i++) {
        if (p%i == 0)
            return 0;
    }
    return 1;
}

int main () {
	int num_testes, a, b, n, A, B, j, flag, i;
    long int qtd_fatores = 0, num;
    fat inserir;
	
	cin >> num_testes;
	
	while (num_testes != 0) {
		cin >> n;
		cin >> a;
		cin >> b;
		vector<qtd> quantidade_primos(n+1);
		vector<fat> fatores;
		quantidade_primos[0].qtd_a = 1;
		quantidade_primos[0].qtd_b = 0;
		quantidade_primos[1].qtd_a = 0;
		quantidade_primos[1].qtd_b = 1;
		for (i = 2; i <= n; i++) {
			quantidade_primos[i].qtd_a = quantidade_primos[i-1].qtd_a + quantidade_primos[i-2].qtd_a;
			quantidade_primos[i].qtd_b = quantidade_primos[i-1].qtd_b + quantidade_primos[i-2].qtd_b;
		}
		
		A = a;
		for (i = 2; i <= A/2 && a > 1; i++) {
            if (primo(i)) {
                num = 0;
                while (a%i == 0) {
                    a = a/i;
                    num++;
                }
            
                if (num > 0) {
                    inserir.fator = i;
                    inserir.qtd_vezes = num * quantidade_primos[n].qtd_a;
                    fatores.push_back (inserir);
                }
            }
        }
        if (A == a) {
            inserir.fator = a;
            inserir.qtd_vezes = quantidade_primos[n].qtd_a;
            fatores.push_back (inserir);
        }
        
        B = b;
		for (i = 2; i <= B/2 && b > 1; i++) {
            if (primo(i)) {
                num = 0;
                while (b%i == 0) {
                    b = b/i;
                    num++;
                }
            
                if (num > 0) {
                    for (j = 0, flag = 1; j < fatores.size() && flag; j++) {
                        if (fatores[j].fator == i) {
                            fatores[j].qtd_vezes += num * quantidade_primos[n].qtd_b;
                            flag = 0;
                        }
                    }
                    if (flag) {    
                        inserir.fator = i;
                        inserir.qtd_vezes = num * quantidade_primos[n].qtd_b;
                        fatores.push_back (inserir);
                    }
                }
            }
        }
        if (B == b) {
            for (j = 0, flag = 1; j < fatores.size() && flag; j++) {
                if (fatores[j].fator == b) {
                    fatores[j].qtd_vezes += quantidade_primos[n].qtd_b;
                    flag = 0;
                }
            }
            if (flag) {    
                inserir.fator = b;
                inserir.qtd_vezes = quantidade_primos[n].qtd_b;
                fatores.push_back (inserir);
            }
        }
            
        sort (fatores.begin(), fatores.end());
        
        for (i = 0 ; i < fatores.size(); i++) {
            cout << fatores[i].fator << " " << fatores[i].qtd_vezes << "\n";
        }
        cout << "\n";
		
		num_testes--;
    }
	
	
	return 0;
}
