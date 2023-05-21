#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USUARIOS 1000
#define TAM_NOME 50
#define TAM_EMAIL 50
#define TAM_ENDERECO 100

typedef struct {
    int id;
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char sexo[TAM_NOME];
    char endereco[TAM_ENDERECO];
    double altura;
    int vacina;
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;

// Função para gerar um ID aleatório
int gerarId() {
    return rand() % 1000 + 1;
}

// Função para verificar se o email é válido
bool validarEmail(const char *email) {
    int i;
    int countAt = 0;

    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            countAt++;
        }
    }

    return countAt == 1;
}

// Função para validar o sexo
bool validarSexo(const char *sexo) {
    return strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0;
}

// Função para validar a altura
bool validarAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}

// Função para adicionar um novo usuário
void adicionarUsuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    Usuario novoUsuario;

    novoUsuario.id = gerarId();

    printf("Digite o nome completo do usuario: ");
    fgets(novoUsuario.nome, TAM_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Digite o email do usuario: ");
    fgets(novoUsuario.email, TAM_EMAIL, stdin);
    novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';

    while (!validarEmail(novoUsuario.email)) {
        printf("Email invalido. Digite novamente: ");
        fgets(novoUsuario.email, TAM_EMAIL, stdin);
        novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';
    }

    printf("Digite o sexo do usuario (Feminino, Masculino ou Indiferente): ");
    fgets(novoUsuario.sexo, TAM_NOME, stdin);
    novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';

    while (!validarSexo(novoUsuario.sexo)) {
        printf("Sexo invalido. Digite novamente: ");
        fgets(novoUsuario.sexo, TAM_NOME, stdin);
        novoUsuario.sexo[strcspn(novoUsuario.sexo, "\n")] = '\0';
    }

    printf("Digite o endereço do usuario: ");
    fgets(novoUsuario.endereco, TAM_ENDERECO, stdin);
    novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0';

    printf("Digite a altura do usuario (entre 1.0 e 2.0 m): ");
    scanf("%lf", &novoUsuario.altura);

    while (!validarAltura(novoUsuario.altura)) {
        printf("Altura invalida. Digite novamente: ");
        scanf("%lf", &novoUsuario.altura);
    }

    printf("O usuario foi cadastrado com sucesso.\n");

    usuarios[numUsuarios++] = novoUsuario;
}

// Função para encontrar um usuário pelo email
void buscarUsuarioPorEmail() {
    char emailBusca[TAM_EMAIL];

    printf("Digite o email do usuario que deseja buscar: ");
    fgets(emailBusca, TAM_EMAIL, stdin);
    emailBusca[strcspn(emailBusca, "\n")] = '\0';

    int i;
    bool encontrado = false;

    for (i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, emailBusca) == 0) {
            printf("Usuario encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %d\n", usuarios[i].vacina);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum usuário encontrado com o email fornecido.\n");
    }
}

// Função para imprimir todos os usuários cadastrados
void imprimirUsuarios() {
    int i;

    for (i = 0; i < numUsuarios; i++) {
        printf("Usuario %d:\n", i + 1);
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %d\n", usuarios[i].vacina);
        printf("\n");
    }

    if (numUsuarios == 0) {
        printf("Nenhum usuário cadastrado.\n");
    }
}

// Função para editar um usuário existente
void editarUsuario() {
    int idEdicao;

    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &idEdicao);

    int i;
    bool encontrado = false;

    for (i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == idEdicao) {
            printf("Digite o novo nome completo do usuário: ");
            getchar();
            fgets(usuarios[i].nome, TAM_NOME, stdin);
            usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0';

            printf("Digite o novo email do usuário: ");
            fgets(usuarios[i].email, TAM_EMAIL, stdin);
            usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';

            while (!validarEmail(usuarios[i].email)) {
                printf("Email inválido. Digite novamente: ");
                fgets(usuarios[i].email, TAM_EMAIL, stdin);
                usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
            }

            printf("Digite o novo sexo do usuário (Feminino, Masculino ou Indiferente): ");
            fgets(usuarios[i].sexo, TAM_NOME, stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';

            while (!validarSexo(usuarios[i].sexo)) {
                printf("Sexo inválido. Digite novamente: ");
                fgets(usuarios[i].sexo, TAM_NOME, stdin);
                usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';
            }

            printf("Digite o novo endereço do usuário: ");
            fgets(usuarios[i].endereco, TAM_ENDERECO, stdin);
            usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

            printf("Digite a nova altura do usuário (entre 1.0 e 2.0 m): ");
            scanf("%lf", &usuarios[i].altura);

            while (!validarAltura(usuarios[i].altura)) {
                printf("Altura inválida. Digite novamente: ");
                scanf("%lf", &usuarios[i].altura);
            }

            printf("O usuário foi editado com sucesso.\n");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum usuário encontrado com o ID fornecido.\n");
    }
}

// Função para excluir um usuário
void excluirUsuario() {
    int idExclusao;

    printf("Digite o ID do usuário que deseja excluir: ");
    scanf("%d", &idExclusao);

    int i;
    bool encontrado = false;

    for (i = 0; i < numUsuarios; i++) {
        if (usuarios[i].id == idExclusao) {
            int j;

            for (j = i; j < numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }

            numUsuarios--;
            printf("O usuário foi excluído com sucesso.\n");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Nenhum usuário encontrado com o ID fornecido.\n");
    }
}

// Função para fazer backup dos usuários cadastrados
void fazerBackup() {
    FILE *arquivo = fopen("backup.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de backup.\n");
        return;
    }

    int i;

    for (i = 0; i < numUsuarios; i++) {
        fprintf(arquivo, "Usuario %d:\n", i + 1);
        fprintf(arquivo, "ID: %d\n", usuarios[i].id);
        fprintf(arquivo, "Nome: %s\n", usuarios[i].nome);
        fprintf(arquivo, "Email: %s\n", usuarios[i].email);
        fprintf(arquivo, "Sexo: %s\n", usuarios[i].sexo);
        fprintf(arquivo, "Endereço: %s\n", usuarios[i].endereco);
        fprintf(arquivo, "Altura: %.2lf\n", usuarios[i].altura);
        fprintf(arquivo, "Vacina: %d\n", usuarios[i].vacina);
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);

    printf("Backup realizado com sucesso.\n");
}

// Função para fazer a restauração dos dados a partir do backup
void restaurarBackup() {
    FILE *arquivo = fopen("backup.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de backup.\n");
        return;
    }

    numUsuarios = 0;

    while (!feof(arquivo) && numUsuarios < MAX_USUARIOS) {
        Usuario usuario;

        fscanf(arquivo, "Usuário %*d:\n");
        fscanf(arquivo, "ID: %d\n", &usuario.id);
        fscanf(arquivo, "Nome: %[^\n]\n", usuario.nome);
        fscanf(arquivo, "Email: %[^\n]\n", usuario.email);
        fscanf(arquivo, "Sexo: %[^\n]\n", usuario.sexo);
        fscanf(arquivo, "Endereço: %[^\n]\n", usuario.endereco);
        fscanf(arquivo, "Altura: %lf\n", &usuario.altura);
        fscanf(arquivo, "Vacina: %d\n", &usuario.vacina);

        usuarios[numUsuarios++] = usuario;
    }

    fclose(arquivo);

    printf("Restauraçao realizada com sucesso.\n");
}

int main() {
    srand(time(NULL));

    char opcao;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Adicionar usuario\n");
        printf("2. Buscar usuario por email\n");
        printf("3. Imprimir usuarios cadastrados\n");
        printf("4. Editar usuario\n");
        printf("5. Excluir usuario\n");
        printf("6. Fazer backup dos usuarios cadastrados\n");
        printf("7. Restaurar dados a partir do backup\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarUsuario();
                break;
            case '2':
                buscarUsuarioPorEmail();
                break;
            case '3':
                imprimirUsuarios();
                break;
            case '4':
                editarUsuario();
                break;
            case '5':
                excluirUsuario();
                break;
            case '6':
                fazerBackup();
                break;
            case '7':
                restaurarBackup();
                break;
            case '0':
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opçao invalida. Digite novamente.\n");
        }

        printf("\n");

    } while (opcao != '0');

    return 0;
}
