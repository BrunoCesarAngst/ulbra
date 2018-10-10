#include <stdio.h>
#include <conio.h>

int main(){

int cod1, cod2, quan1, quan2;
float vl1, vl2, vtc1, vtc2, vt;

   printf("Qual eh o codigo da primeira peca? \n");
   scanf("%i", &cod1);
   scanf("%i", &cod2);

   printf("\nSao quantas pecas do produto %i? ",cod1);
   scanf("%i", &quan1);
   printf("\nSao quantas pecas do produto %i? ",cod2);
   scanf("%i", &quan2);

   printf("\nQual eh o valor do produto %i? ",cod1);
   scanf("%f", &vl1);
   printf("\nQual eh o valor do produto %i? ",cod2);
   scanf("%f", &vl2);

   vtc1 = quan1 * vl1;
   vtc2 = quan2 * vl2;
   vt = vtc1 + vtc2;

   printf("\nVoce comprou %i unidades do produtos codigo %i no valor de R$%.2f e %i unidades do produtos codigo %i no valor de R$%.2f.", quan1, cod1, vl1, quan2, cod2, vl2);

   printf("\nDando um total de R$%.2f.",vt);

}