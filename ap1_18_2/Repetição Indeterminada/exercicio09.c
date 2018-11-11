#include <stdio.h>

/*Faça um algoritmo que leia um número inteiro e divida-o por dois
(sucessivamente) ate que o resultado seja menor que 1. Mostre o resultado da
ultima divisão e a quantidade de divisões efetuadas.*/

int main(){

float num, cont;

printf("Digite um número: \n");
scanf("%f",&num);

do {
  printf("\n%.f", num/2);
  num=num/2;
  cont++;
} 
while(num > 1);
  printf("\n%.f \n", num/2);

return 0;
}
