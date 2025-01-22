/*
Scrivere una funzione differenzaMassima(int *arr, int n) che restituisce la differenza massima tra due elementi dell'array. 
La differenza è calcolata come |arr[i] - arr[j]| per ogni coppia (i, j).

Esempio:

    Input: arr = [2, 7, 3, 10]
    Output: 8 (|10 - 2| = 8).
*/
#include <stdio.h>

int differenzaMax(int array[], int n){
    int max = array[0], min=array[0];
    for(int i=1; i<n; i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    return max-min;
}

int main(){
    int array[]={2,7,3,10};
    int n=4;
    printf("Differnza massima: %d\n", differenzaMax(array, n));

    return 0;
}