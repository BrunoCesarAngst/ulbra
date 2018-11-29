#include "stdio.h"
#include "stdlib.h" 

int main(void){

int n1, n2, rd;

printf("Me informe um numero: ");
scanf("%d", &n1);

printf("Me informe outro numero: ");
scanf("%d", &n2);

rd = n1 % n2;

printf("O resto da divisao entre %d e %d he %d. \n", n1, n2, rd);

system ("pause");
return (0);
}
