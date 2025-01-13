/*
    Calcolare la somma delle cifre di un numero //123456
*/

#include <stdio.h>

int sommaCifre(int n){
    if(n==0)
        return 0;
    return n %10 + sommaCifre(n/10);
}


int main(){
    int n; 
    printf("Insersici il numero: ");
    scanf("%d", &n);

    printf("Somma della cifre: %d \n", sommaCifre(n));
    return 0;
}