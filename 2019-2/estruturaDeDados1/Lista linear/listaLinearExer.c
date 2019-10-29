#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Node{
 int num;
 int dados[MAX];
}; 
typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);


int main(void)
{
 node *LISTA = (node *) malloc(sizeof(node));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(LISTA);
 int opt;
 
 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
 }
}

void inicia(node *LISTA){
 LISTA -> num = 0;
}

int menu(void)
{
 int opt;
 
 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Zerar lista\n");
 printf("2. Exibir lista\n");
 printf("3. Adicionar node no inicio\n");
 printf("4. Adicionar node no final\n");
 printf("5. Escolher onde inserir\n");
 printf("6. Retirar do inicio\n");
 printf("7. Retirar do fim\n");
 printf("8. Escolher de onde tirar\n");
 printf("Opcao: "); scanf("%d", &opt);
 
 return opt;
}

void opcao(node *LISTA, int op)
{
 node *tmp;
 switch(op){
  case 0:
   libera(LISTA);
   break;
   
  case 1:
   libera(LISTA);
   inicia(LISTA);
   break;
  
  case 2:
   exibe(LISTA);
   break;
  
  case 3:
   insereInicio(LISTA);
   break;  
   
  case 4:
   insereFim(LISTA);
   break;
   
  case 5:
   insere(LISTA);
   break;
  
  case 6:
   tmp= retiraInicio(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
   
  case 7:
   tmp= retiraFim(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  case 8:
   tmp= retira(LISTA);
   printf("Retirado: %3d\n\n", tmp->num);
   break;
  
  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(node *LISTA)
{
 if(LISTA->num == 0)
  return 1;
 else
  return 0;
}

node *aloca()
{
 node *novo=(node *) malloc(sizeof(node));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}


void insereFim(node *LISTA)
{
 node *novo=aloca();
 novo->num = 0;
 
 if(vazia(LISTA))
  LISTA->num=0;
 else{
  node *tmp = LISTA->num;
  
  while(tmp->num != 0)
   tmp = tmp->num;
  
  tmp->num = novo;
 }
 MAX++;
}

void insereInicio(node *LISTA)
{
 node *novo=aloca(); 
 node *oldHead = LISTA->num;
 
 LISTA->num = novo;
 novo->num = oldHead;
 
 MAX++;
}

void exibe(node *LISTA)
{
 system("clear");
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 node *tmp;
 tmp = LISTA->num;
 printf("Lista:");
 while( tmp != 0){
  printf("%5d", tmp->num);
  tmp = tmp->num;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < MAX ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < MAX ; count++)
  printf("%5d", count+1);
 
  
 printf("\n\n");
}

void libera(node *LISTA)
{
 if(!vazia(LISTA)){
  node *numNode,
     *atual;
  
  atual = LISTA->num;
  while(atual != 0){
   numNode = atual->num;
   free(atual);
   atual = numNode;
  }
 }
}

void insere(node *LISTA)
{
 int pos,
  count;
 printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", MAX);
 scanf("%d", &pos);
 
 if(pos>0 && pos <= MAX){
  if(pos==1)
   insereInicio(LISTA);
  else{
   node *atual = LISTA->num,
     *anterior=LISTA; 
   node *novo=aloca();
     
   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->num;
   }
   anterior->num=novo;
   novo->num = atual;
   MAX++;
  }
   
 }else
  printf("Elemento invalido\n\n");  
}

node *retiraInicio(node *LISTA)
{
 if(LISTA->num == 0){
  printf("Lista ja esta vazia\n");
  return 0;
 }else{
  node *tmp = LISTA->num;
  LISTA->num = tmp->num;
  MAX--;
  return tmp;
 }
    
}

node *retiraFim(node *LISTA)
{
 if(LISTA->num == 0){
  printf("Lista ja vazia\n\n");
  return 0;
 }else{
  node *ultimo = LISTA->num,
    *penultimo = LISTA;
    
  while(ultimo->num != 0){
   penultimo = ultimo;
   ultimo = ultimo->num;
  }
    
  penultimo->num = 0;
  MAX--;
  return ultimo;  
 }
}

node *retira(node *LISTA)
{
 int opt,
  count;
 printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", MAX);
 scanf("%d", &opt);
 
 if(opt>0 && opt <= MAX){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   node *atual = LISTA->num,
     *anterior=LISTA; 
     
   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->num;
   }
   
  anterior->num=atual->num;
  MAX--;
  return atual;
  }
   
 }else{
  printf("Elemento invalido\n\n");
  return 0;
 }
}
