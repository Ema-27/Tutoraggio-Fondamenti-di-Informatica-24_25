#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione delle struct
typedef struct {
    char nome[20];
    char cat[20];
    int qntDisp;
    int prezzo;
} Prodotto;

typedef struct {
    Prodotto prodotti[5];
    int vendite[8][3];
} VenditeProdotti;

// Funzione 1: valoreMagazzino
int valoreMagazzino(VenditeProdotti vp) {
    int totale = 0;
    for (int i = 0; i < 5; i++) {
        totale += vp.prodotti[i].qntDisp * vp.prodotti[i].prezzo;
    }
    return totale;
}

// Funzione 2: prodottiTop
int *prodottiTop(VenditeProdotti vp, char cat[20], int num, int *count) {
    int *risultato = malloc(5 * sizeof(int));
    if (!risultato) {
        printf("Errore nella malloc\n");
        exit(1);
    }
    *count = 0;

    int venditeTotali[5] = {0};
    for (int i = 0; i < 8; i++) {
        int codProd = vp.vendite[i][0];
        int numPez = vp.vendite[i][1];
        venditeTotali[codProd] += numPez;
    }
    
    for (int i = 0; i < 5; i++) {
        if (strcmp(vp.prodotti[i].cat, cat) == 0 && venditeTotali[i] > num) {
            risultato[*count] = i;
            (*count)++;
        }
    }
    
    risultato = realloc(risultato, (*count) * sizeof(int));
    if (!risultato && *count > 0) {
        printf("Errore nella malloc\n");
        exit(1);
    }
    
    return risultato;
}

// Funzione 3: categoriaRedditizia
char *categoriaRedditizia(VenditeProdotti vp) {
    int guadagni[5] = {0};
    char *migliore = malloc(20 * sizeof(char));
    if (!migliore) {
        printf("Errore nella malloc\n");
        exit(1);
    }

    for (int i = 0; i < 8; i++) {
        int codProd = vp.vendite[i][0];
        int numPez = vp.vendite[i][1];
        int prezzo = vp.vendite[i][2];
        guadagni[codProd] += numPez * prezzo;
    }

    int maxGuadagno = -1;
    for (int i = 0; i < 5; i++) {
        if (guadagni[i] > maxGuadagno) {
            maxGuadagno = guadagni[i];
            strcpy(migliore, vp.prodotti[i].cat);
        }
    }
    return migliore;
}

// Funzione 4: prodottoInvenduto
int prodottoInvenduto(VenditeProdotti vp) {
    int venduto[5] = {0};
    for (int i = 0; i < 8; i++) {
        venduto[vp.vendite[i][0]] = 1;
    }
    for (int i = 0; i < 5; i++) {
        if (!venduto[i]) return i;
    }
    return -1;
}

// Funzione principale di test
int main() {
    VenditeProdotti vp = {
        .prodotti = {{"Mouse", "PC", 20, 35}, {"Spazzolino", "Elettrodomestici", 35, 70}, {"Notebook", "PC", 5, 500},
                     {"TV", "Elettrodomestici", 10, 350}, {"Monitor", "PC", 20, 200}},
        .vendite = {{1, 2, 30}, {2, 1, 550}, {0, 10, 25}, {4, 1, 200}, {0, 3, 35}, {2, 3, 450}, {2, 2, 500}, {1, 1, 35}}
    };

    printf("Valore magazzino: %d\n", valoreMagazzino(vp));
    
    int count;
    int *topProdotti = prodottiTop(vp, "PC", 5, &count);
    printf("Prodotti top: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topProdotti[i]);
    }
    printf("\n");
    free(topProdotti);
    
    char *catMax = categoriaRedditizia(vp);
    printf("Categoria con massimo guadagno: %s\n", catMax);
    free(catMax);
    
    printf("Prodotto invenduto: %d\n", prodottoInvenduto(vp));
    
    return 0;
}
