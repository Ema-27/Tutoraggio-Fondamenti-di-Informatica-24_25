/*
Scrivi una funzione sommaMultipli(int *arr, int n, int k) che riceve in ingresso un array di interi arr di lunghezza n e un numero intero k. 
La funzione restituisce la somma di tutti gli elementi di arr che sono multipli di k.

Input: arr = [3, 6, 8, 12], n = 4, k = 3
    Output: 21

*/

#include <stdio.h>

int sommaMultipli(int* arr, int n, int k){
    int somma=0;

    for(int i=0; i<n; i++){
        if(arr[i]%k==0){
            somma+=arr[i];
        }
    }

    return somma;
}

int main(){

    int arr[] = {3,6,8,12};
    int n =4, k=3;

    printf("Somma dei multipli di %d: %d \n", k, sommaMultipli(arr, n, k));
    return 0;
}