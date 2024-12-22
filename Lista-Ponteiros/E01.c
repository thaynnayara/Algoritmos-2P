#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10
#define MAX_NOME 50

typedef struct {

    int matricula;
    char nome[MAX_NOME];
    float nota1, nota2;

} Aluno;

int main() {

    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;

    do {

        printf("\n Menu alunos:\n");
        printf("1. Cadastrar novo aluno\n");
        printf("2. Exibir relatório de alunos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numAlunos < MAX_ALUNOS) {
                    printf("Digite a matrícula do aluno %d: ", numAlunos + 1);
                    scanf("%d", &alunos[numAlunos].matricula);

                    printf("Digite o nome do aluno %d: ", numAlunos + 1);
                    scanf("%s", alunos[numAlunos].nome);

                    printf("Digite a primeira nota do aluno %d: ", numAlunos + 1);
                    scanf("%f", &alunos[numAlunos].nota1);

                    printf("Digite a segunda nota do aluno %d: ", numAlunos + 1);
                    scanf("%f", &alunos[numAlunos].nota2);

                    numAlunos++;
                } else {
                    printf("Número máximo de alunos atingido.\n");
                }
                break;

            case 2:
                printf("\nRelatório de Alunos:\n");
                for (int i = 0; i < numAlunos; i++) {
                    float media = (alunos[i].nota1 + alunos[i].nota2) / 2;
                    printf("Matrícula: %d\n", alunos[i].matricula);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Média: %.2f\n\n", media);
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}


//Thaynná Yara