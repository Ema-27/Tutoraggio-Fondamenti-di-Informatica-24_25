/*
Calcolare la potenza a^b utilizzando la ricorsione.
b=4
a*a*a*a
*/
#include <stdio.h>
int potenza(int a, int b){
    if(b==0)
        return 1;
    return a* potenza(a, b-1); //passo ricorsivo
}

int main(){
    int a =2, b=3;
    printf("%d^%d = %d\n", a, b, potenza(a, b));

    return 0;
}