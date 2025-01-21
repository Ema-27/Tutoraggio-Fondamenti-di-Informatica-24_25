#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[20];
    char strumento[20];
}Musicista;

typedef struct
{
    Musicista musicisti[6]; 
    int collaborazioni[8][4];
}MusicistiCollaborazioni;

int *numeroCollaborazione(MusicistiCollaborazioni c){
    int *result = (int*)calloc(6, sizeof(int));
    for(int i=0; i<8; i++){
        result[c.collaborazioni[i][0]]++;
        result[c.collaborazioni[i][1]]++;
    }
    return result;
}

int musicistaSimile(MusicistiCollaborazioni c, int cod){

    int durata[6] = {0};

    for(int i=0; i<8; i++){
        if(c.collaborazioni[i][0]==cod){
            int altro = c.collaborazioni[i][1];
            durata[altro] += c.collaborazioni[i][3]-c.collaborazioni[i][2]+1;
        }
        else if(c.collaborazioni[i][1]==cod){
            int altro = c.collaborazioni[i][0];
            durata[altro] += c.collaborazioni[i][3]-c.collaborazioni[i][2]+1;
        }
    }

    int maxDurata =0, risultato =-1;
    for(int i=0; i<6; i++){
        if(durata[i]>maxDurata){
            maxDurata = durata[i];
            risultato = i;
        }
    }
    return risultato;

}

int *durateStrumento(MusicistiCollaborazioni c, char strum[20]){

    int *result= (int*)calloc(8, sizeof(int));

    for(int i=0; i<8; i++){
        int cod1 = c.collaborazioni[i][0];
        int cod2 = c.collaborazioni[i][1];

        if(strcmp(c.musicisti[cod1].strumento, strum)==0 ||
          strcmp(c.musicisti[cod2].strumento, strum)==0){
            result[i] = c.collaborazioni[i][3] - c.collaborazioni[i][2]+1;
          }
          else {
            result[i]=0;
          }
    }

    return result;

}

int musicistaRichiesto(MusicistiCollaborazioni c){
    int connessioni[6][6] ={0};

    for(int i=0; i<8; i++){
        connessioni[c.collaborazioni[i][0]][c.collaborazioni[i][1]] = 1;
        connessioni[c.collaborazioni[i][1]][c.collaborazioni[i][0]] = 1;
    }

    for(int i=0; i<6; i++){
        int cont =0;
        for(int j=0; j<6; j++){
            if(i!=j && connessioni[i][j]){
                cont++;
            }
        }
        if(cont == 5 ){
        return i;
        }

    }
    return -1;
    
}

int main(){
    MusicistiCollaborazioni c = {
        .musicisti = {
            {"Mario", "Chitarra"},
            {"Giovanni", "Basso"},
            {"Andrea", "Batteria"},
            {"Giuseppe", "Chitarra"},
            {"Luigi", "Chitarra"},
            {"Simona", "Tastiera"}
        },
        .collaborazioni = {
            {0, 1, 2015, 2019},
            {2, 0, 2017, 2021},
            {1, 5, 2020, 2022},
            {4, 3, 2015, 2018},
            {3, 2, 2019, 2023},
            {5, 2, 2017, 2023},
            {2, 1, 2017, 2023},
            {2, 4, 2018, 2019}
        }
    };

    int *numCollab = numeroCollaborazione(c);
    for(int i=0; i<6; i++){
        printf("%d ", numCollab[i]);
    }

    printf("\n");
    free(numCollab);

    printf("Musicista simile a 4: %d \n", musicistaSimile(c, 4));

    int *durate = durateStrumento(c, "Chitarra");
    for(int i=0; i<8; i++){
        printf("%d ", durate[i]);
    }
    printf("\n");
    free(durate);

    printf("Musicista richiesto: %d\n", musicistaRichiesto(c));


    return 0;
}