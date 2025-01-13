/*
Si scriva una funzione che calcola il prodotto tra due matrici
*/

#include <stdio.h>

void prodottoMatrici(int righe1, int colonne1, int colonne2,  int m1[][colonne1], int m2[][righe1], int m3[righe1][colonne2]){
    for(int i=0; i<righe1; i++){
        for(int j=0; j<colonne2; j++)
            m3[i][j]=0;
    }

    for(int i=0; i<righe1; i++){
        for(int j=0; j<colonne2; j++)
            for(int k=0; k<colonne1; k++)
                m3[i][j] += m1[i][k]*m2[k][j];
    }


}

void stampa_matrice(int m3[][10], int righe1, int colonne2){
    for(int i=0; i<righe1; i++){
        for(int j=0; j<colonne2; j++){
                printf("%d", m3[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int righe1, colonne1, righe2, colonne2;
    int m1[righe1][colonne1], m2[righe2][colonne2], m3[righe1][colonne2];

    printf("Inserisci il numero di righe e colonne della prima matrice: ");
    scanf("%d %d", &righe1, &colonne1);

    printf("Inserisci gli elementi della prima matrice: ");
    for(int i=0; i<righe1; i++){
        for(int j=0; j<colonne1; j++){
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Inserisci il numero di righe e colonne della seconda matrice: ");
    scanf("%d %d", &righe2, &colonne2);

    if(colonne1 != righe2){
        printf("Errore nella dimensione della matrice");
    }

    printf("Inserisci gli elementi della seconda matrice: ");
    for(int i=0; i<righe2; i++){
        for(int j=0; j<colonne2; j++){
            scanf("%d", &m2[i][j]);
        }
    }

    prodottoMatrici(righe1, colonne1, colonne2, m1, m2, m3);

    printf("Il risultato del prodotta tra matrici è: \n");
    stampa_matrice(m3, righe1, colonne2);

    


    return 0;
}