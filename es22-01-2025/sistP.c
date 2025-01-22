/*
Scrivere un programma per gestire un sistema di prenotazioni per una sala conferenze. Ogni prenotazione è rappresentata da una struct
 contenente il nome del cliente, la data (in formato stringa) e un array dinamico di servizi richiesti (ognuno rappresentato da una stringa).
 Il programma deve permettere di:

    Aggiungere una nuova prenotazione.
    Aggiungere un servizio a una prenotazione esistente.
    Stampare tutte le prenotazioni, includendo i servizi richiesti.
    Liberare la memoria allocata.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
   char nomeCliente[50];
   char data[15];
   char **servizi;
   int numServizi;
}Prenotazione;

Prenotazione* aggiungiPrenotazione(Prenotazione* prenotazioni, int *numPrenotazioni, char* nomeCliente, char* data){
    prenotazioni = (Prenotazione*)realloc(prenotazioni, (*numPrenotazioni+1)*sizeof(Prenotazione));
    strcpy(prenotazioni[*numPrenotazioni].nomeCliente, nomeCliente);
    strcpy(prenotazioni[*numPrenotazioni].data, data);
    prenotazioni[*numPrenotazioni].servizi = NULL;
    prenotazioni[*numPrenotazioni].numServizi =0;
    (*numPrenotazioni)++;
    return prenotazioni;
}

void aggiungiServizio(Prenotazione* prenotazioni,int numPrenotazioni, char* nomeCliete, char* servizio){
    for(int i=0; i<numPrenotazioni; i++){
        if(strcmp(prenotazioni[i].nomeCliente, nomeCliete)==0){
            prenotazioni[i].servizi=(char**)realloc(prenotazioni[i].servizi, (prenotazioni[i].numServizi + 1)*sizeof(char*));
            prenotazioni[i].servizi[prenotazioni[i].numServizi] = (char*)malloc(strlen(servizio)+1);
            strcpy(prenotazioni[i].servizi[prenotazioni[i].numServizi], servizio);
            prenotazioni[i].numServizi++;
            return;
        }
    }
    printf("Prenotazione non trovata! \n");
}

void stampaPrenotazioni(Prenotazione* prenotazioni, int numPrenotazioni){
    printf("Prenotazioni: \n");
    for(int i=0; i<numPrenotazioni; i++){
        printf("Cliente: %s, Data: %s, Servizi: ", prenotazioni[i].nomeCliente, prenotazioni[i].data);
        if(prenotazioni[i].numServizi==0){
            printf("Nessuno. \n");
        }else{
            for(int j=0; j<prenotazioni[i].numServizi; j++){
                printf("%s ", prenotazioni[i].servizi[j]);
            }
            printf("\n");
        }
    }
}

void liberaMemoria(Prenotazione* prenotazioni, int numPrenotazioni){
    for(int i=0; i<numPrenotazioni; i++){
        for(int j=0; j<prenotazioni[i].numServizi; j++){
            free(prenotazioni[i].servizi[j]);
        }
        free(prenotazioni[i].servizi);
    }
    free(prenotazioni);
}


int main(){
    Prenotazione *prenotazioni =NULL;
    int numPrenotazioni =0;

    prenotazioni = aggiungiPrenotazione(prenotazioni, &numPrenotazioni, "Mario Rossi", "22-01-2025");
    aggiungiServizio(prenotazioni, numPrenotazioni, "Mario Rossi", "Catering");
    aggiungiServizio(prenotazioni, numPrenotazioni, "Mario Rossi", "Audio/Video");

    stampaPrenotazioni(prenotazioni, numPrenotazioni);
    liberaMemoria(prenotazioni, numPrenotazioni);

    return 0;
}