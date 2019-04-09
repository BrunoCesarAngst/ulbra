// /home/bruno/ulbra/2019-1/ap2/matriz/matrizex06a.c
// Criado em:dom 07/abr/2019 hs 22:40
/* Propósito:  Escreva um programa que leia uma matriz de 5 linhas e 3 colunas de números inteiros. Faça uma validação de entrada de dados para aceitar somente números impares. Ao final da leitura escreva a matriz resultante na tela.*/
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <string.h>
#define l 2
#define c 2

int main()
{
	int aux = 0, m[l][c], mresul[l][c], a;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("\n Digite números impares: ");
			scanf("%d", &m[i][j]);
			aux = m[i][j] % 2;
			if (aux != 0) {
				mresul[i][j] = m[i][j];
			} else {
				a = aux;
				printf("\n Digite somente impares!!!");
			}
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("%3.0d", mresul[i][j]);
		}
		printf("\n");
	}

	return 0;
}
