/*Scrivere una funzione elementiFrequenti(int *arr, int n, int soglia, int *nFrequenti) che restituisce gli elementi che appaiono 
più volte della soglia.

Esempio:

    Input: arr = [1, 2, 2, 3, 3, 3, 4], soglia = 2
    Output: [2, 3], nFrequenti = 2.
*/


#include <stdio.h>
#include <stdlib.h>

int* elementiFrequenti(int *arr, int n, int soglia, int *nFrequenti){

    int *frequenti = (int *)malloc(n*sizeof(int));
    if(frequenti==NULL){
        printf("Errore nella malloc\n");
        exit(1);
    }
    int *conteggio = (int *)calloc(n, sizeof(int));
    if(conteggio==NULL){
        printf("Errore nella malloc\n");
        exit(2);
    }

    *nFrequenti=0;

    for(int i=0; i<n; i++){
        conteggio[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(conteggio[arr[i]]>=soglia){
            int trovato=0;
            for(int j=0; j<*nFrequenti; j++){
                if(frequenti[j]==arr[i]){
                    trovato =1;
                    break;
                }
            }
            if(!trovato){
                frequenti[*nFrequenti] = arr[i];
                (*nFrequenti)++;
            }
        }
    }

    free(conteggio);
    return frequenti;
}

int main(){
    int arr[] = {1, 2, 2, 3, 3, 3, 4};
    int n=7, soglia=2, nFrequenti;

    int *risultato = elementiFrequenti(arr, n, soglia, &nFrequenti);

    printf("Elementi frequenti: ");
    for(int i=0;i<nFrequenti; i++){
        printf("%d ", risultato[i]);
    }

    printf("\n");

    free(risultato);

    return 0;
}