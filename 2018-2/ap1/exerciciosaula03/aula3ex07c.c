#include "stdio.h"
#include "stdlib.h" 

int main(void){

float pc, pv, lc;

printf("O preco de custo desse produto he de R$: ");
scanf("%f", &pc);

printf("Vendendo esse produto por R$: ");
scanf("%f", &pv);

lc = pv - pc;

printf("Lucrarei com essa venda R$ %f. \n", lc);

system ("pause");
return (0);
}
