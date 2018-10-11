#include <stdio.h>

main()
{
  int numero, i;

  printf("Informe um numero inteiro: \n");
  scanf("%i", &numero );

  for (i = 1; i <= 10; i++)
  {
    printf("%i\n", numero);
  }

  return(0);
}
