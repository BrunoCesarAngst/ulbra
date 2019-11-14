#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct alunos{
	char nome[30], telefone[30], email[30];
	int codigo;
	float g1, g2;
} Aluno;

typedef struct nodo{
	Aluno dados;
	struct nodo *elo;
} Nodo;

typedef struct descritor{
	Nodo *primeiro;
	Nodo *ultimo;
	int nElementos;
} Descritor;

void CriaLista(Descritor *d){
	d->primeiro = NULL;
	d->nElementos = 0;
	d->ultimo = NULL;
}

void IncluirInicio(Descritor *d, Aluno dados){
	Nodo *n;
	
	n = (Nodo*) malloc (sizeof(Nodo));
	if(n == NULL)
		printf("\nLISTA CHEIA OU INEXISTENTE.");
	else{
		n->dados = dados;
		n->elo = d->primeiro;
		d->primeiro = n;
			if(d->nElementos == 0){
				d->ultimo = n;
				d->nElementos++;
			}
		printf("\nELEMENTO INCLUIDO COM SUCESSO!");
	}
}

void IncluirFinal(Descritor *d, Aluno dados){
	Nodo *n;
	
	n = (Nodo*) malloc(sizeof(Nodo));
	if(n == NULL)
		printf("\nLISTA CHEIA OU INEXISTENTE.");
	else{
		n->dados = dados;
		n->elo = NULL;
		if(d->nElementos == 0){
			d->primeiro = n;
		}else{
			d->ultimo->elo = n;
			d->ultimo = n;
			d->nElementos++;
			printf("\nELEMENTO INCLUIDO COM SUCESSO!");
		}
	}
}

void IncluirAposNome(Descritor *d, Aluno dados, char nomeProcurado[30]){
	Nodo *n, *novoNodo, *aux;
  int contador;
  Aluno al;
	
	if(d->primeiro == NULL)
		printf("\nLISTA VAZIA OU INEXISTENTE.");
	else{
		n = d->primeiro;
		while(n != NULL){
			contador = strcmp(nomeProcurado,n->dados.nome);
      if (contador==0){
        break;
      }
      n = n->elo;
    }
    if(contador==0){
      al = dados;
      novoNodo = (Nodo*) malloc (sizeof(Nodo));
      if(novoNodo == NULL) {
        printf("faltou memória");
      } else {
      novoNodo->dados = al;
      if(novoNodo->elo == NULL){ ///aqui
        n->elo = novoNodo;
        d->ultimo = novoNodo;
        novoNodo->elo = NULL;
        } else {
          aux = n->elo;
          n->elo = novoNodo;
          novoNodo->elo = aux;
        }
        d->nElementos++;
      }
    }else{
      printf("\nNOME NAO ENCONTRADO.");
    }
	}
}

void ConsultarPorNome(Descritor *d, Aluno dados, char nomeProcurado[30]){
	Nodo *n;
	
	if(d->primeiro == NULL){
		printf("\nLISTA VAZIA OU INEXISTENTE.");
	}else{
		n = d->primeiro;
		while(n != NULL){
			if(strcmp(nomeProcurado,n->dados.nome)==0){
				printf("\nCodigo: %d", n->dados.codigo);
				printf("\nNome: %s", n->dados.nome);
				printf("\nE-mail: %s", n->dados.email);
				printf("\nTelefone: %s", n->dados.telefone);
				printf("\nNota G1: %.2f", n->dados.g1);
				printf("\nNota G2: %.2f", n->dados.g2);
				break;
			}
			n = n->elo;
		}
	}
}

void ExcluirInicio(Descritor *d){
	Nodo *n;
	
	if(d->primeiro == NULL){
		printf("\nLISTA VAZIA OU INEXISTENTE.");
	}else{
		n = d->primeiro;
		d->primeiro = n->elo;
		free(n);
		printf("\nELEMENTO REMOVIDO COM SUCESSO!");
	}
}

void ExcluirFinal(Descritor *d){
	Nodo *n, *ant;
	
	if(d->primeiro == NULL){
		printf("\nLISTA VAZIA OU INEXISTENTE.");
	}else{
		n = d->primeiro;
		while(n->elo != NULL){
			ant = n;
			n = n->elo;
		}
		if(n == d->primeiro){
			d->primeiro = NULL;
			d->ultimo = NULL;
		}else{
			ant->elo = n->elo;
			d->ultimo = ant;
		}
		free(n);
		d->nElementos--;
		printf("\nELEMENTO REMOVIDO COM SUCESSO!");
	}
}

void ExcluirPorCodigo(Descritor *d, int codigoProcurado){
	Nodo *n, *ant, *final, *aux, *prox;
	
	if(d->primeiro == NULL){
		printf("\nLISTA VAZIA");
	}else{
		n = d->primeiro;
		final = d->ultimo;
		while(n != NULL){
			if(codigoProcurado == n->dados.codigo){
				ExcluirFinal(d);
			}else if(codigoProcurado == final->dados.codigo){
				ExcluirInicio(d);
			}else{
				aux = d->primeiro;
				while(aux != NULL){
					if(codigoProcurado == aux->dados.codigo){
						break;
					}
					ant = aux;
					aux = aux->elo;
				}
				prox = aux->elo;
				ant->elo = prox;
				free(aux);
				d->nElementos--;
				printf("\nELEMENTO REMOVIDO COM SUCESSO!");
			}
		}
	}	
}

void ListarRegistros(Descritor *d){
	Nodo *n;
	
	if(d->primeiro == NULL){
		printf("\nLISTA VAZIA");
	}else{
		printf("\nLISTA:");
		n = d->primeiro;
		while(n != NULL){
			printf("\nCodigo: %d", n->dados.codigo);
			printf("\nNome: %s", n->dados.nome);
			printf("\nE-mail: %s", n->dados.email);
			printf("\nTelefone: %s", n->dados.telefone);
			printf("\nNota G1: %.2f", n->dados.g1);
			printf("\nNota G2: %.2f", n->dados.g2);
			printf("\n-----------------------\n");
			n = n->elo;
		}
	}
}

void ListarRegistrosComMedia(Descritor *d){
	Nodo *n;
	
	if(d->primeiro == NULL){
		printf("\nLISTA VAZIA");
	}else{
		printf("\nLISTA:");
		n = d->primeiro;
		while(n != NULL){
			printf("\nCodigo: %d", n->dados.codigo);
			printf("\nNome: %s", n->dados.nome);
			printf("\nE-mail: %s", n->dados.email);
			printf("\nTelefone: %s", n->dados.telefone);
			printf("\nNota G1: %.2f", n->dados.g1);
			printf("\nNota G2: %.2f", n->dados.g2);
			printf("\nMedia final: %.2f",n->dados.g1 + n->dados.g2 /2);
			printf("\n-----------------------\n");
			n = n->elo;
		}
	}
}

int main()
{
	int op=0;
	char nomeProcurado[30];
	Aluno a;
	Descritor d;
	int codigoProcurado;
	
	CriaLista(&d);
	while(op != 10){
		printf("\n\nESCOLHA UMA OPCAO");
	 	printf("\n[1]INCLUIR NO FINAL");
	 	printf("\n[2]INCLUIR NO INICIO");
	  	printf("\n[3]INCLUIR APOS UM NOME");
	  	printf("\n[4]CONSULTAR POR NOME");
	  	printf("\n[5]EXCLUIR DO INICIO");
	  	printf("\n[6]EXCLUIR DO FIM");
	  	printf("\n[7]EXCLUIR POR CODIGO");
	  	printf("\n[8]LISTAR TODOS OS REGISTROS");
	  	printf("\n[9]LISTAR COM MEDIAS FINAIS");
	  	printf("\n[10]SAIR");
	  	printf("\nOPCAO => ");
	  	scanf("%d", &op);
	  	system("cls");
	  	
	  	switch(op){
	  		case 1:
	  			printf("\nDIGITE OS DADOS DO ALUNO: ");
    			printf("\nCODIGO: ");
    			scanf("%d",&a.codigo);
    			// fflush(stdin);
          getchar();
    			printf("\nNOME: ");
    			gets(a.nome);
    			printf("\nEMAIL: ");
    			gets(a.email);
    			printf("\nTELEFONE: ");
    			gets(a.telefone);
    			printf("\nNOTA DA G1: ");
    			scanf("%f",&a.g1);
    			// fflush(stdin);
          getchar();
    			printf("\nNOTA DA G2: ");
    			scanf("%f",&a.g2);
    			
	  			IncluirFinal(&d, a);
	  			break;
	  			
	  		case 2:
	  			printf("\nDIGITE OS DADOS DO ALUNO: ");
    			printf("\nCODIGO: ");
    			scanf("%d",&a.codigo);
    			// fflush(stdin);
          getchar();
    			printf("\nNOME: ");
    			gets(a.nome);
    			printf("\nEMAIL: ");
    			gets(a.email);
    			printf("\nTELEFONE: ");
    			gets(a.telefone);
    			printf("\nNOTA DA G1: ");
    			scanf("%f",&a.g1);
    			// fflush(stdin);
          getchar();
    			printf("\nNOTA DA G2: ");
    			scanf("%f",&a.g2);
    			
	  			IncluirInicio(&d, a);
	  			break;
	  			
	  		case 3:
	  			printf("\nINFORME O NOME QUE DESEJA PROCURAR: ");
    			// fflush(stdin);
          getchar();
    			gets(nomeProcurado);
	  			
	  			printf("\nDIGITE OS DADOS DO ALUNO: ");
    			printf("\nCODIGO: ");
    			scanf("%d",&a.codigo);
    			// fflush(stdin);
          getchar();
    			printf("\nNOME: ");
    			gets(a.nome);
    			printf("\nEMAIL: ");
    			gets(a.email);
    			printf("\nTELEFONE: ");
    			gets(a.telefone);
    			printf("\nNOTA DA G1: ");
    			scanf("%f",&a.g1);
    			// fflush(stdin);
          getchar();
    			printf("\nNOTA DA G2: ");
    			scanf("%f",&a.g2);
    			
	  			IncluirAposNome(&d, a, nomeProcurado);
	  			break;
	  		
	  		case 4:
	  			printf("\nINFORME O NOME QUE DESEJA PROCURAR: ");
    			// fflush(stdin);
          getchar();
    			gets(nomeProcurado);
    			
    			ConsultarPorNome(&d, a, nomeProcurado);
	  			break;
	  			
	  		case 5:
	  			ExcluirInicio(&d);
	  			break;
	  			
	  		case 6:
	  			ExcluirFinal(&d);
	  			break;
	  			
	  		case 7:
	  			printf("\nINFORME O CODIGO QUE DESEJA REMOVER: ");
    			scanf("%d",&codigoProcurado);
    			
    			ExcluirPorCodigo(&d, codigoProcurado);
    			break;
	  			
	  		case 8:
	  			ListarRegistros(&d);
	  			break;
	  			
	  		case 9:
	  			ListarRegistrosComMedia(&d);
	  			break;
	  			
	  		case 10:
	  			printf("\nPROGRAMA FINALIZADO...");
	  			exit(0);
	  			
	  		default:
    			printf("\nOPCAO INVALIDA. DIGITE NOVAMENTE:");
			}
  	}
}
