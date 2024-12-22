#include <stdio.h>

//Escreva um programa em C, que contenha duas variáveis inteiras. Compare seus endereços e exiba o maior endereço.

int main() {
    int A, B;

    // Obtendo os endereços das variáveis
    int *endereco_a = &A;
    int *endereco_b = &B;

    // Comparando os endereços
    if (endereco_a > endereco_b) {
        printf("A variavel A é maior, endereço: %p\n", (void *)endereco_a);
    } else if (endereco_b > endereco_a) {
        printf("A variavel B é maior, endereço:  %p \n", (void *)endereco_b);
    } else {
        printf("Os endereços são iguais: %p\n", (void *)endereco_a);
    }

    return 0;
}

/*
Aplicações Práticas

Depuração: Você pode usar esse tipo de comparação para depurar problemas de alocação de memória em programas mais complexos.
Otimização de Memória: Em sistemas embarcados, onde a memória é limitada, 
entender onde as variáveis estão alocadas pode ajudar a otimizar o uso de memória.
*/

//Thaynná Yara