#include <stdio.h>
#include <conio.h>

int main (){

float lt, te, vm, dst;
	
	printf("\nInforme o tempo gasto na viagem: ");
	scanf("%f",&te);

	printf("\nInforme a velocidade media: ");
	scanf("%f",&vm);

	dst = te * vm;
	lt = dst / 12;

	printf("\nForam gastos %.2f litros na viagem",lt);

	return(0);

}