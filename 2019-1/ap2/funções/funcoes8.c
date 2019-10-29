/* Escreva um programa que leia 10 duplas de valores inteiros. Exibir cada
 * dupla em ordem crescente. A ordem deve ser obtida através da chamada da
 * função ClassificaDupla especificada abaixo:
Nome: ClassificaDupla
Descrição: Classifica em ordem crescente 2 valores inteiros.
Entrada: 2 inteiros.
Saída: Os 2 inteiros em ordem crescente.
OBS: A função não deve modificar os valores dos parâmetros de entrada. */

#include <stdio.h>

void classificaDupla(int *x, int *y){
    if (*x < *y) {
        printf("\n A ordem é essa: %d e %d", *x, *y);
    } else if (*x > *y) {
        printf("\n A ordem é essa: %d e %d", *y, *x);
    }
}

int main(int argc, char *argv[])
{
    int x, y;
    for (int i = 0; i < 10; ++i) {
        printf("\n Digite um número: ");
        scanf("%d", &x);
        printf("\n Digite outro número: ");
        scanf("%d", &y);
        classificaDupla(&x, &y);
    }
    return 0;
}
