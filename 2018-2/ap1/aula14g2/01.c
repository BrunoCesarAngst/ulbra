/*1 . Em uma eleição presidencial, existem quatro candidatos. Os votos são informados através de código. Os códigos utilizados são:
•	1,2,3,4 votos para os respectivos candidatos;
•	5 voto em branco;
•	Escreva uma Programa que calcule e imprima:
•	total de votos para cada candidato;
•	total de votos em branco;
Para finalizar o conjunto de votos, tem-se o valor zero.*/

#include <stdio.h>
int main(int argc, char const *argv[]) {
  int candidato, cand1 = 0, cand2 = 0, cand3 = 0, cand4 = 0, nulo = 0;
  do {
    printf("Vote em um desses candidados: 1, 2, 3, 4 ou 5 para votar em branco: \n");
    scanf("%i", &candidato);
    switch (candidato) {
      case 1: cand1++;
              break;
      case 2: cand2++;
              break;
      case 3: cand3++;
              break;
      case 4: cand4++;
              break;
      case 5: nulo++;
              break;
      default: printf("Número incorreto!!\n");
              break;
    }
  } while(candidato != 0);
  printf("O candita 1 fez %i votos\n", cand1);
  printf("O candita 1 fez %i votos\n", cand2);
  printf("O candita 1 fez %i votos\n", cand3);
  printf("O candita 1 fez %i votos\n", cand4);
  printf("Nulos foram %i votos\n", nulo);
  return 0;
}
