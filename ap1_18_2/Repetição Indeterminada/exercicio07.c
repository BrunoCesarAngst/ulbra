#include <stdio.h>

/*Faça um programa que leia um número e calcule a soma de todos os números de
1 até ele (use laço enquanto). Ex.: se o usuário digitar 7, o programa vai mostrar
28, pois 1+2+3+4+5+6+7=28.*/

main(){

int numero=0, resultado=0;

printf ("Digite o numero: \n");
scanf ("%d", &numero);

    do{

		resultado=resultado+numero;
    numero=numero-1;

    }while(numero>=0);
    printf("%d", resultado);

}
