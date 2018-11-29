#include <stdio.h>

int main()
{
  int numero, i, cont, seq;

  printf("Informe um numero para fazer a tabuada: \n");
  scanf("%d", &numero);

    for (i = 0; i <= 10; i++){
      cont = i * numero;
      seq = i;
      printf("\n +---+---+---+---+----+");
      printf("\n | %d | x | %d | = | %d |", numero, seq, cont);
    }
    printf("\n +---+---+----+---+----+");
return (0);
}
