// /home/bruno/ulbra/2019-1/ap2/matriz/matriz.c
// Criado em:seg 01/abr/2019 hs 19:32
/* Propósito: Faça um programa que faz a leitura de uma matriz de 3 linhas e 4 colunas. Na matriz devem ser armazenados números inteiros. Após a leitura multiplique cada número da matriz por 10. Escreva a matriz resultante na tela.*/
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>

int main()
{
	int matriz[3][4];
	int l, c, v;
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 4; c++) {
			printf("Digite um número para L[%d] - C[%d]: ", l, c);
			scanf("%d", &v);
			matriz[l][c] = v * 10;
		}
	}
	printf("\n");
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 4; c++) {
			printf("%4.0d", matriz[l][c]);
		}
		printf("\n");
	}

	return 0;
}
