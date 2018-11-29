#include "stdio.h"
#include "conio.h"

int main()
{
	int a, b, c;

	printf("informe 3 valores inteiros: \n");
	scanf("%i", &a);
	scanf("%i", &b);
	scanf("%i", &c);
	printf ("o produto dos numero lidos eh: %i\n", a*b*c);
	printf ("a soma dos numero lidos eh: %i\n", a+b+c);
	printf ("a subtracao dos numero lidos eh: %i\n", a-b-c);
	printf ("a soma dos valores anteriores eh: %i\n",(a*b*c)+(a+b+c)+(a-b-c));

	return 0;
}