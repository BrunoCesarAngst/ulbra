// /home/bruno/ulbra/2019-1/ap2/matriz/matrizex02.c
// Criado em:seg 01/abr/2019 hs 20:18
/* Propósito: Faça um programa que faz a leitura de uma matriz de 4 linhas e 4 colunas e um número X. Após a leitura conte quantas vezes o número X aparece na matriz.*/
// Cadeira: APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <string.h>

int main()
{
	int matriz[4][4];
	int l, c, num, cont = 0;
	for (int l = 0; l < 4; l++) {
		for (int c = 0; c < 4; c++) {
			scanf("%d", &matriz[l][c]);
		}
	}

	printf("Digite um número: \n");
	scanf("%d", &num);

	for (int l = 0; l < 4; l++) {
		for (int c = 0; c < 4; c++) {

			if (num == matriz[l][c]) {
				cont++;
			}
		}
	}

	printf("O número %d apareceu %d vezes.\n", num, cont);
	return 0;
}
