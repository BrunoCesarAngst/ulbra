#include<stdio.h>
#include<string.h>
#define v 4

struct cadastro{
    char nome[30];
    char tipo[10];
    float preco;
};

void incluirDoce(struct cadastro doces[v]){
    int i;

    for (i = 0; i < v; ++i) {
        printf("nome: ");
        gets(doces[i].nome);
        printf("tipo: ");
        gets(doces[i].tipo);
        printf("preço: ");
        scanf("%f", &doces[i].preco);
        getchar();
    }
}

float mediaPreco(struct cadastro doces[v]){
    float total = 0, media = 0;
    int i;

    for (i = 0; i < v; ++i) {
        if(strcmp(doces[i].tipo, "bolo") == 0){
            total += doces[i].preco;
        }
    }
    media = total / v;
    return media;
}

void doceBaratoECaro(struct cadastro doces[v]){
    int i, flag = 0, vBarato, vCaro;
    float valorCaro = 0, valorBarato = 0;

    for (i = 0; i < v; ++i) {
        if(strcmp(doces[i].tipo, "docinho") == 0){
            if(flag == 0){
                valorBarato = doces[i].preco;
                valorCaro = doces[i].preco;
                vBarato = i;
                vCaro = i;
            }
            else
            {
                if (doces[i].preco < valorBarato) {
                    valorBarato = doces[i].preco;
                    vBarato = i;
                }
                if (doces[i].preco > valorCaro) {
                    valorCaro = doces[i].preco;
                    vCaro = i;
                }
            }
        }
    }
    printf("\n O docinho mais caro é o %s e custa R$ %.2f.", doces[vCaro].nome, valorCaro);
    printf("\n O docinho mais barato é o %s e custa R$ %.2f.", doces[vBarato].nome, valorBarato);
}

int main(){
    struct cadastro doces[v];
    float media;

    incluirDoce(doces);
    media = mediaPreco(doces);
    printf("\n Preço médio dos bolos é: R$ %.2f", media);
    doceBaratoECaro(doces);
    return 0;
}
