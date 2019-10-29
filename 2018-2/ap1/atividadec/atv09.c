#include "stdio.h"
#include "conio.h"

int main()
{
	float salfixo, comissao, salfinal;
	int n_func, n_carros;

	printf( "informe o nunero do vendedor: ");
	scanf ("%i", &n_func );
	printf( "informe o nunero de carros vendidos: ");
	scanf ("%i", &n_carros );
	printf( "informe o salario fixo: ");
	scanf ("%f", &salfixo );
	printf( "informe o valor da comissao por carro: ");
	scanf ("%f", &comissao );
	salfinal = salfixo + n_carros * comissao;
	printf ("\no funcionario de codigo:  %i", n_func);
	printf ("\nterah salario final de r$ %.2f", salfinal);

	return 0;
}