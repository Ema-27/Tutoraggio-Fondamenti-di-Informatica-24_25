/*
    Scrivere un programma C che utilizzando le struct generi un
 tipo punto formato dalle coordinate x e y, e un tipo cerchio formato dal centro(punto) e dal raggio e scrivi una funzione che calcola l'area del cerchio
  e la distanza tra i due punti
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} punto;

typedef struct{
    punto centro;
    float raggio;
} cerchio;

float distanza(punto, punto);
float area(cerchio);

int main(){

    punto p1;
    cerchio C;

    punto *p_punto;
    cerchio *cerchi;

    cerchi = (cerchio*)malloc(10*sizeof(cerchio[0]));
    free(cerchi);

    p1.x = 3.2;
    p1.y = 5.4;

    p_punto = &p1;
    
    printf("L'ascissa di p1 %f \n", (*p_punto).x);

    printf("L'ascissa di p1 %f \n", p_punto->x);

    printf("Inserire il raggio del cerchio: ");
    scanf("%f", &C.raggio);
    C.centro =p1;

    printf("L'area del cerchio è %f \n", area(C));



    return 0;
}

float distanza( punto p1, punto p2){

    // sqrt((p1.x - p2.x)^2 + (p1.y -p2.y)^2)
    float dx = p1.x -p2.x;
    float dy = p1.y - p2.y;

    return sqrt(dx*dx + dy*dy);
}

float area(cerchio c){
    return 3.14 * c.raggio*c.raggio;
}