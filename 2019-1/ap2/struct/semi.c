/*
Escreva um programa para realizar o cadastro de, no máximo, 100 automóveis. 

Para cada automóvel deve ser armazenado: placa, nome, marca, ano e quilometragem.

A cada inclusão de caro o programa deve perguntar se o usuário deseja incluir outro. 

Caso o usuário não queira mais incluir, o programa deve encerrar as inclusões e oferecer a opção de pesquisar carro por placa. 

O programa deve listar todos os dados do carro que tem a placa procurada.

OBS: Utilize um struct para organizar as informações e um vetor para os 100 automóveis.

*/

#include <string.h>
#include <stdio.h>

struct automovel
{
	char placa[10];
	char nome[10];
	char marca[10]; 
	int ano; 
	float quilometragem;
};


main()
{
	
	struct automovel veiculo[10]; //MUDAR PARA 100 AUTOMOVEIS
	char placa[10], resp;
	int r;
	int i = 0, veiculo_indice = 0;

	do{

		printf("Insira os dados do veiculo: \n");
		printf("Marca: ");
		gets(veiculo[i].marca);

		printf("Nome: ");
		gets(veiculo[i].nome);

		printf("Placa: ");
		gets(veiculo[i].placa);

		printf("Ano: ");
		scanf("%d", &veiculo[i].ano);
		getchar();

		printf("Quilometragem: ");
		scanf("%f", &veiculo[i].quilometragem);
		getchar();

		do{
			printf("\nDeseja adicionar mais um veiculo na lista? ");
			scanf("%c", &resp);
			getchar();
		}while((resp != 'n' && resp != 'N') && (resp != 's' && resp != 'S'));

		i++;
		veiculo_indice = i;

	}while(veiculo_indice < 10 && (resp != 'n' && resp != 'N'));

	do{

		printf("\nDeseja pesquisar por placa? ");
		scanf("%c", &resp);
		getchar();

		if (resp == 'S' || resp == 's')
		{
			printf("Informe a placa do veiculo: ");
			gets(placa);

			for (i = 0; i < veiculo_indice; i++)
			{

				r = strcmp(veiculo[i].placa, placa);

				if (r == 0)
				{
					printf("Dados do automovel: \n");
					printf("Placa: %s \n", veiculo[i].placa);
					printf("Marca: %s \n", veiculo[i].marca);
					printf("Nome: %s \n", veiculo[i].nome);
					printf("Quilometragem: %0.1f \n", veiculo[i].quilometragem);
					printf("Ano %d \n\n\n", veiculo[i].ano);
				}
			}
		}
		else if((resp != 's' && resp != 'S') && (resp != 'n' && resp != 'N')){
			printf("Por favor digite S para Sim ou N para Não !!!\n\n");
		}

	}while(resp != 'n' && resp != 'N');
}