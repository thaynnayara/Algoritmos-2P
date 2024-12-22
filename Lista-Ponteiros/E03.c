#include <stdio.h>

/*
Usando ponteiros, crie uma função que encontre o valor mínimo e máximo de um vetor
*/

void encontrarMinMax(int *vetor, int tamanho, int *minimo, int *maximo) {
    if (tamanho <= 0) {
        return;
    }

    *minimo = *maximo = vetor[0];

    // Percorre o vetor para encontrar os valores mínimo e máximo
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < *minimo) {
            *minimo = vetor[i];
        }
        if (vetor[i] > *maximo) {
            *maximo = vetor[i];
        }
    }
}

int main() {
    int vetor[100];
    int tamanho, minimo, maximo;

    // Leitura do tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Leitura dos elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    encontrarMinMax(vetor, tamanho, &minimo, &maximo);
    printf("Valor MIN: %d\n", minimo);
    printf("Valor MAX: %d\n", maximo);

    return 0;
}