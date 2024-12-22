#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa, em C, que: 

    Define um registro chamado ALUNO contendo o CPF do aluno, seu nome e uma nota (média geral).
    Cria um arquivo binário chamado turma.arq.
    Leia do teclado o número n de alunos e suas respectivas informações
    (nome, CPF e média) e grave-os no arquivo turma.arq
*/

#define MAX_NOME 100

#include <stdlib.h>
typedef struct {
    char cpf[12];         
    char nome[MAX_NOME];  
    float media;          
} ALUNO;

int main() {
    FILE *arquivo;
    ALUNO aluno;
    int n, i;

    // Abre o arquivo binário para escrita
    arquivo = fopen("turma.arq", "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_SUCCESS;
    }

    // Lê o número de alunos
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    getchar();

    // Lê as informações de cada aluno e grava no arquivo
    for (i = 0; i < n; i++) {
        printf("Digite o CPF do aluno %d: ", i + 1);
        fgets(aluno.cpf, sizeof(aluno.cpf), stdin);
        aluno.cpf[strcspn(aluno.cpf, "\n")] = 0; 

        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(aluno.nome, sizeof(aluno.nome), stdin);
        aluno.nome[strcspn(aluno.nome, "\n")] = 0; 

        printf("Digite a média do aluno %d: ", i + 1);
        scanf("%f", &aluno.media);
        getchar();

        // Grava o aluno no arquivo
        fwrite(&aluno, sizeof(ALUNO), 1, arquivo);
    }

  
    fclose(arquivo);
    printf("Dados salvos!!\n");

    return EXIT_SUCCESS;
}