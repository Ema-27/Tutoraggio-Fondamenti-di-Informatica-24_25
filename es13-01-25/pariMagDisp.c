/*
Si scriva una funzione che dato un vettore restituisce true se la somma degli elementi pari è maggiore della somma degli elementi dispari
*/

#include <stdio.h>
#include <stdlib.h>

void leggiVettore(int *v, int dim){
    int i;
    for(i=0; i<dim; i++){
        printf("Inserisci v[%d]: ", i);
        scanf("%d", &v[i]);
    }
}

int pariMagDis(int *v, int dim){
    int pari=0;
    int dispari=0;
    for(int i=0; i<dim; i++){
        if(v[i]%2==0)
            pari = pari+v[i];
        else
            dispari = dispari+ v[i];
    }
    if(pari>dispari)
        return 1;
    return 0;
}

int main(){
    int *v;
    int i, dim, pariMagDisp;
    printf("Inserire la dimensione dle vettore: ");
    scanf("%d", &dim);
    v=(int*)malloc(dim*sizeof(int));


    if(v==NULL){
        printf("Errore nella malloc");
        return 1;
    }

    leggiVettore(v, dim);
    pariMagDisp = pariMagDis(v, dim);
    if(pariMagDisp)
        printf("Pari sono maggiori dei dispari\n");
    else    
        printf("Dispari sono maggiori dei pari\n");

    free(v);

    return 0;
}