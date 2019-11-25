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
  #define inexistente -1

// ---------- data types
  typedef struct student {
    int code;
    char name[25];
    char fone[25];
    char email[25];
    float gradesG1;
    float gradesG2;
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
  int codeSearch(DescriptorData *dd, int code);
  void listAverages(DescriptorData *dd);
  int insertAtBeginning(DescriptorData *dd, StudentData sd);
  int insertAtEnd(DescriptorData *dd, StudentData sd);
  void excludeFromTheBeginning(DescriptorData *dd);
  void excludeFromEnd(DescriptorData *dd);
  void includeAfterName(DescriptorData *dd);
  void excludeByCode(DescriptorData *dd);
  void reportList(DescriptorData dd);
  void queryByName(DescriptorData* dd);

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
  // ---------- function menu
    int menu(int answer, DescriptorData *dd, StudentData sd) {
      int warning;
      
      printf("\n\tMenu de opções:                                                        \n 1 -> Incluir no final.                                                      \n 2 -> Incluir no início.                                                     \n 3 -> Incluir após um nome:                                                       \n\t(ler um nome, encontrar na lista e incluir na posição posterior)      \n 4 -> Consultar por nome:                                                         \n\t(ler um nome e mostrar o registro do nome procurado)                  \n 5 -> Excluir do início.                                                     \n 6 -> Excluir do fim.                                                        \n 7 -> Excluir por código.                                                    \n 8 -> Listar todos os registros.                                             \n 9 -> Listar com médias finais:                                              \n\t( listar os nomes dos alunos com suas médias finais calculadas)            \n10 -> Sair.                                                                  \nEscolha uma opção: ");
      scanf("%i", &answer);
      getchar();

    // ---------- part switch-case
      switch (answer) {
      case 1:
        printf("\n\tIncluir no final.\n");
        warning = insertAtEnd(dd, sd);
        break;
      case 2:
        printf("\n\tIncluir no início.\n");
        warning = insertAtBeginning(dd, sd);
        break;
      case 3:
        printf("\n\tIncluir após nome.\n");
        includeAfterName(dd);
        break;
      case 4:
        printf("Consultar por nome.\n");
        queryByName(dd);
        break;
      case 5:
        printf("\n\tExcluir do início.\n");
        excludeFromTheBeginning(dd);
        break;
      case 6:
        printf("\n\tExcluir no final.\n");
        excludeFromEnd(dd);
        break;
      case 7:
        printf("\n\tExcluir por código.\n");
        excludeByCode(dd);
        break;
      case 8:
        printf("Case 8\n");
        reportList(*dd);
        break;
      case 9:
        printf("\n\tListar médias.\n");
        listAverages(dd);
        break;
      case 10:
        printf("\n\tAté logo!!!\n");
        break;
      default:
        printf("\nEscolha uma opção válida!\n");
        break;
      }
      return answer;
    }

  // ---------- function initializesDescriptor  
    void initializesDescriptor(DescriptorData *dd) {
      dd->first = NULL;
      dd->amountOfData = 0;
      dd->last = NULL;
      printf("\n\tCreated descriptor and initialized!");
      printf("\nDescriptor first : %i | amountOfData: %i | last: %i\n", dd->first, dd->amountOfData, dd->last);
      // graphic representation
          //          Descriptor dd
          // +-------+--------------+------+
          // | first | amountOfData | last | 
          // | NULL  |       0      | NULL |
          // +-------+--------------+------+
    }

  // ---------- function reportError
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
  
  // ---------- function insertStudant
    StudentData insertStudant() {
      StudentData sd;
      printf("\n\tRegistro de Aluno\n");
      printf("Código do aluno: ");
      scanf("%i", &sd.code);
      getchar();
      printf("Nome do aluno: ");
      gets(sd.name);
      printf("Telefone do aluno: ");
      gets(sd.fone);
      printf("Email do aluno: ");
      gets(sd.email);
      printf("Nota G1 do aluno: ");
      scanf("%f", &sd.gradesG1);
      getchar();
      printf("Nota G2 do aluno: ");
      scanf("%f", &sd.gradesG2);
      return sd;
    }

  // ---------- function reportStudant
    void reportStudant(DataLink *dl, StudentData *sd) {
      printf("Aluno %s de código %i, contato telefone %s e email %s tem notas de G1: %.1f e G2: %.1f.",  dl->data.name, dl->data.code, dl->data.fone, dl->data.email, dl->data.gradesG1, dl->data.gradesG2);
      printf("\n");
    }
  
  // ---------- function insertAtEnd 
    int insertAtEnd(DescriptorData *dd, StudentData sd) {
      DataLink *dl;
      dl = (DataLink*)malloc(sizeof(DataLink));
      // graphic representation
        // +------+------+
        // | data | link |
        // +------+------+
        // new DataLink dl

      if (dl == NULL) {
        printf("Faltou Memória!!!");
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
              // |      |      |
              // +------+------+
              // new DataLink dl
        
        dl->link = NULL;
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
              // |  sd  |      | <----- NULL
              // +------+------+
              // new DataLink dl

        if (dd->amountOfData == 0) {
          dd->first = dl;
        // graphic representation
            //                         Descriptor dd
            //                  +-------+--------------+------+
            //                  | first | amountOfData | last | 
            //                  |  *dl  |       0      | NULL |
            //                  +-------+--------------+------+                      
            //                     | 
            //            +--------+
            //            |
            //           \|/
                // +------+------+
                // | data | link |
                // |  sd  | NULL | 
                // +------+------+
                // new DataLink dl

          // graphic representation of the next steps: dd->last = dl and (dd->amountOfData)++;
              //   StudentData             Descriptor dd
              // +-------------+  +-------+--------------+------+
              // |             |  | first | amountOfData | last | 
              // |     sd      |  |*newDl |       1      |*newDl|
              // |             |  +-------+--------------+------+                    
              // +-------------+     |                      | 
              //        |   +--------+----------------------+
              //        |   |                                
              //        V  \|/
                  // +------+------+
                  // | data | link |
                  // |  sd  | NULL | 
                  // +------+------+
                  // new DataLink dl
              
        } else {
          dd->last->link = dl;
        // graphic representation
            //                           Descriptor dd
            //                  +-------+--------------+--------+
            //                  | first | amountOfData | last   | 
            //                  |*oldDl |     >=1      | *oldDl |
            //                  +-------+--------------+--------+                    
            //                     |                      |   |                      
            //            +--------+----------------------+   |                 
            //            |                                   |
            //           \|/          +-----------------------+            
                // +------+------+    |    +------+------+
                // | data | link | <--+    | data | link |
                // |  sd  |      | ------> |  sd  |      |
                // +------+------+         +------+------+
                // old DataLink dl         new DataLink dl

          // graphic representation
            //                           Descriptor dd
            //                  +-------+--------------+--------+
            //                  | first | amountOfData | last   | 
            //                  |*oldDl |     >=1      | *oldDl |
            //                  +-------+--------------+--------+                    
            //                     |                                              
            //            +--------+                                         
            //            |                           
            //           \|/                                               
                // +------+------+         +------+------+
                // | data | link |         | data | link |
                // |  sd  |*newDl| ------> |  sd  |      |
                // +------+------+         +------+------+
                // old DataLink dl         new DataLink dl
        
        }
        dd->last = dl;
        // graphic representation
            //                           Descriptor dd
            //                  +-------+--------------+--------+
            //                  | first | amountOfData | last   | 
            //                  |*oldDl |       1      | *newDl |
            //                  +-------+--------------+--------+                    
            //                     |                       |                         
            //            +--------+              +--------+                         
            //            |                       |                
            //           \|/                     \|/                                 
                // +------+------+         +------+------+
                // | data | link |         | data | link |
                // |  sd  |*newDl| ------> |  sd  |      |
                // +------+------+         +------+------+
                // old DataLink dl         new DataLink dl

        (dd->amountOfData)++;
        // graphic representation
            //                           Descriptor dd
            //                  +-------+--------------+--------+
            //                  | first | amountOfData | last   | 
            //                  |*oldDl |       2      | *newDl |
            //                  +-------+--------------+--------+                    
            //                     |                       |                         
            //            +--------+              +--------+                         
            //            |                       |                
            //           \|/                     \|/                                 
                // +------+------+         +------+------+
                // | data | link |         | data | link |
                // |  sd  |*newDl| ------> |  sd  |      |
                // +------+------+         +------+------+
                // old DataLink dl         new DataLink dl
      }
    }

  // ---------- function insertAtBeginning
    int insertAtBeginning(DescriptorData *dd, StudentData sd) {
      DataLink *dl;
      dl = (DataLink*)malloc(sizeof(DataLink));
      // graphic representation
        // +------+------+
        // | data | link |
        // +------+------+
        // new DataLink dl

      if (dl == NULL) {
        return (lackOfMemory);
      } else {
        sd = insertStudant();
        dl->data = sd;
        // graphic representation
          //   StudentData             Descriptor dd                 
          // +-------------+  +----------+--------------+----------+
          // |             |  |   first  | amountOfData |   last   | 
          // |     sd      |  |  *oldDl  |     >=1      |  *oldDl  |
          // |             |  +----------+--------------+----------+                 
          // +-------------+        |                        |
          //        |               +-----------+------------+    
          //        |                           |  
          //        V                          \|/                  
              // +------+------+         +------+------+
              // | data | link |         | data | link |
              // |  sd  |      |         |  sd  |      |
              // +------+------+         +------+------+
              // new DataLink dl  (...)  old DataLink dl
        
        dl->link = dd->first;
        // graphic representation
          //   StudentData             Descriptor dd                
          //                   +----------+--------------+----------+                
          //                   |   first  | amountOfData |   last   |                
          //                   |  *oldDl  |     >=1      |  *oldDl  |
          //                   +----------+--------------+----------+                
          //                    /|\  |                        | 
          //                    /    +-----------+------------+ 
          //                   /                 | 
          //                  /                  |              
              // +------+-------+         +------+------+
              // | data | link  |         | data | link |
              // |  sd  |*oldDl |         |  sd  |      |
              // +------+-------+         +------+------+
              // new DataLink dl         old DataLink dl

          //                              Descriptor dd                
          //                   +----------+--------------+----------+                
          //                   |   first  | amountOfData |   last   |                
          //                   |  *oldDl  |     >=1      |  *oldDl  |
          //                   +----------+--------------+----------+                
          //                         |                        | 
          //                         +-----------+------------+ 
          //                                     | 
          //                                    \|/             
              // +------+-------+         +------+------+
              // | data | link  | ----->  | data | link |
              // |  sd  |*oldDl |         |  sd  |      |
              // +------+-------+         +------+------+
              // new DataLink dl         old DataLink dl

        dd->first = dl;
        // graphic representation
          //   StudentData             Descriptor dd                
          //                  +----------+--------------+----------+                 
          //                  |   first  | amountOfData |   last   |                 
          //                  |  *oldDl  |     >=1      |  *oldDl  |
          //                  +----------+--------------+----------+                 
          //                        |                        | 
          //            +-----------+            +-----------+ 
          //            |                        | 
          //           \|/                      \|/            
              // +------+-------+         +------+------+
              // | data | link  | ----->  | data | link |
              // |  sd  |*oldDl |         |  sd  |      |
              // +------+-------+         +------+------+
              // new DataLink dl         old DataLink dl

        if (dd->amountOfData == 0) {
          dd->last = dl;
          // TODO - compreender melhor essa parte
          // graphic representation
            //   StudentData             Descriptor dd
            // +-------------+  +-------+--------------+------+
            // |             |  | first | amountOfData | last | 
            // |     sd      |  | dl    |       0      |   dl |
            // |             |  +-------+--------------+------+                      
            // +-------------+      |                     | 
            //        |    _________|_____________________|
            //        |   |                      
            //        V  \|/
                // +------+------+
                // | data | link |
                // |  sd  |      |
                // +------+------+
                // new DataLink dl
        }
        (dd->amountOfData)++;
        // graphic representation
            //   StudentData             Descriptor dd
            // +-------------+  +-------+--------------+------+
            // |             |  | first | amountOfData | last | 
            // |     sd      |  | dl    |       1      |   dl |
            // |             |  +-------+--------------+------+                      
            // +-------------+      |                     | 
            //        |    _________|_____________________|
            //        |   |                      
            //        V  \|/
                // +------+------+
                // | data | link |
                // |  sd  |      |
                // +------+------+
                // new DataLink dl
        return (success);
      }
    }

  // ---------- function reportList 
    void reportList(DescriptorData dd) {
      DataLink *dl;
      StudentData *sd;
      printf("\n\tLista de alunos:\n");
      if (dd.first == NULL) {
        printf("\n\tA Lista está vazia!!!\n");
      } else {
        dl = dd.first;
        // graphic representation
          // # dl that will be printed; Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  |  dl   |     !=0      |  dl  |
          //                  +-------+--------------+------+                        
          //                     /|\                    /|\
          //            +---------+                      +------+
          //            |                                       |    
          //          # |                                       |
              // +------+------+     +------+------+     +------+------+
              // | data | link |---->| data | link |---->| data | link |
              // +------+------+     +------+------+     +------+------+
              //   DataLink dl
        while (dl != NULL) {
          reportStudant(dl, sd);
          dl = dl->link;
          // graphic representation
          // # dl that will be printed; Descriptor dd
          //                  +---------+--------------+---------+
          //                  |  first  | amountOfData | last    | 
          //                  | dl > 1  |     > 0      |dl!=NULL |
          //                  +---------+--------------+---------+                   
          //                     /|\                    /|\
          //            +---------+                      +---------------------+
          //            |                      while dl is different from NULL |    
          //            |                #                                     |
              // +------+------+     +------+------+     +------+------+
              // | data | link |---->| data | link |---->| data | link |----> ***
              // +------+------+     +------+------+     +------+------+
              //   DataLink dl
        }
      }
    }

  // ---------- function queryByName
    void queryByName(DescriptorData* dd) {
      DataLink *dl;
      char name[25];
      
      if (dd->first == NULL) {
      printf("Não há registros!!!");
      } else {
        printf("informe o nome: ");
        gets(name);
        dl = dd->first;
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  |  dl   |     !=0      |  dl  |
          //                  +-------+--------------+------+                        
          //                     /|\                    /|\
          //            +---------+                      +------+
          //            |                                       |    
          //            |                                       |
              // +------+------+     +------+------+     +------+------+
              // | data | link |---->| data | link |---->| data | link |
              // +------+------+     +------+------+     +------+------+
              //   DataLink dl
        while (dl != NULL) {
          if (strcmp(name, dl->data.name) == 0) {
            printf("Aluno %s de código %i, contato telefone %s e email %s tem notas de G1: %f e G2: %f.",  dl->data.name, dl->data.code, dl->data.fone, dl->data.email, dl->data.gradesG1, dl->data.gradesG2);
            // graphic representation
              // # dl that will be printed; Descriptor dd
              //                  +---------+--------------+---------+
              //                  |  first  | amountOfData | last    | 
              //                  | dl > 1  |     > 0      |dl!=NULL |
              //                  +---------+--------------+---------+               
              //                     /|\                    /|\
              //            +---------+                      +---------------------+
              //            |                      while dl is different from NULL | 
              //            |                #                                     |
                  // +------+------+     +------+------+     +------+------+
                  // | data | link |---->| data | link |---->| data | link |----> ***
                  // +------+------+     +------+------+     +------+------+
                  //   DataLink dl    data.name == wanted name
            break;
          }
          dl = dl->link;
        }
      }
    }

  // ---------- function includeAfterName
    void includeAfterName(DescriptorData *dd) {
      DataLink *dl, *auxiliary, *newNodo;
      StudentData sd;
      char name[25];
      int comparator;

      if (dd->first == NULL) {
        printf("Lista vazia!!!\n");
      } else {
        printf("Informe o nome: ");
        gets(name);

        dl = dd->first;
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  |  dl   |     !=0      |  dl  |
          //                  +-------+--------------+------+                        
          //                     /|\                    /|\
          //            +---------+                      +------+
          //            |                                       |    
          //            |                                       |
              // +------+------+     +------+------+     +------+------+
              // | data | link |---->| data | link |---->| data | link |
              // +------+------+     +------+------+     +------+------+
              //   DataLink dl

        while (dl != NULL) {
          comparator = strcmp(name, dl->data.name);
          // graphic representation
              //                             Descriptor dd
              //                  +---------+--------------+---------+
              //                  |  first  | amountOfData | last    | 
              //                  | dl > 1  |     > 0      |dl!=NULL |
              //                  +---------+--------------+---------+               
              //                     /|\                    /|\
              //            +---------+                      +---------------------+
              //            |                      while dl is different from NULL | 
              //            |                #                                     |
                  // +------+------+     +------+------+     +------+------+
                  // | data | link |---->| data | link |---->| data | link |----> ***
                  // +------+------+     +------+------+     +------+------+
                  //   DataLink dl    data.name == wanted name

          if (comparator == 0) {
            break;
          }
          dl = dl->link;
        }
        if (comparator == 0) {
          sd = insertStudant();
          newNodo = (DataLink*)malloc(sizeof(DataLink));
          // graphic representation
            // +------+------+
            // | data | link |
            // +------+------+
            // new DataLink dl

          if (newNodo == NULL) {
            printf("Faltou memória!!!\n");
          } else {
            newNodo->data = sd;
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
                  // |  sd  |      |
                  // +------+------+
                  // new DataLink dl

            if (dl->link == NULL) {
              //                           Descriptor dd
              //                  +-------+--------------+------+
              //                  | first | amountOfData | last | 
              //                  |*oldDl |       1      |*oldDl|
              //                  +-------+--------------+------+                    
              //                     |                      | 
              //            +--------+----------------------+
              //            |                                
              //           \|/
                  // +------+------+
                  // | data | link |
                  // |  sd  |      | 
                  // +------+------+
                  // old DataLink dl

              dl->link = newNodo;
              //                           Descriptor dd
              //                  +-------+--------------+------+
              //                  | first | amountOfData | last | 
              //                  |*oldDl |       1      |*oldDl|
              //                  +-------+--------------+------+                    
              //                     |                      | 
              //            +--------+----------------------+
              //            |                                
              //           \|/
                  // +------+------+      +------+------+
                  // | data | link | ---> | data | link |
                  // |  sd  |*newDl|      |  sd  |      | 
                  // +------+------+      +------+------+
                  // old DataLink dl      new DataLink dl

              dd->last = newNodo;
              //                           Descriptor dd
              //                  +-------+--------------+------+
              //                  | first | amountOfData | last | 
              //                  |*oldDl |       1      |*newDl|
              //                  +-------+--------------+------+                    
              //                     |                      | 
              //            +--------+           +----------+
              //            |                    |           
              //           \|/                  \|/            
                  // +------+------+      +------+------+
                  // | data | link | ---> | data | link |
                  // |  sd  |*newDl|      |  sd  |      | 
                  // +------+------+      +------+------+
                  // old DataLink dl      new DataLink dl

              newNodo->link = NULL;
              //                           Descriptor dd
              //                  +-------+--------------+------+
              //                  | first | amountOfData | last | 
              //                  |*oldDl |       1      |*newDl|
              //                  +-------+--------------+------+                    
              //                     |                      | 
              //            +--------+           +----------+
              //            |                    |           
              //           \|/                  \|/            
                  // +------+------+      +------+------+
                  // | data | link | ---> | data | link |
                  // |  sd  |*newDl|      |  sd  | NULL | 
                  // +------+------+      +------+------+
                  // old DataLink dl      new DataLink dl
            } else {
              auxiliary = dl->link;
              // graphic representation
                //                             Descriptor dd
                //                  +---------+--------------+---------+
                //                  |  first  | amountOfData | last    | 
                //                  | dl > 1  |     > 1      |dl!=NULL |
                //                  +---------+--------------+---------+             
                //                     /|\                    /|\
                //     +----------------+                      +--------+
                //     |                                                |
                //     |     data.name == wanted name                   |
                // +---+---+     +------+------+     +---+---+
                // | d | l |---->| data | link |---->| d | l |---->   ***
                // +---+---+     +------+------+     +---+---+
                //                         |                                         
                //  +------+------+       \|/                                    
                //  | data | link |     +-----+                                   
                //  |  sd  |      |     | aux |                                   
                //  +------+------+     +-----+                                   
                //  new DataLink dl                                                  
                //                             Descriptor dd
                //                  +---------+--------------+---------+
                //                  |  first  | amountOfData | last    | 
                //                  | dl > 1  |     > 1      |dl!=NULL |
                //                  +---------+--------------+---------+             
                //                     /|\                    /|\
                //     +----------------+                      +--------+
                //     |                                                |
                //     |     data.name == wanted name                   |
                // +---+---+     +------+------+     +---+---+
                // | d | l |---->| data | link |     | d | l |---->   ***
                // +---+---+     +------+------+     +---+---+
                //                                       |
                //  +------+------+        +-------------+                        
                //  | data | link |       \|/                                    
                //  |  sd  |      |     +-----+                                   
                //  +------+------+     | aux |                                   
                //  new DataLink dl     +-----+                                   
                //                                                                   

              dl->link = newNodo;
              // graphic representation
                //                             Descriptor dd
                //                  +---------+--------------+---------+
                //                  |  first  | amountOfData | last    | 
                //                  | dl > 1  |     > 1      |dl!=NULL |
                //                  +---------+--------------+---------+             
                //                     /|\                    /|\
                //     +----------------+                      +--------+
                //     |                                                |
                //     |     data.name == wanted name                   |
                // +---+---+     +------+------+     +---+---+
                // | d | l |---->| data | link |     | d | l |---->   ***
                // +---+---+     |      |*newDl|     +---+---+
                //               +------+------+                
                //                         /                                         
                //                        /                                          
                //                      \|/              |        
                //                +------+------+        |                      
                //                | data | link |       \|/                          
                //                |  sd  |      |     +-----+                        
                //                +------+------+     | aux |                        
                //                new DataLink dl     +-----+                        
                //                                                                   

              newNodo->link = auxiliary;
              // graphic representation
                //                             Descriptor dd
                //                  +---------+--------------+---------+
                //                  |  first  | amountOfData | last    | 
                //                  | dl > 1  |     > 1      |dl!=NULL |
                //                  +---------+--------------+---------+             
                //                     /|\                    /|\
                //     +----------------+                      +--------+
                //     |                                                |
                //     |     data.name == wanted name                   |
                // +---+---+     +------+------+     +---+---+
                // | d | l |---->| data | link |     | d | l |---->   ***
                // +---+---+     |      |*newDl|     +---+---+
                //               +------+------+                
                //                         /                                         
                //                        /                                          
                //                      \|/              |        
                //                +------+------+        |                      
                //                | data | link |       \|/                          
                //                |  sd  | *aux | --> +-----+                        
                //                +------+------+     | aux |                        
                //                new DataLink dl     +-----+                        
                //                                                                   
              // graphic representation
                //                             Descriptor dd
                //                  +---------+--------------+---------+
                //                  |  first  | amountOfData | last    | 
                //                  | dl > 1  |     > 1      |dl!=NULL |
                //                  +---------+--------------+---------+             
                //                     /|\                    /|\
                //     +----------------+                      +-------------------+
                //     |                                                           |
                //     |     data.name == wanted name                              |
                // +---+---+   +------+------+    +------+------+   +---+---+
                // | d | l |-->| data | link |--->| data | link |-->| d | l |-->  ***
                // +---+---+   |      |*newDl|    |  sd  |      |   +---+---+
                //             +------+------+    +------+------+              
                //                                new DataLink dl               
                //
            }
            dd->amountOfData++;
            // graphic representation
                //                             Descriptor dd
                //                  +---------+--------------+---------+
                //                  |  first  | amountOfData | last    | 
                //                  | dl > 1  |     >= 3     |dl!=NULL |
                //                  +---------+--------------+---------+             
                //                     /|\                    /|\
                //     +----------------+                      +-------------------+
                //     |                                                           |
                //     |     data.name == wanted name                              |
                // +---+---+   +------+------+    +------+------+   +---+---+
                // | d | l |-->| data | link |--->| data | link |-->| d | l |-->  ***
                // +---+---+   |      |*newDl|    |  sd  |      |   +---+---+
                //             +------+------+    +------+------+              
                //                                new DataLink dl               
          }
        } else {
          printf("\n\tNome não Encontrado!!!\n");
        }
      }

    }

  // ---------- function excludeFromTheBeginning
    void excludeFromTheBeginning(DescriptorData *dd) {
      DataLink *newNodo;

      if (dd->first == NULL) {
        printf("Lista vazia!!!\n");
      } else {
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  |  dl   |     >=1      |  dl  |
          //                  +-------+--------------+------+                        
          //                     /|\                     /|\
          //            +---------+                       +------+
          //            |                                        |
              // +------+------+                          +------+------+
              // | data | link |----> ..., ..., ..., ---->| data | link |
              // +------+------+                          +------+------+
              //   DataLink dl  

        newNodo = dd->first;
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  | *dl   |     >=1      | *dl  |
          //                  +-------+--------------+------+                        
          //                  /|\                        /|\       
          //            +------+                          +------+ 
          //            |                                        |     
          //            |       +------+------+                  |    
          //            +------>|  *DataLink  |                  |    
          //            |       +------+------+                  |
              // +------+------+    newNodo               +------+------+
              // | data | link |----> ..., ..., ..., ---->| data | link |
              // +------+------+                          +------+------+
              //   DataLink dl  

        dd->first = newNodo->link;
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  | *dl   |     >=1      | *dl  |
          //                  +-------+--------------+------+                        
          //                  /|\                        /|\       
          //            +------+                          +------+ 
          //            |                                        |     
          //            |       +------+------+                  |    
          //            +------>|  *DataLink  |                  |    
          //            |       +------+------+                  |
              // +------+------+    newNodo               +------+------+
              // | data | link |----> ..., ..., ..., ---->| data | link |
              // +------+------+                          +------+------+
              //   DataLink dl  

        free(newNodo);
        if (dd->first == NULL){
          dd->last= NULL; 
        }
        dd->amountOfData--;
      }
    }

  // ---------- function codeSearch
    int codeSearch(DescriptorData *dd, int code) {
      DataLink *dl;

      dl = dd->first;

      while (dl != NULL) {
        if (code == dl->data.code) {
          return code;
          break;
        }
        dl = dl->link;
      }
    }

  // ---------- function excludeFromEnd
    void excludeFromEnd(DescriptorData *dd) {
      DataLink *dl, *previous;

      if (dd->first == NULL) {
        printf("Lista vazia!!!\n");
      } else {
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  |  dl   |     >=1      |  dl  |
          //                  +-------+--------------+------+                        
          //                     /|\                     /|\
          //            +---------+                       +------+
          //            |                                        |
              // +------+------+                          +------+------+
              // | data | link |----> ..., ..., ..., ---->| data | link |
              // +------+------+                          +------+------+
              //   DataLink dl  

        dl = dd->first;
        // graphic representation
          //                           Descriptor dd
          //                  +-------+--------------+------+
          //                  | first | amountOfData | last | 
          //                  | *dl   |     >=1      | *dl  |
          //                  +-------+--------------+------+                        
          //                  /|\                        /|\       
          //            +------+                          +------+ 
          //            |                                        |     
          //            |       +------+------+                  |    
          //            +------>|  *DataLink  |                  |    
          //            |       +------+------+                  |
              // +------+------+       dl                 +------+------+
              // | data | link |----> ..., ..., ..., ---->| data | link |
              // +------+------+                          +------+------+
              //   DataLink dl  

        while (dl->link != NULL) {
          previous = dl;
          dl = dl->link;
        }
        if (dl == dd->first) {
          dd->first = NULL;
          dd->last = NULL;
        } else {
          previous->link = dl->link;
          dd->last = previous;
        }
        free(dl);
        dd->amountOfData--;
      }
    }

  // ---------- function excludeByCode
    void excludeByCode(DescriptorData *dd) {
      DataLink *dl, *auxiliary, *finale, *previous, *next;
      int code;

      if (dd->first == NULL) {
        printf("Lista vazia!!!\n");
      } else {
        printf("Qual o código do cadastro que será removido: ");
        scanf("%d", &code);
        if (codeSearch(dd, code) == 0) {
          printf("Código não encontrado!!!\n");
        } else {
          dl = dd->last;
          finale = dd->first;
          if (code == dl->data.code) {
            excludeFromEnd(dd);
          } else if (code == finale->data.code) {
            excludeFromTheBeginning(dd);
          } else {
            auxiliary = dd->first;
            while (auxiliary != NULL) {
              if(code == auxiliary->data.code) {
                break;
              }
              previous = auxiliary;
              auxiliary = auxiliary->link;
            }
            next = auxiliary->link;
            previous->link = next;
            free(auxiliary);
            dd->amountOfData--;
          }
        }
      }
    }

  // ---------- function listAverages
    void listAverages(DescriptorData *dd) {
      DataLink *dl;

      if (dd->first == NULL) {
        printf("Lista vazia!!!\n");
      } else {
        dl = dd->first;

        while (dl != NULL) {
          printf("\nO aluno %s, tem nota média de %.1f.\n", dl->data.name, (dl->data.gradesG1 + (dl->data.gradesG2 * 2) / 3));
          dl = dl->link; 
        }
      }
    }
