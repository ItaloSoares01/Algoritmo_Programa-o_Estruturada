#include <stdio.h>

int main() {
    int opcao, quantidade, continuar = 1;
    float total = 0;

    while (continuar) {
        printf("\n==== Menu de Frutas ====\n");
        printf("1 - ABACAXI - R$ 5,00 a unidade\n");
        printf("2 - MACA - R$ 1,00 a unidade\n");
        printf("3 - PERA - R$ 4,00 a unidade\n");
        printf("4 - Encerrar compra\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                total += 5.0 * quantidade;
                printf("Adicionado %d unidade(s) de ABACAXI ao carrinho.\n", quantidade);
                break;
            case 2:
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                total += 1.0 * quantidade;
                printf("Adicionado %d unidade(s) de MACA ao carrinho.\n", quantidade);
                break;
            case 3:
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                total += 4.0 * quantidade;
                printf("Adicionado %d unidade(s) de PERA ao carrinho.\n", quantidade);
                break;
            case 4:
                continuar = 0;
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    printf("Total da compra: R$ %.2f\n", total);

    return 0;
}
