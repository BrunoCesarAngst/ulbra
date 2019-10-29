/*1. Escreva um programa na linguagem C que leia um vetor G de 10 elementos do tipo caracter que representa o gabarito de uma prova; a seguir, para cada um dos 20 alunos da turma, leia o vetor respostas do aluno (vetor R com 10 elementos do tipo caracter) e conte o número de acertos. Para cada aluno, mostre o número de acertos do aluno e a mensagem de “Aprovado” se a quantidade de acertos for maior ou igual a 6, e uma mensagem “Reprovado” caso contrário.*/ 

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, certo = 0;
    char G[10], R[10];

    for (i = 0; i < 10; ++i) {
        printf("Gabarito %d: ", i + 1);
        scanf(" %c", &G[i]);
    }
    for (i = 0; i < 20; ++i) {
        for (i = 0; i < 10; ++i) {
            printf("Resposta do Aluno: \n");
            scanf(" %c", &R[i]);
            if (G[i] == R[i]) {
                certo++;
            }
        }
        if (certo >= 6) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }
    return 0;
}
