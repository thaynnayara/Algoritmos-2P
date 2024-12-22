#include<stdio.h>
#include<string.h>

/* Faça um programa, em C, que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo, 
ou seja, esta função é chamada passando duas variáveis A e B por exemplo e, após a execução da função, 
a variável A conterá o valor da variável B e a variável B terá o valor da variável A. */

void trocar(int *num1, int *num2){
    int aux = *num1; // armazenando o valor de num1 em aux
    *num1 = *num2; // atribuindo o valor de num2 a num1
    *num2 = aux; // atribuindo o valor armazenado em aux a num2
    
}


int main () {

    int num1, num2;

    //SOLICITANDO VALORES PARA 2 NÚMEROS
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2); 

    printf("| Valor anterior |\n");
    printf("| Número 1: %d |\n", num1);
    printf("| Número 2: %d |\n", num2);

    //
    trocar(&num1, &num2);

    printf("| Valor após a troca |\n");
    printf("| Número 1: %d |\n", num1);
    printf("| Número 2: %d |\n", num2);

    return 0;
}