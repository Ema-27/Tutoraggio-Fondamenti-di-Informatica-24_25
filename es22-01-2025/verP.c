/*
Scrivere una funzione ricorsiva che verifica se un array di numeri interi è palindromo 
*/

#include <stdio.h>

int is_palindromo(int array[], int start, int end){
    if(start>=end) return 1;
    if(array[start] != array[end])
        return 0;//elementi non uguali
    return is_palindromo(array, start +1, end -1);
}

int main(){
    int array[]={1,2,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    if(is_palindromo(array, 0, n-1)){
        printf("l'array è palindromo\n");
    }else{
        printf("L'array non è palindromo\n");
    }
    return 0;
}