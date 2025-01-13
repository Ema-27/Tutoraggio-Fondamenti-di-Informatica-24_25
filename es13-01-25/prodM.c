#include <stdio.h>

#define MAX 10 // Dimensione massima per le matrici

void prodottoMatrici(int righe1, int colonne1, int colonne2, int m1[][MAX], int m2[][MAX], int m3[][MAX]) {
    for (int i = 0; i < righe1; i++) {
        for (int j = 0; j < colonne2; j++) {
            m3[i][j] = 0;
            for (int k = 0; k < colonne1; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void stampa_matrice(int m3[][MAX], int righe, int colonne) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int righe1, colonne1, righe2, colonne2;
    int m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX];

    // Input dimensioni prima matrice
    printf("Inserisci il numero di righe e colonne della prima matrice: ");
    scanf("%d %d", &righe1, &colonne1);

    // Input elementi prima matrice
    printf("Inserisci gli elementi della prima matrice:\n");
    for (int i = 0; i < righe1; i++) {
        for (int j = 0; j < colonne1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    // Input dimensioni seconda matrice
    printf("Inserisci il numero di righe e colonne della seconda matrice: ");
    scanf("%d %d", &righe2, &colonne2);

    // Controllo compatibilità dimensioni
    if (colonne1 != righe2) {
        printf("Errore: le dimensioni delle matrici non sono compatibili per la moltiplicazione.\n");
        return 1;
    }

    // Input elementi seconda matrice
    printf("Inserisci gli elementi della seconda matrice:\n");
    for (int i = 0; i < righe2; i++) {
        for (int j = 0; j < colonne2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    // Calcolo del prodotto
    prodottoMatrici(righe1, colonne1, colonne2, m1, m2, m3);

    // Stampa del risultato
    printf("Il risultato del prodotto tra matrici è:\n");
    stampa_matrice(m3, righe1, colonne2);

    return 0;
}