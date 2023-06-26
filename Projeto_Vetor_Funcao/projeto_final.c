#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_DE_USUARIOS 1000
#define CARACTERES_NOME 40
#define CARACTERES_EMAIL 40
#define CARACTERES_ENDERECO 40

typedef struct {
    int id;
    char nome[CARACTERES_NOME];
    char email[CARACTERES_EMAIL];
    char genero[CARACTERES_NOME];
    char endereco[CARACTERES_ENDERECO];
    double altura;
    int vacinado;
} Usuario;

Usuario usuarios[MAXIMO_DE_USUARIOS];
int numUsuarios = 0;

int Id_usuario() {
    return rand() % 1000 - 0.44;
}

int validacaoEmail(const char* email) {
    return strchr(email, '@') != NULL;
}

int validacaoGen(const char* genero) {
    return strcmp(genero, "Feminino") == 0 || strcmp(genero, "Masculino") == 0 || strcmp(genero, "Nao Definido") == 0;
}

int validacaoAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}

void adicionarUsuario() {
    if (numUsuarios >= MAXIMO_DE_USUARIOS) {
        printf("Quantidade maxima de usuarios atingida.\n");
        return;
    }

    Usuario novoUsuario;

    novoUsuario.id = Id_usuario();

    printf("Digite o nome completo: ");
    fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
    novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';

    while (!validacaoEmail(novoUsuario.email)) {
        printf("Email incorreto. Tente novamente: ");
        fgets(novoUsuario.email, sizeof(novoUsuario.email), stdin);
        novoUsuario.email[strcspn(novoUsuario.email, "\n")] = '\0';
    }

    printf("Digite o sexo (Feminino, Masculino ou Nao Definido): ");
    fgets(novoUsuario.genero, sizeof(novoUsuario.genero), stdin);
    novoUsuario.genero[strcspn(novoUsuario.genero, "\n")] = '\0';

    while (!validacaoGen(novoUsuario.genero)) {
        printf("Sexo nao cadastrado. Tente novamente: ");
        fgets(novoUsuario.genero, sizeof(novoUsuario.genero), stdin);
        novoUsuario.genero[strcspn(novoUsuario.genero, "\n")] = '\0';
    }

    printf("Digite seu endereco: ");
    fgets(novoUsuario.endereco, sizeof(novoUsuario.endereco), stdin);
    novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario.altura);

    while (!validacaoAltura(novoUsuario.altura)) {
        printf("Altura incorreta. Digite novamente: ");
        scanf("%lf", &novoUsuario.altura);
    }

    printf("Digite 1 se o usuario foi vacinado ou 0 caso nao tenha sido vacinado: ");
    scanf("%d", &novoUsuario.vacinado);

    while (novoUsuario.vacinado != 0 && novoUsuario.vacinado != 1) {
        printf("Opcao invalida. Digite 1 se o usuario foi vacinado ou 0 caso nao tenha sido vacinado: ");
        scanf("%d", &novoUsuario.vacinado);
    }

    getchar(); // Limpar o buffer do teclado após a leitura de inteiro

    usuarios[numUsuarios] = novoUsuario;
    numUsuarios++;

    printf("Usuario adicionado com sucesso!\n");
}

int encontrarUsuarioPorEmail(const char* email) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            return i; // Retorna o índice do usuário encontrado
        }
    }
    return -1; // Usuário não encontrado
}

void editarUsuario() {
    char email[CARACTERES_EMAIL];
    printf("Digite o email do usuario que deseja editar: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    int indiceUsuario = encontrarUsuarioPorEmail(email);

    if (indiceUsuario == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    Usuario* usuario = &usuarios[indiceUsuario];

    printf("Digite o novo nome completo: ");
    fgets(usuario->nome, sizeof(usuario->nome), stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

    printf("Digite o novo email: ");
    fgets(usuario->email, sizeof(usuario->email), stdin);
    usuario->email[strcspn(usuario->email, "\n")] = '\0';

    while (!validacaoEmail(usuario->email)) {
        printf("Email incorreto. Tente novamente: ");
        fgets(usuario->email, sizeof(usuario->email), stdin);
        usuario->email[strcspn(usuario->email, "\n")] = '\0';
    }

    printf("Digite o novo sexo (Feminino, Masculino ou Nao Definido): ");
    fgets(usuario->genero, sizeof(usuario->genero), stdin);
    usuario->genero[strcspn(usuario->genero, "\n")] = '\0';

    while (!validacaoGen(usuario->genero)) {
        printf("Sexo nao cadastrado. Tente novamente: ");
        fgets(usuario->genero, sizeof(usuario->genero), stdin);
        usuario->genero[strcspn(usuario->genero, "\n")] = '\0';
    }

    printf("Digite o novo endereco: ");
    fgets(usuario->endereco, sizeof(usuario->endereco), stdin);
    usuario->endereco[strcspn(usuario->endereco, "\n")] = '\0';

    printf("Digite a nova altura (entre 1 e 2 metros): ");
    scanf("%lf", &usuario->altura);

    while (!validacaoAltura(usuario->altura)) {
        printf("Altura incorreta. Digite novamente: ");
        scanf("%lf", &usuario->altura);
    }

    printf("Digite 1 se o usuario foi vacinado ou 0 caso nao tenha sido vacinado: ");
    scanf("%d", &usuario->vacinado);

    while (usuario->vacinado != 0 && usuario->vacinado != 1) {
        printf("Opcao invalida. Digite 1 se o usuario foi vacinado ou 0 caso nao tenha sido vacinado: ");
        scanf("%d", &usuario->vacinado);
    }

    printf("Usuario editado com sucesso!\n");
}

void deletarUsuario() {
    char email[CARACTERES_EMAIL];
    printf("Digite o email do usuario que deseja excluir: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    int indiceUsuario = encontrarUsuarioPorEmail(email);

    if (indiceUsuario == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    for (int i = indiceUsuario; i < numUsuarios - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }

    numUsuarios--;

    printf("Usuario excluido com sucesso!\n");
}

void procurarUsuarioPorEmail() {
    char email[CARACTERES_EMAIL];
    printf("Digite o email do usuario que deseja procurar: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    int indiceUsuario = encontrarUsuarioPorEmail(email);

    if (indiceUsuario == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    Usuario usuario = usuarios[indiceUsuario];

    printf("Usuario encontrado:\n");
    printf("ID: %d\n", usuario.id);
    printf("Nome: %s\n", usuario.nome);
    printf("Email: %s\n", usuario.email);
    printf("Genero: %s\n", usuario.genero);
    printf("Endereco: %s\n", usuario.endereco);
    printf("Altura: %.2lf\n", usuario.altura);
    printf("Vacinado: %s\n", usuario.vacinado ? "Sim" : "Nao");
}

void listarUsuarios() {
    if (numUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("Lista de usuarios:\n");

    for (int i = 0; i < numUsuarios; i++) {
        Usuario usuario = usuarios[i];

        printf("ID: %d\n", usuario.id);
        printf("Nome: %s\n", usuario.nome);
        printf("Email: %s\n", usuario.email);
        printf("Genero: %s\n", usuario.genero);
        printf("Endereco: %s\n", usuario.endereco);
        printf("Altura: %.2lf\n", usuario.altura);
        printf("Vacinado: %s\n", usuario.vacinado ? "Sim" : "Nao");
        printf("-----------\n");
    }
}

void fazerBackup() {
    FILE* arquivo = fopen("backup.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de backup.\n");
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        Usuario usuario = usuarios[i];
        fprintf(arquivo, "%d,%s,%s,%s,%s,%.2lf,%d\n", usuario.id, usuario.nome, usuario.email, usuario.genero, usuario.endereco, usuario.altura, usuario.vacinado);
    }

    fclose(arquivo);

    printf("Backup realizado com sucesso!\n");
}

void restaurarBackup() {
    FILE* arquivo = fopen("backup.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo de backup nao encontrado.\n");
        return;
    }

    numUsuarios = 0;

    while (fscanf(arquivo, "%d,%[^,],%[^,],%[^,],%[^,],%lf,%d\n", &usuarios[numUsuarios].id, usuarios[numUsuarios].nome, usuarios[numUsuarios].email, usuarios[numUsuarios].genero, usuarios[numUsuarios].endereco, &usuarios[numUsuarios].altura, &usuarios[numUsuarios].vacinado) != EOF) {
        numUsuarios++;
    }

    fclose(arquivo);

    printf("Backup restaurado com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\n----- Menu de Opcoes -----\n");
        printf("1. Adicionar Usuario\n");
        printf("2. Editar Usuario\n");
        printf("3. Excluir Usuario\n");
        printf("4. Procurar Usuario por Email\n");
        printf("5. Listar Usuarios\n");
        printf("6. Fazer Backup\n");
        printf("7. Restaurar Backup\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        getchar(); // Limpar o buffer do teclado após a leitura de inteiro

        switch (opcao) {
            case 1:
                adicionarUsuario();
                break;
            case 2:
                editarUsuario();
                break;
            case 3:
                deletarUsuario();
                break;
            case 4:
                procurarUsuarioPorEmail();
                break;
            case 5:
                listarUsuarios();
                break;
            case 6:
                fazerBackup();
                break;
            case 7:
                restaurarBackup();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}