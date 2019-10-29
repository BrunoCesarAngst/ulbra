#include <stdio.h>
#define a 2

void leMatriz(float m[a][a]){
    int l, c;
    for (l = 0; l < a; ++l) {
        for (c = 0; c < a; ++c) {
            printf("digite L%d - C%d: ", l+1, c+1);
            scanf("%f", &m[l][c]);
        }
    }
}

void escreveMatriz(float m[a][a]){
    int l, c;
    for (l = 0; l < a; ++l) {
        for (c = 0; c < a; ++c) {
            printf("%2.0f", m[l][c]);
        }
        printf("\n");
    }
}

int procuraIguaisEmMesmaPosicao(float m1[a][a], float m2[a][a]){
    int cont = 0;
    for (int l = 0; l < a; ++l) {
        for (int c = 0; c < a; ++c) {
            if (m1[l][c] == m2[l][c]) {
                cont++;
            }
        }
    }
    return (cont);
}

int main(){
    float m1[a][a], m2[a][a];
    int x;

    printf("Escreva matriz m1 \n");
    leMatriz(m1);
    printf("Escreva matriz m2 \n");
    leMatriz(m2);

    printf("Matriz m1 \n");
    escreveMatriz(m1);
    printf("Matriz m2 \n");
    escreveMatriz(m2);
    x = procuraIguaisEmMesmaPosicao(m1, m2);

   printf("\n Número de elementos iguais na mesma posição: %d \n", x);
   printf("\n");
}
