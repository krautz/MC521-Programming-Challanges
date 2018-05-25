#include <stdio.h>
#include <string.h>
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

int main () {
    lli n, i, j, caso = 1;
    char antigo, marotario, texto[2];

    cin >> n;
    int a = scanf("%c", &marotario);
    while (n > 0) {
        string texto, saida;
        scanf("%c", &texto[0]);
        antigo = '1';
        i = 0;
        while (texto[0] != '\n'){
            if (texto[i] == 'a') {
                if (antigo == '2')
                    saida.push_back(' ');
                antigo = '2';
                saida.push_back('2');
            } else if (texto[i] == 'b') {
                if (antigo == '2')
                    saida.push_back(' ');
                antigo = '2';
                saida.push_back('2');
                saida.push_back('2');
            } else if (texto[i] == 'c') {
                if (antigo == '2')
                    saida.push_back(' ');
                antigo = '2';
                saida.push_back('2');
                saida.push_back('2');
                saida.push_back('2');
            } else if (texto[i] == 'd') {
                if (antigo == '3')
                    saida.push_back(' ');
                antigo = '3';
                saida.push_back('3');
            } else if (texto[i] == 'e') {
                if (antigo == '3')
                    saida.push_back(' ');
                antigo = '3';
                saida.push_back('3');
                saida.push_back('3');
            } else if (texto[i] == 'f') {
                if (antigo == '3')
                    saida.push_back(' ');
                antigo = '3';
                saida.push_back('3');
                saida.push_back('3');
                saida.push_back('3');
            } else if (texto[i] == 'g') {
                if (antigo == '4')
                    saida.push_back(' ');
                antigo = '4';
                saida.push_back('4');
            } else if (texto[i] == 'h') {
                if (antigo == '4')
                    saida.push_back(' ');
                antigo = '4';
                saida.push_back('4');
                saida.push_back('4');
            } else if (texto[i] == 'i') {
                if (antigo == '4')
                    saida.push_back(' ');
                antigo = '4';
                saida.push_back('4');
                saida.push_back('4');
                saida.push_back('4');
            } else if (texto[i] == 'j') {
                if (antigo == '5')
                    saida.push_back(' ');
                antigo = '5';
                saida.push_back('5');
            } else if (texto[i] == 'k') {
                if (antigo == '5')
                    saida.push_back(' ');
                antigo = '5';
                saida.push_back('5');
                saida.push_back('5');
            } else if (texto[i] == 'l') {
                if (antigo == '5')
                    saida.push_back(' ');
                antigo = '5';
                saida.push_back('5');
                saida.push_back('5');
                saida.push_back('5');
            } else if (texto[i] == 'm') {
                if (antigo == '6')
                    saida.push_back(' ');
                antigo = '6';
                saida.push_back('6');
            } else if (texto[i] == 'n') {
                if (antigo == '6')
                    saida.push_back(' ');
                antigo = '6';
                saida.push_back('6');
                saida.push_back('6');
            } else if (texto[i] == 'o') {
                if (antigo == '6')
                    saida.push_back(' ');
                antigo = '6';
                saida.push_back('6');
                saida.push_back('6');
                saida.push_back('6');
            } else if (texto[i] == 'p') {
                if (antigo == '7')
                    saida.push_back(' ');
                antigo = '7';
                saida.push_back('7');
            } else if (texto[i] == 'q') {
                if (antigo == '7')
                    saida.push_back(' ');
                antigo = '7';
                saida.push_back('7');
                saida.push_back('7');
            } else if (texto[i] == 'r') {
                if (antigo == '7')
                    saida.push_back(' ');
                antigo = '7';
                saida.push_back('7');
                saida.push_back('7');
                saida.push_back('7');
            } else if (texto[i] == 's') {
                if (antigo == '7')
                    saida.push_back(' ');
                antigo = '7';
                saida.push_back('7');
                saida.push_back('7');
                saida.push_back('7');
                saida.push_back('7');
            } else if (texto[i] == 't') {
                if (antigo == '8')
                    saida.push_back(' ');
                antigo = '8';
                saida.push_back('8');
            } else if (texto[i] == 'u') {
                if (antigo == '8')
                    saida.push_back(' ');
                antigo = '8';
                saida.push_back('8');
                saida.push_back('8');
            } else if (texto[i] == 'v') {
                if (antigo == '8')
                    saida.push_back(' ');
                antigo = '8';
                saida.push_back('8');
                saida.push_back('8');
                saida.push_back('8');
            } else if (texto[i] == 'w') {
                if (antigo == '9')
                    saida.push_back(' ');
                antigo = '9';
                saida.push_back('9');
            } else if (texto[i] == 'x') {
                if (antigo == '9')
                    saida.push_back(' ');
                antigo = '9';
                saida.push_back('9');
                saida.push_back('9');
            } else if (texto[i] == 'y') {
                if (antigo == '9')
                    saida.push_back(' ');
                antigo = '9';
                saida.push_back('9');
                saida.push_back('9');
                saida.push_back('9');
            } else if (texto[i] == 'z') {
                if (antigo == '9')
                    saida.push_back(' ');
                antigo = '9';
                saida.push_back('9');
                saida.push_back('9');
                saida.push_back('9');
                saida.push_back('9');
            } else if (texto[i] == ' ') {
                if (antigo == '0')
                    saida.push_back(' ');
                antigo = '0';
                saida.push_back('0');
            }
            scanf("%c", &texto[0]);
        }
        cout << "Case #" << caso << ": " << saida << endl;
        caso++;
        n--;
    }
    cout << endl;
    return 0;
}
