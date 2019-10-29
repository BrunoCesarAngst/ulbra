/*Crie um programa que permita cadastrar até 40 clientes (código, nome, endereço,
telefone e e-mail). O programa deve permitir as operações: inclusão, alteração por
código, consulta por nome e listar(relatório).*/

#include <stdio.h>
#include <string.h>
#define v 3

struct cadCliente {
    int cod, telefone;
    char nome[40], endereco[40], email[15];
};

int main(int argc, char *argv[])
{
    int numCli = 0, i = 0, opcao;
    struct cadCliente cadast[v];
    char novInc;

    do {
        printf("\n ========= Cadastro de Clientes ========="); 
        printf("\n Escolha uma opção:"); 
        printf("\n 1 - Incluir"); 
        printf("\n 2 - Alterar dados por código"); 
        printf("\n 3 - Consultar por nome"); 
        printf("\n 4 - Listar"); 
        printf("\n =>"); 
        printf("\n Qual é a opção escolhida: ");
        scanf("%d", &opcao);
        getchar();
        numCli++;

        switch (opcao) {
            case 1:
                printf("Código do cliente: ");
                scanf("%d", &cadast[i].cod);
                getchar();
                break;
            default:
                printf("\n Opção inválida!");
        }
        printf("\n Deseja uma nova inclusão (s/n)? ");
        scanf("%c", &novInc);
        getchar();
        if (novInc != 's') {
            break;
        }    
    } while (numCli < v || novInc == 's'); 
    return 0;
}
