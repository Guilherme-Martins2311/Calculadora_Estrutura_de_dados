#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "expressao.h"

int ehNumero(const char *elemento) {
    int i = 0, temDig = 0;

    if (elemento[0] == '+' || elemento[0] == '-') i = 1;

    for (; elemento[i] != '\0'; i++) {
        if (isdigit(elemento[i])) temDig = 1;
        else if (elemento[i] == '.' || elemento[i] == ',') continue;
        else return 0;
    }

    return temDig;
}

int ehFuncao(const char *elemento) {
    return (
        strcmp(elemento, "sen") == 0 ||
        strcmp(elemento, "cos") == 0 ||
        strcmp(elemento, "tg")  == 0 ||
        strcmp(elemento, "log") == 0 ||
        strcmp(elemento, "raiz") == 0
    );
}

int ehOperador(const char *elemento) {
    return (
        strcmp(elemento, "+") == 0 ||
        strcmp(elemento, "-") == 0 ||
        strcmp(elemento, "*") == 0 ||
        strcmp(elemento, "/") == 0 ||
        strcmp(elemento, "^") == 0
    );
}

char *getFormaInFixa(char *Str) {
    static char resultado[300];
    char pilha[50][300];
    int topo = -1;

    char *elemento = strtok(Str, " ");

    while (elemento != NULL) {

        if (ehNumero(elemento)) {
            strcpy(pilha[++topo], elemento);
        } else if (ehFuncao(elemento)) {
            if (topo < 0) return NULL;

            char op[300];
            strcpy(op, pilha[topo--]);

            char temp[300];
            sprintf(temp, "%s(%s)", elemento, op);

            strcpy(pilha[++topo], temp);
        } else if (ehOperador(elemento)) {
            if (topo < 1) return NULL;

            char b[300], a[300];
            strcpy(b, pilha[topo--]);
            strcpy(a, pilha[topo--]);

            char temp[300];
            sprintf(temp, "(%s %s %s)", a, elemento, b);

            strcpy(pilha[++topo], temp);
        } else {
            return NULL;
        }

        elemento = strtok(NULL, " ");
    }

    if (topo != 0) return NULL;

    strcpy(resultado, pilha[0]);
    return resultado;
}

float getValorPosFixa(char *StrPosFixa) {
    float pilha[50];
    int topo = -1;

    for (int i = 0; StrPosFixa[i] != '\0'; i++)
        if (StrPosFixa[i] == ',') StrPosFixa[i] = '.';

    char *elemento = strtok(StrPosFixa, " ");

    while (elemento != NULL) {

        if (ehNumero(elemento)) {
            pilha[++topo] = atof(elemento);
        } else if (ehFuncao(elemento)) {
            float x = pilha[topo--];
            float r = 0;

            if (strcmp(elemento, "sen") == 0) r = sin(x * M_PI / 180.0);
            else if (strcmp(elemento, "cos") == 0) r = cos(x * M_PI / 180.0);
            else if (strcmp(elemento, "tg")  == 0) r = tan(x * M_PI / 180.0);
            else if (strcmp(elemento, "log") == 0) r = log10(x);
            else if (strcmp(elemento, "raiz") == 0) r = sqrt(x);

            pilha[++topo] = r;
        } else if (ehOperador(elemento)) {
            float b = pilha[topo--];
            float a = pilha[topo--];
            float r = 0;

            switch (elemento[0]) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/': r = a / b; break;
                case '^': r = pow(a, b); break;
            }

            pilha[++topo] = r;
        }

        elemento = strtok(NULL, " ");
    }

    return pilha[topo];
}
