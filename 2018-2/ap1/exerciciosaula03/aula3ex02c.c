#include "stdio.h"
#include "stdlib.h"

int main(void){

	float a, b, som, sub, mul, div;

	printf("Digite um numero: ");
	scanf("%f", &a);

	printf("digite um outro numero: ");
	scanf("%f", &b);

	som = a+b;
	sub = a-b;
	mul = a*b;
	div = a/b;

	printf("A soma de %f e %f he %f. \n", a, b, som);
	printf("A subtracao de %f e %f he %f.\n", a, b, sub);
	printf("A multiplicacao de %f e %f he %f.\n", a, b, mul);
	printf("A divisao de %f e %f he %f.\n", a, b, div);

	system ("pause");
	return (0);
}
