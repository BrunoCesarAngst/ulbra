// Lista Encadeada

// um ponteiro indicando o início e esse NULL

#include <stdio.h>
#include <stdlib.h>

// ------------------------------------ definições
#define sucesso 0 
#define faltaDeMemoria 1 
#define ListaVazia 2 

// ------------------------------------ tipos de dados
typedef int tdados;

typedef struct nodo{
  tdados dado;
  struct nodo *elo;
}tnodo;
  
typedef struct lista{
  tnodo *primeiro;
}tlista;


// ------------------------------------ cabeçalhos das funções
void criarLista(tlista *L);
int incluirLista(tlista *L, tdados D);
int removerPrimeiro(tlista *L);
int contarElementosLista(tlista *L);
void imprimirElementosLista(tlista *L);
int removerUltimo(tlista *L);
void imprimirErro(int erro);
void destroirLista(tlista *L);


int main(){
  tlista L;
  tdados D;
  int n, erro;

  criarLista(&L);
  do {
    printf("Valor a inserir na lista: ");
    scanf("%d",&D); // zero para sair
    if(D != 0){
      erro = incluirLista(&L,D);
      if(erro){
        imprimirErro(erro);
        break;
      }
    }
  } while (D != 0);
  n = contarElementosLista(&L);
  printf("Número de Elementos: %d\n", n);
  imprimirElementosLista(&L);
  destroirLista(&L);
  getchar();
  return 0;
}

void criarLista(tlista *L){
  L -> primeiro = NULL;
  printf("\nPrimeiro");
  printf("\n +---+\n");
  printf(  " |   |\n");
  printf(  " |   |\n");
  printf(  " |   |\n");
  printf(  " +---+\n");
}

int incluirLista(tlista *L, tdados D){
  tnodo *P;

  P = (tnodo *)malloc(sizeof(tnodo));
  if(P == NULL){
    if(P == NULL){
      printf("%d", faltaDeMemoria);
    }    
    return(faltaDeMemoria);
  }else{
    printf("\nIncluindo na lista");
    if(L -> primeiro == NULL){
      L -> primeiro = P;
      P -> dado = D;
      P -> elo = NULL;
      printf("\n  Dado  | elo");
      printf("\n+-------+-----+\n");
      printf(  "|       |     |\n");
      printf(  "|   %d   |%p|\n", P ->dado, P -> elo);
      printf(  "|       |     |\n");
      printf(  "+-------+-----+\n");
    }else{
      P -> dado = D;
      P -> elo = L -> primeiro;
      L -> primeiro = P;
      printf("\n  Dado  | elo");
      printf("\n+-------+-----+\n");
      printf(  "|       |     |\n");
      printf(  "|   %d   |  *  |\n", P ->dado);
      printf(  "|       |     |\n");
      printf(  "+-------+-----+\n");
    }
    return(sucesso);
  }
}

int removerPrimeiro(tlista *L){
  tnodo *P;

  if(L -> primeiro == NULL){
    return(ListaVazia);
  }else{
    P = L -> primeiro;
    free(P);
    return(sucesso);
  }
}

int contarElementosLista(tlista *L){
  tnodo *P;
  int n = 0;

  if(L -> primeiro == 0){
    return(n);
  }else{
    P = L -> primeiro;
    while(P != NULL){
      n++;
      P = P -> elo;
    }
    return(sucesso);
  }
}

void imprimirElementosLista(tlista *L){
  tnodo *P;

  while(P -> elo != NULL){
    printf("\n  Dado  | elo");
    printf("\n+-------+-----+\n");
    printf(  "|       |     |\n");
    printf(  "|   %d   |  *  |\n", P -> dado);
    printf(  "|       |     |\n");
    printf(  "+-------+-----+\n");
    P = P -> elo;
  }
  
  printf("\nNULL");
}

int removerUltimo(tlista *L){
  tnodo *P, *Q;

  if(L -> primeiro == NULL){
    return(ListaVazia);
  }else{
    Q = L -> primeiro;
    P = L -> primeiro;
    while(P -> elo != NULL){
      Q = P;
      P = P -> elo;
    }
    if(L -> primeiro == P){
      L -> primeiro = NULL;
    }else{
      Q -> elo = NULL;
      free(P);
      return(sucesso);
    }
  }
  return 0;
}

void imprimirErro(int erro){
  switch (erro){
    case faltaDeMemoria: printf("ERRO: Falta de Memória\n");
    break;
    case ListaVazia: printf("ERRO: Lista Vazia\n");
    break;
  }
  getchar();
}

void destroirLista(tlista *L){
  tnodo *P;

  if (L -> primeiro != NULL){
    P = L -> primeiro;
  }
  while (P -> elo != NULL){
    L -> primeiro = P -> elo;
    free(P);
    P = L -> primeiro;
  }
}
