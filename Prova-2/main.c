#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
O objetivo do projeto é criar um programa, em C-ANSI, que permita armazenar informações sobre diversos produtos em um arquivo binário, adicionar novos produtos e consultar produtos específicos pelo seu código de identificação.
A loja está crescendo rapidamente e precisa de uma forma mais eficiente para gerenciar seu inventário. 
O sistema deve ser capaz de registrar produtos com detalhes como código, nome, quantidade, preço, e permitir consultas rápidas para verificar a disponibilidade e os detalhes dos produtos.
*/

// Definição da estrutura `Produto`
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Função para abrir ou criar o arquivo binário
FILE* abrir_arquivo(const char* filename) {
    FILE *file = fopen(filename, "ab+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    return file;
}

// Função para adicionar um produto ao arquivo
void adicionar_produto(FILE* file, Produto* produto) {
    fseek(file, 0, SEEK_END);
    fwrite(produto, sizeof(Produto), 1, file);
}

// Função para consultar um produto pelo código
Produto* consultar_produto(FILE* file, int codigo) {
    Produto *produto = malloc(sizeof(Produto));
    rewind(file);
    while (fread(produto, sizeof(Produto), 1, file)) {
        if (produto->codigo == codigo) {
            return produto;
        }
    }
    free(produto);
    return NULL;
}
// Função para exibir as informações do produto

void exibir_produto(Produto* produto) {

    if (produto != NULL) {

        printf("Código: %d\n", produto->codigo);
        printf("Nome: %s\n", produto->nome);
        printf("Preço: %.2f\n", produto->preco);

    } else {

        printf("Produto não encontrado.\n");
    }

}

int main() {
    FILE *file = abrir_arquivo("produtos.bin");
    int opcao;
    Produto produto;

    do {

        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Consultar Produto\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();


        switch (opcao) {

            case 1: // Adicionar Produto

                printf("Digite o código do produto: ");
                scanf("%d", &produto.codigo);
                getchar();

                printf("Digite o nome do produto: ");
                fgets(produto.nome, 50, stdin);
                produto.nome[strcspn(produto.nome, "\n")] = 0; 

                printf("Digite o preço do produto: ");
                scanf("%f", &produto.preco);
                adicionar_produto(file, &produto);

                printf("Produto adicionado com sucesso!\n");
                break;

            case 2: // Exemplo de consulta de produto

                printf("Digite o código do produto a ser consultado: ");
                int codigo;
                scanf("%d", &codigo);
                Produto* encontrado = consultar_produto(file, codigo);
                exibir_produto(encontrado);

                free(encontrado);
                break;

            case 3: // Sair

                printf("Saindo...\n");
                break;

            default:

                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 3);
    
    fclose(file);
    return 0;
}