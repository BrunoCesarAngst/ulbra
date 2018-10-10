#include "stdio.h"
#include "stdlib.h" 

int main(void){

float vp, desc, vdesc;

printf("Qual he o valor do produto? \n");
scanf("%f", &vp);

printf("Informe o percentual de desconto: \n");
scanf("%f", &desc);

vdesc = vp - (vp * desc / 100);

printf("O produto de R$%f, com o desconto de %f%, saira por R$%f.\n", vp, desc, vdesc);

system ("pause");
return (0);
}
