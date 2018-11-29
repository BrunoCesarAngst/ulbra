#include <stdio.h>

main()
{
  int vneg, vzero, vposi, i, n1;

  vneg = 0;
  vzero = 0;
  vposi = 0;

  for (i = 0; i <= 10; i++){

    printf("Informe um numero: \n");
    scanf("%d", &n1);

    if (n1 < 0) {
      vneg = vneg + 1;
    } else if (n1 > 0) {
      vposi = vposi + 1;
    } else {
      vzero = vzero + 1;
    }

    printf("%d, numero negativo\n", vneg);
    printf("%d, numero zero\n", vzero);
    printf("%d, numero positivo\n", vposi);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");


}
return (0);
}
