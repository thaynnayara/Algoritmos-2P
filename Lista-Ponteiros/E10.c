#include <stdio.h>
#include <stdlib.h>

#define MAX_M 100  // Número máximo de linhas
#define MAX_N 100  // Número máximo de colunas
#define MAX_SIZE (MAX_M * MAX_N) // Tamanho máximo para armazenar elementos

int main() {
    int m, n;
    double A[MAX_M][MAX_N];
    double elementosVistos[MAX_SIZE];
    int i, j, k;
    int repetido = 0;
    int contador = 0;

    // Leitura das dimensões da matriz
    printf("Digite o número de linhas (m): ");
    scanf("%d", &m);
    printf("Digite o número de colunas (n): ");
    scanf("%d", &n);

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    // Verificação de elementos repetidos
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            int encontrado = 0;
            for (k = 0; k < contador; k++) {
                if (A[i][j] == elementosVistos[k]) {
                    printf("Elemento repetido encontrado: %.2f em A[%d][%d]\n", A[i][j], i, j);
                    encontrado = 1;
                    repetido = 1;
                    break; 
                }
            }
            // Se não foi encontrado, adiciona ao array de vistos
            if (!encontrado) {
                elementosVistos[contador++] = A[i][j];
            }
        }
    }

    if (!repetido) {
        printf("Não existem elementos repetidos na matriz.\n");
    }

    return 0;
}