/* Faça um algoritmo que receba o código, o preço de custo e o preço de venda de diversos produtos. Para cada um mostre como resultado o valor do lucro. O último produto a ser lido deve ser o de código 10.*/

#include <stdio.h>

int main() {
int cod = 0;
float cus,
      ven,
      valorLucro,
      totalcus,
      totalven,
      lucroTotal;
  do {
    while (cod < 10) {
      printf("Informe o código do produto: \n");
      scanf("%i", &cod);
      printf("Informe o custo do produto: \n");
      scanf("%f", &cus);
      printf("Informe o valor de venda do produto: \n");
      scanf("%f", &ven);
      valorLucro = ven - cus;
      printf("Lucro do código %i de R$%.2f.\n", cod, valorLucro);
      totalcus += cus;
      totalven += ven;
    }
  } while(cod < 10);
  printf("%.2f", totalcus);
  printf("%.2f", totalven);
  lucroTotal  = totalven - totalcus;
  printf("Lucro total de R$%.2f\n", lucroTotal);
}
