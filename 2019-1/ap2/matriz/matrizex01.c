// /home/bruno/ulbra/2019-1/ap2/matriz/matriz.c
// Criado em:seg 01/abr/2019 hs 19:32
/* Propósito: matrizes */
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <string.h>

int main()
{
	int matriz[3][4];
	int l, c, v;
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 4; c++) {
			scanf("%d", &v);
			matriz[l][c] = v * 10;
		}
	}
	for (int l = 0; l < 3; l++) {
		for (int c = 0; c < 4; c++) {
			printf("%4.0d", matriz[l][c]);
		}
		printf("\n");
	}

	return 0;
}
