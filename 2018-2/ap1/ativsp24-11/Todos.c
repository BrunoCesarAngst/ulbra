#include <stdio.h>

int main()
{

  int numPes,
      opc;
  float valorD;

  printf("São quantas pessoas? ");
  scanf("%i", &numPes);
  printf("Qual é o padrão do Quarto:\n");
  printf("1-Suíte\n");
  printf("2-Quarto de luxo\n");
  printf("3-Quarto conjugado\n");
  printf("4-Quaro Standart\n");
  scanf("%i", &opc);

  switch (opc)
  {
    case 1:
      valorD = numPes * 180;
      printf("A suite para %i pessoa(s), custará %.2f por dia.\n", numPes, valorD);
      break;
    case 2:
      valorD = numPes * 150;
      printf("O Quarto de luxo para %i pessoa(s), custará %.2f por dia.\n", numPes, valorD);
      break;
    case 3:
      valorD = numPes * 130;
      printf("O Quarto conjugado para %i pessoa(s), custará %.2f por dia.\n", numPes, valorD);
      break;
    case 4:
      valorD = numPes * 100;
      printf("O Quarto Standart para %i pessoa(s), custará %.2f por dia.\n", numPes, valorD);
      break;
    default:
      printf("Quarto Inválido!!!\n");
      break;
  }
  return 0;
}
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
