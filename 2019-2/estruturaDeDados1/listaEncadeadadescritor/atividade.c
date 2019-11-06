// Lista Encadeada com Descritor
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ------------------------------------ Definições
#define SUCESSO 0
#define FALTA_DE_MEMORIA 1
#define LISTA_VAZIA 2
// ------------------------------------ Tipos de Dados
typedef struct cliente {
  char nome[25];
  char telefone[25];
  char email[25];
  char cidade[25];
} tDados;

typedef struct nodo {
  tDados dado;
  struct nodo *elo;
} tNodo;

//---------------------------------Descritor
typedef struct {
  tNodo *primeiro;
  int n;
  tNodo *ultimo;
} tDescritor;
// ------------------------------------ Prototypes
void Cria_Lista(tDescritor *d);
int Inclui_Esquerda(tDescritor *d, tDados dado);
int Inclui_Direita(tDescritor *d, tDados dado);
int Consulta_Ultimo(tDescritor d, tDados *dado);
void Imprime_Lista(tDescritor d);
void Imprime_Erro(int erro);
// ------------------------------------ Programa Principal
int main(void) {
  tDescritor d;
  tDados dado;
  char tecla;
  int erro;
  Cria_Lista(&d);
  do {
    Imprime_Lista(d);
    getchar();
    printf("\nNome (ou fim) : ");
    gets(dado.nome);
    if (strcmp(dado.nome, "fim") != 0) {
      printf("\nTelefone: ");
      gets(dado.telefone);
      printf("\nEmail: ");
      gets(dado.email);
      printf("\nCidade: ");
      gets(dado.cidade);
      printf("[E]squerda ou [D]ireita : ");
      do {
        tecla = toupper(getchar());
      } while (!strchr("ED", tecla));
      switch (tecla) {
      case 'E':
        erro = Inclui_Esquerda(&d, dado);
        break;
      case 'D':
        erro = Inclui_Direita(&d, dado);
        break;
      }
      if (erro) {
        Imprime_Erro(erro);
        break;
      }
    }
  } while (strcmp(dado.nome, "fim") != 0);
  erro = Consulta_Ultimo(d, &dado);
  if (erro == SUCESSO)
    printf(" Último Elemento : %s\n", dado.nome);
  else
    Imprime_Erro(erro);
  getchar();
}
// ------------------------------------ Cria_Lista

void Cria_Lista(tDescritor *l) {
  l->primeiro = NULL;
  l->n = 0;
  l->ultimo = NULL;
}
// ------------------------------------ Inclui_Esquerda
int Inclui_Esquerda(tDescritor *d, tDados dado) {
  tNodo *p;
  p = (tNodo *)malloc(sizeof(tNodo));
  if (p == NULL)
    return (FALTA_DE_MEMORIA);
  else {
    p->dado = dado;
    p->elo = d->primeiro;
    d->primeiro = p;
    if (d->n == 0)
      d->ultimo = p;
    (d->n)++;
    return (SUCESSO);
  }
}
// ------------------------------------ Inclui_Direita
int Inclui_Direita(tDescritor *d, tDados dado) {
  tNodo *p;
  p = (tNodo *)malloc(sizeof(tNodo));
  if (p == NULL)
    return (FALTA_DE_MEMORIA);
  else {
    p->dado = dado;
    p->elo = NULL;
    if (d->n == 0)
      d->primeiro = p;
    else
      d->ultimo->elo = p;
    d->ultimo = p;
    (d->n)++;
    return (SUCESSO);
  }
}
// ------------------------------------ Consulta_Ultimo
int Consulta_Ultimo(tDescritor d, tDados *dado) {
  tNodo *p;

  if (d.primeiro == NULL)
    return (LISTA_VAZIA);
  else {
    p = d.primeiro;
    while (p->elo != NULL)
      p = p->elo;
    *dado = p->dado;
    return (SUCESSO);
  }
}
// ------------------------------------ Imprime_Erro
void Imprime_Erro(int erro) {
  switch (erro) {
  case FALTA_DE_MEMORIA:
    printf(" ERRO : Falta de Memória\n");

    break;

  case LISTA_VAZIA:
    printf(" ERRO : Lista Vazia\n");

    break;
  }
}
// ------------------------------------ Imprime_Lista
void Imprime_Lista(tDescritor l) {
  tNodo *p;
  tDados *d;
  printf("\nLista Encadeada : ");
  if (l.primeiro == NULL)
    printf(" VAZIA");
  else {
    p = l.primeiro;
    while (p != NULL) {
      printf("(%s %s %s %s)", p->dado.nome, p->dado.telefone, p->dado.email,
             p->dado.cidade);
      p = p->elo;
    }
  }
}
