#include <stdio.h>
#include <stdlib.h>

//Funcoes do MergeSort obtidas em https://www.geeksforgeeks.org/merge-sort/
void merge(long int arr[], int l, int m, int r) {

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
    
        if (L[i] <= R[j]) {
        
            arr[k] = L[i];
            i++;
        } else {
        
            arr[k] = R[j];
            j++;
        }
        
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], int l, int r) {

    if (l < r) {
    
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

//Funcao binarysearch obtidas em https://www.geeksforgeeks.org/binary-search/

long int binarySearch(long int arr[], int l, int r, long int x) {

   if (r >= l) {
        int mid = l + (r - l)/2;
        
        if (arr[mid] == x)  
            return mid;
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 
        return binarySearch(arr, mid+1, r, x);
   }
 
   return -1;
}

long int count_repeticoes (long int arr[], int ini, int fim, long int val, long int pos) {
	
	int i = pos - 1;
	long int count = 1;
	
	while (i >= ini && arr[pos] == arr[i]) {
		i--;
		count++;
	}
	i = pos + 1;
	while (i <= fim && arr[pos] == arr[i]) {
		i++;
		count++;
	}
	
	return count;
}

int main () {
    long int **matriz, *AeB, *CeD, count = 0, resp;
    int numero_linhas, i, j, k;
    
    scanf("%d", &numero_linhas);
    
    matriz = malloc(numero_linhas * sizeof(long int *));
    for (i = 0; i < numero_linhas; i++)
        matriz[i] = malloc(4 * sizeof(long int));
        
    AeB = malloc (numero_linhas * numero_linhas * sizeof (long int));
    CeD = malloc (numero_linhas * numero_linhas * sizeof (long int));
    
    for (i = 0; i < numero_linhas; i++) {
        scanf("%ld %ld %ld %ld", &matriz[i][0], &matriz[i][1], &matriz[i][2], &matriz[i][3]);
    }
    
    for (i = 0, k = 0; i < numero_linhas; i++) {
        for (j = 0; j < numero_linhas; j++) {
        	AeB[k] = matriz[i][0] + matriz[j][1];
        	k++;
        }
    }
    
    for (i = 0, k = 0; i < numero_linhas; i++) {
        for (j = 0; j < numero_linhas; j++) {
        	CeD[k] = matriz[i][2] + matriz[j][3];
        	k++;
        }
    }
    
    mergeSort (CeD, 0, k-1);
    
    for (i = 0; i < k; i++) {
    	resp = binarySearch (CeD, 0, k-1, (-AeB[i]));
    	
    	if (resp != -1) {
    		j = count_repeticoes (CeD, 0, k-1, (-AeB[i]), resp);
    		count += j;
    	}
    }
        	 
    printf("%ld\n", count);
    
    return 0;
    
}