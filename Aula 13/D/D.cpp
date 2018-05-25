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

    lli n, num_cores, tam, i, total, get_red, get_blue, caso = 1;
    char cor;

    cin >> n;

    while (n > 0) {
        total = 0;
        vetor blue;
        vetor red;

        cin >> num_cores;
        for (i = 0; i < num_cores; i++) {
            scanf ("%lld%c", &tam, &cor);
            if (cor == 'B')
                blue.push_back(tam);
            else
                red.push_back(tam);
        }

        sort (blue.begin(), blue.end());
        sort (red.begin(), red.end());

        get_blue = blue.size() - 1;
        get_red = red.size () - 1;
        while (get_red >= 0 && get_blue >= 0) {
            total += blue[get_blue] + red[get_red] - 2;
            get_blue--;
            get_red--;
        }
        cout << "Case #" << caso << ": " << total << endl;
        caso++;
        n--;
    }

    return 0;
}
