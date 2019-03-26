// /home/bruno/ulbra/2019-1/ap2/vetor_string/strex01.c
// Criado em:seg 25/mar/2019 hs 21:07
/* Propósito: Escreva um programa em C para ler uma palavra e escrever:
-A primeira letra da palavra.
-A última letra da palavra.
-O número de letras existente na palavra.*/
// Cadeira:APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <string.h>

int main()
{
	char palavra[100];
	int tam, letras = 0;

	printf("Escreva algo até cem carateres: \n");
	gets(palavra);

	printf("Você começou a escrever com a letra %c, \n", palavra[0]);

	tam = strlen(palavra);
	printf("... e terminou com a letra %c.\n", palavra[tam - 1]);
	printf("Esse é número de caracteres com espaço: %i.\n", tam);

	for (int i = 0; i < tam; i++) {
		if (palavra[i] != ' ') {
			letras++;
		}
	}
	printf("Esse é número de caracteres sem espaço: %i.\n", letras);

	return 0;
}
