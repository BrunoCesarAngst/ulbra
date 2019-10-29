#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5

//Struct Aluno
struct aluno {
    int codigo;
    char nome[30];
    char telefone[12];
    char email[30];
    float notaG1;
    float notaG2;
};
typedef struct aluno Aluno;

struct lista{
 int finalDaLista;
 Aluno dados[max];
}; 
typedef struct lista Lista;

int tam;

void inicia(Lista *LISTA);
int menu(void);
void opcao(Lista *LISTA, int op);
Lista *criaNo();
void insereFim(Lista *LISTA);
void insereInicio(Lista *LISTA);
void exibe(Lista *LISTA);
void libera(Lista *LISTA);
void insere (Lista *LISTA);
Lista *retiraInicio(Lista *LISTA);
Lista *retiraFim(Lista *LISTA);
Lista *retira(Lista *LISTA);


int main(void)
{
 Lista *LISTA = (Lista *) malloc(sizeof(Lista));
 if(!LISTA){
  printf("Sem memoria disponível!\n");
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

void inicia(Lista *LISTA){
 LISTA -> dados = NULL;
 tam = 0;
}

int menu(void)
{
 int opt;
 
 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Zerar lista\n");
 printf("2. Exibir lista\n");
 printf("3. Adicionar Lista no inicio\n");
 printf("4. Adicionar Lista no final\n");
 printf("5. Escolher onde inserir\n");
 printf("6. Retirar do inicio\n");
 printf("7. Retirar do fim\n");
 printf("8. Escolher de onde tirar\n");
 printf("Opcao: "); scanf("%d", &opt);
 
 return opt;
}

void opcao(Lista *LISTA, int op)
{
 Lista *tmp;
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

int vazia(Lista *LISTA)
{
 if(LISTA->dados == NULL)
  return 1;
 else
  return 0;
}

Lista *aloca()
{
 Lista *novo=(Lista *) malloc(sizeof(Lista));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}


void insereFim(Lista *LISTA)
{
 Lista *novo=aloca();
 novo->dados = NULL;
 
 if(vazia(LISTA))
  LISTA->dados=novo;
 else{
  Lista *tmp = LISTA->dados;
  
  while(tmp->dados != NULL)
   tmp = tmp->dados;
  
  tmp->dados = novo;
 }
 tam++;
}

void insereInicio(Lista *LISTA)
{
 Lista *novo=aloca(); 
 Lista *oldHead = LISTA->dados;
 
 LISTA->dados = novo;
 novo->dados = oldHead;
 
 tam++;
}

void exibe(Lista *LISTA)
{
 system("clear");
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 Lista *tmp;
 tmp = LISTA->dados;
 printf("Lista:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->dados;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);
 
  
 printf("\n\n");
}

void libera(Lista *LISTA)
{
 if(!vazia(LISTA)){
  Lista *dadosLista,
     *atual;
  
  atual = LISTA->dados;
  while(atual != NULL){
   dadosLista = atual->dados;
   free(atual);
   atual = dadosLista;
  }
 }
}

void insere(Lista *LISTA)
{
 int pos,
  count;
 printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
 scanf("%d", &pos);
 
 if(pos>0 && pos <= tam){
  if(pos==1)
   insereInicio(LISTA);
  else{
   Lista *atual = LISTA->dados,
     *anterior=LISTA; 
   Lista *novo=aloca();
     
   for(count=1 ; count < pos ; count++){
     anterior=atual;
     atual=atual->dados;
   }
   anterior->dados=novo;
   novo->dados = atual;
   tam++;
  }
   
 }else
  printf("Elemento invalido\n\n");  
}

Lista *retiraInicio(Lista *LISTA)
{
 if(LISTA->dados == NULL){
  printf("Lista ja esta vazia\n");
  return NULL;
 }else{
  Lista *tmp = LISTA->dados;
  LISTA->dados = tmp->dados;
  tam--;
  return tmp;
 }
    
}

Lista *retiraFim(Lista *LISTA)
{
 if(LISTA->dados == NULL){
  printf("Lista ja vazia\n\n");
  return NULL;
 }else{
  Lista *ultimo = LISTA->dados,
    *penultimo = LISTA;
    
  while(ultimo->dados != NULL){
   penultimo = ultimo;
   ultimo = ultimo->dados;
  }
    
  penultimo->dados = NULL;
  tam--;
  return ultimo;  
 }
}

Lista *retira(Lista *LISTA)
{
 int opt,
  count;
 printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
 scanf("%d", &opt);
 
 if(opt>0 && opt <= tam){
  if(opt==1)
   return retiraInicio(LISTA);
  else{
   Lista *atual = LISTA->dados,
     *anterior=LISTA; 
     
   for(count=1 ; count < opt ; count++){
    anterior=atual;
    atual=atual->dados;
   }
   
  anterior->dados=atual->dados;
  tam--;
  return atual;
  }
   
 }else{
  printf("Elemento invalido\n\n");
  return NULL;
 }
}
