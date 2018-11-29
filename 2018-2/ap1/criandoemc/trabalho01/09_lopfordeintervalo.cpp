#include <stdio.h>

int main()
{
  int interv1, interv3, i, n1;

  interv1 = 0;
  interv3 = 0;

  for (i = 0; i <= 10; i++){

    printf("Informe um numero: \n");
    scanf("%d", &n1);

    if (n1 >= 10 && n1 <= 20) {
      interv1 = interv1 + 1;
    } else {
      interv3 = interv3 + 1;
    }

    printf("%d, numeros dentro do intervalo de [10,20]\n", interv1);
    printf("%d, numeros fora do intervalo de [10,20]\n", interv3);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  };
return (0);
}
