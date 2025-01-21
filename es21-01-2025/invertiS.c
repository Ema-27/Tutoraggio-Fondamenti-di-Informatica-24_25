/*
Scrivere una funzione ricorsiva per invertire una stringa.
*/

#include <stdio.h>
#include <string.h>

void invertiStringa(char str[], int start, int end){
    if( start>=end) return;
    //scambia caratteri
    char tmp = str[start];
    str[start]=str[end];
    str[end]=tmp;

    //passo ricorsivo
    invertiStringa(str, start+1, end-1);
}

int main(){
    char str[]= "itopinonavevanonipoti";
    invertiStringa(str, 0, strlen(str)-1);
    printf("Stringa invertita: %s\n", str);

    return 0;
}