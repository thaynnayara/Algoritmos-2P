#include <stdio.h>
#include <math.h>

/*
Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R. Essa função deve obedecer ao protótipo: 

void calc_esfera(float R, float *area, float *volume) 

A área da superfície e o volume são dados, respectivamente, por: 

A = 4 ∗ p ∗ R^2

V = 4/3 ∗ p ∗ R^3


Ob.:

    na função, as variáveis area e volume são ponteiros.
*/
void calc_esfera(float R, float *area, float *volume) { // Função que calcula a área da superfície e o volume de uma esfera
    
    const float pi = M_PI;

    *area = 4 * pi * (R * R); // Cálculo da área da superfície

    *volume = (4.0 / 3.0) * pi * (R * R * R); // Cálculo do volume
}

int main() {
    float R, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &R);

    // Chamada da função para calcular a área e o volume
    calc_esfera(R, &area, &volume);

    // Impressão dos resultados
    printf("Área da superfície: %.2f\n", area);
    printf("Volume: %.2f\n", volume);

    return 0;
}