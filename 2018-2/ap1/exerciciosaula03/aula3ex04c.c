#include "stdio.h"
#include "stdlib.h"

int main(void){

	float a, b, area;

	printf("Oi, vamos calcular a area de um triangulo, informe em metros a medida de base: ");
	scanf("%f", &b);

	printf("Agora preciso da medida em metros, da altura do triangulo: ");
	scanf("%f", &a);

	area = (a*b)/2;

	printf("A area he %f m2. \n", area);

	system ("pause");
	return (0);
}
