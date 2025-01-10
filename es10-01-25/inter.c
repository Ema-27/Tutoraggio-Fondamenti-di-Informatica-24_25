/*
Si scriva una programma che legge 2  vettori, e costruisce un terzo vettore, che è composto interponendo gli elementi dei primi due
    (i due vettori hanno uguale dimensione).
    v1 = 1 3 5 7
    v2 = 2 4 6 8
    v3 = 1 2 3 4 5 6 7 8

*/

#include <stdio.h>

void intercalare(int v1[], int v2[], int n, int v3[]){

    for(int i = 0; i<n; i++){
        v3[2*i] = v1[i];
        v3[2*i+1] = v2[i];
    }
}

//i=1
// v3[1, 2, 3,4]

int main(){
    int v1[]={1,3,5,7};
    int v2[]={2,4,6,8};

    int n = sizeof(v1)/sizeof(v1[0]);

    int v3[2*n];

    intercalare(v1, v2, n, v3);

    printf("Vettore risultato: ");
    for(int i=0; i<2*n; i++){
        printf("%d ", v3[i]);
    }
    printf("\n");
    return 0;
}