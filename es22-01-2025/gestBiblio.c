/*
Gestione di un sistema bibliotecario

Un programma deve gestire un sistema di informazioni sui libri in una biblioteca. 
I dati sono organizzati come segue:

    Struct Libro
    Contiene:
        char titolo[50]: il titolo del libro.
        char autore[50]: il nome dell'autore.
        int anno: l'anno di pubblicazione.

    Struct Biblioteca
    Contiene:
        Un array di libri dinamico Libro *libri.
        Un intero numLibri che rappresenta il numero di libri presenti.

Scrivere un programma che includa le seguenti funzionalità:

    Aggiungere un nuovo libro alla biblioteca.
    Contare quanti libri sono stati pubblicati da un autore specifico.
    Trovare tutti i libri pubblicati in un determinato intervallo di anni.
    Stampare l'intero catalogo della biblioteca.
    Liberare correttamente la memoria allocata dinamicamente.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char titolo[50];
    char autore[50];
    int anno;
}Libro;

typedef struct 
{
    Libro *libri;
    int numLibri;
}Biblioteca;

Biblioteca aggiungiLibro(Biblioteca b, char *titolo, char *autore, int anno){
    b.libri = (Libro*)realloc(b.libri, (b.numLibri +1)*sizeof(Libro));
    strcpy(b.libri[b.numLibri].titolo, titolo);
    strcpy(b.libri[b.numLibri].autore, autore);
    b.libri[b.numLibri].anno=anno;
    b.numLibri++;
    return b;
}

int contaLibriAutore(Biblioteca b, char* autore){
    int cont=0;
    for(int i=0; i<b.numLibri; i++){
        if(strcmp(b.libri[i].autore, autore)==0){
            cont++;
        }
    }
    return cont;
}

void trovaIntervalloLibri(Biblioteca b, int annoI, int annoF){
    printf("Libri pubblicati tra %d e %d: \n", annoI, annoF);
    for(int i=0; i<b.numLibri; i++){
        if(b.libri[i].anno>= annoI && b.libri[i].anno<= annoF){
            printf("%s di %s (%d)\n", b.libri[i].titolo, b.libri[i].autore, b.libri[i].anno);
        }
    }
}

void stampaCatalogo(Biblioteca b){
    printf("Catalogo: \n");
    for(int i=0; i<b.numLibri; i++){
        printf("Titolo %s, Autore %s, Anno %d\n", b.libri[i].titolo, b.libri[i].autore, b.libri[i].anno);
    }
}

void liberaMemoria(Biblioteca b){
    free(b.libri);
}

int main(){

    Biblioteca b = {NULL, 0};
    b=aggiungiLibro(b, "Il signore degli anelli", "Tolkien", 1954);
    b=aggiungiLibro(b, "1984", "Orwell", 1949);
    b=aggiungiLibro(b, "La fattoria degli animale", "Orwell", 1945);
    
    printf("Libri di Orwell: %d \n", contaLibriAutore(b, "Orwell"));

    trovaIntervalloLibri(b, 1940, 1950);

    stampaCatalogo(b);

    liberaMemoria(b);

    return 0;
}