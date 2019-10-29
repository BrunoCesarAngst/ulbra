/* Escreva um algoritmo para ler o peso de 20 indivíduos (repetição determinada). Calcular e exibir na tela: -A média aritmética das pessoas que possuem mais de 60 Kg. */

#include <stdio.h>
int main() {
  float peso,
        maisDe60,
        pessoas,
        media;
  for (pessoas = 0; pessoas < 20; pessoas++) {
    printf("Qual é o peso? \n");
    scanf("%f", &peso);
    if (peso > 60) {
      maisDe60++;
    }
  }
  media = maisDe60 / pessoas;
  printf("A cada 20 pessoas, em média %.2f pessoas então acima 60 Kg.\n", media);
}
