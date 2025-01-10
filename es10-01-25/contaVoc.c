/*
Si scriva una funzione che conti le vocali di una stringa
*/
#include <stdio.h>
#include <string.h>

int contaVocali(char str[]){
    int count =0;
    for(int i = 0; str[i] != '\0'; i++){
        char c = str[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ){
                count++;
            }
    }
    return count;
//aeiou AEIOU
}

int main(){
    char stringa[100];
    printf("Inserisci una stringa: ");
    scanf("%s", stringa);

    //int n = strlen(stringa);
    int n = sizeof(stringa) / sizeof(stringa[0]);
    printf("La dimensione della stringa è: %d\n", n);

    printf("La stringa contiene %d vocali \n", contaVocali(stringa));
    return 0;
}