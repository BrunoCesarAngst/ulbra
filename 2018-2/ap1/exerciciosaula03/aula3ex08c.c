#include "stdio.h"
#include "stdlib.h" 

int main(void){

float pp, qp, vt;

printf("O preco do produto he de R$: ");
scanf("%f", &pp);

printf("Quantos esta levando? ");
scanf("%f", &qp);

vt = pp*qp;

printf("%f unidades a R$ %f/cada, vai lhe custar um total de R$ %f. \n", pp, qp, vt);

system ("pause");
return (0);
}
