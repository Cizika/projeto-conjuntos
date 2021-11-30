#include "TAD_Conjunto/Set.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    SET *conjunto = set_criar();

    set_inserir(conjunto, 1);
    set_inserir(conjunto, 10);
    set_inserir(conjunto, 11);
    set_inserir(conjunto, 7);

    set_imprimir(conjunto);
    printf("\n");

    set_remover(conjunto, 10);

    set_imprimir(conjunto);

    set_apagar(&conjunto);
    return 0;
}