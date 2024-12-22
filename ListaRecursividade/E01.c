#include <stdio.h>
#include <stdlib.h>

//Fatorial de um número usando recursividade direta.

int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
        }
}

int main(int arg, char *argv[]){
    int n;
    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, fatorial(n));
    
}