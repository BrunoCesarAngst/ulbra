#include <stdio.h>

void troca(int x, int y){
    int aux;
    aux = x;
    x =y;
    y = aux;
    printf("\n numero 1: %d", x);
    printf("\n numero 2: %d", y);
}

int main(int argc, char *argv[])
{
    int x, y;
    printf("\n Numero 1: ");
    scanf("%d", &x);
    printf("\n Numero 2: ");
    scanf("%d", &y);
    troca(x, y);
    printf("\n numero 1: %d", x);
    printf("\n numero 2: %d", y);
    return 0;
}
