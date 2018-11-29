#include <stdio.h>
#include <conio.h>

int main(){

float a, b, soma, sub, mul, divi;

   printf("Digite um valor para a: ");
   scanf("%f", &a);
   printf("Digite um valor para b: ");
   scanf("%f", &b);
   
   soma = a + b;
   sub = a - b;
   mul = a * b;
   divi = a / b;

   printf("\nx = a + b _ %.1f + %.1f = %.1f ", a, b, soma);
   printf("\nx = a - b _ %.1f - %.1f = %.1f ", a, b, sub);
   printf("\nx = a * b _ %.1f * %.1f = %.1f ", a, b, mul);
   printf("\nx = a / b _ %.1f / %.1f = %.1f ", a, b, divi);

}