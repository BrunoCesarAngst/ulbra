#include <stdio.h>
#define l 10

int main(){
  int L[l] = {9, 3, 8, 6};
  int i = 0;
  int n = 4;
  int j = 0;

  printf("Vetor inicial: \n");
  for(i = 0; i < n; i++){
    printf("%d ", L[i]);
  }
  printf("\n");

  printf("\nInserindo o 7 no final: \n");
  L[n] = 7;
  n++;
  for(i = 0; i < n; i++){
    printf("%d ", L[i]);
  }
  printf("\n");

  printf("\nRetirar o primeiro elemento: \n");
  for(i = 0; i < n; i++){
    L[i] = L[i + 1];
  }
  n--;
  for(i = 0; i < n; i++){
    printf("%d ", L[i]);
  }
  printf("\n");

  printf("\nRetirar o valor 8 da lista: \n");
  for(i = 0; i < n; i++){
    if(L[i] == 8){
      for(j = i; j < n; j++){
        L[j] = L[j+1];
      }
      n--;
    }
  }

  for(i = 0; i < n; i++){
    printf("%d ", L[i]);
  }
  printf("\n");

  printf("\nInserir -4 no inicio da lista: \n");
  for(i = n; i >= 0; i--){
    L[i] = L[i-1];
  }
  L[0] = -4;
  n++;
  for(i = 0; i < n; i++){
    printf("%d ", L[i]);
  }
  printf("\n");

  printf("\nRetirar o element na terceira posição da lista: \n");
  for(i = 0; i < n; i++){
    if(i == 2){
      for(j = i; j < n; j++){
        L[j] = L[j+1];
      }
    }
  }
  n--;
  for(i = 0; i < n; i++){
    printf("%d ", L[i]);
  }
  printf("\n");
  printf("\n");

  return 0;
}
