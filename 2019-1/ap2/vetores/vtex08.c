// /home/bruno/ulbra/2019-1/ap2/vetores/vtex08.c
// Criado em:dom 24/mar/2019 hs 19:32
/* Propósito: Escreva um programa que leia dois vetores de 10 posições e faça a multiplicação dos elementos de mesmo índice, colocando o resultado em um terceiro vetor. Mostrar o vetor resultante. */
// Cadeira: APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>

int main()
{
	int i, vetA[10], vetB[10], vetC[10];

	for (i = 0; i < 10; i++) {
		printf("Digite um número para o vetor A: \n");
		scanf("%d", &vetA[i]);
	}
	for (i = 0; i < 10; i++) {
		printf("Digite um número para o vetor B: \n");
		scanf("%d", &vetB[i]);
	}
	for (int i = 0; i < 10; i++) {
		vetC[i] = vetB[i] * vetA[i];
		printf("%d x %d = %d\n",vetA[i], vetB[i], vetC[i]);
	}
	return 0;
}
