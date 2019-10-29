#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define total 10

typedef struct person {
  char name[20];
} Person;

typedef struct list {
  int endOfList;
  Person names[total];
} List;

Person registerName() {
  Person person;

  printf("\nEnter a person name: \n");
  gets(person.name);
  printf("\n\tName inclued!\n");

  return person;
}

List * createList(){
  List* list = (List*)malloc(sizeof(List));

  if (list != NULL) {
    list -> endOfList = 0;
  }
}

List * AddAtEndOfList(List* listPointer){
  Person person;

  if (listPointer -> endOfList >= total){
    printf("\n\tThe list is full!\n");
  } else {
    person = registerName();
    listPointer->names[listPointer->endOfList] = person;
    listPointer->endOfList++;
    printf("\n\tName was added to list.\n");
  }
  return listPointer;
}

void removingNameList(List * listPointer) {
  char nameRemove[20];
  bool correctIndex = 1;
  if (listPointer->endOfList > 0){
    printf("\n\tList of names entered\n");
    for (int i= 0; i < listPointer->endOfList; i++){
      printf(" %s", listPointer->names[i].name);
    }

    printf("\nEnter the name you want to remove? \n");
    gets(nameRemove);

    for (int i = 0; i < listPointer->endOfList; i++){
      if (strcmp(listPointer->names[i].name, nameRemove) == 0){
        for (int j = i; j < listPointer->endOfList; j++){
          listPointer->names[j] = listPointer->names[j + 1];
        }
        listPointer->endOfList--;
        break;
      } else {
        printf("\n\tName not found!!!\n");
      }
    }
  } else {
      printf("\n\tThe list is empty!\n");
    }  
}

int main() {
  int op;
  char answer;
  Person person;
  List* listPointer;

  printf("\n\tCreating a name list.\n");

  do
  {
    printf("\n\tOptions menu\n 1 - Create list\n 2 - Destruction List\n 3 - Insert an element\n 4 - Removing an element\n 5 - Get out\n choose an option: ");
    scanf("%i", &op);
    getchar();

    switch (op)
    {
    case 1:
      listPointer = createList();
      printf("\n\tSuccessfully created list!!!\n");
      break;

    case 2:
      do {

        printf("Do you want to delete all stored names (y/n)? ");
        scanf("%c", &answer);
        getchar();

        if (strchr("yY", answer) != 0){
          listPointer = createList();
          printf("\n\tDestroyed list!!!\n");
        } else if (strchr("nN", answer) != 0) {
          printf("\n\tOperation canceled!\n");
        } else if (strchr("yYnN", answer) == 0){
          printf("\n\tEnter only yes or no.\n");
        }

      } while (strchr("yYnN", answer) == 0);

      break;

    case 3:
      AddAtEndOfList(listPointer);
      break;
    
    case 4:
      removingNameList(listPointer);
      break;

    case 5:
      printf("\n\tGet out\n\n");
      break;
    
    default:
      printf("\n\tInvalid option, try again!\n");
      break;
    } 
  } while (op != 5);  

  return 0;
}



