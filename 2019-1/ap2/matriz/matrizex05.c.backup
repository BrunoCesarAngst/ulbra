// /home/bruno/ulbra/2019-1/ap2/matriz/matrizex05.c
// Criado em:dom 07/abr/2019 hs 16:12
/* Propósito: Reescreva o programa do exercício 4 utilizando a média ponderada (G1 peso 1 e G2 peso 2). */
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#define l 2
#define c 2

int main()
{
	float g1[l][c], g2[l][c], somaG1[l], somaG2[l], mediaG1[l], mediaG2[l], mediaFinal[l];

	printf("\n");
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("Aluno %d, recebeu a nota %d de G1: ", i + 1, j + 1);
			scanf(" %f", &g1[i][j]);
			somaG1[i] += g1[i][j];
		}
	}

	printf("\n");
	for (int i = 0; i < l; i++) {
		mediaG1[i] = somaG1[i] / 2;
		printf("O aluno %d teve média de G1: %0.2f \n", i + 1, mediaG1[i]);
	}

	printf("\n");
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("Aluno %d, recebeu a nota %d de G2: ", i + 1, j + 1);
			scanf(" %f", &g2[i][j]);
			somaG2[i] += g2[i][j];
		}
	}
		
	printf("\n");
	for (int i = 0; i < l; i++) {
		mediaG2[i] = somaG2[i] / 2;
		printf("O aluno %d teve média de G2: %0.2f \n", i + 1, mediaG2[i]);
	}
	
	printf("\n");
	for (int i = 0; i < l; i++) {
		mediaFinal[i] = (mediaG1[i] + (mediaG2[i] * 2)) / 3;
		printf("O aluno %d teve média final: %0.2f \n", i + 1, mediaFinal[i]);
	}

	return 0;
}
