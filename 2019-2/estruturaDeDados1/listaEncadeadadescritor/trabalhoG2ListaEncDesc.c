/*
  Descrição do trabalho: Faça a implementação de uma lista encadeada com descritor para armazenar registros de alunos. Para cada aluno deve ser armazenado: código, nome, telefone, email, nota g1 e nota g2.
  O programa deve ser feito com base no exemplo apresentado na aula do dia 28/10. Cada nodo, ou nó, da lista deve conter na parte de informações um registro de alunos.
  O programa deve implementar o seguinte menu de opções( cada opção corresponde a uma função);
  1- Incluir no final
  2 - Incluir no início
  3- Incluir após um nome(ler um nome, encontrar na lista e incluir na posição posterior)
  4 - Consultar por nome (ler um nome e mostrar o registro do nome procurado)
  5 - Excluir do início
  6 - Excluir do fim
  7 - Excluir por código
  8 - Listar todos os registros
  9 - Listar com médias finais ( listar os nomes dos alunos com suas médias finais calculadas)
  10- Sair
*/

// ---------- inclusions
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <ctype.h>

// ---------- definitions
  #define success 0
  #define lackOfMemory 1
  #define emptyList 2

// ---------- data types
  typedef struct student {
    int code;
    char name[25];
    char fone[25];
    char email[25];
    int gradesG1;
    int gradesG2;
  } StudentData;

  typedef struct data {
    StudentData data;
    struct data *link;
  } DataLink;
  
// ---------- descriptor
  typedef struct {
    DataLink *first;
    int amountOfData;
    DataLink *last;
  } DescriptorData;

// ---------- header function
  int menu(int answer, DescriptorData *dd, StudentData sd);
  void initializesDescriptor(DescriptorData *dd);
  void reportError(int warning);
  StudentData insertStudant();
  void reportStudant();
  int insertAtEnd(DescriptorData *dd, StudentData sd);
  void reportList(DescriptorData dd);

// ---------- main
  int main() {
    int answer = 0, warning;
    DescriptorData dd;
    StudentData sd;

    initializesDescriptor(&dd);
    do {      
      answer = menu(answer, &dd, sd);
    } while (answer != 10);
    if (warning){
      reportError(warning);
      return 1;
    }
    
    return 0;
  }

// ---------- function
  int menu(int answer, DescriptorData *dd, StudentData sd) {
    int warning;
    
    printf("\n\tMenu de opções:                                                        \n 1 -> Incluir no final.                                                        \n 2 -> Incluir no início.                                                       \n 3 -> Incluir após um nome:                                                           \n\t(ler um nome, encontrar na lista e incluir na posição posterior)      \n 4 -> Consultar por nome:                                                             \n\t(ler um nome e mostrar o registro do nome procurado)                  \n 5 -> Excluir do início.                                                       \n 6 -> Excluir do fim.                                                          \n 7 -> Excluir por código.                                                      \n 8 -> Listar todos os registros.                                               \n 9 -> Listar com médias finais:                                                       \n\t( listar os nomes dos alunos com suas médias finais calculadas)       \n10 -> Sair.                                                                    \nEscolha uma opção: ");
    scanf("%i", &answer);

    switch (answer) {
    case 1:
      printf("Case 1\n");
      int warning = insertAtEnd(dd, sd);
      break;
    case 2:
      printf("Case 2\n");
      break;
    case 3:
      printf("Case 3\n");
      break;
    case 4:
      printf("Case 4\n");
      break;
    case 5:
      printf("Case 5\n");
      break;
    case 6:
      printf("Case 6\n");
      break;
    case 7:
      printf("Case 7\n");
      break;
    case 8:
      printf("Case 8\n");
      reportList(*dd);
      break;
    case 9:
      printf("Case 9\n");
      break;
    case 10:
      printf("Case 10\n");
      break;
    default:
      printf("\nEscolha uma opção válida!\n");
      break;
    }
    return answer;
  }

  void initializesDescriptor(DescriptorData *dd) {
    dd->first = NULL;
    dd->amountOfData = 0;
    dd->last = NULL;
    printf("Created descriptor and initialized!");
    printf("\nDescriptor first : %i", dd->first);
    printf("\nDescriptor amountOfData : %i", dd->amountOfData);
    printf("\nDescriptor last : %i", dd->last);
    // graphic representation
        //          Descriptor dd
        // +-------+--------------+------+
        // | first | amountOfData | last | 
        // | NULL  |       0      | NULL |
        // +-------+--------------+------+
  }

  void reportError(int warning) {
    switch (warning) {
    case lackOfMemory:
      printf("ERRO: Falta de memória!!!\n");
      break;
    case emptyList:
      printf("ERRO: Lista vazia!!!\n");
      break;
    }
  }

  StudentData insertStudant() {
    StudentData sd;
    printf("\n\tRegistro de Aluno\n");
    printf("Código do aluno: ");
    scanf("%i", &sd.code);
    getchar();
    printf("Nome do aluno: ");
    fgets(sd.name, 24, stdin);
    printf("Telefone do aluno: ");
    fgets(sd.fone, 24, stdin);
    printf("Email do aluno: ");
    fgets(sd.email, 24, stdin);
    printf("Nota G1 do aluno: ");
    scanf("%i", &sd.gradesG1);
    getchar();
    printf("Nota G2 do aluno: ");
    scanf("%i", &sd.gradesG2);
    getchar();
    return sd;
  }

  void reportStudant(DataLink *dl, StudentData *sd) {
    printf("Aluno código %i", dl->data.code);
    printf("Nome do aluno %s", dl->data.name);
    printf("Telefone do aluno %s", dl->data.fone);
    printf("Email do aluno %s", dl->data.email);
    printf("Nota G1 do aluno %i", dl->data.gradesG1);
    printf("Nota G2 do aluno %i", dl->data.gradesG2);
    printf("\n");
  }

  int insertAtEnd(DescriptorData *dd, StudentData sd) {
    DataLink *dl;

    dl = (DataLink*)malloc(sizeof(DataLink));
    // graphic representation
      // +------+------+
      // | data | link |
      // +------+------+
      //   DataLink dl

    if (dl == NULL) {
      return (lackOfMemory);
    } else {
      sd = insertStudant();
      dl->data = sd;
      // graphic representation
        //   StudentData 
        // +-------------+  
        // |             |  
        // |     sd      | 
        // |             |                           
        // +-------------+   
        //        |         
        //        |        
        //        V        
            // +------+------+
            // | data | link |
            // +------+------+
            //   DataLink dl
      
      dl->link = dd->first;
      // graphic representation
        //   StudentData             Descriptor dd
        // +-------------+  +-------+--------------+------+
        // |             |  | first | amountOfData | last | 
        // |     sd      |  | NULL  |       0      | NULL |
        // |             |  +-------+--------------+------+                          
        // +-------------+   / 
        //        |         /
        //        |        |
        //        V        V
            // +------+------+
            // | data | link |
            // +------+------+
            //   DataLink dl

      dd->first = dl;
      // graphic representation
        //   StudentData             Descriptor dd
        // +-------------+  +-------+--------------+------+
        // |             |  | first | amountOfData | last | 
        // |     sd      |  |  dl   |       0      | NULL |
        // |             |  +-------+--------------+------+                          
        // +-------------+     /|\
        //        |             |
        //        |    _________|
        //        V   |
            // +------+------+
            // | data | link |
            // +------+------+
            //   DataLink dl

      if (dd->amountOfData == 0) {
        dd->last = dl;
        // graphic representation
          //   StudentData             Descriptor dd
          // +-------------+  +-------+--------------+------+
          // |             |  | first | amountOfData | last | 
          // |     sd      |  | dl    |       0      |   dl |
          // |             |  +-------+--------------+------+                       
          // +-------------+     /|\                   /|\
          //        |             |                     |
          //        |    _________|_____________________|
          //        V   |
              // +------+------+
              // | data | link |
              // +------+------+
              //   DataLink dl
      }
      dd->amountOfData++;
      // graphic representation
          //   StudentData             Descriptor dd
          // +-------------+  +-------+--------------+------+
          // |             |  | first | amountOfData | last | 
          // |     sd      |  | dl    |       1      |   dl |
          // |             |  +-------+--------------+------+                       
          // +-------------+     /|\                   /|\
          //        |             |                     |
          //        |    _________|_____________________|
          //        V   |
              // +------+------+
              // | data | link |
              // +------+------+
              //   DataLink dl
      return (success);
    }
  }

  void reportList(DescriptorData dd) {
    DataLink *dl;
    StudentData *sd;
    printf("\n\tLista de alunos:\n");
    if (dd.first == NULL) {
      printf("A Lista está vazia!!!");
    } else {
      dl = dd.first;
      while (dl != NULL) {
        reportStudant(dl, sd);
        dl = dl->link;
      }
    }

  }
