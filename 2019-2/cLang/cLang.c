#include <stdio.h>

int main(int argc, char const *argv[])
{
  int base;
  int altura;
  int area;

  printf("Digite o valor da base (cm): ");
  scanf("%i", &base);
  printf("Digite o valor da altura (cm): ");
  scanf("%i", &altura);

  area = base * altura;

  printf("Com base de %i cm e altura de %i cm temos uma retangulo de área de %i cm.", base, altura, area);

  return 0;
}

