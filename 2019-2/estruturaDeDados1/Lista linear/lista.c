#include<stdio.h> 
#include<stdlib.h> 

struct Lista {

	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens; 

};

void criarLista( struct Lista *f, int c ) { 

	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void inserirNoFinal(struct Lista *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

void excluirNoFinal(struct Lista *f, int v) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

int remover( struct Lista *f ) { // pega o item do começo da Lista

	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( struct Lista *f ) { // retorna verdadeiro se a Lista estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia( struct Lista *f ) { // retorna verdadeiro se a Lista estÃ¡ cheia

	return (f->nItens == f->capacidade);
}

void mostrarLista(struct Lista *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%d ",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n");

}

void main () {

	int opcao, capa;
	int valor;
	struct Lista umaLista;

	// cria a Lista
	printf("\nCapacidade da Lista? ");
	scanf("%d",&capa);
	criarLista(&umaLista, capa);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover o último elemento\n5 - Mostrar Lista\n6 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){			

			case 1: // insere elemento
				if (estaCheia(&umaLista)){

					printf("\nLista Cheia!!!\n\n");

				}
				else {

					printf("\nValor do elemento a ser inserido? ");
					scanf("%d", &valor);
					inserirNoFinal(&umaLista,valor);

				}

				break;

			case 2: // remove o último elemento
				if (estaVazia(&umaLista)){

					printf("\nLista vazia!!!\n\n");

				}
				else {

					valor = remover(&umaLista);
					printf("\n%d removido com sucesso\n\n", valor) ; 

				}
				break;

      case 2: // remove elemento
				if (estaVazia(&umaLista)){

					printf("\nLista vazia!!!\n\n");

				}
				else {

					valor = excluirNoFinal(&umaLista);
					printf("\n%d removido com sucesso\n\n", valor) ; 

				}
				break;

      case 5: // mostrar Lista
        if (estaVazia(&umaLista)){

          printf("\nLista vazia!!!\n\n");

        }
        else {

          printf("\nConteudo da Lista => ");
          mostrarLista(&umaLista);

        }
        break;

      case 6: exit(0);

      default:
        printf("\nOpcao Invalida\n\n");

		}
	}
}
