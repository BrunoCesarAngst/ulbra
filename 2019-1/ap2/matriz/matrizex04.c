// /home/bruno/ulbra/2019-1/ap2/matriz/matrizex04.c
// Criado em:dom 07/abr/2019 hs 06:46
/* Propósito: *Escreva um programa que faz a leitura de duas matrizes de 10 linhas e 2 colunas. Cada linha da matriz armazena duas notas de um aluno. A primeira matriz armazena as notas de G1 e a segunda as notas de G2. Após a leitura das duas matrizes calcule a média final de cada um dos alunos e armazene em um vetor de 10 posições. Importante a média das notas é aritmética. Escreva o vetor resultante na tela. Importante: a nota final de G1 é obtida pela média das duas notas da matriz G1. A nota de G2 é obtida pela média das duas notas da matriz de G2. */
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#define l 10
#define c 2

int main()
{
	float g1[l][c], g2[l][c], somaG1[l], somaG2[l], mediaG1[l], mediaG2[l], mediaFinal[l];

	printf("\n");
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("Aluno %d, recebeu a nota %d de G1: ", i + 1, j + 1);
			scanf("%f", &g1[i][j]);
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
			scanf("%f", &g2[i][j]);
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
		mediaFinal[i] = (mediaG1[i] + mediaG2[i]) / 2;
		printf("O aluno %d teve média final: %0.2f \n", i + 1, mediaFinal[i]);
	}

	return 0;
}
