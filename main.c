#include "TAD_Conjunto/Set.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    SET *conjunto = set_criar();

    set_inserir(conjunto, 1);
    set_inserir(conjunto, 10);
    set_inserir(conjunto, 11);
    set_inserir(conjunto,10);
    set_inserir(conjunto, 7);

    SET *conjunto2 = set_criar();
    set_inserir(conjunto2, 15);
    set_inserir(conjunto2, 102);
    set_inserir(conjunto2, 11);
    set_inserir(conjunto2, 7);
    printf("10 pertence: %d\n",(set_pertence(conjunto,10)));
    
    printf("Conjunto: ");
    set_imprimir(conjunto);
    printf("\n");
    printf("Conjunto2: ");
    set_imprimir(conjunto2);
    printf("\n");
    printf("Conjunto inter Conjunto2: ");
    set_imprimir(set_inter(conjunto2,conjunto));
    printf("\n");
    printf("Conjunto uniao Conjunto2: ");
    set_imprimir(set_uniao(conjunto2,conjunto));
    printf("\n");
    printf("Conjunto remover 10\n");
    set_remover(conjunto, 10);
    printf("Conjunto: ");
    set_imprimir(conjunto);
    printf("\n");

    set_apagar(&conjunto);
    return 0;
}