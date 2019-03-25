#include <stdio.h>

/*Escreva um programa que leia e mostre um vetor de 20 elementos inteiros e, a seguir, conte
quantos valores pares existem no vetor.*/

main()
{
	int vet5[5],
		i,
		cont = 0;


	for(i = 0; i < 5; i++)
	{
	printf("\n Vetor na posição %d: ", i);
	scanf("%d", &vet5[i]);
	}
	for(i = 0; i < 5; i++)
	{
	if(vet5[i]%2 == 0)
	{
	cont++;
	}
	}
	printf("%d são pares", cont);

	return 0;

}
#include <stdio.h>

/*Escreva um programa que leia um vetor de 30 posições de números inteiros e mostre na tela
somente os positivos.*/

main()
{
	int vet5[5],
		i,
		cont = 0;


	for(i = 0; i < 5; i++)
	{
	printf("\n Vetor na posição %d: ", i);
	scanf("%d", &vet5[i]);
	}
	for(i = 0; i < 5; i++)
	{
	if(vet5[i] > 0)
	printf("\n %d é um número positivo.", vet5[i]);
	}

	return 0;

}
#include <stdio.h>

/*Escreva um programa que leia um vetor de 30 posições e encontre e escreva na tela o menor */

main()
{
	int vet5[5],
		i,
		menor;


	for(i = 0; i < 5; i++){
	printf("\n Vetor na posição %d: ", i);
	scanf("%d", &vet5[i]);
	}

	menor = vet5[0];
	for(i = 0; i < 5; i++){
	if(vet5[i] < menor)
	menor = vet5[i];
	}
	printf("\n %d é o menor número.", menor);

	return 0;

}
// /home/bruno/Documentos/ulbra/2019-1/ap2/vetores
// Criado em:qua 13/mar/2019 hs 22:12
// Cadeira: apII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)
/*Ler um vetor de até 10 elementos. A leitura deverá ser executada até que o vetor fique totalmente preenchido ou seja informado um valor negativo ou zero. Calcular e imprimir a soma dos valores maiores que 10 existentes no vetor.*/

#include <stdio.h>

main()
{
	int vet[10],
		i,
		n = 0,
		soma = 0;
	for (i = 0; i < 10; i++) {
		printf("Digite um número: \n");
		scanf("%i", &vet[n]);
		if (vet[n] > 10) {
			soma += vet[n];
		}
		if ((vet[n] < 0) || (vet[n] == 0)) {
			break;
		}
	}
	printf("Soma dos valores maior que 10: %i\n", soma);
	return 0;
}
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
// /home/bruno/ulbra/2019-1/ap2/vetores/vtex08.c
// Criado em:dom 24/mar/2019 hs 19:32
/* Propósito: Escreva um programa que leia dois vetores de 10 posições e faça a multiplicação dos elementos de mesmo índice, colocando o resultado em um terceiro vetor. Mostrar o vetor resultante. */
// Cadeira: APII
// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)

#include <stdio.h>

int main()
{
	int i, vetA[10], vetB[10], vetC[10];

	for (i = 0; i < 10; i++) {
		printf("Digite um número para o vetor A: \n");
		scanf("%d", &vetA[i]);
	}
	for (i = 0; i < 10; i++) {
		printf("Digite um número para o vetor B: \n");
		scanf("%d", &vetB[i]);
	}
	for (int i = 0; i < 10; i++) {
		vetC[i] = vetB[i] * vetA[i];
		printf("%d x %d = %d\n",vetA[i], vetB[i], vetC[i]);
	}
	return 0;
}
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
