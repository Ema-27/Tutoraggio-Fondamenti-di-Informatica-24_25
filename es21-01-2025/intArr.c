/*
Scrivi una funzione intersezioneArray(int *A, int *B, int nA, int nB) che riceve in ingresso due array A e B di lunghezze rispettive nA e nB.
 La funzione restituisce un array contenente gli elementi comuni ai due array, senza duplicati.
Esempio:

    Input: A = [1, 2, 2, 3], B = [2, 3, 4]
    Output: [2, 3]
*/
#include <stdio.h>
#include <stdlib.h>

int* intersezioneArray(int *A, int* B, int nA, int nB, int *nRisultato){
        int *risultato = (int*)malloc(nA * sizeof(int));
        *nRisultato =0;

        for(int i =0; i<nA; i++){
            int trovato=0;
            for( int j=0; j<*nRisultato; j++){
                if(risultato[j]==A[i]){
                    trovato = 1;
                    break;
                }
            }
            if(!trovato){
                for(int j=0; j<nB; j++){
                    if(A[i]==B[j]){
                        risultato[*nRisultato]=A[i];
                        (*nRisultato)++;
                        break;
                    }
                }
            }
        }

        return risultato;
    }

int main(){

    int A[]={1, 2, 2, 3};
    int B[]={2, 3, 4};

    int nA=4; 
    int nB= 3;
    int nRisultato;
    int *risultato = intersezioneArray(A, B, nA, nB, &nRisultato);

    printf("Intersezione : ");
    for(int i=0; i<nRisultato; i++){
        printf("%d ", risultato[i]);
    }

    printf("\n");

    free(risultato);
    return 0;
}