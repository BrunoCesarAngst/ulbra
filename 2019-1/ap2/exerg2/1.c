#include <stdio.h>

void troca(int x, int y){
    int z, aux;
    aux = x;
    x = y;
    y = aux;
    z = 40;
}

void trocaVerdadeira(int *x, int *y, int *z){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
    *z = 40;
}

int soma(int *x, int *y, int *z){
    int aux;
    aux = *x;
    *x = *y;
    *z = 100;
    *y = aux;
    return (*x + *y);
}

int main(void)
{
    int x, y, z;
    x = 200;
    y = 90;
    z = y + 1;
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    printf("z = %d \n", z);

    printf("\n Função falsa trocando os valores de x e y \n");
    troca(x, y);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    printf("z = %d \n", z);


    printf("\n Função verdadeira trocando os valores de x, y e z \n");
    trocaVerdadeira(&x, &y, &z);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    printf("z = %d \n", z);

    printf("\n Função soma reatribuindo os valores de x, y e z \n");
    z = soma(&x, &y, &z);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    printf("z = %d \n", z);

    printf("\n");
}
