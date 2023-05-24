#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO_DE_USUARIOS 1000
#define CARACTERES_NOME 40
#define CARACTERES_EMAIL 40
#define CARACTERES_ENDERECO 40

int ids[MAXIMO_DE_USUARIOS];
char nomes[MAXIMO_DE_USUARIOS][CARACTERES_NOME];
char emails[MAXIMO_DE_USUARIOS][CARACTERES_EMAIL];
char generos[MAXIMO_DE_USUARIOS][CARACTERES_NOME];
char enderecos[MAXIMO_DE_USUARIOS][CARACTERES_ENDERECO];
double alturas[MAXIMO_DE_USUARIOS];
int vacinados[MAXIMO_DE_USUARIOS];

int numUsuarios = 0;

int Id_usuario() {
    return rand() % 1000 - 0.44;
}


void adicionarUsuario() {
    if (numUsuarios >= MAXIMO_DE_USUARIOS) {
        printf("Quantidade maxima de usuarios atingida.\n");
        return;
    }

    int newId = Id_usuario();
    ids[numUsuarios] = newId;



    printf("Digite o nome completo: ");
    fgets(nomes[numUsuarios], sizeof(nomes[numUsuarios]), stdin);
    nomes[numUsuarios][strcspn(nomes[numUsuarios], "\n")] = '\0';

    printf("Digite o email: ");
    fgets(emails[numUsuarios], sizeof(emails[numUsuarios]), stdin);
    emails[numUsuarios][strcspn(emails[numUsuarios], "\n")] = '\0';

    while (!validacaoEmail(emails[numUsuarios])) {
        printf("Email Inconrreto. Tente novamente: ");
        fgets(emails[numUsuarios], sizeof(emails[numUsuarios]), stdin);
        emails[numUsuarios][strcspn(emails[numUsuarios], "\n")] = '\0';
    }

    printf("Digite o sexo (Feminino, Masculino ou Nao Definido): ");
    fgets(generos[numUsuarios], sizeof(generos[numUsuarios]), stdin);
    generos[numUsuarios][strcspn(generos[numUsuarios], "\n")] = '\0';

    while (!validacaoGen(generos[numUsuarios])) {
        printf("Sexo nao cadastrado. Tente novamente: ");
        fgets(generos[numUsuarios], sizeof(generos[numUsuarios]), stdin);
        generos[numUsuarios][strcspn(generos[numUsuarios], "\n")] = '\0';
    }

    printf("Digite seu endereco: ");
    fgets(enderecos[numUsuarios], sizeof(enderecos[numUsuarios]), stdin);
    enderecos[numUsuarios][strcspn(enderecos[numUsuarios], "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[numUsuarios]);

    while (!validacaoAltura(alturas[numUsuarios])) {
        printf("Altura Incorreta. Digite novamente: ");
        scanf("%lf", &alturas[numUsuarios]);
    }

       printf("Digite 1 se o usuario foi vacinado ou 0 caso nao cadastrado:");
    scanf("%d", &vacinados[numUsuarios]);
    printf("\n\n");
    printf("\tO usuario foi cadastrado com sucesso.\n");
    numUsuarios++;


    printf("\t(Seja bem vindo usuario(ID): %d\n\n)", newId);
    
}

void editarUsuario() {
    if (numUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario que deseja fazer a alteracao: ");
    scanf("%d", &id);

    int indiceUsuario = -1;
    for (int i = 0; i < numUsuarios; i++) {
        if (ids[i] == id) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("usuario nao localizado.\n");
        return;
    }

    printf("Digite o novo nome: ");
    fgets(nomes[indiceUsuario], sizeof(nomes[indiceUsuario]), stdin);
    nomes[indiceUsuario][strcspn(nomes[indiceUsuario], "\n")] = '\0';
    getchar();

    printf("Digite o novo email: ");
    fgets(emails[indiceUsuario], sizeof(emails[indiceUsuario]), stdin);
    emails[indiceUsuario][strcspn(emails[indiceUsuario], "\n")] = '\0';

    while (!validacaoEmail(emails[indiceUsuario])) {
        printf("Email Inconrreto. Tente novamente: ");
        fgets(emails[indiceUsuario], sizeof(emails[indiceUsuario]), stdin);
        emails[indiceUsuario][strcspn(emails[indiceUsuario], "\n")] = '\0';
    }

    printf("Digite o novo sexo (Feminino, Masculino ou Nao definido): ");
    fgets(generos[indiceUsuario], sizeof(generos[indiceUsuario]), stdin);
    generos[indiceUsuario][strcspn(generos[indiceUsuario], "\n")] = '\0';

    while (!validacaoGen(generos[indiceUsuario])) {
        printf("Sexo nao cadastrado. Tente novamente: ");
        fgets(generos[indiceUsuario], sizeof(generos[indiceUsuario]), stdin);
        generos[indiceUsuario][strcspn(generos[indiceUsuario], "\n")] = '\0';
    }

    printf("Digite o novo endereco: ");
    fgets(enderecos[indiceUsuario], sizeof(enderecos[indiceUsuario]), stdin);
    enderecos[indiceUsuario][strcspn(enderecos[indiceUsuario], "\n")] = '\0';

    printf("Digite a nova altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[indiceUsuario]);

    while (!validacaoAltura(alturas[indiceUsuario])) {
        printf("Altura incorreta. Digite novamente: ");
        scanf("%lf", &alturas[indiceUsuario]);
    }

    printf("O usuario foi editado com sucesso.\n");
}

void deletarUsuario() {
    if (numUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);

    int indiceUsuario = -1;
    for (int i = 0; i < numUsuarios; i++) {
        if (ids[i] == id) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("usuario nao localizado.\n");
        return;
    }

    for (int i = indiceUsuario; i < numUsuarios - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
        strcpy(emails[i], emails[i + 1]);
        strcpy(generos[i], generos[i + 1]);
        strcpy(enderecos[i], enderecos[i + 1]);
        alturas[i] = alturas[i + 1];
    }

    numUsuarios--;
    printf("O usuario foi excluido com sucesso.\n");
}

void procurarPorEmail() {
    if (numUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    char procurarEmail[CARACTERES_EMAIL];
    printf("Digite o email do usuario que deseja localizar: ");
    fgets(procurarEmail, sizeof(procurarEmail), stdin);
    procurarEmail[strcspn(procurarEmail, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(emails[i], procurarEmail) == 0) {
            printf("usuario encontrado:\n");
            printf("ID: %d\n", ids[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("Email: %s\n", emails[i]);
            printf("Sexo: %s\n", generos[i]);
            printf("Endereco: %s\n", enderecos[i]);
            printf("Altura: %.2lf\n", alturas[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Usuario nao localizado.\n");
    }
}

void listarUsuarios() {
    if (numUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("usuarios cadastrados:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomes[i]);
        printf("Email: %s\n", emails[i]);
        printf("Sexo: %s\n", generos[i]);
        printf("Endereço: %s\n", enderecos[i]);
        printf("Altura: %.2lf\n", alturas[i]);
        printf("\n");
    }
}

void usuariosBackup() {
    FILE* file = fopen("Notes.txt", "w");
    if (file == NULL) {
        printf("Falha na criacao do arquivo.\n");
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%.2lf\n", ids[i], nomes[i], emails[i], generos[i], enderecos[i], alturas[i]);
    }

    fclose(file);
    printf("Backup realizado com sucesso em Notes.\n");
}
