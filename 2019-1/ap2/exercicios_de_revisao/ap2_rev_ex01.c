#include <stdio.h>

int main(void)
{
	int idade;
		
	printf("Qual é sua idade? ");
	scanf("%i", &idade);

	if(idade < 16){
		printf("Você não pode votar!!!");
	}
    else if((idade >= 16 && idade <= 17) || idade > 60){
		printf("Votar é facultativo!!");
	}
	else {
     printf("Seu voto é obrigatório!");
	}

	return 0;
}
