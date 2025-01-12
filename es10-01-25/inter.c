/*
Si scriva una programma che legge 2  vettori, e costruisce un terzo vettore, che è composto interponendo gli elementi dei primi due
    (i due vettori hanno uguale dimensione).
    v1 = 1 3 5 7
    v2 = 2 4 6 8
    v3 = 1 2 3 4 5 6 7 8

*/

#include <stdio.h>

#define false 0
#define true 1

typedef int boolean;

void intercalare_v1(int v1[], int v2[], int n, int v3[]){

    for(int i = 0; i<n; i++){
        v3[2*i] = v1[i];
        v3[2*i+1] = v2[i];
    }
}

void intercalare_v2(int v1[], int v2[], int n, int v3[]){

    int j=0;
    for(int i = 0; i<2*n; i++){
        if(j==0){
            v3[i] = v1[i/2];
            j++;
        }else{
            v3[i] = v2[(i-1)/2];
            j=0;
        }
        
    }
}

void intercalare_v3 (int v1[], int v2[], int n, int v3[]){

    boolean el_v1=true;
    for(int i = 0; i<2*n; i++){
        if(el_v1){
            v3[i] = v1[i/2];
            el_v1=false;
        }else{
            v3[i] = v2[(i-1)/2];
            el_v1=true;
        }
        
    }
}

//i=1
// v3[1, 2, 3,4]

int main(){
    int v1[]={1,3,5,7};
    int v2[]={2,4,6,8};

    int n = sizeof(v1)/sizeof(v1[0]);

    int v3[2*n];

    intercalare_v3(v1, v2, n, v3);

    printf("Vettore risultato: ");
    for(int i=0; i<2*n; i++){
        printf("%d ", v3[i]);
    }
    printf("\n");
    return 0;
}