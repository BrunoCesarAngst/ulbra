#include <stdio.h>

main()
{

 int x = 0, num;

 printf("Digite um número: ");
 scanf("%d", &num);

 while(x <= 10){
		 printf("\n%d x %d = %d", x, num, x *num);
		 x++;
 }
}
