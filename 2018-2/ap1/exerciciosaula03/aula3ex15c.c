#include "stdio.h"
#include "stdlib.h" 

int main(void){

int dn, aa, ia, ifut;

printf("Ola, em qual ano voce nasceu? \n");
scanf("%d", &dn);

printf("Em qual ano estamos? \n");
scanf("%d", &aa);

ia = aa - dn;

ifut = 2050 - dn;

printf("Seu idade he %d anos, e no ano de 2050 voce tera %d anos.\n", ia, ifut);

system ("pause");
return (0);
}
