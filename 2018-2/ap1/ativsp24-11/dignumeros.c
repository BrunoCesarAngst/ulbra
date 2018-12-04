/* Escrever um algoritmo que leia diversos números, até que o usuário digite algum valor negativo. Ao final (quando o usuário digitar número negativo), imprimir a quantidade de números iguais a ZERO e a soma de todos os números positivos.  */

#include <stdio.h>
main()
{
  int num,
      cont = 0,
      totalPosit = 0;

  do {
    printf("Digite um número inteiro positivo (Negativo encerra): \n");
    scanf("%i", &num);
    if (num == 0) {
      cont++;
    }
    if (num > 0 && (num % 2) == 0) {
      totalPosit += num;
    }
  } while(num >= 0);
  printf("Você digitou %i zeros.\n", cont);
  printf("E a soma dos positivos é %i\n", totalPosit);
}
