/*
Calcola la media di n elementi (while e for)
*/

#include <stdio.h>

int main(){
    int dim = 0;
    printf("Inserisci la dimensione della lista: ");
    scanf("%d", &dim);
    int numeri[dim];
    int somma = 0;

    printf("Inserisci %d numeri: \n", dim);
    int i =0;
    while(i <dim){
        scanf("%d", &numeri[i]);
        somma += numeri[i];
        i++;
    }
    /*
    for(int i=0; i<dim; i++){
        scanf("%d", &numeri[i]);
        somma += numeri[i];
    }
    */ 
    printf("Media: %.2f \n", (somma/(float)dim));
    return 0;
}