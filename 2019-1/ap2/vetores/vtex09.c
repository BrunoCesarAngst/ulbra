// /home/bruno/ulbra/2019-1/ap2/vetores/vtex09.c
// Criado em:seg 25/mar/2019 hs 14:52
/* Propósito:Escreva um programa em C para ler um vetor X de 10 elementos inteiros. Logo após copie os elementos do vetor X para um vetor Y fazendo com que o 1o. elemento de X seja copiado para o 10o. de Y, o 2o. de X para o 9o. de Y e assim sucessivamente. Após o término da cópia, imprimir o vetor Y. */
// Cadeira: APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
 int main()
 {
 	int i, vetx[3];
		
 	for (i = 0; i < 3; i++) {
		printf("Digite um número: ");
		scanf("%d", &vetx[i]);
		getchar();
	}
	for (i = 3; i >= 1; i--) {
		printf("%d\n", vetx[i]);
	}
 	return 0;
 }
