#include <stdio.h>

int main() {
    int idade, maisvelho = 0, maisbaixo = 0, generoF = 0, count = 0;
    float altura, peso = 0, pesofeminino = 0, perc;
    char genero, resp;
    do {
        printf("Sua idade: \n");
				scanf("%d", &idade);
        if (idade > maisvelho) maisvelho = idade;
        printf("Sua altura: \n");
				scanf("%f", &altura);
        printf("Seu peso: \n");
				scanf("%f", &peso);
        do {
            printf("Seu genero(F-M): \n");
            scanf(" %c", &genero);
        } while ((genero != 'M') && (genero != 'm') && (genero != 'F') && (genero != 'f'));

        if (genero == 'f' || genero == 'F') {
            generoF++;
            pesofeminino += peso;
        } else if ((genero == 'm' || genero == 'M') && altura < 1.70) {
            maisbaixo++;
        }
        do {
            printf("Tem mais alguém para ser entrevistado?(S-N): ");
            scanf(" %c", &resp);
        } while ((resp != 'S') && (resp != 's') && (resp != 'N') && (resp != 'n'));
        count++;
    } while (resp != 'N' && resp != 'n');
    printf("\n\nMaior idade: %d\n", maisvelho);
    perc = (generoF * 100) / count;
    printf("%5.1f%% dos atletas são do genero feminino\n", perc);
    perc = 100 - perc;
    printf("%.2f%% dos atletas são do genero masculino\n", perc);
    if (pesofeminino > 0) pesofeminino /= generoF;
    printf("Peso medio das mulheres %.3f\n", pesofeminino);
    printf("%d dos homens tem menos que 1.70\n", maisbaixo);
}
