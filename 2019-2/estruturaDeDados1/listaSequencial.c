#include<stdio.h>
#define l 10

int main()
{
  int L[l] = {9, 3, 8, 6};
  int i;
  int n;
  n = 4;
  int p = 0;

  printf("Vetor inicial\n");
  for (i = 0; i < n; i++)  {
    // 9, 3, 8, 6
    printf("%d ", L[i]);
  }
  printf("\n");
  
  printf("Inserindo 7 no final\n");
  L[n] = 7;
  n++;  
  for (i = 0; i < n; i++)  {
  //   // 9, 3, 8, 6, + 7
    printf("%d ", L[i]);
  //   L[n - 1] = 7;    
  }  
  printf("\n");

  printf("Retirar o primeiro elemento\n");
  for (i = 0; i < n - 1; i++) {
    L[i] = L[i + 1];
    printf("%d ", L[i]);
  }
  n--;
  printf("\n");

  printf("Retirar o valor 8 da lista (valor, não posição)\n");
  int x = 8;
  int h = -1;
  int j;
  for (i = 0; i < n; i++) {
    if (L[i] == x)
    h = i;
    }
    if (h != -1) {
      for (j = h; j < n - 1; j++) {
        L[j] = L[j + 1];
      }
      n--;
    }
    // printf("%d ", L[i]);
  
  printf("\n");
  for ( i = 0; i < n; i++)
  {
    printf("%d ", L[i]);
  }
  

  printf("\n");

  printf("Inserir -4 no início\n");
  n++;
  int y = -4;
  for (i = n - 1; i > 0; i--)
    L[i] = L[i - 1];
  L[0] = y;
  for (i = 0; i < n; i++) {
    printf("%d ", L[i]); 
  }   
  printf("\n");

  printf("Retirar o elemento na terceira posição da lista\n");
  for (i = 0; i < n - 1; i++) {
    L[i] = L[i - 1];
    printf("%d ", L[i]);
  }
  n--;
  printf("\n");

  return 0;

}

