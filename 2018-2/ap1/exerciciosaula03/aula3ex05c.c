#include "stdio.h"
#include "stdlib.h"

int main(void){

	float a, q;

	printf("Me informe um numero: ");
	scanf("%f", &a);

	q = a*a;

	printf("O quadrado do numero he %f. \n", q);

	system ("pause");
	return (0);
}
