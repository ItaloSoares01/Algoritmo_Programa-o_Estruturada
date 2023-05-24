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