#include <stdio.h>

void leVetor(int vet[5]){
    int i;
    for (i = 0; i < 5; ++i) {
        printf("\n vetor [%d]: ", i);
        scanf("%d", &vet[i]);
    }
}

void soma(int a[5], int b[5], int c[5]){
    int i;
    for (i = 0; i < 5; ++i) {
       c[i] = a[i] = a[i] + b[i];
    }
}

int main(int argc, char *argv[])
{
    int v1[5], v2[5], v3[4], i;
    leVetor(v1);
    leVetor(v2);
    soma(v1, v2, v3);

    for (i = 0; i < 5; ++i) {
        printf("\n vetor soma [%d]: %d", i, v3[i]);
    }
    return 0;
}
