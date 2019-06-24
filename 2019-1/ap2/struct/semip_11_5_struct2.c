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
    char add_in,
         consult[8];
    int i,
        counter = 0,
        examiner,
        position;

    for (i = 0; i < v; ++i) {
        printf("\n ++++++++++++++++++++++++++++++++++++++++++");
        printf("\n\t Cadastro de Automóvel \n");
        printf(" Digite a placa do automóvel: ");
        gets(car[i].plate);
        counter++;
        printf(" Nome do automóvel: ");
        gets(car[i].name);
        printf(" Marca do automóvel: ");
        gets(car[i].mark);
        printf(" Ano do automóvel: ");
        scanf(" %d", &car[i].year);
        __fpurge(stdin);
        printf(" Km do automóvel: ");
        scanf(" %d", &car[i].km);
        __fpurge(stdin);
        printf("\n Deseja incluir outro automóvel (S ou N): ");
        scanf(" %c", &add_in);
        __fpurge(stdin);
        if (add_in == 'n' || add_in == 'N') {
            break;
        } else if (counter == v) {
            printf("\n\t Limite de cadastro atingido (100)");
            break;
        }
    }

    printf("\n ++++++++++++++++++++++++++++++++++++++++++");
    printf("\n Placas cadastradas: ");
    for (i = 0; i < counter; ++i) {
        printf(" %s", car[i].plate);
    }
    printf("\n Pesquisar por placa: ");
    gets(consult);
    __fpurge(stdin);

    for (i = 0; i < counter; ++i) {
        examiner = strcmp(car[i].plate, consult);
        if (examiner == 0) {
            printf("\n ++++++++++++++++++++++++++++++++++++++++++");
            printf("\n\t Registro Encontrado");
            printf("\n O nome é: %s", car[i].name);
            printf("\n A marca é: %s", car[i].mark);
            printf("\n O ano é: %d", car[i].year);
            printf("\n O km é: %d", car[i].km);
            printf("\n\t Pesquisa encerrada!");
            printf("\n ++++++++++++++++++++++++++++++++++++++++++");
        } else if (examiner != 0){
            printf("\n\t Placa não encontrada!");
        }
    }

    return 0;
}
