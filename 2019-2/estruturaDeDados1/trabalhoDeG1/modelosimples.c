#include<stdio.h>
#include<stdlib.h>
#define quantidade 3

typedef struct pessoa {
  char nome[30];
  int idade;
} pes;

typedef struct registro {
  int finalDaLista;
  pes dados[quantidade];
} reg;

pes novaPessoa() {
  pes pessoa;
  printf("nome: ");
  fgets(pessoa.nome, 30, stdin);
  printf("idade: ");
  scanf("%i", &pessoa.idade);
  return pessoa;
}

reg * criarLista(void) {
  reg * lugarDaMemoria = (reg *)malloc(sizeof(reg));
  if (lugarDaMemoria != NULL) {
    lugarDaMemoria->finalDaLista = 0;
  }
  printf("Uma novo arquivo!\n");
  return lugarDaMemoria;
}

reg * pessoaNoFim(reg * umaMemoria) {
  pes pessoa;

  if (umaMemoria->finalDaLista == quantidade) {
    printf("Memória cheia.\n");
  } else {
    printf("Uma nova pessoa.\n");
    pessoa = novaPessoa();
    umaMemoria->dados[umaMemoria->finalDaLista] = pessoa;
    umaMemoria->finalDaLista++;
    printf("Pessoa incluida.\n");
  }

  return umaMemoria;
}

int main() {
  int op;

  reg *umaMemoriaDeRegistro;
  umaMemoriaDeRegistro = criarLista();
  // memoria criada.
  do {
    printf("Escolha:\n 1- Arquivar no final.\n 2- Arquivar no início.\n 3- Arquivar após nome.\n 0- Sair.\n ==> ");
    scanf("%i", &op);
    getchar();
    
    switch (op) {
      case 1:
        pessoaNoFim(umaMemoriaDeRegistro);
        break;
      case 0:
        break;

      default:
        printf("Não valeu!\n");
        break;
    }
  } while (op != 0);  
  return 0;
}
