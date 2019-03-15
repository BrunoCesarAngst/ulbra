#include <stdio.h>

/*Escreva um programa que leia e mostre um vetor de 20 elementos inteiros e, a seguir, conte
quantos valores pares existem no vetor.*/

main()
{
	int vet5[5],
		i;


	for(i = 0; i < 5; i++)
	{
	printf("\n Vetor na posição %d: ", i);
	scanf("%d", &vet5[i]);
	}
	for(i = 0; i < 5; i++)
	{
	printf("\n vetor na posição %d : %d", i, vet5[i]);
	}
	

	return 0;

}
