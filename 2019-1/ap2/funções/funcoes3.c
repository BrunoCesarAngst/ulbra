#include <stdio.h>

void troca(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    int x, y;
    printf("\n Numero 1: ");
    scanf("%d", &x);
    printf("\n Numero 2: ");
    scanf("%d", &y);
    troca(&x, &y);
    printf("\n numero 1: %d", x);
    printf("\n numero 2: %d", y);
}
