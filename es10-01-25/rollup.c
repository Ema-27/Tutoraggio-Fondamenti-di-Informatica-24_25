/*
    Si scriva una funzione “rollup” che riceve in input una lista l di lunghezza n (con n pari) e 
    restituisce una lista di lunghezza n/2 il cui i-esimo elemento è pari a l[2*i]+l[2*i+1]. Si invochi 
    inoltre la funzione sulla lista [1, 3, 6, 1, 6, 3, 8, 9] e se ne discutano i risultati.
*/
#include <stdio.h>

void rollup(int lista[], int n, int risultato[]){
    for(int i =0; i<n/2; i++){
        risultato[i]= lista[2*i]+lista[2*i +1 ];
    }
}

int main(){
    int lista[] = {1, 3, 6, 1, 6, 3, 8, 9};
    int n=8;
    int risultato[n/2];

    rollup(lista, n, risultato);

    printf("lista dopo il rollup: ");
    for(int i=0; i<n/2; i++){
        printf("%d ", risultato[i]);
    }

    printf("\n");
    return 0;
}