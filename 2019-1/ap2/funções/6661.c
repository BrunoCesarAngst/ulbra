#include <stdio.h>
#include <string.h>

/*Estrutura da peca*/
struct pecas {
	char nome[30];
	char marca[30];
	float preco;
	int qtd_estoque;
	int qtd_minima;
};

int incluir_peca(struct pecas peca[100], int i){
	char resp;

	do{
		printf("Insira os dados da peca %d : \n", i+1);
		printf("\nNome: ");
		gets(peca[i].nome);

		printf("\nMarca: ");
		gets(peca[i].marca);

		printf("\nPreco: ");
		scanf("%f", &peca[i].preco);
		getchar();

		printf("\nEstoque: ");
		scanf("%d", &peca[i].qtd_estoque);
		getchar();

		printf("\nMinimo: ");
		scanf("%d", &peca[i].qtd_minima);
		getchar();

        i++;

		do{
			printf("\nIncluir mais pecas(s/n)? ");
	        scanf("%c", &resp);
	        getchar();	
            if (!strchr("SsNn", resp)) {
                printf("\nResposta inválida!");
            }
    	}while(!strchr("SsNn", resp) && i < 100);
	}while (!strchr("SsNn", resp) && i < 100);

	return(i);
}

void consulta_peca(struct pecas peca[100], int i, char nome_peca[30]){
	flag = 0;
	for(int j = 0; j < i; j++){
		if(strcmp(nome_peca, peca[j].nome)) {
			printf("\nNome: %s", peca[j].nome);
			printf("\nMarca: %s", peca[j].marca);
			printf("\nPreco: %f", peca[j].preco);
			printf("\nEstoque minimo: %d", peca[j].qtd_minima);
			printf("\nQuantidade em estoque: %d", peca[j].qtd_estoque);
            flag = 1;
		}
        if (flag == 0) {
            printf("\nPeça não encontrada");
        }
	}
}


void listar(struct pecas peca[100], int i){
	for (int j = 0; j < i; j++){
		if(peca[i].qtd_estoque < peca[i].qtd_minima){
			printf("\nNome: %s", peca[i].nome);
			printf("\nEstoque minimo: %d", peca[i].qtd_minima);
			printf("\nQuantidade em estoque: %d\n", peca[i].qtd_estoque);
		}
	}
}


void vender(struct pecas peca[100], int i){
	char nome[30];
	int qtd_venda;

	printf("Nome da peca: ");
	gets(nome);

	printf("Quantidade vendida: ");
	scanf("%d", &qtd_venda);

	for(int j = 0; j < i; j++){
		if(strcmp(peca[j].nome, nome) == 0){
			if(qtd_venda > peca[j].qtd_estoque){ 
				printf("Só temos %d em estoque\n", peca[j].qtd_estoque);
				break;
			}else{
				peca[j].qtd_estoque -= qtd_venda;
				if(peca[j].qtd_estoque < peca[j].qtd_minima){
					printf("A peca %s ficou com estoque %d - ABAIXO DO MINIMO! \n", peca[j].nome, peca[j].qtd_estoque);
				}
				break;
			}
		}
	}
}



int main(){
	struct pecas peca[100];
	int r = 1, i = 0;
	int op;
	char nome[30];

	do{

		printf("1 - Incluir peça\n");
		printf("2 - Consultar peça por nome\n");
		printf("3 - Exibir peças com estoque baixo\n");
		printf("4 - Vender peça\n");
		printf("5 - Sair\n");
		
		scanf("%d", &op);
		getchar();

		switch(op){
			case 1:
				i = incluir_peca(peca, i);
				break;
			case 2:
				printf("Nome da peca: ");
				gets(nome);
				consulta_peca(peca, i, nome);
				break;
			case 3:
				listar(peca, i);
				break;
			case 4:
				vender(peca, i);
				break;
			case 5:
				printf("Programa encerrado!\n");
				break;
			default:
				printf("\nOpcao incorreta!\n");
		}

	}while(op != 5);

	return 0;
}
