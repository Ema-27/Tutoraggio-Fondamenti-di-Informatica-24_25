/*
Si scriva una funzione che calcola la somma e la differenza di due numeri utilizzando i puntatori
*/

#include <stdio.h>

void sommaEDifferenza(int a, int b, int *somma, int *differenza){
    *somma = a+b;
    *differenza = a-b;
}

int main(){
    int a = 10, b =5, somma, differenza;

    sommaEDifferenza(a, b, &somma, &differenza);

    printf("Somma: %d, Differenza: %d \n", somma, differenza);

    return 0;
}