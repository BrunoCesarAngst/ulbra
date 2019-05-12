#include <stdio.h>

int main()
{
	float valor,
		  total = 0,
		  maiorvenda = 0;
	int x,
		numero = 0;
	char outra;

for(x = 1; x <= 200; x++)
	printf("\n Qual eh o valor da venda? ");
	scanf("%f", &valor);
	total += valor;
	numero ++;
	if(valor > maiorvenda)
		maiorvenda = valor;
	_fpurge(stdin);

	printf("Outra venda (S/N)? ");
	scanf("%s", &outra);
    if(outra == "N" || outra == "n")
		{
         printf("\n Venda encerrada!");
		 break;
		}

}
