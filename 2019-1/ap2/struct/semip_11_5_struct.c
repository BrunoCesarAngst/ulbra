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

struct cadastro_automoveis {
    char placa [8],
         nome [15],
         marca [15];
    int ano,
        km;
};

int main(int argc, char *argv[])
{
    do {
        printf("Cadastro de Automóveis\n");
        printf("Digite a placa do automóvel: ");
        sc
    } while (includ == s);
    return 0;
}
