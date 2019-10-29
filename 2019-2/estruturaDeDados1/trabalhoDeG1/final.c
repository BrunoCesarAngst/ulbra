// Importacao de bibliotecas
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// Defines
#define max 5

// Struct para armazenar dados de um aluno.
typedef struct aluno {
  int codigo;
  char nome[20];
  char telefone[20];
  char email[20];
  float notaG1;
  float notaG2;
} Aluno;

// Struct que armazena os dados dos alunos em lista.
typedef struct lista {
  int finLista;     // É o contador/regulador da lista.
  Aluno dados[max]; // vetor que recebe os dados struct aluno.
} Lista;

void continuar() {
  printf("\n\tTecle a tecla enter para continuar!!!\n");
  getchar();
}

// Adiciona alunos
Aluno addAluno() {

  Aluno aluno;
  int num;

  do{
    printf("Código: ");
    num = scanf("%d", &aluno.codigo);
    getchar();
    if(num != 1){
      printf("\n\tDigite apenas números!!!\n");
    }
  }while(num != 1);
  
  // do{
    
  //   if(num != 1){
  //     printf("\n\tDigite apenas números!!!\n");
  //   }
  // }while(num != 1);

  printf("Nome: ");
  fgets(aluno.nome, 20, stdin);

  printf("Telefone: ");
  fgets(aluno.telefone, 20, stdin);

  printf("Email: ");
  fgets(aluno.email, 20, stdin);

  printf("Nota G1: ");
  scanf("%f", &aluno.notaG1);
  getchar();

  printf("Nota G2: ");
  scanf("%f", &aluno.notaG2);
  getchar();

  return aluno;
}

// FUNCAO DE TESTES
// INSERIR MAX DE DADOS -- OP 99
Lista *inserirMax(Lista *Ptl) {

  printf("\n\tPreenchendo automaticamente toda a lista de dados!\n");
  Aluno dados;

  strcpy(dados.telefone, "000");
  strcpy(dados.email, "email@g.com");
  dados.notaG1 = 10;
  dados.notaG2 = 9;

  for (int i = 0; i < max; i++) {
    if (Ptl == NULL || Ptl->finLista == max) {

      printf("\n\tLista completa ou nula\n");
    } else {

      strcpy(dados.nome, "teste" + (char)i);
      dados.codigo = i;
      Ptl->dados[Ptl->finLista] = dados;
      // A cada inserção de dados a lista fica maior.
      Ptl->finLista++;
    }
    printf("\nIncluido aluno código: %i.\n", i);
  }
  printf("\n\tPreenchimento concluído!\n");

  continuar();

  return Ptl;
}

// CRIA LISTA -- OP 10
Lista *criaLista(void) {

  // sizeof(lista); sizeof(), retorna o tamanho(número) de bytes da Lista.
  // malloc(sizeof(Lista)); malloc(), retornando um ponteiro para a área
  // alocada. (Lista *)malloc(sizeof(Lista)); (Lista *), um cast que converte o
  // ponteiro do retorno de malloc para o tipo de dados desejado
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  if (lista != NULL) {

    lista->finLista = 0;
  }
  printf("\nO endereço de memória da variável lista: %p.", &lista);
  printf("\nNos índices\n -> ");
  for (int i = 0; i < max; i++) {
    printf(" [%i]: %p;", i, &lista[i]);
  }

  printf("\nFoi atribuido o valor %i para o fim da lista.\n", lista->finLista);
  printf("\n\tLista criada com sucesso!!!\n");
  continuar();
  return lista;
}

// Add No final da lista -- OP 1
// declara o parametro Ptl um ponteiro do struct Lista
Lista *addNoFinal(Lista *Ptl) {
  // declara a variável aluno uma struct Aluno
  Aluno aluno;

  if (Ptl->finLista == max) {

    printf("\n\tLista cheia, completou os %i registros de alunos!!\n",
           Ptl->finLista);
    printf("\tPara novos registros faça alguma exclusão\n");

    continuar();
  } else {
    printf("\n\tInserindo dados do Aluno no índice [%i]:\n", Ptl->finLista);

    aluno = addAluno();

    Ptl->dados[Ptl->finLista] = aluno;
    Ptl->finLista++;
    printf("\n\tInclusao realizada!!!\n");
  }
  // Retorna o Ptl incluindo esses novos dados no vetor de Alunos
  return Ptl;
}

// Add No inicio da lista -- OP 2
Lista *addNoInicio(Lista *Ptl) {

  int i;
  Aluno aluno;

  if (Ptl->finLista == max) {
    printf("\n\tLista cheia, completou os %i registros de alunos!!\n",
           Ptl->finLista);
    printf("\tPara novos registros faça alguma exclusão\n");

    continuar();
  } else {

    aluno = addAluno();

    // if (Ptl->finLista < max - 1){
    //   Ptl->finLista++;
    // }  isso serviria se fosse dinâmica.

    for (i = Ptl->finLista; i >= 0; i--) {
      Ptl->dados[i + 1] = Ptl->dados[i];
      //[0][1][2][3][ ]
      //   \  \  \  \  <- transferimos tudo um índice à direita.
      //[x][0][1][2][3]
      //[0][1][2][3][4]
    }
    Ptl->dados[0] = aluno;
    printf("\n\tAluno adicionado!!!\n");

    continuar();
  }
}

// Incluir após um nome -- OP 3
void addAposNome(Lista *Ptl) {
  int i, j, cod;
  int localizado;
  char nome[25];
  Aluno a;

  if (Ptl->finLista == max) {

    printf("\n\tLista cheia!!!\n");
    continuar();
  } else if (Ptl->finLista == 0) {

    printf("\n\tLista vazia!!!\n");
    continuar();
  } else {

    printf("\nInforme após qual aluno desejas incluir um novo aluno.\n");
    printf("\nDigite o nome: ");
    fgets(nome, 20, stdin);

    for (i = 0; i < Ptl->finLista; i++) {
      // nome == i
      // [0][i][2][3] <- nome está no índice 1.
      localizado = strcmp(nome, Ptl->dados[i].nome);
      // strcmp retorna 0 se a comparação for igual.

      if (localizado == 0) {

        printf("\nNome localizado!\n");
        Ptl->finLista++;
        // [0][i][2][3]["4"] <- aumenta-se o índice.
        for (j = Ptl->finLista; j > i + 1; j--) {

          Ptl->dados[j] = Ptl->dados[j - 1];
          //  j| j>i |dados[j-1]| dados[j]| j--
          //  4| true|    4-1   |     3   | 4-1
          //  3| true|    3-1   |     2   | 3-1
          //  2| true|    2-1   |     1   | 2-1
          //  1|false|    not   |   not   | not
          // [0][i]\/[2][3][4]
          //            \  \
          // [0][i]\/[ ][2][3] <- move-se
        }

        do {
          a = addAluno(a);
          for (i = 0; i < Ptl->finLista; i++) {
            if (a.codigo == Ptl->dados[i].codigo) {
              printf("\n\tCódigo existente, digite um código diferente!!!");
              continuar();
              break;
            }
          }
        } while (a.codigo == Ptl->dados[i].codigo);
        Ptl->dados[i + 1] = a;
        // [0][i][a][2][3]
        break;
      }
    }

    if (localizado != 0) {
      printf("\nNome não localizado!!!!\n");
    }
  }
}

// Pesquisar por nome de aluno -- OP 4
void pesquisaNome(Lista *Ptl) {

  int i;
  int r;
  char nome[25];
  if (Ptl->finLista > 0) {
    printf("\n\tFazer uma consulta por nome:\n");
    printf("\nInforme um nome: ");
    fgets(nome, 20, stdin);

    for (i = 0; i < Ptl->finLista; i++) {
      r = strcmp(nome, Ptl->dados[i].nome);
      if (r == 0) {
        printf("Cod.: %d\n", Ptl->dados[i].codigo);
        printf("Nome: %s\n", Ptl->dados[i].nome);
        printf("Telefone: %s\n", Ptl->dados[i].telefone);
        printf("Email: %s\n", Ptl->dados[i].email);
        printf("Nota g1: %.1f\n", Ptl->dados[i].notaG1);
        printf("Nota g2: %.1f\n", Ptl->dados[i].notaG2);
        printf("\n");
        continuar();
        break;
      }
    }

    if (r != 0) {
      printf("\n\tNome não encontrado!!!\n");
      continuar();
    }

  } else {
    printf("\n\tLista vazia!!!\n");
    continuar();
  }
}

// Excluir do inicio -- OP 5
void excluiInicio(Lista *Ptl) {
  int i;

  if (Ptl->finLista > 0) {
    for (i = 0; i < Ptl->finLista; i++) {
      Ptl->dados[i] = Ptl->dados[i + 1];
      // [0][1][2][3][4]
      //    /  /  /  /
      // [1][2][3][4][ ]
    }
    Ptl->finLista--;
    // [1][2][3][4]
    printf("\n\tDados do primeiro aluno excluidos!!\n");
  } else {
    printf("\n\tLista vazia!!\n");
  }
  continuar();
}

// Excluir ultimo elemento da Lista -- OP 6
void excluiFim(Lista *Ptl) {

  if (Ptl->finLista > 0) {

    Ptl->dados[Ptl->finLista - 1].codigo = 0;
    strcmp(Ptl->dados[Ptl->finLista - 1].nome, "0");
    strcmp(Ptl->dados[Ptl->finLista - 1].telefone, "0");
    strcmp(Ptl->dados[Ptl->finLista - 1].email, "0");
    Ptl->dados[Ptl->finLista - 1].notaG1 = 0;
    Ptl->dados[Ptl->finLista - 1].notaG2 = 0;
    printf("\n\tDado do último aluno excluido!!\n");
    Ptl->finLista--;
  } else {

    printf("\n\tLista vazia!!\n");
  }
  continuar();
}

// Excluir por codigo -- OP 7
void excluiPorCod(Lista *Ptl) {
  int i, j, r, codigo;
  if (Ptl->finLista > 0) {
    printf("\nInforme o codigo que deve ser excluido: ");
    scanf("%d", &codigo);
    getchar();
    for (i = 0; i < Ptl->finLista; i++) {
      r = (Ptl->dados[i].codigo == codigo);
      if (r == 1) {
        for (j = i; j < Ptl->finLista; j++) {

          Ptl->dados[j] = Ptl->dados[j + 1];
        }
        Ptl->finLista--;
        printf("\n\tO aluno com código %i, foi excluido da lista!!!\n", codigo);
        continuar();
      }
    }
    if (r != 1) {
      printf("\n\tCodigo não encontrado!!\n");
      continuar();
    }
  } else {
    printf("\n\tLista vazia!!\n");
    continuar();
  }
}

// Listar todos os alunos -- OP 8
void listarAlunos(Lista *Ptl) {
  int i;
  if (Ptl->finLista > 0) {
    printf("\n\tLista de alunos: \n");
    for (i = 0; i < Ptl->finLista; i++) {
      printf("\t+----------+------------------+\n");
      printf("\t|Código:   | %d                \n", Ptl->dados[i].codigo);
      printf("\t+----------+------------------+\n");
      printf("\t|Nome:     | %s                \n", Ptl->dados[i].nome);
      printf("\t+----------+------------------+\n");
      printf("\t|Telefone: | %s                \n", Ptl->dados[i].telefone);
      printf("\t+----------+------------------+\n");
      printf("\t|Email:    | %s                \n", Ptl->dados[i].email);
      printf("\t+----------+------------------+\n");
      printf("\t|Nota g1:  | %.1f              \n", Ptl->dados[i].notaG1);
      printf("\t+----------+------------------+\n");
      printf("\t|Nota g2:  | %.1f              \n", Ptl->dados[i].notaG2);
      printf("\t+----------+------------------+\n");
      printf("\n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    printf("\n");
  } else {
    printf("\n\tLista vazia!!\n");
  }
}

// Listar nomes dos alunos com medias finais -- OP 9
void listarMedia(Lista *Ptl) {
  int i;
  float media;
  printf("\n\tLista de alunos:\n");
  for (i = 0; i < Ptl->finLista; i++) {
    printf("\t+------------+------------------+\n");
    printf("\t|Nome:       |%s                 \n", Ptl->dados[i].nome);
    printf("\t+------------+------------------+\n");
    printf("\t|Nota g1:    |%.1f               \n", Ptl->dados[i].notaG1);
    printf("\t+------------+------------------+\n");
    printf("\t|Nota g2:    |%.1f               \n", Ptl->dados[i].notaG2);
    printf("\t+------------+------------------+\n");
    // calculo da media
    media = (Ptl->dados[i].notaG1 + (Ptl->dados[i].notaG2 * 2)) / 3;

    printf("\t|Media final:|%.1f               \n", media);
    printf("\t+------------+------------------+\n");
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  }
  printf("\n");
}

// funcao main
int main() {
  Lista *pointLista;
  Aluno aluno;
  int op, codigo;
  char nome[10], valid;
  pointLista = criaLista();

  do {

    printf("\n\tMenu de opções:\n");
    printf(" 1 - Incluir no final \n 2 - Incluir no início "
           "\n 3 - Incluir após um nome \n\t(ler um nome, encontrar na lista e "
           "incluir na posição posterior) \n 4 - Consultar por nome \n\t(ler "
           "um nome e mostrar o registro do nome procurado) \n 5 - Excluir do "
           "início \n 6 - Excluir do fim \n 7 - Excluir por código \n 8 - "
           "Listar todos os registros \n 9 - Listar com médias finais \n\t( "
           "listar os nomes dos alunos com suas médias finais calculadas) \n10 - Criar uma nova lista \n11 - Sair \nEscolha uma opção>>> ");

    scanf("%d", &op);
    getchar();

    switch (op) {
    
    case 1:
      addNoFinal(pointLista);
      break;
    case 2:
      addNoInicio(pointLista);
      break;
    case 3:
      addAposNome(pointLista);
      break;
    case 4:
      pesquisaNome(pointLista);
      break;
    case 5:
      excluiInicio(pointLista);
      break;
    case 6:
      excluiFim(pointLista);
      break;
    case 7:
      excluiPorCod(pointLista);
      break;
    case 8:
      listarAlunos(pointLista);
      break;
    case 9:
      listarMedia(pointLista);
    case 10:
      printf("\n\tCriar nova lista: \n");
      printf("\nEssa opção ira criar uma nova lista e todos os dados já "
             "cadastrados serão perdidos");
      do {
        printf("\nProsseguir (s/n)? ");
        scanf("%c", &valid);
        getchar();

        if (strchr("sS", valid) != 0) {
          pointLista = criaLista();
        } else {
          printf("\n\tOperação cancelada!\n");
        }

      } while (strchr("sSnN", valid) == 0);

      break;
    case 11:
      printf("\n");
      printf("\tSaiu!!!\n");
      printf("\n");
      break;
    case 99:
      pointLista = inserirMax(pointLista);
      break;
    default:
      printf("\nTente novamente\n");
      break;
    }

  } while (op != 11);

  return 0;
}
