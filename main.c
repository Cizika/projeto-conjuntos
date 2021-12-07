#include "TAD_Conjunto/Set.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("--------------------------------------------------\n");
    printf("CONJUNTOS MATEMÁTICOS\n");
    printf("1 - Insere um elemento no conjunto desejado\n");
    printf("2 - Remove um elemento do conjunto desejado\n");
    printf("3 - Verifica se o elemento pertence aos conjuntos\n");
    printf("4 - União entre conjuntos\n");
    printf("5 - Intersecção entre conjuntos\n");
    printf("0 - Finalizar Programa\n");
    printf("--------------------------------------------------\n");

    SET *conjunto1 = set_criar();
    SET *conjunto2 = set_criar();
    SET *conjunto3 = set_criar();

    int option = 1, elemento, conjuntoA, conjuntoB;
    while (option)
    {
        scanf(" %i", &option);
        switch (option)
        {
        // Inserção de elementos
        case 1:
            scanf(" %i", &conjuntoA);
            scanf(" %i", &elemento);
            if (conjuntoA == 1)
                set_inserir(conjunto1, elemento);
            else if (conjuntoA == 2)
                set_inserir(conjunto2, elemento);
            else if (conjuntoA == 3)
                set_inserir(conjunto3, elemento);
            else
                printf("Conjunto inexistente");
            printf("Conjunto 1: ");
            set_imprimir(conjunto1);
            printf("Conjunto 2: ");
            set_imprimir(conjunto2);
            printf("Conjunto 3: ");
            set_imprimir(conjunto3);
            break;
        // Remoção de elementos
        case 2:
            scanf(" %i", &conjuntoA);
            scanf(" %i", &elemento);
            if (conjuntoA == 1)
                set_remover(conjunto1, elemento);
            else if (conjuntoA == 2)
                set_remover(conjunto2, elemento);
            else if (conjuntoA == 3)
                set_remover(conjunto3, elemento);
            else
                printf("Conjunto inexistente");
            printf("Conjunto 1: ");
            set_imprimir(conjunto1);
            printf("Conjunto 2: ");
            set_imprimir(conjunto2);
            printf("Conjunto 3: ");
            set_imprimir(conjunto3);
            break;
        // Operação de Pertencimento
        case 3:
            scanf(" %i", &elemento);
            if (set_pertence(conjunto1, elemento))
                printf("O elemento %i pertence ao conjunto 1\n", elemento);
            else
                printf("O elemento %i NÃO pertence ao conjunto 1\n", elemento);

            if (set_pertence(conjunto2, elemento))
                printf("O elemento %i pertence ao conjunto 2\n", elemento);
            else
                printf("O elemento %i NÃO pertence ao conjunto 2\n", elemento);

            if (set_pertence(conjunto3, elemento))
                printf("O elemento %i pertence ao conjunto 3\n", elemento);
            else
                printf("O elemento %i NÃO pertence ao conjunto 3\n", elemento);
            break;
        // União de Conjuntos
        case 4:
            scanf(" %i", &conjuntoA);
            scanf(" %i", &conjuntoB);
            SET *uniao = NULL;
            if (conjuntoA + conjuntoB == 3)
                uniao = set_uniao(conjunto1, conjunto2);
            else if (conjuntoA + conjuntoB == 4)
                uniao = set_uniao(conjunto1, conjunto3);
            else
                uniao = set_uniao(conjunto2, conjunto3);
            printf("União(%i, %i): ", conjuntoA, conjuntoB);
            set_imprimir(uniao);
            set_apagar(&uniao);
            break;
        // Intersecção de Conjuntos
        case 5:
            scanf(" %i", &conjuntoA);
            scanf(" %i", &conjuntoB);
            SET *inter = NULL;
            if (conjuntoA + conjuntoB == 3)
                inter = set_inter(conjunto1, conjunto2);
            else if (conjuntoA + conjuntoB == 4)
                inter = set_inter(conjunto1, conjunto3);
            else
                inter = set_inter(conjunto2, conjunto3);
            printf("Intersecção(%i, %i): ", conjuntoA, conjuntoB);
            set_imprimir(inter);
            set_apagar(&inter);
            break;
        default:
            printf("Finalizando Programa\n");
        }
        printf("--------------------------------------------------\n");
    }

    set_apagar(&conjunto1);
    set_apagar(&conjunto2);
    set_apagar(&conjunto3);

    return 0;
}