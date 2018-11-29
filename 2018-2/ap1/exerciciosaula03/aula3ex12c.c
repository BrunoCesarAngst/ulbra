#include "stdio.h"
#include "stdlib.h" 

int main(void){

char no[13];
float sal, ns;

printf("Ola, qual he o seu nome? \n");
scanf("%s", &no);

printf("%s, me informe seu salario: \n", no);
scanf("%f", &sal);

printf("%s, seu salario de %f tera um reajuste de 25%.\n", no, sal);

ns = sal + (sal * 25 / 100);

printf("Seu salario passa a ser de R$%f.\n", ns);

system ("pause");
return (0);
}
