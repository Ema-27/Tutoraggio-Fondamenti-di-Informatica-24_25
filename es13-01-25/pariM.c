/*
Si scriva una programma che alloca e legge un  vettore e verifica che tutti gli elementi in posizione pari sono maggiori di 10.
*/
#include <stdio.h>

int main(){
    int n;
    printf("Inserisci la dimensione del vettore: ");
    scanf("%d", &n);

    int vettore[n];
    printf("Inserisci gli elementi: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &vettore[i]);
    }

    int tuttiMaggiori = 1;
    for(int i=0; i<n; i +=2){
        if( vettore[i]<10){
            tuttiMaggiori = 0;
        }
    }

    if(tuttiMaggiori)
        printf("Tutti gli elementi in posizione pari sono maggiori di 10\n");
    else
        printf("Non tutti gli elementi in posizione pari sono maggiori di 10\n");



    return 0;
}