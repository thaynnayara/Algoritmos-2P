#include <stdio.h>
#include <string.h>

/*
Crie um programa, em C, que contenha um array de float contendo 10 elementos. 
Imprima o endereço de cada posição desse array.
*/

int main(){

    float array[10];
    int i;
    for(i = 0; i < 10; i++){
        printf("Endereço de array[%d]: %p\n", i, (void*)&array[i]); //(void*)& pega o edereço do elemento na memoria
    }
}