#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int jogada_computador(){
	int r;
	srand(time(NULL));
	r = (rand() % 3) + 1;
	return r;
}

int jogada_jogador(){
	int aux;
	char jogada;
	bool loop = true;
	do{
		printf("Escolha uma opção: \n1 ------ Pedra \n2 ------ Papel \n3 ------ Tesoura \n>>");
		scanf("%c", &jogada);

	}while(strchr("123", jogada) == 0);

	aux = jogada - '0';
	//printf("%d", jogada);
	return aux;
}

void compara_jogadas(int c, int j){

	if(j == c){
		printf("empatou");
	}else{

		if(j == 1 && c == 2){
			printf("Você jogou pedra e o computador jogou papel\n");
			printf("computador ganhou");
		}

		if(j == 1 && c == 3){
			printf("Você jogou pedra e o computador jogou tesoura\n");
			printf("você ganhou");
		}

		if(j == 2 && c == 1){
			printf("Você jogou papel e o computador jogou pedra\n");
			printf("você ganhou");
		}

		if(j == 2 && c == 3){
			printf("Você jogou papel e o computador jogou tesoura\n");
			printf("computador ganhou");
		}

		if(j == 3 && c == 1){
			printf("Você jogou tesoura e o computador jogou pedra\n");
			printf("computador ganhou");
		}

		if(j == 3 && c == 2){
			printf("Você jogou tesoura e o computador jogou papel\n");
			printf("jogador ganhou");
		}
	}

}

void main(){

	int jogada_c, jogada_j;

	jogada_c = jogada_computador();

	jogada_j = jogada_jogador();

	compara_jogadas(jogada_c, jogada_j);

}
