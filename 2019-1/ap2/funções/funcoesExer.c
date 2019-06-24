/*Crie um programa na linguagem C que permita cadastrar até 40 clientes{{{
(código, nome, endereço, telefone e e-mail). O programa deve permitir as
operações: inclusão, alteração por código, consulta por nome e
listar(relatório). O seguinte menu deve ser apresentado ao usuário:
========Cadastro de Clientes========
Escolha uma opção:
1 - Incluir
2 - Alterar dados por código
3 - Consultar por nome
4 - Listar
=>
O programa deve permitir o cadastro de no máximo 40 clientes. Após cada
inclusão, o programa deve perguntar, “Deseja nova inclusão(s/n)?”.
Caso o usuário não queira incluir mais clientes, a inclusão deve ser
encerrada. Após as inclusões, deve ser impresso na tela o número de clientes
cadastrados. O programa deve retornar ao menu inicial perimindo as operações
de incluir, alterar por código, consultar por nome e listar. Importante: se
o usuário escolher novamente a opção de Incluir, nenhum dado pode ser
sobrescrito. Cada novo cliente deve ser cadastrado na sequencia
(após o anterior). Para tanto, será necessário uma variável que indique o
numero de elementos no vetor. Para a opção de relatório todos os clientes
cadastrados devem ser listados. *//*}}}*/

#include <stdio.h>
#include <string.h>
#define v 3
#define n 45

struct cadastro{
    int cod, tel;
    char nome[n], end[n], email[15];
};

int incluir(struct cadastro cliente[v], int contador)
{
    char resp;
    do {
        printf("\n Cadastro %d", contador);
        printf("\n Digite seu código: ");
        scanf("%d", &cliente[contador].cod);
        getchar();
        printf("\n Digite seu nome: ");
        gets(cliente[contador].nome);
        printf("\n Digite seu endereço: ");
        gets(cliente[contador].end);
        printf("\n Digite seu telefone: ");
        scanf("%d", &cliente[contador].tel);
        getchar();
        printf("\n Digite seu e-mail: ");
        gets(cliente[contador].email);
        printf("\n Cadastrar mais cliente (S, N)? ");
        scanf("%c", &resp);
        getchar();
        contador++;
    //    if (resp != 's' || resp != 'S') {
      //      break;
       // }
    } while (resp == 's' || resp == 'S');
    return (contador);
}

void altDadosPorCod(struct cadastro cliente[v], int controle)
{
    int consulta, i, novoCod, novoTel;
    char r1, r2, r3, r4, r5, novoNome[n], novoEnd[n], novoEmail[n];
    printf("\n Aterar dados por código.");
    printf("\n Digite um código: ");
    scanf("%d", &consulta);
    getchar();
    for (i = 0; i < controle; ++i) {
        if (consulta == cliente[i].cod) {
            printf("\n=======================");
            printf("\n Editando o cadastro %d", i);
            printf("\n Editando código %d", cliente[i].cod);
            printf("\n Alterar (S, N)? ");
            scanf("%c", &r1);
            getchar();
            if (r1 == 's' || r1 == 'S') {
                printf("\n Qual é o novo código: ");
                scanf("%d", &novoCod);
                cliente[i].cod = novoCod;
            }
            printf("\n Editando nome %s", cliente[i].nome);
            printf("\n Alterar (S, N)? ");
            scanf("%c", &r2);
            getchar();
            if (r2 == 's' || r2 == 'S') {
                printf("\n Qual é o novo nome: ");
                gets(novoNome);
                strcpy (cliente[i].nome, novoNome);
            }
            printf("\n Editando endereço %s", cliente[i].end);
            printf("\n Alterar (S, N)? ");
            scanf("%c", &r3);
            getchar();
            if (r3 == 's' || r3 == 'S') {
                printf("\n Qual é o novo endereço: ");
                gets(novoEnd);
                strcpy (cliente[i].end, novoEnd);
            }
            printf("\n Editando telefone %d", cliente[i].tel);
            printf("\n Alterar (S, N)? ");
            scanf("%c", &r4);
            getchar();
            if (r4 == 's' || r4 == 'S') {
                printf("\n Qual é o novo telefone: ");
                scanf("%d", &novoTel);
                cliente[i].tel = novoTel;
            }
            printf("\n Editando e-mail %s ", cliente[i].email);
            printf("\n Alterar (S, N)? ");
            scanf("%c", &r5);
            getchar();
            if (r5 == 's' || r5 == 'S') {
                printf("\n Qual é o novo e-mail: ");
                gets(novoEmail);
                strcpy (cliente[i].email, novoEmail);
            }
            printf("\n");
        }
        if (consulta != cliente[i].cod) {
            printf("\n Cadastro não encontrado!");
        }
    }
}

void consPorNome(struct cadastro cliente[v], int controle)
{
    char consulta[20];
    int i, compara;
    printf("\n Consultar por nome.");
    printf("\n Digite um nome: ");
    gets(consulta);
    for (i = 0; i < controle; ++i) {
        compara = strcmp(cliente[i].nome, consulta);
        if (compara == 0) {
            printf("\n=======================");
            printf("\n Cadastro %d", i);
            printf("\n Código %d", cliente[i].cod);
            printf("\n Nome %s", cliente[i].nome);
            printf("\n Endereço %s", cliente[i].end);
            printf("\n Telefone %d", cliente[i].tel);
            printf("\n E-mail %s ", cliente[i].email);
            printf("\n");
        }else if (compara != 0) {
            printf("\n Cadastro não encontrado!");
        }
    }

}

void listar(struct cadastro cliente[v], int controle)
{
    int i;
    for (i = 1; i < controle; ++i) {
        printf("\n=======================");
        printf("\n Cadastro %d", i);
        printf("\n Código %d", cliente[i].cod);
        printf("\n Nome %s", cliente[i].nome);
        printf("\n Endereço %s", cliente[i].end);
        printf("\n Telefone %d", cliente[i].tel);
        printf("\n E-mail %s ", cliente[i].email);
        printf("\n");
    }
}

int main()
{
    struct cadastro cliente[v];
    int i, op, controle = 1;

    for (i = 0; i < v; ++i) {
        printf("\n =========Cadastro de Clientes==========");
        printf("\n Escolha uma opção:");
        printf("\n 1 - Incluir \n 2 - Alterar dados por código");
        printf("\n 3 - Consultar dados por código \n 4 - Listar");
        printf("\n => ");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1:
                controle = incluir(cliente, controle);
                break;
            case 2:
                altDadosPorCod(cliente, controle);
                break;
            case 3:
                consPorNome(cliente, controle);
                break;
            case 4:
                listar(cliente, controle);
                break;
            default:
                printf("\n Digite uma opção válida!!!");
        }
    }
    return 0;
}
