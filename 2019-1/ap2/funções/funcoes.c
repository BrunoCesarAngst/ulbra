#include <stdio.h>

int quadrado (int num){
    int r;
    r = num * num;
    return(r);
}

int main(int argc, char *argv[])
{
    int n,q;
    printf("\n Digite um número: ");
    scanf("%d", &n);
    q = quadrado(n);
    printf("\n O quadrado de %d é %d", n, q);
    return 0;
}
