#include "stdio.h"
#include "stdlib.h"

int main(void){

	float nf, ht, vh, vt;

	printf("Quantos funcionarios sao? \n");
	scanf("%f", &nf);

	printf("Quantas horas eles trabalharam? \n");
	scanf("%f", &ht);

	printf("Quanto e o valor por hora? \n");
	scanf("%f", &vh);

	vt = nf*ht*vh;

		printf("Seus %f funcionarios, vao receber R$ %f\n", nf, vt);

	system ("pause");
	return (0);
}