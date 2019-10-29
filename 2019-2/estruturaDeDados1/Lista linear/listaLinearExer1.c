/* Com base na TDA e sugestão de implementação apresentada em aula, crie um programa com o seguinte menu.
1 - Criar lista
2 - Inserir no final
3 - Excluir do final
4- Apagar lista
5- Sair
Após a execução de cada operação o menu deve ser apresentado novamente. Quando a opção 5 for escolhida o programa deve ser encerrado */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct lista{
  int FL;
  int dados[MAX];

};
typedef struct lista Lista;

Lista* Cria_lista(void){
  Lista* pt = (Lista*)malloc(sizeof(Lista));
  if(pt != NULL){
    pt->FL = 0;
  }
  return pt;
}

Lista* Insere_elem_final(Lista* Ptl, int elem){
  if (Ptl == NULL || Ptl->FL == MAX)
  return Ptl;
  Ptl->dados[Ptl->FL] = elem;
  Ptl->FL++;
  return Ptl;
}

Lista* Remove_elem_final(Lista* Ptl, int elem){
  if (Ptl == NULL || Ptl->FL == MAX)
  return Ptl;
  Ptl->dados[Ptl->FL] = elem;
  Ptl->FL++;
  return Ptl;
}

int main(){

  int op;

  printf("\n");
  printf("1 - Criar lista\n2 - Inserir no final\n3 - Excluir do final\n4- Apagar lista\n5- Sair\n=> ");
  scanf("%d", &op);

  switch (op){
    case 1:
      Lista* Cria_lista(void);
      break;
    case 2:
      Lista* Insere_elem_final(Lista* Ptl, int elem);
      break;
    case 3
      Lista* Remove_elem_final(Lista* Ptl, int elem);
      break;
    case 4:
      Lista* Apagar_lista();
      break;
    default:
      break;
  }
}
