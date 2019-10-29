// /home/bruno/Documentos/ulbra/2019-1/ap2/vetores/vtex06.c
// Criado em:seg 18/mar/2019 hs 14:33
/* Propósito: Escreva um programa em C para ler um vetor A de 10 elementos inteiros e um valor X. A seguir imprimir os índices do vetor A em que aparece um valor igual a X.*/
// Cadeira: APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>

main()
{
	int i,
		a[10],
		x;

	for (i = 0; i < 10; i++) {
		printf("Valor A na posição %d: \n", i);
		scanf("%d", &a[i]);
	}
	printf("Digite um valor qualquer: \n");
	scanf("%d", &x);
	for (i = 0; i < 10; i++) {
		if (a[i] == x) {
			printf("O número %d faz parte do Indice A[%d] \n", x, i);
		}
	}
	return 0;
}
