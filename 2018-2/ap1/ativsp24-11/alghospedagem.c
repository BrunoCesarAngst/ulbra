#include <stdio.h>
int main(){
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
