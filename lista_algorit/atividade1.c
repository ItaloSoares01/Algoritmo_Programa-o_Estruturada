#include <stdio.h>

int main() {
    int a, b, c, d, diferenca;
    
    // executar valores de A, B, C e D
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);
    printf("Digite o valor de C: ");
    scanf("%d", &c);
    printf("Digite o valor de D: ");
    scanf("%d", &d);
    
    // calcular diferença
    diferenca = (a * b) - (c * d);
    
    // exibe o resultado na tela
    printf("DIFERENCA = (%d * %d - %d * %d)\n", a, b, c, d);
    printf("DIFERENCA = (%d)\n", diferenca);
    
    return 0;
}
