// /home/bruno/Documentos/ulbra/2019-1/ap2/vetores/vtex07.c
// Criado em:seg 18/mar/2019 hs 16:25
/* Propósito: Escreva um programa em C para ler um vetor A de 10 elementos e um valor X. Copie para um vetor S (sem deixar elementos vazios entre os valores copiados) os elementos de A que são maiores que X. Logo após imprimir o vetor S.*/
// Cadeira: APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>

int main()
{
	int i, realvet[10], menor = 0, 	maior = 0, 	x, indexnew = 0, copvet[10];

	for (i = 0; i < 10; i++) {
		printf("\nDigite um número para o índice [%d]: ", i);
		scanf("%d", &realvet[i]);
		}
			menor = realvet[0];
			for (i = 0; i < 10; i++) {
				if (realvet[i] < menor) {
					menor = realvet[i];
				}	
			}	
			maior = realvet[0];
			for (i = 0; i < 10; i++) {
				if (realvet[i] > maior) {
					maior = realvet[i];
				}
			}
		printf("Informe um valor entre %d e %d: \n", menor, maior);
		scanf("%d", &x);
		for (i = 0; i < 10; i++) {
			if (realvet[i] > x) {
				indexnew++;
			}
		}
		for (i = 0; i < indexnew; i++) {
			if (realvet[i] > x) {
				copvet[i] = realvet[i];
			}
		}
		for (i = 0; i < indexnew; i++){
			printf("Novo índice [%d]: %d \n", i, copvet[i]);
		}
	return 0;
}
