#include<stdio.h>

int main(){
  
  int fatorial, arquivo, resposta = 1;

  printf("Digite um número para fatorar: ");
  scanf("%i", &fatorial);

  arquivo = fatorial;

  for ( ; fatorial >= 1; fatorial--)
  {
    resposta *= fatorial;
  }
  printf("O fatorial de %i!, é %i.\n", arquivo, resposta);  
  
  return 0;
}
