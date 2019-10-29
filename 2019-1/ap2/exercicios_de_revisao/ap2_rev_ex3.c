/*Escrever um algoritmo que leia diversos números, até que o usuário digite o valor ZERO.
Ao final (quando o usuário digitar ZERO), imprimir a quantidade de números negativos e a
soma de todos os números positivos.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int resp;
    do {
        printf("Digite un numero: \n");
        scanf(" %d", &resp);
    } while (resp != 0);
    return 0;
}
