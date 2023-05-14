#include <stdio.h>

int main() {
    const double pi = 3.14159;  // define a constante pi
    
    double raio, area, volume;  // declara as variáveis de entrada e saída
    
    // lê o valor do raio
    printf("Digite o valor do raio da esfera: ");
    scanf("%lf", &raio);
    
    // calcula a área da superfície e o volume da esfera
    area = 4 * pi * raio * raio;
    volume = (4.0 / 3) * pi * raio * raio * raio;
    
    // exibe os resultados na tela
    printf("Área da superfície da esfera: %.2lf\n", area);
    printf("Volume da esfera: %.2lf\n", volume);
    
    return 0;
}
