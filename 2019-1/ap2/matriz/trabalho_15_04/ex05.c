#include <stdio.h>
#include <string.h>

int main()
{
	
	char st1[40], st2[40];
	int t1, t2, x = 0;

	printf("\n string1: ");
	gets(st1);

	printf("\n string2: ");
	gets(st2);

	t1 = strlen(st1);
	t2 = strlen(st2);

	if (t1 == t2) {
		for (int i = 0; i < t1; i++) {
			if (st1[i] != st2[i]) {
				x = 1;
				break;
			}
		}
	}
	if (t1 == t2 && x == 0) {
		printf("\nstring iguais.");
	} else {
		printf("\n tring diferentes.");
	}

	return 0;
}
