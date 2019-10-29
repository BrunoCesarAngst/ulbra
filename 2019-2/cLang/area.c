#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int base;
  int altura;
  int area;
  char formato[11];

  printf("Digite o valor da base (cm): ");
  scanf("%i", &base);
  printf("Digite o valor da altura (cm): ");
  scanf("%i", &altura);

  if (base == altura)
  {
    strcpy(formato, "quadrado");
  } else
  {
    strcpy(formato, "retangulo");
  }
  

  area = base * altura;

  printf("Com base de %i cm e altura de %i cm temos uma %s de área de %i cm\n.", base, altura, formato, area);

  return 0;
}

