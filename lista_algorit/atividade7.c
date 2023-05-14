#include <stdio.h>

int main() {
    int n, i, Seq1 = 0, Seq2 = 1, Seq;
    
    do {
        printf("Escreuva um número inteiro maior ou igual a zero: ");
        scanf("%d", &n);
    } while (n < 0);
    

    if (n == 0) {
        Seq = Seq1;
    } else if (n == 1) {
        Seq = Seq2;
    } else {
        for (i = 2; i <= n; i++) {
            Seq = Seq1 + Seq2;
            Seq1 = Seq2;
            Seq2 = Seq;
        }
    }
    
    printf("A enésima sequência de Fibonacci é: %d\n", Seq);
    
    return 0;
}
