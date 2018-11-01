#include <stdio.h>

int main()
{
  for (int a = 1; a <= 10 ; a++) {
    for (int b = 0; b <= 5; b++) {
      printf("%d x %d = %d\n",a, b, a*b );
    }
    printf("\n");
  }
}
