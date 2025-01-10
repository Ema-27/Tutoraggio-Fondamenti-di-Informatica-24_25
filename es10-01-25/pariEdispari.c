/*
Si scriva una funzione che data una lista conta quanti sono i numeri pari o dispari
*/

#include <stdio.h>

void contaPariDispari(int lista[], int n, int *pari, int *dispari){
    *pari= 0;
    *dispari = 0;

    for(int i =0; i<n; i++){
        if(lista[i]%2==0)
            (*pari)++;
        else
            (*dispari)++;
    }

}

void contaPariDispari_v2(int array[],int dim, int risultati[]){
    risultati[0] =0;
    risultati[1] =0;
    for(int i=0; i<dim; i++){
        if(array[i]%2 ==0){
            risultati[0]++;
        }
        else{
            risultati[1]++;
        }
    }

}

int* contaPariDispari_v3( int array[], int n){
    int* ris = (int*)malloc(2 * sizeof(int));
    for(int i=0; i<n, i++){
        for(int i=0; i<dim; i++){
            if(array[i]%2 ==0){
                ris[0]++;
            }
            else{
                ris[1]++;
            }
        }
    }
    return ris;
}

int main(){
    int lista[] = {1,2,3,4,5,6,7,8};
    int pari, dispari;
    int n = sizeof(lista) / sizeof(lista[0]);
    
    contaPariDispari(lista, n, &pari, &dispari);

    

    int risultati[2];
    int dim = 0;
    printf("Inserisci la dimensione della lista: ");
    scanf("%d", &dim);
    int array[dim];
    for(int i=0; i<dim; i++){
        printf("Inserisci l'elemento in posizione: %d ", i);
        scanf("%d", &array[i]);
    }
    contaPariDispari_v2(array, dim, risultati);

    int* ris = contaPariDispari_v3(lista, n);

    printf("Numeri Pari: %d, Numeri Dispari: %d \n", pari, dispari);
    printf("Numeri Pari: %d, Numeri Dispari: %d \n", risultati[0], risultati[1]);
    printf("Numeri Pari: %d, Numeri Dispari: %d \n", ris[0], ris[1]);
    return 0;
}