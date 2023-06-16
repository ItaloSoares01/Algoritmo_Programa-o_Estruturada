#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 40
#define MAX_EMAIL_LENGTH 40
#define MAX_ADDRESS_LENGTH 40

int ids[MAX_USERS];
char nomes[MAX_USERS][MAX_NAME_LENGTH];
char emails[MAX_USERS][MAX_EMAIL_LENGTH];
char generos[MAX_USERS][MAX_NAME_LENGTH];
char enderecos[MAX_USERS][MAX_ADDRESS_LENGTH];
double alturas[MAX_USERS];
int vacinados[MAX_USERS];

int numUsers = 0;

int generateRandomId() {
    return rand() % 1000 + 1;
}

int isEmailValid(const char* email) {
    return strchr(email, '@') != NULL;
}

int isGenderValid(const char* gender) {
    return strcmp(gender, "Feminino") == 0 || strcmp(gender, "Masculino") == 0 || strcmp(gender, "Nao Definido") == 0;
}


int isHeightValid(double height) {
    return height >= 1.0 && height <= 2.0;
}

void addUser() {
    if (numUsers >= MAX_USERS) {
        printf("Quantidade maxima de usuarios atingida.\n");
        return;
    }

    int newId = generateRandomId();
    ids[numUsers] = newId;



    printf("Digite o nome completo: ");
    fgets(nomes[numUsers], sizeof(nomes[numUsers]), stdin);
    nomes[numUsers][strcspn(nomes[numUsers], "\n")] = '\0';

    printf("Digite o email: ");
    fgets(emails[numUsers], sizeof(emails[numUsers]), stdin);
    emails[numUsers][strcspn(emails[numUsers], "\n")] = '\0';

    while (!isEmailValid(emails[numUsers])) {
        printf("Email Inconrreto. Tente novamente: ");
        fgets(emails[numUsers], sizeof(emails[numUsers]), stdin);
        emails[numUsers][strcspn(emails[numUsers], "\n")] = '\0';
    }

    printf("Digite o sexo (Feminino, Masculino ou Nao Definido): ");
    fgets(generos[numUsers], sizeof(generos[numUsers]), stdin);
    generos[numUsers][strcspn(generos[numUsers], "\n")] = '\0';

    while (!isGenderValid(generos[numUsers])) {
        printf("Sexo nao cadastrado. Tente novamente: ");
        fgets(generos[numUsers], sizeof(generos[numUsers]), stdin);
        generos[numUsers][strcspn(generos[numUsers], "\n")] = '\0';
    }

    printf("Digite seu endereco: ");
    fgets(enderecos[numUsers], sizeof(enderecos[numUsers]), stdin);
    enderecos[numUsers][strcspn(enderecos[numUsers], "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[numUsers]);

    while (!isHeightValid(alturas[numUsers])) {
        printf("Altura inválida. Digite novamente: ");
        scanf("%lf", &alturas[numUsers]);
    }

    printf("O usuario foi cadastrado com sucesso.\n");
    numUsers++;
       printf("Digite 1 se o usuario foi vacinado ou 0 caso contrário: ");
    scanf("%d", &vacinados[numUsers]);

    printf("O usuario foi cadastrado com sucesso.\n");
    numUsers++;
    printf("Seu ID é: %d\n", newId);
    
}

void editUser() {
    if (numUsers == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &id);

    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (ids[i] == id) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("usuario não encontrado.\n");
        return;
    }

    printf("Digite o novo nome completo: ");
    fgets(nomes[userIndex], sizeof(nomes[userIndex]), stdin);
    nomes[userIndex][strcspn(nomes[userIndex], "\n")] = '\0';

    printf("Digite o novo email: ");
    fgets(emails[userIndex], sizeof(emails[userIndex]), stdin);
    emails[userIndex][strcspn(emails[userIndex], "\n")] = '\0';

    while (!isEmailValid(emails[userIndex])) {
        printf("Email inválido. Digite novamente: ");
        fgets(emails[userIndex], sizeof(emails[userIndex]), stdin);
        emails[userIndex][strcspn(emails[userIndex], "\n")] = '\0';
    }

    printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
    fgets(generos[userIndex], sizeof(generos[userIndex]), stdin);
    generos[userIndex][strcspn(generos[userIndex], "\n")] = '\0';

    while (!isGenderValid(generos[userIndex])) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(generos[userIndex], sizeof(generos[userIndex]), stdin);
        generos[userIndex][strcspn(generos[userIndex], "\n")] = '\0';
    }

    printf("Digite o novo endereço: ");
    fgets(enderecos[userIndex], sizeof(enderecos[userIndex]), stdin);
    enderecos[userIndex][strcspn(enderecos[userIndex], "\n")] = '\0';

    printf("Digite a nova altura (entre 1 e 2 metros): ");
    scanf("%lf", &alturas[userIndex]);

    while (!isHeightValid(alturas[userIndex])) {
        printf("Altura inválida. Digite novamente: ");
        scanf("%lf", &alturas[userIndex]);
    }

    printf("O usuario foi editado com sucesso.\n");
}

void deleteUser() {
    if (numUsers == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);

    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (ids[i] == id) {
            userIndex = i;
            break;
        }
    }

    if (userIndex == -1) {
        printf("usuario não encontrado.\n");
        return;
    }

    for (int i = userIndex; i < numUsers - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
        strcpy(emails[i], emails[i + 1]);
        strcpy(generos[i], generos[i + 1]);
        strcpy(enderecos[i], enderecos[i + 1]);
        alturas[i] = alturas[i + 1];
    }

    numUsers--;
    printf("O usuario foi excluído com sucesso.\n");
}

void searchUserByEmail() {
    if (numUsers == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    char searchEmail[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(searchEmail, sizeof(searchEmail), stdin);
    searchEmail[strcspn(searchEmail, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(emails[i], searchEmail) == 0) {
            printf("usuario encontrado:\n");
            printf("ID: %d\n", ids[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("Email: %s\n", emails[i]);
            printf("Sexo: %s\n", generos[i]);
            printf("Endereço: %s\n", enderecos[i]);
            printf("Altura: %.2lf\n", alturas[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("usuario não encontrado.\n");
    }
}

void printAllUsers() {
    if (numUsers == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("usuarios cadastrados:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomes[i]);
        printf("Email: %s\n", emails[i]);
        printf("Sexo: %s\n", generos[i]);
        printf("Endereço: %s\n", enderecos[i]);
        printf("Altura: %.2lf\n", alturas[i]);
        printf("\n");
    }
}

void backupUsers() {
    FILE* file = fopen("backup.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de backup.\n");
        return;
    }

    for (int i = 0; i < numUsers; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%.2lf\n", ids[i], nomes[i], emails[i], generos[i], enderecos[i], alturas[i]);
    }

    fclose(file);
    printf("Backup dos usuarios realizado com sucesso.\n");
}

void restoreUsers() {
    FILE* file = fopen("backup.txt", "r");
    if (file == NULL) {
        printf("Arquivo de backup não encontrado.\n");
        return;
    }

    numUsers = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%[^,],%[^,],%lf\n", &ids[numUsers], nomes[numUsers], emails[numUsers], generos[numUsers], enderecos[numUsers], &alturas[numUsers]) == 6) {
        numUsers++;
    }

    fclose(file);
    printf("Restauração dos usuarios realizada com sucesso.\n");
}

int main() {
    char option;

    do {
        printf("Selecione uma opção:\n");
        printf("1. Incluir usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Imprimir todos os usuarios\n");
        printf("6. Fazer backup dos usuarios\n");
        printf("7. Restaurar dados dos usuarios\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf(" %c", &option);
        getchar();

        switch (option) {
            case '1':
                addUser();
                break;
            case '2':
                editUser();
                break;
            case '3':
                deleteUser();
                break;
            case '4':
                searchUserByEmail();
                break;
            case '5':
                printAllUsers();
                break;
            case '6':
                backupUsers();
                break;
            case '7':
                restoreUsers();
                break;
            case '0':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
        }

        printf("\n");
    } while (option != '0');

    return 0;
}