/*
Scrivere un programma per gestire un inventario di prodotti. Ogni prodotto è rappresentato da una struct che contiene il nome del prodotto,
 la quantità disponibile e un array dinamico di prezzi storici. Il programma deve permettere di:

    Aggiungere un nuovo prodotto.
    Aggiornare il prezzo corrente di un prodotto.
    Stampare l'inventario, mostrando la media dei prezzi storici per ogni prodotto.
    Liberare la memoria allocata.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[50];
    int quantita;
    float *prezziStorici;
    int numPrezzi;
}Prodotto;

Prodotto* aggiungiProdotto(Prodotto* inventario, int *numProdotti, char *nome, int qtn, float prezzo){
    inventario = (Prodotto*)realloc(inventario, (*numProdotti+1)*sizeof(Prodotto));
    strcpy(inventario[*numProdotti].nome, nome);
    inventario[*numProdotti].quantita=qtn;
    inventario[*numProdotti].prezziStorici=(float*)malloc(sizeof(float));
    inventario[*numProdotti].prezziStorici[0]=prezzo;
    inventario[*numProdotti].numPrezzi =1;
    (*numProdotti)++;
    return inventario;

}

void aggiornaPrezzo(Prodotto* inventario, int numProdotti, char *nome, float nuovoPrezzo){
    for(int i=0; i<numProdotti; i++){
        if(strcmp(inventario[i].nome, nome)==0){
            inventario[i].prezziStorici = (float*)realloc(inventario[i].prezziStorici, (inventario[i].numPrezzi +1)* sizeof(float));
            inventario[i].prezziStorici[inventario[i].numPrezzi]=nuovoPrezzo;
            inventario[i].numPrezzi++;
            return;
        }
    }
    printf("Prodotto non trovato!\n");
}

void stampaInventario(Prodotto* inventario, int numProdotti){
    printf("Invertario:\n");
    for(int i=0; i<numProdotti; i++){
        printf("Prodotto: %s, quantita: %d, Prezzi: ", inventario[i].nome, inventario[i].quantita);
        float somma =0;
        for(int j=0;j<inventario[i].numPrezzi; j++){
            printf("%.2f ", inventario[i].prezziStorici[j]);
            somma+= inventario[i].prezziStorici[j];
        }
        printf("(Media: %.2f)\n", somma/inventario[i].numPrezzi);
    }
}

void liberaMemoria(Prodotto* inventario, int numProdotti){
    for(int i =0; i<numProdotti; i++){
        free(inventario[i].prezziStorici);
    }
    free(inventario);
}

int main(){
    Prodotto *inventario =NULL;
    int numProdotti=0;

    inventario = aggiungiProdotto(inventario, &numProdotti, "Mela", 50, 1.20);
    inventario = aggiungiProdotto(inventario, &numProdotti, "Pera", 30, 0.80);

    aggiornaPrezzo(inventario, numProdotti, "Mela", 1.25);
    aggiornaPrezzo(inventario, numProdotti, "Pera", 0.85);

    stampaInventario(inventario,numProdotti);
    liberaMemoria(inventario, numProdotti);

    return 0;
}