/*
Scrivere un programma in C che permetta di gestire un registro di studenti, ogni studente ha un nome, un età e una lista dinamica di voti. Il programma deve 
permettere di:
Inserire un nuovo studente con i dati
Aggiungere un voto ad uno studente specifico
Stampare i dati di tutti gli studenti, ivi inclusa la media dei voti
liberare correttamente la memoria allocata dinamicamente prima della chiusura del programma
Utilizzare:
Si deve utilizzare un array dinamico di struct per rappresentare il registro degli studenti(ogni struct uno studente) 
array dinamico per i voti di ciascuno studente 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nome[50];
    int eta;
    int *voti;
    int num_voti;

}  Studente;

typedef Studente Registro;

float calcolaMedia(int *, int);

Studente *aggiungiStudente(Registro *studenti, int *num_studenti, char *nome, int eta ){
    studenti = realloc(studenti, (*num_studenti + 1)*sizeof(Studente));
    if(!studenti){
        printf("Errore di allocazione\n");
        exit(1);
    }
    strcpy(studenti[*num_studenti].nome, nome);
    studenti[*num_studenti].eta = eta;
    studenti[*num_studenti].voti = NULL;
    studenti[*num_studenti].num_voti = 0;
    (*num_studenti)++;

    /*
    Studente *nuovoStudente = &studenti[*num_studenti];
    strcpy(nuovoStudente->nome, nome);
    nuovoStudente->eta = eta;
    nuovoStudente->voti = NULL;
    nuovoStudente->num_voti = 0;
    (*num_studenti)++;
    */

    return studenti;

}

void aggiungiVoto(Registro *studenti, int num_studenti, char *nome, int voto){
    for(int i=0; i<num_studenti; i++){
        if(strcmp(studenti[i].nome, nome)==0){
            Studente *studente = &studenti[i];
            studente->voti= realloc(studente->voti, (studente->num_voti+1)*sizeof(int));
            if(!studente->voti){
                printf("Errore di allocazione\n");
                exit(1);
            }
            studente->voti[studente->num_voti] = voto;
            studente->num_voti++;
            return;
        }
    }
    printf("Studente '%s' non trovato  \n ", nome);
}

void stampaStudenti(Registro *studenti, int num_studenti){
    for(int i =0; i<num_studenti; i++){
        printf("Nome : %s \n", studenti[i].nome);
        printf("Eta : %d \n", studenti[i].eta);
        printf("Voti : \n");
        for(int j=0; j< studenti[i].num_voti; j++){
            printf("%d \n", studenti[i].voti[j]);
        }
        printf("\n Media voti: %.2f \n\n", calcolaMedia(studenti[i].voti, studenti[i].num_voti));
    }
}

float calcolaMedia(int *voti, int num_voti){
    if(num_voti == 0) return 0.0;
    int somma=0;
    for(int i=0; i<num_voti; i++){
        somma+= voti[i];
    }
    return somma / (float)num_voti;
}

void liberaMem(Registro *studenti, int num_studenti){
    for(int i =0; i<num_studenti; i++)
        free(studenti[i].voti);
    free(studenti);
}

int main(){

    Registro *studenti =  NULL;
    int num_studenti = 0;

    studenti = aggiungiStudente( studenti, &num_studenti, "Mario Rossi", 20 );
    studenti = aggiungiStudente( studenti, &num_studenti, "Luigi  Bianchi", 25 );

    aggiungiVoto( studenti, num_studenti, "Mario Rossi", 28);
    aggiungiVoto( studenti, num_studenti, "Mario Rossi", 30);

    aggiungiVoto( studenti, num_studenti, "Luigi  Bianchi", 18);

    stampaStudenti(studenti, num_studenti);

    liberaMem(studenti, num_studenti);

    return 0;
}