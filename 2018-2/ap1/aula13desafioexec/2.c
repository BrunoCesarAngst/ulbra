#include <stdio.h>
int main() {
  float valor,
        novoValor = 0,
        maiorValor = 0,
        med;
  char resp;
  int venDiaria = 0;
  do {
    printf("Qual é valor? \n");
    scanf(" %f", &valor);
    novoValor += valor;
    venDiaria++;
    if (valor > maiorValor) {
      maiorValor = valor;
    }
    do {
      printf("\nOutra Venda?(S-N): ");
      scanf(" %c", &resp);
    } while ((resp != 'S') && (resp != 's') && (resp != 'N') && (resp != 'n'));
  } while((resp != 'N') && (resp != 'n') && (venDiaria <= 200));
  printf("Número de vendas = %d\n", venDiaria);
  printf("Total de vendas = R$%.2f\n", novoValor);
  med = (float)(novoValor / venDiaria);
  printf("Média de vendas = R$%.2f\n", med);
  printf("Venda de maior valor = R$%.2f\n", maiorValor);
}
