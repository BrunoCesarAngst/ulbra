#include <stdio.h>

main(){
int numero;
	printf("Digiti um numero: \n");
	scanf("%i", &numero);
	while(numero > 0){
	printf("%i \n", numero);
	numero--;
}
}
