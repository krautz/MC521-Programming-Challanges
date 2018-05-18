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

int _lis(vetor arr, lli n, lli *max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;

    // 'max_ending_here' is length of LIS ending with arr[n-1]
    lli res, max_ending_here = 1;

    /* Recursively get all LIS ending with arr[0], arr[1] ...
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and
       max ending with arr[n-1] needs to be updated, then
       update it */
    for (lli i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    // Compare max_ending_here with the overall max. And
    // update the overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;

    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}

// The wrapper function for _lis()
lli lis(vetor &arr , lii n)
{
    // The max variable holds the result
    lli max = 1;

    // The function _lis() stores its result in max
    _lis( arr, n, &max );

    // returns max
    return max;
}

int main () {

    lli n, max, ini, max_local, i , j, maior, inicio, fim, inicio_seq, inicio_local;
    string numero;

    cin >> n;

    scanf (" ");

    while (n > 0) {
        vetor numeros;
        getline(cin, numero);
        while (!numero.empty()) {
            numeros.push_back (stoll(numero));
            getline(cin,numero);
        }

        for (i = 0; i < numeros.size(); i++)
            cout << numeros[i] << " ";
        cout << endl;



        /*
        for (lli i = 0; i < numeros.size(); i++)
            cout << numeros[i] << " ";
        cout << endl;
        */
        n--;
    }

    return 0;
}
