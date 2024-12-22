#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){

    //caso básico

    if (n == 0) {
        return 1;
    }

    // caso recursivo
    return n * fatorial(n - 1);
}

int fibo( int n){

    //caso recursivo

    if (n == 1){
        return 0;
    }

    if (n == 2){
        return 1;
    }    

    return fibo(n - 1) + fibo(n - 2);
}

int main(int arg, char *argv[]){
    int n;
    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, fibo(n));
    
}