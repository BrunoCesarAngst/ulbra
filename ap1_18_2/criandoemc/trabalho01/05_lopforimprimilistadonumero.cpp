#include <stdio.h>

int main()
{
  int numero, i, cont;

  cont = 0;
  printf("Informe um numero inteiro: ");
  scanf("%d/n/n", &numero );

    for (i = 0; i < numero; i++){

      cont = i + 1;
      printf("%d\n", cont);
    }
return (0);
}
