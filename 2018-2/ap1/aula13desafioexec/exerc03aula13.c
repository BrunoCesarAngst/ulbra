#include <stdio.h>

int main() {
  int idade, maisVelho = 0, entrevistados = 0, bomSal = 0;
  float sal, totalSal = 0, medSal;
  char genero,resp;
  do {
    printf("A sua idade: ");
    scanf("%i", &idade);
      if (idade > maisVelho) {
        maisVelho = idade;
      }
    printf("Qual é o seu salário atual: ");
    scanf("%f", &sal);
      totalSal += sal;
      do {
        printf("Seu genero(F-M): ");
        scanf(" %c", &genero);
      } while ((genero != 'M') && (genero != 'm') && (genero != 'F') && (genero != 'f'));
      if ((genero == 'f' || genero == 'F') && (sal > 4999)) {
        bomSal++;
      }
    do {
      printf("\n\nTem mais alguém para ser entrevistado?(S-N): ");
      scanf(" %c", &resp);
    } while ((resp != 'S') && (resp != 's') && (resp != 'N') && (resp != 'n'));
    entrevistados++;
  } while((resp != 'N') && (resp != 'n'));
  medSal = totalSal / entrevistados;
  printf("A média salarial é de R$ %.2f per capita.\n", medSal);
  printf("O entrevistado de maior idade tem %i anos\n", maisVelho);
  printf("%i é o número de mulheres, com salário superior a R$ 5.000,00.\n", bomSal);
  return 0;
}
