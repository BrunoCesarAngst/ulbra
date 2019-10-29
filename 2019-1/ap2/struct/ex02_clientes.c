/*Crie um programa que permita cadastrar 40 clientes (código, nome, endereço,
 * telefone e e-mail). O programa deve ler todos os clientes e depois ler um
 * nome. Para o nome lido escrever na tela todos dos dados(código, endereço,
 * telefone e email). Caso o nome não seja encontrado, o programa deve
 * escrever na tela "cliente não cadastrado”.*/

#include <stdio.h>
#include <string.h>
#define v 3

struct cadCliente{
    int cod,
        telefone;
    char nome[30],
         email[15],
         endereco[40];

};

int main(int argc, char *argv[])
{
    
    struct cadCliente cliente[v];
    int i, examiner;
    char consult[30];

    for (i = 0; i < v; ++i) {
        printf("\n Cadastro nº %d", i+1);
        printf("\n Código: ");
        scanf("%d", &cliente[i].cod);
        getchar();
        printf("Seu nome: ");
        gets(cliente[i].nome);
        printf("Seu endereço: ");
        gets(cliente[i].endereco);
        printf("Seu telefone: ");
        scanf("%d", &cliente[i].telefone);
        getchar();
        printf("Seu email: ");
        gets(cliente[i].email);
        printf("###########################");
    }

    printf("\n Digite o nome que procuras: ");
    gets(consult);
    getchar();
    
    for (i = 0; i < v; ++i) {
        examiner = strcmp(cliente[i].nome, consult);
        if (examiner == 0) {
            printf("\n ###############################");
            printf("\n \t Registro encontrado");
            printf("\n \t Código %d", cliente[i].cod);
            printf("\n \t Nome %s", cliente[i].nome);
            printf("\n \t Edereço %s", cliente[i].endereco);
            printf("\n \t Telefone %d", cliente[i].telefone);
            printf("\n \t Email %s", cliente[i].email);
        } else if (examiner != 0) {
            printf("\n \t Registro não encontrado!");
        }
    }

    return 0;
}
