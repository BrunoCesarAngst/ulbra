#include <stdio.h>

int main() {

  int dia, mes, ano;
  do {
    printf("Escreva uma data, dia/mês/ano; (xx/xx/xxxx): \n");
    scanf("%i", &dia);
    scanf("%i", &mes);
    scanf("%i", &ano);
    if (dia == 13 && mes == 02 && ano == 1983) {
      printf("Acesso data válida!\n");
    } else {
      printf("Data inválida!\n");
    }
  } while(dia != 13 && mes != 02 && ano != 1983);
  return (0);
}
