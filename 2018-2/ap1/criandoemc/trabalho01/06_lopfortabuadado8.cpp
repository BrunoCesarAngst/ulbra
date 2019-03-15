#include <stdio.h>

int main()
{
  int numero, i, cont, seq;

    for (i = 0; i <= 10; i++){

      cont = i * 8;
      seq = i;
      printf("\n +---+---+---+---+----+");
      printf("\n | 8 | x | %d | = | %d |", seq, cont);
    }
    printf("\n +---+---+----+---+----+");
return (0);
}
