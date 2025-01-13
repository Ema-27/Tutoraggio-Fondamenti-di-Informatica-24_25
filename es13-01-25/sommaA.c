/*
Calcolare la somma degli elementi di un array.
*/
#include <stdio.h>

int sommaArray(int array[], int n){
    if(n==0)
        return 0;
    return array[n-1]+ sommaArray(array, n-1);
}

int main(){
    int array[]={1,2,3,4,5,6}; 
    int n=sizeof(array)/sizeof(array[0]);
    printf("Somma dell'array: %d \n", sommaArray(array, n));
    return 0;
}