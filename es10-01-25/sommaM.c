/*
Si scriva una funzione che calcola la somma la somma tra due matrici
*/

#include <stdio.h>
#include <stdlib.h>

void sommaMatrici(int righe, int colonne, int m1[righe][colonne], int m2[righe][colonne], int ris[righe][colonne]){
    for(int i=0; i<righe; i++){
        for(int j =0; j<colonne; j++){
            ris[i][j]=m1[i][j]+m2[i][j];
        }
    }
}

int main(){
    int righe, colonne;

    printf("Inserisci il numero di righe: ");
    scanf("%d", &righe);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &colonne);

    int m1[righe][colonne], m2[righe][colonne], risultato[righe][colonne];

    printf("Inserisci gli elementi della prima matrice: \n");
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Inserisci gli elementi della seconda matrice: \n");
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    sommaMatrici(righe, colonne, m1, m2, risultato);

    printf("La somma delle due matrici è: \n");
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("%d ",risultato[i][j]);
        }
        printf("\n");
    }

    return 0;
}