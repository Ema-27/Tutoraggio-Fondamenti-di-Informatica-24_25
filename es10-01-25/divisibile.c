/*
Si scriva una funzione che determina quali numeri di una lista sono divisibili per un intero dato
*/

#include <stdio.h>

void divisibili(int lista[], int n, int divisore){
    printf("Numeri divisibili per %d: ", divisore);
    for(int i=0; i<n; i++){
        if(lista[i]%divisore==0){
            printf("%d ", lista[i]);
        }
    }
    printf("\n");
}

int main(){
    int lista[] = {2, 4, 5, 8, 10, 15};
    int n = sizeof(lista)/sizeof(lista[0]);

    int divisore = 0;
    printf("Inserisci il divisore: ");
    scanf("%d", &divisore);

    divisibili(lista, n, divisore);

    return 0;
}