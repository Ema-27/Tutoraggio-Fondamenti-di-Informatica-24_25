/*
Si scriva un programma che attraverso la funzione random resituisca la frequenza dei primi 6 numeri
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int freq1=0;
    int freq2=0;
    int freq3=0;
    int freq4=0;
    int freq5=0;
    int freq6=0;

    srand(time(NULL));
    for(int i=0; i<500; ++i){
        
        int f_i = 1+rand()%6;

        switch (f_i) {
            case 1:
                ++freq1;
                break;
            case 2:
                ++freq2;
                break;
            case 3:
                ++freq3;
                break;
            case 4:
                ++freq4;
                break;
            case 5:
                ++freq5;
                break;
            case 6:
                ++freq6;
                break;

        }
    }

    printf("1: %d\n", freq1);
    printf("2: %d\n", freq2);
    printf("3: %d\n", freq3);
    printf("4: %d\n", freq4);
    printf("5: %d\n", freq5);
    printf("6: %d\n", freq6);
    return 0;
}