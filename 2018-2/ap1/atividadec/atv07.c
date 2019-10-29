#include "stdio.h"
#include "conio.h"

int main()
{
	int a, b, c, d, e;
	float media;

	printf ("informe 5 valores inteiros: \n");
	scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	scanf("%i", &d);
	scanf("%i", &e);
	media = ( a + b + c + d + e);
	printf ("o resultado da mehdia eh: %.2f", media);

	return 0;
}