#include <stdio.h>

#define SIZE 8 //dimensione della scacchiera 


int conta_catture(char S[SIZE][SIZE], char c, int i, int j){
    if(S[i][j]!='V'){
        return 0; //la cella non è vuota
    }

    int catture=0;
    int direzione[8][2] ={
        {-1,-1},{-1,0},{-1,1},
        {0,1},         {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    for(int d=0; d<8; d++){
        int x = i+direzione[d][0];
        int y = j+direzione[d][1];
        int cattura_tmp =0;
    

        while(x>=0 && x<SIZE && y>=0 && y<SIZE && S[x][y]!='V' && S[x][y]!=c){
            cattura_tmp++;
            x +=direzione[d][0];
            y +=direzione[d][1];

            if(x>=0 && x<SIZE && y>=0  && y<SIZE && S[x][y]==c){
                catture += cattura_tmp;
            }

        }

    }

    return catture;
}


char vittoria(char S[SIZE][SIZE]){
    int cont_B =0, cont_N=0;

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(S[i][j]=='B'){
                cont_B++;
            }else if(S[i][j]=='N'){
                cont_N++;
            }
        }
    }

    if(cont_B+cont_N == SIZE*SIZE){
        return (cont_B > cont_N) ? 'B' : 'N';
    }

    return 'T';//la partita non è ancora terminata

}

int esiste_mossa_valida(char S[SIZE][SIZE], char c, int k){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(S[i][j]== 'V' && conta_catture(S, c, i, j)>k){
                return 1; //esiste una mossa valida
            }
        }
    }
    return 0;//nessuna mossa valida

}


int mossa(char S[SIZE][SIZE], char c, int i, int j){
    if( S[i][j]!='V' || conta_catture(S, c, i, j)==0){
        return 0;//mossa non valida
    }

    int direzione[8][2] ={
        {-1,-1},{-1,0},{-1,1},
        {0,1},         {0,1},
        {1,-1}, {1,0}, {1,1}
    };

    S[i][j]=c;//posiziono pedina

    for(int d=0; d<SIZE; d++){
        int x = i+direzione[d][0];
        int y = j+direzione[d][1];
        int cattura =0;

         while(x>=0 && x<SIZE && y>=0 && y<SIZE && S[x][y]!='V' && S[x][y]!=c){
            x +=direzione[d][0];
            y +=direzione[d][1];
            cattura++;
         }

         if(x>=0 && x<SIZE && y>=0 && y<SIZE && S[x][j]==c){
            //cambia colore delle pedine catturate
            for(int k=0; k<cattura; k++){
                x -=direzione[d][0];
                y -=direzione[d][1];
                S[x][y]=c;
            }
         }
    }

    return 1;
}


void  stampa_scacchiera(char S[SIZE][SIZE]){
    for(int i=0; i<8;i++){
        for(int j=0; j<8; j++){
            printf("%c ", S[i][j]);
        }
        printf("\n");
    }
}

int main(){

    //scacchiera iniziale
    char S[SIZE][SIZE] = {
        {'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V'},
        {'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V'},
        {'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V'},
        {'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V'},
        {'V', 'V', 'V', 'B', 'B', 'B', 'V', 'V'},
        {'V', 'V', 'B', 'B', 'B', 'B', 'B', 'V'},
        {'V', 'N', 'N', 'N', 'N', 'N', 'N', 'N'},
        {'V', 'V', 'V', 'V', 'V', 'V', 'V', 'V'}
    };

    printf("Scacchiera iniziale: \n");
    stampa_scacchiera(S);

    printf("Risultato: %d\n", conta_catture(S, 'N', 3, 4));

    printf("Risultato: %c\n", vittoria(S));

    printf("Risultato: %d\n", esiste_mossa_valida(S, 'N', 2));

    if(mossa(S, 'N', 3, 4)){
        printf("Mossa valida. Scacchiera aggiornata\n");
        stampa_scacchiera(S);
    }else {
        printf("Mossa non valida\n");
    }

    return 0;
}