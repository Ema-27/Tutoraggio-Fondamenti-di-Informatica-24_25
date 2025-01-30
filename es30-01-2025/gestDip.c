/*
Scrivere un programma per gestire i dipendenti di un'azienda. Ogni dipendente è rappresentato da una struct contenente nome, 
età e un array dinamico di progetti completati (ognuno rappresentato da una stringa). Il programma deve permettere di:

    Aggiungere un nuovo dipendente.
    Aggiungere un progetto completato a un dipendente.
    Stampare l'elenco di tutti i dipendenti, includendo i progetti completati.
    Liberare la memoria allocata.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int eta;
    char **progetti;
    int numProgetti;
}Dipendente;

Dipendente* aggiungiDipendente(Dipendente* dipendenti, int *numDipendenti, char *nome, int eta){
    Dipendente *temp = (Dipendente *)realloc(dipendenti, (*numDipendenti +1)*sizeof(Dipendente));
    if(temp == NULL){
        printf("Errore nella realloc\n");
        free(temp);
        exit(1);
    }

    dipendenti = temp;

    strcpy(dipendenti[*numDipendenti].nome, nome);
    dipendenti[*numDipendenti].eta=eta;
    dipendenti[*numDipendenti].progetti=NULL;
    dipendenti[*numDipendenti].numProgetti=0;
    (*numDipendenti)++;
    return dipendenti;
}

void aggiungiProgetto(Dipendente *dipendenti, int numDipendenti, char *nome, char *progetto){
    for(int i=0; i<numDipendenti; i++){
        if(strcmp(dipendenti[i].nome, nome)==0){
            dipendenti[i].progetti = (char**)realloc(dipendenti[i].progetti, (dipendenti[i].numProgetti+1)*sizeof(char*));
            dipendenti[i].progetti[dipendenti[i].numProgetti]=(char *)malloc(strlen(progetto)+1);
            strcpy(dipendenti[i].progetti[dipendenti[i].numProgetti], progetto);
            dipendenti[i].numProgetti++;
            return;
        }
    }

    printf("Dipendente non trovato\n");
}

void stampaDipendente(Dipendente *dipendenti, int numDipendenti){
    printf("Dipendenti: \n");
    for(int i=0; i<numDipendenti; i++){
        printf("Nome: %s, Eta: %d, Progetti: ", dipendenti[i].nome, dipendenti[i].eta);
        if(dipendenti[i].numProgetti==0){
            printf("Nessuno\n");
        }else{
            for(int j=0; j<dipendenti[i].numProgetti; j++){
                printf("%s ", dipendenti[i].progetti[j]);
            }
            printf("\n");
        }
    }
}

void liberaMemoria(Dipendente *dipendenti, int numDipendenti){
    for(int i=0; i<numDipendenti; i++){
        for(int j=0; j<dipendenti[i].numProgetti; j++){
            free(dipendenti[i].progetti[j]);
        }
        free(dipendenti[i].progetti);
    }

    free(dipendenti);
}


int main(){

    Dipendente *dipendenti = NULL;
    int numDipendenti =0;

    dipendenti = aggiungiDipendente(dipendenti, &numDipendenti, "Mario Rossi", 45);

    dipendenti = aggiungiDipendente(dipendenti, &numDipendenti, "Luca Bianchi", 45);

    aggiungiProgetto(dipendenti, numDipendenti, "Mario Rossi", "Progetto A");

    aggiungiProgetto(dipendenti, numDipendenti, "Mario Rossi", "Progetto B");
    
    stampaDipendente(dipendenti, numDipendenti);

    liberaMemoria(dipendenti, numDipendenti);

    return 0;
}