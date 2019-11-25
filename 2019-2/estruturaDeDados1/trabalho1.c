#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[9] = {9, 7, 2, 4, 8, 6, 5, 1, 3};
    int i, j, aux;
    int tam = 0;
    tam = sizeof(vetor)/sizeof(vetor[0]);
    
    for(i = 1; i <= tam; i++) {
        j = i;
        while((j != 0) && (vetor[j] > vetor[j - 1])) {
            aux = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = aux;
            j--;            
        }
    }
    printf("\n[");
    for(i = tam; i >= 1; i--) {
        printf("%i ", vetor[i]);
    }
    printf("].\n");
}
// que tem esse resultado [1 2 3 4 5 6 7 8 9 ].