#include <stdio.h>
#include <string.h>
#include "expressao.h"

int main() {
    Expressao exp;
    
    printf("Digite a expressao pos-fixa:\n");
    fgets(exp.posFixa, 200, stdin);
    exp.posFixa[strcspn(exp.posFixa, "\n")] = '\0';

    char copia1[200], copia2[200];
    strcpy(copia1, exp.posFixa);
    strcpy(copia2, exp.posFixa);

    char *infixa = getFormaInFixa(copia1);
    exp.Valor = getValorPosFixa(copia2);

    strcpy(exp.inFixa, infixa);

    printf("\nForma Infixa: %s\n", exp.inFixa);
    printf("Valor: %.4f\n", exp.Valor);

    return 0;
}
