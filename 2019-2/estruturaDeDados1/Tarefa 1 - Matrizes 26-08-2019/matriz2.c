/**
    Faça um programa, que uma matriz seja criada de 3 por 3, essa Matriz representa um estacionamento. Crie uma Classe para representar um veículo, com placa modelo e cor.

  O programa deve apresentar o seguinte menu:
    Adicionar Carro
    Remover Carro(coloca o valor null)
    Limpar Estacionamento
    Mostrar Estacionamento
    Sair

    Ao pressionar A no menu, o usuário irá informar a linha e coluna e o carro que deseja adicionar.
    Se já existir um carro na posição o mesmo deve informar ao usuário para aí sim sobrescrever o valor.
    Ao pressionar R, o usuário deve informar a linha e coluna e o valor deve ser apagado “0”;
    Ao pressionar L, a matriz deve ser “limpa” adicionando o valor 0 em todos os campos
    Ao pressionar M, o programa deve mostrar a matriz e os valores;
    Ao pressionar S, o programa deve para a execução;
    IMPORTANTE o programa deve validar os índices da matriz e as opções do menu;
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define v 1

struct carro
{
  char placa[8];
  char cor[12];
};

char cria_matriz(/*char placa, char cor */){
  struct carro dados[9];
  int matriz[9], i;

  for (i = 0; i < 9; i++)
  {
    printf("placa: ");
    scanf(" %s", dados->placa[i]);
    printf("cor: ");
    scanf(" %s", dados->cor[i]);
  }
  
}

// mostrar_matriz(int matriz[3][3]){

//   int l = 0, c = 0;

//   for(l = 0; l < 3; l++){
//     for(c = 0; c < 3; c++){
//       printf("%d", matriz[l][c]);
//     }
//     printf("\n");
//   }
// }

// limpar_matriz(int matriz[3][3]){

//   int l = 0, c = 0;

//   for(l = 0; l < 3; l++){
//     for(c = 0; c < 3; c++){
//       matriz[l][c] = 0;
//     }
//   }
// }

int main()
{
  cria_matriz();
  
  return 0;
}
