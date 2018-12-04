/*2. Faça um algoritmo que leia a altura de um nadador e valide se ela esta correta para ele participar de uma competição, se estiver incorreta, informe e solicite nova altura. A altura deve estar entre 1,60m e 1,90m. Depois de validada, leia sua idade e classifique-a na sua categoria:
Entre 8 e 10 anos: infantil
Entre 11 e 13 anos: Juvenil A
Entre 14 e 17 anos: Juvenil B
Mais do que 17 anos: adulto.
Lembre-se de verificar se a idade não é menor do que 8. Se for, avisar que esta idade esta fora da competição.*/

#include <stdio.h>
int main(int argc, char const *argv[]) {
  float alt;
  int idade;
  do {
    printf("Qual é a sua altura: \n");
    scanf("%f", &alt);
    if (alt >= 1.6 && alt <= 1.9) {
      printf("Altura OK!\n");
    } else {
      printf("Altura incorreta!\n");
      printf("Proximo por favor!\n");
    }
  while(alt >= 1.6 && alt <= 1.9) {
    printf("Qual é a sua idade: \n");
    scanf("%i", &idade);
    if (idade >= 8 && idade < 10) {
      printf("Categoria infantil\n");
    } else if (idade >= 10 && idade <= 13) {
      printf("Categoria juvenil A\n");
    } else if (idade >= 14 && idade <= 17) {
      printf("Categoria juvenil B\n");
    } else if (idade > 17) {
      printf("Categoria adulta\n");
    } else if (idade < 8) {
      printf("Idade inválida!\n");
      printf("Proximo por favor!\n");
    }
  }
  } while(alt <= 1.6 && alt >= 1.9 && idade < 8);
  return 0;
}
