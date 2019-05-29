/*Escreva um programa para ler 5 números inteiros positivos (utilize a
 * função LePositivo). Para cada valor lido escrever a soma dos inteiros
 * de 1 ao número informado. O resultado do cálculo desse somatório deve
 * ser obtido através da função Somatorio.
Nome: LePositivo
Descrição: Faz a leitura de um valor. Se ele for negativo ou zero, a leitura
deve ser repetida até que o valor lido seja positivo.
Entrada: Nenhuma.
Saída: (int) o valor lido.
Nome: Somatorio
Descrição: Calcula o somatório dos inteiros de 1 ao número fornecido como entrada.
Entrada: (int) Número limite do somatório.
Saída: (int) O valor do somatório.*/

#include <stdio.h>

float lePositivo(){
    float num;
    do {
        printf("\n Digite um número: ");
        scanf("%f", &num);
        getchar();
        if (num <= 0) {
            printf("\n Digite um número positivo maior que 0 (zero)!");
        }
        if (num != (int)num) {
            printf("\n Digite um número inteiro!");
        }
    } while (num <= 0 || num != (int)num);
    return num;
}

float somatorio(float num){
    float i, soma = 1;
    for (i = 1; i < num; ++i) {
        soma += i + 1;
    }
    return soma;
}

int main()
{
    int somaTo = 0, n;
    for (int i = 0;  i < 5; ++i) {
        n = lePositivo();
        somaTo = somatorio(n);
        printf("\n O somatório é %d", somaTo);
    }
}

