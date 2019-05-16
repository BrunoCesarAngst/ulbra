/*Uma escola deseja armazenar as seguintes informações sobre os seus professores: Nome, endereço, telefone, idade, sexo, titulação. Escreva um algoritmo que leia todas estas informações de 20 professores. As informações devem ser armazenadas em um vetor de 20 posições. Logo após a leitura deve ser informado o número de professores do sexo masculino, a média das idades de todos os professores e os nomes dos professores que tem idade acima da média.*/

#include <stdio.h>
#include <string.h>

struct info_prof{
    char nome [50],
         end [80],
         sexo,
         titulacao[50];
    int tel,
        idade;
};

int main()
{
    struct info_prof cadastro [20];
    int i,
        cont = 0,
        men = 0,
        tIdade;
    float medIdade;

    for (i = 0; i < 20; ++i) {
        printf("\nCadastro [%d]\n", i + 1);
        printf("Seu nome: ");
        gets(cadastro[i].nome);
        printf("Seu endereço: ");
        gets(cadastro[i].end);
        printf("Seu telefone: ");
        scanf(" %d", &cadastro[i].tel);
        printf("Sua idade: ");
        scanf(" %d", &cadastro[i].idade);
        __fpurge(stdin);
        printf("Seu sexo(F/M): ");
        scanf(" %c", &cadastro[i].sexo);
        __fpurge(stdin);
        printf("Seu título: ");
        gets(cadastro[i].titulacao);

        cont++;

        if (cadastro[i].sexo == 'm' || cadastro[i].sexo == 'M') {
            men++;
        }

        tIdade += cadastro[i].idade;

    }

    printf("\n Temos %d de professores do sexo masculino.", men);

    medIdade = tIdade / cont;

    printf("\n A média das idades dos professores é de %0.2f.", medIdade);
    printf("\n Esses são os professores que estão com idade acima da média: \n");
    for (i = 0; i < 20; ++i) {
        if (cadastro[i].idade > medIdade) {
            printf("%s\n", cadastro[i].nome);
        }
    }

    return 0;
}
