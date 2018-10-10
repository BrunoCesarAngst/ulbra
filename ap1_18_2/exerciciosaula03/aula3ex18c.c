#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){

float vq, qws, tp, vd;

printf("Quanto custa o quilowatt? \n");
scanf("%f", &vq);

printf("Quantos quilowatts foram consumodos? \n");
scanf("%f", &qws);

tp = qws * vq;
vd = tp - (tp * 15/100);

printf("Atraves do comsumo de %.0f kws, com um custo de R$ %.2f Chegamos a um total de R$ %.2f mas como o senhor é um bom consumidor tera 15 %% de desconto pagando somente: R$ %.2f\n", qws, vq, tp, vd);

system("pause");
return 0;
}
