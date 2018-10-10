#include "stdio.h"
#include "stdlib.h" 

int main(void){

char no [13];
float sal, ns;

printf("Ola, qual he o seu nome? \n");
scanf("%s", &no);

printf("%s, me informe seu salario: ", no);
scanf("%f", &sal);

printf("%s, seu salario de %f tem uma gratificação de 5%, e tem uma desconto de impostos de 7%.\n", no, sal);

ns = (sal + (sal * 5 / 100)) - (sal * 7 / 100);

printf("Seu salario final he de R$%f.\n", ns);

system ("pause");
return (0);
}
