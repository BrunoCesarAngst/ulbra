#include "stdio.h"
#include "stdlib.h" 

int main(void){

float esp, alt, ndeg;

printf("Qual he a medida dos espelhos da escada? \n");
scanf("%f", &esp);

printf("Qual he a altura da escada? \n");
scanf("%f", &alt);

ndeg = alt / esp;

printf("Esta escada tera %.0f degraus ate o topo.\n", ndeg);

system ("pause");
return (0);
}
