#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "forca.h"
#define v 50

//char palavraSecreta[v];
char chutes[26];
int chutesDados = 0;

void aberturaDoJogo() {
    printf("\t/***********************/\n");
    printf("\t/***  Jogo da Forca  ***/\n");
    printf("\t/***********************/\n");
}

void listaDePalavras() {
    int tam = 0;
    string palavras[3] = {"casa", "vida", "amor"};
    tam = sizeof(palavras);
    int index = rand();
    printf("%d\n", tam);
    printf("%d\n", index);
}

int main()
{
    aberturaDoJogo();
    listaDePalavras();

    return 0;
}
