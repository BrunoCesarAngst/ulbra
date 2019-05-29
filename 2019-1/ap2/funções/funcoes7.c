/* Escreva um programa que leia duas letras em duas variáveis distintas.
 * O programa deve fazer a troca do conteúdo das variáveis. A troca do
 * conteúdo deve ser realizada por uma função chamada troca especificada
 * abaixo:
Nome: Troca
Descrição: Troca o conteúdo de duas variáveis do tipo char.
Entrada: 2 caracteres.
Saída: Os dois caracteres em ordem inversa */

#include <stdio.h>

void troca(char *pri, char *seg){
    char aux;
    aux = *pri;
    *pri = *seg;
    *seg = aux;
}

int main()
{
    char pri, seg;
    printf("\n Digite um caracter: ");
    scanf(" %c", &pri);
    printf("\n Digite outro caracter: ");
    scanf(" %c", &seg);
    troca(&pri, &seg);
    printf("\n Primeiro caracter %c", pri);
    printf("\n Segundo caracter %c", seg);
}
