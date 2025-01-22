/*
Scrivere una funzione rimuoviDuplicati(int *arr, int n, int *nUnici) che restituisce un array con elementi unici.
Aggiorna nUnici con la lunghezza del nuovo array.

Esempio:

    Input: arr = [1, 2, 2, 3, 3, 4]
    Output: [1, 2, 3, 4], nUnici = 4.
*/

#include <stdio.h>
#include <stdlib.h>

int* rimuoviDuplicati(int* arr, int n, int *nUnici){

    int* unici= (int*)malloc(n*sizeof(int));
    *nUnici=0;
    for(int i=0; i<n; i++){
        int trovato=0;
        for(int j=0; j<*nUnici; j++){
            if(arr[i]==unici[j]){
                trovato = 1;
                break;
            }
        }
        if(!trovato){
            unici[*nUnici] = arr[i];
            (*nUnici)++;
        }
    }

    return unici;
}

int main(){
    int array[]={1, 2, 2, 3, 3, 4};
    int n=6;
    int nUnici;

    //Aggiorna nUnici con la lunghezza del nuovo array
    int *risultato = rimuoviDuplicati(array, n, &nUnici);

    printf("Array senza duplicati: ");
    for(int i=0; i<nUnici; i++){
        printf("%d ", risultato[i]);
    }
    printf("\n");

    free(risultato);
    return 0;
}