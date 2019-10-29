/**
  Faça um programa, que uma matriz seja criada de 4 por 4 contento valor 0 em     todos os campos. O programa deve apresentar o seguinte menu

  Adicionar elemento
    Remover elemento(coloca o valor 0)
    Limpar Matriz
    Mostrar Matriz
    Sair

  Ao pressionar A no menu, o usuário irá informar a linha e coluna e o elemento
    que deseja adicionar. Se já existir um valor na posição o mesmo deve informar   ao usuário para aí sim sobrescrever o valor.
    Ao pressionar R, o usuário deve informar a linha e coluna e o valor deve ser apagado “0”;
    Ao pressionar L, a matriz deve ser “limpa” adicionando o valor 0 em todos os campos\
    Ao pressionar M, o programa deve mostrar a matriz e os valores;
    Ao pressionar S, o programa deve para a execução;
  IMPORTANTE o programa deve validar os índices da matriz e as opções do menu;
*/
#include<stdio.h>

int main()
{
  int matriz[4][4], i, j, linhaA, colunaA, linhaR, colunaR, novoValor, elemento;
  char resp, menu;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matriz[i][j] = 0;
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf(" %d", matriz[i][j]);
    }
    printf("\n");
  }

  do
  {
    printf("Digite uma opção:\n A = Adicionar elemento\n R = Remover elemento\n L = Limpar Matriz\n M = Mostrar Matriz\n S = Sair\n => ");
    scanf(" %c", &resp);

    switch (resp)
      {
      case 'A': case 'a':
        printf("Adicionar um novo elemento\n");
        printf("Informar a linha desejada: ");
        scanf(" %d", &linhaA);
        printf("Informar a coluna desejada: ");
        scanf(" %d", &colunaA);
        printf("Informe o novo elemento: ");
        scanf(" %d", &novoValor);
        elemento = matriz[linhaA][colunaA];
        if (elemento == novoValor) {
          printf("Valor já incluso!\n");
        }        
        matriz[linhaA][colunaA] = novoValor;
        break;

      case 'R': case 'r':
        printf("Informar a linha desejada: ");
        scanf(" %d", &linhaR);
        printf("Informar a coluna desejada: ");
        scanf(" %d", &colunaR);
        matriz[linhaR][colunaR] = 0;
        break;

      case 'L': case 'l':
        for (i = 0; i < 4; i++) {
          for (j = 0; j < 4; j++) {
            matriz[i][j] = 0;
          }
        }
        break;

      case 'M': case 'm':
        for (i = 0; i < 4; i++) {
          for (j = 0; j < 4; j++) {
            printf(" %d", matriz[i][j]);
          }
          printf("\n");
        }
        break;
      
      default:
        break;
      }
      
  } while (resp != 's' && resp != 'S');
  
  return 0;
}
