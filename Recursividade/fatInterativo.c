#include <stdio.h>
#include <stdlib.h>

int fatINTER(int n){
    int f = 1;
    int i;
    for (i = n; i >= 1; i--){
        f = f * i;
    }

    return f;

    }


int main(int arg, char *argv[]){
    int n;
    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, fatINTER(n));
    
}