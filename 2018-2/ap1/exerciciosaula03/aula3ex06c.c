#include "stdio.h"
#include "stdlib.h" 

int main(void){

float coe, cust;

printf("Quantos coelhos sao: ");
scanf("%f", &coe);

cust = (coe*0.7)/18+10;

printf("Criar %f coelhos, vai ter um custo de %f. \n", coe, cust);

system ("pause");
return (0);
}
