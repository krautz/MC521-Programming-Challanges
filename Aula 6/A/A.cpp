#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <deque>
#include <string>

int main () {
	int end = 1;
	char c;
	
	
	while (end) {
		int indice_palavra = 0;
		string palavra
		do {
			scanf("%c", &c);
			if (c >= 97 && c <= 122) {
				palavra[indice_palavra] = c;
				indice_palavra++;
			} else if (c >= 65 && c <= 90) {
				c += 32;
				indice_palavra++;
				palavra[indice_palavra] = c;
			}
		} while (c >= 97 && c <= 122);
		
		while !(c >= 97 && c <= 122) {
			scanf("%c", &c);
		}
	return 0;
}
