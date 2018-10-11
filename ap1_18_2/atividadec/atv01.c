#include <stdio.h>
#include <conio.h>

int main(){

float pc, nv;

printf("Me informe o preco do computador: \n");
scanf("%f", &pc);

nv = pc + (pc * 30 / 100) + (pc * 10 /100);

printf("Seu valor final passa a ser R$%.2f.\n", nv);

