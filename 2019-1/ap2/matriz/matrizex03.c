// /home/bruno/ulbra/2019-1/ap2/matriz/matizex03.c
// Criado em:sáb 06/abr/2019 hs 16:06
/* Propósito: Faça um programa que leia uma matriz de 4 linhas e 3 colunas. Após a leitura some os valores de cada linha e insira em um vetor de 4 posições ( a soma de cada linha da matiz na posição correspondente do vetor. Escreva a matriz e o vetor resultante na tela. */
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>

int main()
{
	int matriz [4][3];
	int	l, c, soma = 0;
	int somaLinha[4] = {0,0,0,0};

	printf("\n");
	for (int l = 0; l < 4; l++) {
		for (int c = 0; c < 3; c++) {
			printf("Posição lc-(%d, %d): ", l + 1, c + 1);
			scanf("%d", &matriz[l][c]);
			somaLinha[l] += matriz[l][c];
		}
	}
	printf("\n");
	printf("Matriz gerada\n");
	for (int l = 0; l < 4; l++) {
		for (int c = 0; c < 3; c++) {
			printf("%4.0d", matriz[l][c]);
		}
		printf("\n");
	}
	printf("\n");
	printf("A soma das linhas da matriz anterior resulta nesse vetor (");
	for (int l = 0; l < 4; l++) {
		printf("%d ", somaLinha[l]);
	}
	printf(")");

	return 0;
}
