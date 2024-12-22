#include <stdio.h>
#include <stdlib.h>

//Encontrar o maior elemento em um vetor usando recursão direta.

int maiorElemento(int *vetor, int tamanho, int maior) {
    if (tamanho == 0) {
        return maior;
    }else {
        if (vetor[tamanho - 1] > maior) {
            maior = vetor[tamanho - 1];
        }
        return maiorElemento(vetor, tamanho - 1, maior);
    }
}

int main(){
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    int *vetor = (int*) malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %dº elemento do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
        }
        printf("O maior elemento do vetor é: %d", maiorElemento(vetor, tamanho, vetor[0]));
        free(vetor);
}