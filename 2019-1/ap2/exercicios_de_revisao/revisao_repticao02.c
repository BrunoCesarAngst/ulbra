#include <stdio.h>

main()
{

 int x = 0, num;

 printf("\n Digite um número: ");
 scanf("%d", &num);

do{
 printf("\n %d x %d = %d", x, num, x * num);
 x++;

}while(x <= 10);

}
