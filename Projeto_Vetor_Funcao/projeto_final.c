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