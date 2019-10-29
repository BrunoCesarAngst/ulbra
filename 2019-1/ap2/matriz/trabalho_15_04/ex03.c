#include <stdio.h>

int main()
{
	
	int vet[20], num, i;

	do {
		printf("\n dig num: ");
		scanf("%d", &num);

		if (num % 2 == 0) {
			vet[i] = num;
			i++;
		}
	} while (i >20);

	return 0;
}
