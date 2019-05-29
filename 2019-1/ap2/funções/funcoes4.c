/*Escreva um programa em C que leia 5 valores inteiros e imprima para cada um o seu
correspondente valor absoluto. Para obter o valor absoluto do número utilize a função
Absoluto especificada abaixo:
Nome: Absoluto
Descrição: Retorna o valor absoluto do número fornecido.
Entrada: int n
Saída: (int) O respectivo valor absoluto de n.
Obs:
-O valor absoluto de 10 é 10.
-O valor absoluto de -10 é 10.*/

#include <stdio.h>

int absoluto(int x){
    if (x < 0) {
        x = x * -1;
        return(x);
    }
}

int main(int argc, char *argv[])
{
    int i, y, x;

    for (i = 0; i < 5; ++i) {
        printf("\n Digite um número: ");
        scanf("%d", &x);
        y = absoluto(x);
        printf("\n O valor absoluto é %d", y);
    }
    return 0;
}

