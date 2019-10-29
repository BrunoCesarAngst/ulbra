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
