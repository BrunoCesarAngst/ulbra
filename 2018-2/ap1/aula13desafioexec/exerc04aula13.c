#include <stdio.h>

int main() {
  float contador = 0, cobaia = 0, rato = 0, coelho = 0, totalRato = 0, totalCoe = 0, porc = 0, porc2 = 0;
  do {
    printf("Qual tipo de animal vai ser a cobaia (1-Rato ou 2-coelho): \n");
    scanf("%f", &cobaia);
    if (cobaia == 1) {
      printf("Quantos ratos será usado? \n");
      scanf("%f", &rato);
      totalRato += rato;
    }
    if (cobaia == 2) {
      printf("Quantos coelhos será usado? \n");
      scanf("%f", &coelho);
      totalCoe += coelho;
    }
    contador++;
  } while (contador < 2);
  // printf("Forão usados %.0f ratos.\n", totalRato);
  // printf("Foram usados %.0f coelhos.\n", totalCoe);
  printf("Total de cobaias: %.0f\n", (totalRato + totalCoe));
  porc = (totalRato / totalCoe) * 100;
  printf("%.0f%% são ratos.\n", porc);
  printf("%.0f%% são coelhos.\n", 100 - porc);
  return (0);
}
