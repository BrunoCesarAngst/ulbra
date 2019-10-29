#include <stdio.h>

/*
Um algoritmo repetida até que o valor informado seja positivo.
Após aceitar apenas valores menores do que o primeiro.
Por último, dividir o primeiro valor pelo segundo.
*/

main() {
float num, num1;
float cal;

  printf("\tIsso é um teste!!!!\n");
  do {
    printf("Digite um número: \n");
    scanf("%f", &num);
    num1 = num; //Reservando o número.
  } while(num < 0); //O número deve ser positivo.
  do {
  printf("Digite outro número: \n");
  scanf("%f", &num);
  if (num < 0 || num < num1) { //Valida como positivo e menor que o primeiro número.
    printf("Teste encerrado.\n");
    cal = num1 / num;
    printf("Dividindo %.2f, por %.2f, teremos esse valor: %.2f\n", num1, num, cal);
  } else {
    printf("Tente novamente!\n");
  }
} while(num >= num1); //O segundo número deve ser menor e diferente do primeiro.
}
