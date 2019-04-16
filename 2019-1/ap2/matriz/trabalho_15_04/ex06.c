#include <stdio.h>
#include <string.h>

int main()
{
	int v1[10], v2[10], v3[20];

	for (int i = 0; i < 10; i++) {
		printf("\n v1[%d]: ", i);
		scanf("%d", &v1[i]);

		v3[i] = v1[i];
	}
	for (int i = 0; i < 10; i++) {
		printf("\n v2[%d]: ", i);
		scanf("%d", &v2[i]);

		v3[i + 10] = v2[i];
	}
	for (int i = 0; i < 20; i++) {
		printf("\n v3[%d]: %d", i, v3[i]);
	}

	return 0;
}
