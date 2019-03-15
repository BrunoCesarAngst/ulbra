#include "stdio.h"
#include "conio.h"

int main()
{
	float a , b, c, ma, mh;

	printf ("informe 3 valores reais: \n");
	scanf ("%f", &a);
	scanf ("%f", &b);
	scanf ("%f", &c); 
	ma = (a + b + c) / 3; 
	mh = ((1/a) + (1/b) + (1/c)) / 3; 
	printf ("a mehdia aritmehtica dos valores lidos eh: %f\n", ma); 
	printf("a mehdia harmohnica dos valores lidos eh: %f\n", mh); 

	return 0;
}