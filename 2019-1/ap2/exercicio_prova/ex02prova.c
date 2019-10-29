/*2. Escreva um programa em C para ler uma frase, de no máximo 100 caracteres, e uma letra. A seguir retirar da frase, todas as letras iguais a informada. Imprima a frase modificada. (2,0).
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char frase[100], frasen[100], letra;
    int tam = 0, i, n = 0;
    printf("\n Escreva uma frase: ");
    gets(frase);

    printf("\n Digite uma letra: ");
    scanf(" %c", &letra);

    tam = strlen(frase);

    for (i = 0; i <= tam; ++i) {
        if (frase[i] != letra) {
            frasen[n] = frase[i];
            n++;
        }
    }
    
    printf("%s\n", frasen);
    return 0;
}
