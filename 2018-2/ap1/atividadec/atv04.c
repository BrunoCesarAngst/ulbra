#include "stdio.h"
#include "conio.h"

int main()
{
	int x, y, res;
	float quo;

	printf ("informe 2 valores inteiros\n");
	scanf ("%i", &x);
	scanf ("%i", &y);
	quo = x / y;
	res = x % y;
	printf ("o quociente da divisao de %i por  %i eh %.2f\n", x, y, quo);
	printf ("o resto da divisao de %i por %i eh %.2f\n", x, y, res);

	return 0;
}