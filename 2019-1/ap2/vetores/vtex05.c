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
