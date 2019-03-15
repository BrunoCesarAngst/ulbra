#include <stdio.h>

int main()
{
  int numero, i, cont, cont2, cont3, cont4, cont5, seq, seq2, seq3, seq4, seq5;

    for (i = 0; i <= 5; i++){

      cont = i * 1;
      seq = i;
      printf("\n +---+---+---+---+---+");
      printf("\n | 1 | x | %d | = | %d |", seq, cont);
    }
      for (i = 0; i <= 5; i++){

        cont2 = i * 2;
        seq2 = i;
        printf("\n +---+---+---+---+---+");
        printf("\n | 2 | x | %d | = | %d |", seq2, cont2);
      }
        for (i = 0; i <= 5; i++){

          cont3 = i * 3;
          seq3 = i;
          printf("\n +---+---+---+---+---+");
          printf("\n | 3 | x | %d | = | %d |", seq3, cont3);
        }
          for (i = 0; i <= 5; i++){

            cont4 = i * 4;
            seq4 = i;
            printf("\n +---+---+---+---+---+");
            printf("\n | 4 | x | %d | = | %d |", seq4, cont4);
          }
            for (i = 0; i <= 5; i++){

              cont5 = i * 5;
              seq5 = i;
              printf("\n +---+---+---+---+---+");
              printf("\n | 5 | x | %d | = | %d |", seq5, cont5);
            }
    printf("\n +---+---+---+---+---+");

  }
