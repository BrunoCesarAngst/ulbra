#include<stdio.h>
#define v 5

int main()
{
	int vetor[v];

    printf("\n Coletando números para o vetor!!! \n");

	for (int i = 0; i < v; i++)
	{
		printf("\n Digite um número inteiro: ");
		scanf("%d", &vetor[i]);
	}

    printf("\n Imprimindo o vetor!!! \n");
    printf("\n");

	for (int i = 0; i < v; i++)
	{
		printf("%d ", vetor[i]);
	}

    printf("\n");

	return 0;
}

