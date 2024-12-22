#include <stdio.h>

//EX2 - Usando ponteiros, crie um programa que transforme 
//minutos em horas e minutos

void minutosParaHoras(int *minutos, int *horas, int *resto) {
    *horas = *minutos / 60;
    *resto = *minutos % 60;
}

int main() {
    int minutos, horas, resto;

    printf("Digite o número de minutos: ");
    scanf("%d", &minutos);

    minutosParaHoras(&minutos, &horas, &resto);

    printf("%d minutos equivale a %d horas e %d minutos.\n", minutos, horas, resto);
    printf("Fim do codigo!!!\n");
    return 0;
}


//Thaynná Yara