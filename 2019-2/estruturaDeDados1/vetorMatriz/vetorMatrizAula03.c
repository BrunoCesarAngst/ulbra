#include <stdio.h>
#include <string.h>

int main() { 
  char semana[7][8] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado"};
  float resposta[7], temperatura[7], acumulador = 0, media = 0;
  int diasMaisQuentes;
  for (int i = 0; i <= 6; i++) {
    printf("Informe a temperatura de %s: ", semana[i]);
    scanf("%f", &resposta[i]);
    getchar();
    temperatura[i] = resposta[i];
    acumulador = acumulador + temperatura[i];
    media = acumulador / 7;  
  }

  printf("\nA média de temperatura dessa semana foi de %2.1f, por tanto", media);
  printf(" o(s) dia(s) mais quente(s):");
  for (int i = 0; i <= 6; i++) {
    if (temperatura[i] > media) {
      printf("\n%s com %2.1f graus.", semana[i], temperatura[i]);
    }                           
  }
  printf("\n\n");

  return 0;
}
