// /home/bruno/ulbra/2019-1/ap2/matriz/matrizex06.c
// Criado em:dom 07/abr/2019 hs 16:56
/* Propósito:  Escreva um programa que leia uma matriz de 5 linhas e 3 colunas de números inteiros. Faça uma validação de entrada de dados para aceitar somente números impares. Ao final da leitura escreva a matriz resultante na tela.*/
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <string.h>
#define l 2
#define c 2

int main()
{
	int num, teste = 0, aux = 0, m[l][c] = {0,0,0,0}, cont = 0;

	do {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("\n Digite números impares: ");
			scanf("%d", &num);
			teste = num % 2;
			printf("\ntete = %d", teste);
			if (teste != 0) {
				aux = teste;
				cont++;
			}else {
				printf("\n Digiti um número impar!");
			}
			m[i][j] = aux;
			printf("\nmatriz %d", m[i][j]);
			printf("\naux = %d", aux);
		}
	}
	} while (teste == 0 || cont < 4);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++) {
			printf("%2.0d", m[i][j]);
		}
		printf("\n");
	}

	return 0;
}
