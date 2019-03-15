#include "stdio.h"
#include "stdlib.h" 

int main(void){

float kgsra, gt1, gt2, pordia, em5dia;

printf("Quantos quilos de racao voce comprou? \n");
scanf("%f", &kgsra);

printf("Quantos gramas por dia o gato 01 come? \n");
scanf("%f", &gt1);

printf("Quantos gramas por dia o gato 02 come? \n");
scanf("%f", &gt2);

pordia = gt1 + gt2;

em5dia = kgsra - (pordia * 5);

printf("No quinto dia termos somente %f gramas de racao\n",em5dia);

system ("pause");
return (0);
}
