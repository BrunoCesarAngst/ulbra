/*
	Feito por: Bruno Angst & Ramon
	Professora: Adriana Bueno 
*/
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

/*//funcao incluir_peca
Incluir_peca
Entrada: vetor com as estruturas para armazenar as informações das peças e número de elementos no vetor.
Saída: número de elementos do vetor(valor após inclusões).
Descrição: Faz a leitura de n elementos no vetor de pecas. A cada inclusão deve ser perguntado 
se o usuário deseja incluir uma nova peca. As inclusões devem ser encerradas quando o usuário responder “N”.*/
int incluir_peca(struct pecas peca[100], int i){
	char resp;

	do {
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
		do{
			printf("\nIncluir mais pecas(s/n)? ");
	        scanf("%c", &resp);
	        getchar();	
    	}while((resp != 's' && resp != 'S') && (resp != 'n' && resp != 'N'));
	
        i++;

	} while (i < 100 && (resp == 's' || resp == 'S'));

	return(i);
}

/*funcao consultar_peca
Consultar_peca_por_nome
Entrada: vetor de peças, número de peças cadastrados e o nome de uma peça(30 caracteres).
Saída: nenhuma
Descrição: Exibe na tela os dados da peça que tem o nome especificado.*/
void consulta_peca(struct pecas peca[100], int i, char nome_peca[30]){
	int x;
	for(int j = 0; j < i; j++){
		printf("%d \n", strcmp(nome_peca, peca[j].nome));
		if(strcmp(nome_peca, peca[j].nome)) {
			printf("\nNome: %s", peca[j].nome);
			printf("\nMarca: %s", peca[j].marca);
			printf("\nPreco: %f", peca[j].preco);
			printf("\nEstoque minimo: %d", peca[j].qtd_minima);
			printf("\nQuantidade em estoque: %d", peca[j].qtd_estoque);
		}
	}
}


/*/funcao listar
Exibir_peca_estoque_baixo
Entrada: vetor de pecas e o número de pecas cadastradas.
Saída: nenhuma.
Descrição: Mostra na tela os nomes das peças, quantidade em estoque e estoque mínimo,
para todas as peças que possuem estoque abaixo do estoque mínimo.*/
void listar(struct pecas peca[100], int i){
	for (int j = 0; j < i; j++){
		if(peca[i].qtd_estoque < peca[i].qtd_minima){
			printf("\nNome: %s", peca[i].nome);
			printf("\nEstoque minimo: %d", peca[i].qtd_minima);
			printf("\nQuantidade em estoque: %d\n", peca[i].qtd_estoque);
		}
	}
}


/*/funcao vender
Vender_peca
Entrada: vetor de pecas e o número de pecas cadastradas.
Saída: nenhuma.
Descrição: Le o nome da peça que vai ser vendida e a quantidade da venda. Procura a peça e 
atualiza a quantidade em estoque da peça que está sendo vendida (quantidade em estoque – quantidade vendida).
Caso a peça fique com estoque abaixo do mínimo, a função deve escrever na tela 
“A peça x ficou com estoque x - ABAIXO DO MÍNIMO”.*/
void vender(struct pecas peca[100], int i){
	char nome[30];
	int qtd_venda;

	printf("Nome da peca: ");
	gets(nome);

	printf("Quantidade vendida: ");
	scanf("%d", &qtd_venda);

	for(int j = 0; j < i; j++){
		if(strcmp(peca[j].nome, nome) == 0){
			/*verifica se a quantidade de produtos requisitados não é maior que a quantidade em estoque
			se não for maior diminui a quantidade requisitada da quantidade em estoque*/
			if(qtd_venda > peca[j].qtd_estoque){ 
				printf("Só temos %d em estoque\n", peca[j].qtd_estoque);
				break;
			}else{
				peca[j].qtd_estoque -= qtd_venda;
				
				//verifica se a peca está abaixo do minimo e da a mensagem
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
