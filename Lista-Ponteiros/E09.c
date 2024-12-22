#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Faca um programa, em C, que abra o arquivo criado na questão anterior (turma.arq) e nele busque se um nome informado pelo usuário corresponde a algum aluno da lista. 
Caso isso ocorra, imprima a nota e o CPF desse aluno. 
Se o nome não for encontrado, imprima uma mensagem de notificação na tela do usuário.
*/


#define MAX_NOME 100

// Definição do registro ALUNO
typedef struct {
    char cpf[12];         
    char nome[MAX_NOME];  
    float media;         
} ALUNO;

int main() {
    FILE *arquivo;
    ALUNO aluno;
    char nomeBusca[MAX_NOME];
    int encontrado = 0;

    // Abre o arquivo binário para leitura
    arquivo = fopen("turma.arq", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Lê o nome a ser buscado
    printf("Digite o nome do aluno: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0; 

    // Busca pelo aluno no arquivo
    while (fread(&aluno, sizeof(ALUNO), 1, arquivo) == 1) {
        if (strcmp(aluno.nome, nomeBusca) == 0) {
            printf("Encontrado!\n");
            printf("CPF: %s\n", aluno.cpf);
            printf("Média: %.2f\n", aluno.media);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Não encontrado.\n");
    }

    // Fecha o arquivo
    fclose(arquivo);
    return EXIT_SUCCESS;
}
