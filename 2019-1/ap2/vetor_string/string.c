// /home/bruno/ulbra/2019-1/ap2/vetor_string/string.c
// Criado em:seg 25/mar/2019 hs 19:57
/* Propósito: */
// Cadeira:
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>
#include <string.h>

int main()
{
	char teste[50];
	int tam, i, cont = 0, conta = 0;

	printf("Digite uma frase:\n");
	gets(teste);
	tam = strlen(teste);
	printf("Você digitou %d carateres\n",tam);

	for (int i = 0; i < tam; i++) {
		if (teste[i] == ' ') {
			cont++;
		}
		if (teste[i] == 'A' || teste[i] =='a') {
			conta++;
		}
	}
	printf("Sua frase tem %d letra(s) A(s) e %d espaços,\n", conta, cont);

	return 0;
}
