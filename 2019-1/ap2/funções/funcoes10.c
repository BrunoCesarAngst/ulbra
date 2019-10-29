#include <stdio.h>

struct ficha{
    char nome[40];
    int idade;
};

int leAlunos(struct ficha a[100], int cont){
    char resp;

    do {
        printf("\n Nome[%d]", cont);
        gets(a[cont].nome);
        printf("\n Idade: ");
        scanf("%d", &a[cont].idade);
        getchar();
        printf("\n incluir outro(s/n)? ");
        scanf("%c", &resp);
        getchar();
        cont++;
    } while (resp == 's' || resp == 'S');
    return (cont);
}

int main()
{
    struct ficha alunos[100];
    int controle = 0, op, i;

    do {
       printf("\n Escolha uma opção:"); 
       printf("\n 1- Incluir \n 2- Lista \n 3- Sair \n =>");
       scanf("%d", &op);
       getchar();
       switch (op) {
           case 1:
               controle = leAlunos(alunos, controle);
               break;
           case 2:
               for (i = 0; i < controle; ++i) {
                   printf("\n nome[%d]: %s", i, alunos[i].nome);
                   printf("\n Idade: %d", alunos[i].idade);
               }
                break;
           case 3:
               printf("\n Programa encerrado!");
               break;
           default:
               printf("\n Não");
               break;
       }   
    } while (op != 3);

    return 0;
}
