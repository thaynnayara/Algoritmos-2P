#include <stdio.h>
#include <stdlib.h>

int SomaRecu(int n){
    
    if (n == 0){
        return 0;
    }

    return n = n + SomaRecu(n - 1);    

    }


int main(int arg, char *argv[]){
    int n;
    printf("Soma dos primeiros numeros: ");
    scanf("%d", &n);
    printf("%d = %d\n", n, SomaRecu(n));
    
}