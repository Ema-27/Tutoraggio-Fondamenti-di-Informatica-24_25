/*
Si scriva una funzione trovaMax che trovi il massimo e la posizione del massimo in vettori di double.
*/

#include <stdio.h>
void trovaMax(double vettore[], int n, double *massimo, int *posizione){
    *massimo = vettore[0];
    *posizione = 0;

    for(int i=0; i<n; i++){
        if(vettore[i]>*massimo){
            *massimo=vettore[i];
            *posizione=i;
        }
    }
}

int main(){
    double vettore[]={1.1, 3.4, 5.6, 2.9, 7.8};
    int n = sizeof(vettore)/sizeof(vettore[0]);
    double massimo;
    int posizione;

    trovaMax(vettore, n, &massimo, &posizione);
    printf("Massimo: %.2f, Posizione: %d \n", massimo, posizione);

    return 0;
}