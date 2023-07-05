#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[77];
    int idade;
} Usuario;

void inserirUsuario(Usuario** usuarios, int* numUsuarios) {
    Usuario* novo = (Usuario*)malloc(sizeof(Usuario));

    printf("Digite o nome do usuario: ");
    scanf("%s", novo->nome);
    printf("Digite a idade do usuario: ");
    scanf("%d", &(novo->idade));

    (*numUsuarios)++;
    *usuarios = (Usuario*)realloc(*usuarios, (*numUsuarios) * sizeof(Usuario));
    (*usuarios)[(*numUsuarios) - 1] = *novo;

    printf("Usuario cadastrado com sucesso!\n");
}

void editarUsuario(Usuario* usuarios, int numUsuarios) {
    int indice;
    printf("Digite o indice do usuario que deseja editar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numUsuarios) {
        printf("Digite o novo nome do usuario: ");
        scanf("%s", usuarios[indice].nome);
        printf("Digite a nova idade do usuario: ");
        scanf("%d", &(usuarios[indice].idade));
        printf("Usuario editado com sucesso!\n");
    } else {
        printf("Indice invalido!\n");
    }
}

void excluirUsuario(Usuario** usuarios, int* numUsuarios) {
    int indice;
    printf("Digite o indice do usuario que deseja excluir: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < *numUsuarios) {
        for (int i = indice; i < (*numUsuarios) - 1; i++) {
            (*usuarios)[i] = (*usuarios)[i + 1];
        }

        (*numUsuarios)--;
        *usuarios = (Usuario*)realloc(*usuarios, (*numUsuarios) * sizeof(Usuario));
        printf("Usuario excluido com sucesso!\n");
    } else {
        printf("Indice invalido!\n");
    }
}

void listarUsuarios(Usuario* usuarios, int numUsuarios) {
    printf("---- Usuarios cadastrados ----\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("Usuario %d:\n", i);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Idade: %d\n", usuarios[i].idade);
        printf("-----------------------------\n");
    }
}

int main() {
    Usuario* usuarios = NULL;
    int totalUsuarios = 0;

    int opcao;
    do {
        printf("----- Menu -----\n");
        printf("1. Inserir usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Listar usuarios\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirUsuario(&usuarios, &totalUsuarios);
                break;
            case 2:
                editarUsuario(usuarios, totalUsuarios);
                break;
            case 3:
                excluirUsuario(&usuarios, &totalUsuarios);
                break;
            case 4:
                listarUsuarios(usuarios, totalUsuarios);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    free(usuarios);

    return 0;
}
