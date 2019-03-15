#include <stdio.h>

/*Ler os salários dos funcionários de uma empresa.
A cada salário lido o algoritmo deve perguntar ao
usuário se ele deseja continuar (s/n).
Se a resposta for não (n), a leitura de salários
deve ser encerrada. Após, calcular e escrever a
média salarial.*/

int main(){

float sal = 0, total = 0, med = 0;
char resp;
int cont = 0;

	do	{
		printf("Informe seu salários: \n");
		scanf("%f", &sal);
		printf("Desejas continuar?(s/n): \n");
		getchar();
		scanf("%c", &resp);
		total += sal;
		cont++;
	}
	while(resp == 's');
	med = total / cont;
	printf("A média salarial desses %i funcionarior é de %.2f R$.\n", cont, med);
	return 0;
}
