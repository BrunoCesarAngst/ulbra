// /home/bruno/ulbra/2019-1/ap2/matriz/matrizex07.c
// Criado em:dom 07/abr/2019 hs 21:15
/* Propósito:  Escreva um programa para preencher automaticamente uma matriz de 3 linhas e 5 colunas com números pares diferentes começando pelo número 2. Escreva a matriz preenchida.*/
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define l 3
#define c 5

int main()
{
	float m[l][c];

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			m[i][j] = 1 + (rand()%10);			
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("%4.0f", m[i][j]);			
		}
		printf("\n");
	}

	return 0;
}
