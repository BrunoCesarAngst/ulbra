#include <stdio.h>

/* As maçãs custam R$ 0,30 ser forem compradas menos do que uma dúzia, e R$ 0,25 ser forem compradas pelo menos doze. Escreva um programa que leia o número de maçãs compradas, calcule e escreva o valor total da compra.*/

int main()
{

    int unid;
    float tn, td;

    printf("\n São quantas maçãs? ");
    scanf("%d", &unid);

    if (unid < 12) {
        tn = unid * 0.3;
        printf("\n Valor a pagar sem desconto é: R$%0.2f", tn);
    } else if (unid >= 12) {
        td = unid * 0.25;
        printf("\n Comprando 12 ou mais ovos desconto de 5 centavos.");
        printf("\n Valor a pagar com desconto é: R$%0.2f", td);
    }

}
