/*
 Si scriva una funzione che cerca un elemento in un vettore.
*/

//0 1

#include <stdio.h>

#define false 0
#define true 1

typedef int boolean;

int cercaElemento(int vettore[], int n, int elemento){
    for(int i =0; i<n; i++){
        if(vettore[i]==elemento)
            return i;
    }

    return -1;//elemento non trovato
}

int main(){

    int vettore[] = {1, 3, 2, 15}; 
    int i;
    int x;
    boolean trovato;

    printf("Inserisci l'elemento da cercare: ");
    scanf("%d", &x);

    trovato=false;
    for(i=0; i<4 && !trovato; i++){
        if(x==vettore[i])
            trovato = true;
    }

    if(trovato)
        printf("%d è presente nel vettore \n", x);
    else
        printf("%d non è presente nel vettore \n", x);
    
    /*
    int vettore[] = {2,4,6,8,10};
    int n=5;
    int el=6;

    int posizione = cercaElemento(vettore, n, el);
    if( posizione != -1){
        printf("L'elemento è stato trovato alla posizione %d\n", posizione);
    }else{
        printf("L'elemento non è stato trovato\n");
    }
    */
    return 0;

}