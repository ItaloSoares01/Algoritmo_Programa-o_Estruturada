#include <stdio.h>

int main() {
    int numero, divisor;
    
    // lê o número positivo
    do {
        printf("Digite um número positivo: ");
        scanf("%d", &numero);
    } while (numero <= 0);
    
    // imprime os divisores do número
    printf("Os divisores do número %d são: ", numero);
    for (divisor = 1; divisor <= numero; divisor++) {
        if (numero % divisor == 0) {
            printf("%d ", divisor);
        }
    }
    
    return 0;
}





