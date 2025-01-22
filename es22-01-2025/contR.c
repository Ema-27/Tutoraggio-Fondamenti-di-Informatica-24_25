/*
Scrivere una funzione ricorsiva che, dato un array di numeri interi e un valore x, 
conta il numero di elementi nell'array che sono maggiori di x.
*/

#include <stdio.h>

int conta_maggiori(int array[], int n, int x){
    if(n==0)
        return 0;
    return (array[n-1]>x) + conta_maggiori(array, n-1, x);//passo ricorsivo
}

int main(){
    int array[]={5,15,20,25,30};

    int n= sizeof(array)/sizeof(array[0]);
    int x =20;
    printf("Numero di elementi maggiori di %d = %d\n",x, conta_maggiori(array, n, x) );
    return 0;
}