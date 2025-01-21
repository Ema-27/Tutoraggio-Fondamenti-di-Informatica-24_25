#include <stdio.h>
#include <stdlib.h>

int* valutaOccorrenze(int* L1, int* L2, int nL1, int nL2){
    int *result = (int*)malloc(nL1 *sizeof(int));

    for(int i=0; i<nL1; i++){
        int cont = 0;
        for(int j=0; j<nL2; j++){
            if(L2[j]==L1[i]){
                cont++;
            }
        }
        result[i] = (cont == L1[i]) ? L1[i] : -1;
    }
    return result;
}

int main(){
    int L1[]={2,1,3,5};
    int L2[]={2,4,1,2,5,5,5,6,5,1,4,5};

    int nL1=4;
    int nL2=12;

    int *result= valutaOccorrenze(L1, L2, nL1, nL2);

    for(int i=0; i<nL1; i++){
        printf("%d ", result[i]);
    }

    free(result);


    return 0;
}