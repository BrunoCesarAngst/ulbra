#include <stdio.h>

int main() {
  int formaPagto;
  float deb, totalDeb = 0, totalCred = 0, cred;
  do {
    printf("\tAtualização financeira\n");
    printf("Informe 1 para débito, 2 para crédito e 0 para sair: \n");
    scanf("%i", &formaPagto);
    switch (formaPagto) {
      case 1:
        printf("Qual é o valor do débito: \n");
        scanf("%f", &deb);
          totalDeb += deb;
      break;
      case 2:
        printf("Qual é o valor do crédito: \n");
        scanf("%f", &cred);
          totalCred += cred;
      break;
      // default:
      //   printf("valor incorreto\n");
      // break;
    }
  } while(formaPagto != 0);
  printf("R$ %.2f de débito.\n", totalDeb);
  printf("R$ %.2f de crédito.\n", totalCred);
  printf("R$ %.2f de saldo.\n", (totalCred -totalDeb));
  return 0;
}
