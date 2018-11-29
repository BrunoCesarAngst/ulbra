#include "stdio.h"
#include "stdlib.h" 

int main(void){

float nt1, nt2, nt3, mp;

printf("Informe sua nota do primero quadrimestre: ");
scanf("%f", &nt1);

printf("Esse quadrimestre tem peso 2.\n");

printf("Informe sua nota do segundo quadrimestre: ");
scanf("%f", &nt2);

printf("Esse quadrimestre tem peso 4.\n");

printf("Informe sua nota do terceiro quadrimestre: ");
scanf("%f", &nt3);

printf("Esse quadrimestre tem peso 6.\n");

mp = (((nt1*2) + (nt2*4) + (nt3*6))/12);

printf("Sua media ponderada he %f.\n", mp);

system ("pause");
return (0);
}
