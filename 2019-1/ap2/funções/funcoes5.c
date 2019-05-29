/*Escreva um programa em C para ler 5 pares de valores (considere que serão informados apenas valores positivos). Para cada par lido deve ser impresso o valor do maior   elemento do par ou a frase "Eles são iguais" se os valores do par forem iguais. Para obter o maior elemento do par utilize a função MaiorNumero.
Nome: MaiorNumero
Descrição: Retorna o maior elemento entre 2 valores positivos. Se eles forem iguais deve ser retornado o valor -1.
Entrada: (int) Dois valores positivos.
Saída: (int) O maior deles ou -1 se eles forem iguais.
Obs: Considere que os valores de entrada são sempre positivos.*/

#include <stdio.h>

void maiorNumero(int x, int y){
    if (x == y) {
        printf("\n São números iguais!");
    } else if (x < y) {
        printf("\n O maior número é %d", y);
    } else {
        printf("\n O maior número é %d", x);
    }
}

int main(int argc, char *argv[])
{
    int i, x, y;
    for (i = 0; i < 5; ++i) {
        printf("\n Digite um primeiro número: ");
        scanf("%d", &x);
        printf("\n Digite um primeiro número: ");
        scanf("%d", &y);
        maiorNumero(x, y);
    }
    return 0;
}
