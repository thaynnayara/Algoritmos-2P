#include <stdio.h>
#include <stdlib.h>

//Calcular a sequência de Fibonacci recursivamente

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
    printf("Digite um valor para calcular a sequencia de Fibonacci: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, fibo(n));
    
}