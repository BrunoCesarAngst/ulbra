#include <stdio.h>

/*Escreva um algoritmo para repetir a leitura de uma senha até que ela seja válida.
Para cada leitura da senha incorreta informada escrever a mensagem &quot;SENHA
INVÁLIDA&quot;. Quanto a senha for informada corretamente deve ser impressa a
mensagem &quot;ACESSO PERMITIDO&quot; e o algoritmo encerrado. Considere que a
senha correta é o valor 2016.*/

int main(){

int sh;

  do{
    printf("Senha: ");
    scanf("%i", &sh);
    if (sh != 2016) {
      printf("Senha inválida\n");
    }
  }
  while (sh != 2016); {
    printf("Acesso liberado!\n");
  }
  return 0;
}
