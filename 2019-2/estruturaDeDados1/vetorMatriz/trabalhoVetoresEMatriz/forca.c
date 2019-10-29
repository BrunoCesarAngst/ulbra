#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

	char respostaCerta[10] = {"bergamota"}; //vetor onde esta a resposta
	char vetorDeChutes[10]; //vetor que vai recever os chutes feito pelo jogador
	char letraChutada; //letra que o jogador vai chutar
	int numeroDeTentativas = 7; //numero de erros permitidos
	bool acerto = false;
	int tamanhoDaRespostaCerta = strlen(respostaCerta);

	//Popula o vetor palavra com traços, usando um for
	//cujo tamanho é de no maximo o tamanho da string resposta
	for (int i = 0; i < tamanhoDaRespostaCerta; i++) {
		vetorDeChutes[i] = '-';
	}
	
	vetorDeChutes[tamanhoDaRespostaCerta] = '\0';

	while (numeroDeTentativas > 0 && strcmp(vetorDeChutes, respostaCerta)) {
		printf("Letra: ");
		scanf("%c", &letraChutada);
		getchar();

		acerto == false;

        //for que faz iteração com cada índice da palavra, ou seja, cada caracter
		for (int i = 0; i < tamanhoDaRespostaCerta; i++) { 
			if (letraChutada == respostaCerta[i]) {
				vetorDeChutes[i] = letraChutada;
				acerto = true;
			}
		}

		if (acerto == false) {
			printf("Voce errou e agora tem mais %d \n", numeroDeTentativas-1);
			numeroDeTentativas--;
			if (numeroDeTentativas == 0) {
				printf("VOCE PERDEU\n");
				strcpy(vetorDeChutes, respostaCerta);
			}
		} else {
			if (strcmp(vetorDeChutes, respostaCerta) == 0) {
				printf("Parabens você ganhou\n");
			}
		}

		printf("palavra: %s \n", vetorDeChutes);
	}
}
