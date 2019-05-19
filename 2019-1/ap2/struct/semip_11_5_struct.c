// Escreva um programa para realizar o cadastro de, no máximo, 100 automóveis.
// Para cada automóvel deve ser armazenado: placa, nome, marca, ano
//e quilometragem.
// A cada inclusão de carro o programa deve perguntar se o usuário deseja
//incluir outro. Caso o usuário não queira mais incluir, o programa deve
//encerrar as inclusões e oferecer a opção de pesquisar carro por placa.
// O programa deve listar todos os dados do carro que tem a placa procurada.
// OBS: Utilize um struct para organizar as informações e um vetor para os 100
//automóveis.

#include <stdio.h>
#include <string.h>
#define v 3

struct car_registration{
    char plate [8],
         name [15],
         mark [15];
    int year,
        km;
};

int main()
{
    struct car_registration car[v];
    char add_in, consult[8];
    int i, counter = 0;

    for (i = 0; i < v; ++i) {
        do {
            printf("\n\t Cadastro de Automóveis \n");
            printf("Digite a placa do automóvel: ");
            gets(car[i].plate);
            printf("Nome do automóvel: ");
            gets(car[i].name);
            printf("Marca do automóvel: ");
            gets(car[i].mark);
            printf("Ano do automóvel: ");
            scanf("%d", &car[i].year);
            printf("Km do automóvel: ");
            scanf("%d", &car[i].km);
            __fpurge(stdin);
            do {
                printf("\n Deseja cadastrar outro automóvel(S ou N)? ");
                scanf("%c", &add_in);
                __fpurge(stdin);
                if ((add_in != 's' || add_in != 'S') ||
                        (add_in != 'n'|| add_in != 'N'))  {
                    printf("\n Digite S ou N!!!");
                }
            } while ((add_in != 's' || add_in != 'S') ||
                     (add_in != 'n'|| add_in != 'N'));
            counter++;
        } while (add_in == 's' || add_in == 'S');
        if (add_in == 'n' || add_in == 'N') {
            break;
        }
    }

    if (add_in == 'n' || add_in == 'N') {
        printf("\n\t Pesquisa por placa \n");
        printf("Placas cadastradas: ");
        for (i = 0; i < counter; ++i) {
            printf("%s", car[i].plate);
        }
        printf("\n Qual placa desejas consultar: ");
        gets(consult);
    }

    return 0;
}
