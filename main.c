#include "TAD_Conjunto/Set.h"
#include <stdio.h>
#include <stdlib.h>

void inserir_elemento(int set);
void imprimir_conjuntos();
void remover_elemento(int set);
void operacao_pertencimento();
void uniao(int conjuntoA, int conjuntoB);
void interseccao(int conjuntoA, int conjuntoB);

SET *conjunto1 = NULL;
SET *conjunto2 = NULL;
SET *conjunto3 = NULL;

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

    conjunto1 = set_criar();
    conjunto2 = set_criar();
    conjunto3 = set_criar();

    imprimir_conjuntos();

    int option = 1, conjuntoA, conjuntoB;
    while (option)
    {
        scanf(" %i", &option);
        switch (option)
        {
        // Inserção de elementos
        case 1:
            scanf(" %i", &conjuntoA);
            inserir_elemento(conjuntoA);
            imprimir_conjuntos();
            break;
        // Remoção de elementos
        case 2:
            scanf(" %i", &conjuntoA);
            remover_elemento(conjuntoA);
            imprimir_conjuntos();
            break;
        // Operação de Pertencimento
        case 3:
            operacao_pertencimento();
            break;
        // União de Conjuntos
        case 4:
            scanf(" %i", &conjuntoA);
            scanf(" %i", &conjuntoB);
            uniao(conjuntoA, conjuntoB);
            break;
        // Intersecção de Conjuntos
        case 5:
            scanf(" %i", &conjuntoA);
            scanf(" %i", &conjuntoB);
            interseccao(conjuntoA, conjuntoB);
            break;
        default:
            printf("Finalizando Programa\n");
        }
    }

    set_apagar(&conjunto1);
    set_apagar(&conjunto2);
    set_apagar(&conjunto3);

    return 0;
}

void imprimir_conjuntos()
{
    printf("Conjunto 1: ");
    set_imprimir(conjunto1);
    printf("Conjunto 2: ");
    set_imprimir(conjunto2);
    printf("Conjunto 3: ");
    set_imprimir(conjunto3);
    printf("--------------------------------------------------\n");
}

void inserir_elemento(int set)
{
    int elemento;
    scanf(" %i", &elemento);
    if (set == 1)
        set_inserir(conjunto1, elemento);
    else if (set == 2)
        set_inserir(conjunto2, elemento);
    else if (set == 3)
        set_inserir(conjunto3, elemento);
    else
        printf("Conjunto inexistente");
}

void remover_elemento(int set)
{
    int elemento;
    scanf(" %i", &elemento);
    if (set == 1)
        set_remover(conjunto1, elemento);
    else if (set == 2)
        set_remover(conjunto2, elemento);
    else if (set == 3)
        set_remover(conjunto3, elemento);
    else
        printf("Conjunto inexistente");
}

void operacao_pertencimento()
{
    int elemento;
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
    printf("--------------------------------------------------\n");
}

void uniao(int conjuntoA, int conjuntoB)
{
    SET *uniao = NULL;
    if (conjuntoA == 1)
    {
        if (conjuntoB == 1)
            uniao = conjunto1;
        else if (conjuntoB == 2)
            uniao = set_uniao(conjunto1, conjunto2);
        else
            uniao = set_uniao(conjunto1, conjunto3);
    }
    else if (conjuntoA == 2)
    {
        if (conjuntoB == 1)
            uniao = set_uniao(conjunto1, conjunto2);
        else if (conjuntoB == 2)
            uniao = conjunto2;
        else
            uniao = set_uniao(conjunto2, conjunto3);
    }
    else
    {
        if (conjuntoB == 1)
            uniao = set_uniao(conjunto3, conjunto1);
        else if (conjuntoB == 2)
            uniao = set_uniao(conjunto2, conjunto3);
        else
            uniao = conjunto3;
    }
    printf("União(%i, %i): ", conjuntoA, conjuntoB);
    set_imprimir(uniao);
    set_apagar(&uniao);
    printf("--------------------------------------------------\n");
}

void interseccao(int conjuntoA, int conjuntoB)
{
    SET *inter = NULL;
    if (conjuntoA == 1)
    {
        if (conjuntoB == 1)
            inter = conjunto1;
        else if (conjuntoB == 2)
            inter = set_inter(conjunto1, conjunto2);
        else
            inter = set_inter(conjunto1, conjunto3);
    }
    else if (conjuntoA == 2)
    {
        if (conjuntoB == 1)
            inter = set_inter(conjunto1, conjunto2);
        else if (conjuntoB == 2)
            inter = conjunto2;
        else
            inter = set_inter(conjunto2, conjunto3);
    }
    else
    {
        if (conjuntoB == 1)
            inter = set_inter(conjunto3, conjunto1);
        else if (conjuntoB == 2)
            inter = set_inter(conjunto2, conjunto3);
        else
            inter = conjunto3;
    }
    printf("Intersecção(%i, %i): ", conjuntoA, conjuntoB);
    set_imprimir(inter);
    set_apagar(&inter);
    printf("--------------------------------------------------\n");
}