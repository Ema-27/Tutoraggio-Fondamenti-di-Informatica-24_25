#include <stdio.h>
#include <stdlib.h>

int contaOccorrenze(int* V, int dim, int num) {
    int count = 0;
    for (int i =0; i < dim; i++)
        if (V[i] == num)
            count++;
    
    return count;
}

int fM(int* V, int dim) {
    int max = -1;
    for (int i = 0; i < dim; i++) {
        int corrente = contaOccorrenze(V, dim, V[i]);
        if (corrente > max)
            max = corrente;
    }

    return max;
}

int* filtraModa(int* L1, int* L2, int dim1, int dim2, int k, int* dimRes) {
    int count = 0;
    for (int i = 0; i < dim1; i++)
        if (contaOccorrenze(L2, dim2, L1[i]) >= fM(L2, dim2) - k)
            count++;

    *dimRes = count;

    int* res = (int*) malloc(*dimRes * sizeof(int));

    int j = 0;

    for (int i = 0; i < dim1; i++)
        if (contaOccorrenze(L2, dim2, L1[i]) >= fM(L2, dim2) - k) {
            res[j] = L1[i];
            j++;
        }
            
    return res;
}

void stampaVettore(int* a, int n) {
    printf("Stampa del vettore di dimensione %d.\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int L1[] = {2, 1, 3, 5};
    int n1 = sizeof(L1) / sizeof(int);
    int L2[] = {2, 2, 1, 2, 5, 5, 5, 6, 5, 1, 4};
    int n2 = sizeof(L2) / sizeof(int);

    int dim;
    int k = 1;

    int* res = filtraModa(L1, L2, n1, n2, k, &dim);

    stampaVettore(res, dim);

    free(res);

    return 0;
}