#include <stdio.h>

/*Faça um programa que exiba um menu para o usuário com 4 opções de cores:
1- Azul; 2- Preto; 3- Rosa; 4- Vermelho
E solicite que ele escolha uma cor. Enquanto ele digitar números inválidos do
menu, exiba uma mensagem de erro e solicite que informe um novo valor.*/

int main() {
int i;
	do{
		printf("\tEscolha uma opção de cor:\n");
		printf("\t1 - Azul -\n");
		printf("\t2 - Preto -\n");
		printf("\t3 - Rosa -\n");
		printf("\t4 - Vermelho -\n");
		printf("Escolha um numero: ");
		scanf("%i", &i);
		switch (i)
		{
			case 1:
			printf("Você escolheu a cor Azul\n");
			break;
			case 2:
			printf("Você escolheu a cor Preto\n");
			break;
			case 3:
			printf("Você escolheu a cor Rosa\n");
			break;
			case 4:
			printf("Você escolheu a cor Vermelho\n");
			break;
			default:
			printf("Operação inválida\n");
		}
	}while(i < 1 || i > 4);
	return (0);
}
