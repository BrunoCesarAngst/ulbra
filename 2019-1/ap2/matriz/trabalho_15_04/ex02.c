#include <stdio.h>

int main()
{
	int i, x[10], y[10], j = 9;

	for (int i = 0; i < 10; i++) {
		printf("\n Digite x[%d]", i);
		scanf("%d", &x[i]);
		y[j] = x[i] + 10;
		j--;
	}
	for (int i = 0; i < 10; i++) {
		printf("\n y[%d]: %d", i, y[i]);
	}
	return 0;
}
