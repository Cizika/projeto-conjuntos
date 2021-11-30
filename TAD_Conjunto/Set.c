#include "Set.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;

struct no
{
    int elemento;
    NO *esq;
    NO *dir;
    int altura;
};

struct set
{
    NO *raiz;
    int profundidade;
};

// Operação Básica => Função para criar um conjunto
SET *set_criar(void)
{
    SET *set = (SET *)malloc(sizeof(SET));
    if (set != NULL)
    {
        set->raiz = NULL;
        set->profundidade = -1;
    }
    return set;
}

// Função auxiliar que remove os nós em algoritmo de POST-ORDER
void set_apagar_aux(NO **raiz)
{
    if (*raiz != NULL)
    {
        set_apagar_aux(&((*raiz)->esq));
        set_apagar_aux(&((*raiz)->dir));
        free(*raiz);
    }
}

// Operação Básica => Função para remover e desalocar a memória de um conjunto
void set_apagar(SET **set)
{
    set_apagar_aux(&((*set)->raiz));
    free(*set);
    *set = NULL;
}

// Função auxiliar para retornar a altura de um nó
int set_altura_no(NO *raiz)
{
    if (raiz == NULL)
        return -1;
    else
        return raiz->altura;
}

// Rotação a Direita para garantir que a árvore do conjunto permaneça balanceada
NO *set_rotacao_direita(NO *A)
{
    NO *B = A->esq;
    A->esq = B->dir;
    B->dir = A;

    A->altura = max(set_altura_no(A->esq), set_altura_no(A->dir)) + 1;
    B->altura = max(set_altura_no(B->esq), A->altura) + 1;

    return B;
}

// Rotação a Esquerda para garantir que a árvore do conjunto permaneça balanceada
NO *set_rotacao_esquerda(NO *A)
{
    NO *B = A->dir;
    A->dir = B->esq;
    B->esq = A;

    A->altura = max(set_altura_no(A->esq), set_altura_no(A->dir)) + 1;
    B->altura = max(A->altura, set_altura_no(B->dir)) + 1;

    return B;
}

// Rotação Dupla (Dir/Esq) para garantir que a árvore do conjunto permaneça balanceada
NO *set_rotacao_direita_esquerda(NO *A)
{
    A->dir = set_rotacao_direita(A->dir);
    return set_rotacao_esquerda(A);
}

// Rotação Dupla (Esq/Dir) para garantir que a árvore do conjunto permaneça balanceada
NO *set_rotacao_esquerda_direita(NO *A)
{
    A->esq = set_rotacao_esquerda(A->esq);
    return set_rotacao_direita(A);
}

// Função auxiliar de criação de um Nó no conjunto
NO *set_cria_no(int elemento)
{
    NO *no = (NO *)malloc(sizeof(NO));
    if (no != NULL)
    {
        no->altura = 0;
        no->dir = NULL;
        no->esq = NULL;
        no->elemento = elemento;
    }
    return no;
}

// Função auxiliar para inserir um nó
NO *set_inserir_no(NO *raiz, int elemento)
{
    if (raiz == NULL)
        raiz = set_cria_no(elemento);
    else if (elemento > raiz->elemento)
        raiz->dir = set_inserir_no(raiz->dir, elemento);
    else if (elemento < raiz->elemento)
        raiz->esq = set_inserir_no(raiz->esq, elemento);

    raiz->altura = max(set_altura_no(raiz->esq), set_altura_no(raiz->dir)) + 1;
    int FB = set_altura_no(raiz->esq) - set_altura_no(raiz->dir);
    if (FB == 2)
    {
        if (elemento < raiz->esq->elemento)
            raiz = set_rotacao_direita(raiz);
        else
            raiz = set_rotacao_esquerda_direita(raiz);
    }
    else if (FB == -2)
    {
        if (elemento > raiz->dir->elemento)
            raiz = set_rotacao_esquerda(raiz);
        else
            raiz = set_rotacao_direita_esquerda(raiz);
    }
    return raiz;
}

// Operação Básica => Inserção de um elemento no conjunto
boolean set_inserir(SET *set, int elemento)
{
    return ((set->raiz = set_inserir_no(set->raiz, elemento)) != NULL);
}

void troca_max_esq(NO *troca, NO *raiz, NO *ant)
{
    if (troca->dir != NULL)
    {
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }

    if (raiz == ant)
        ant->esq = troca->esq;
    else
        ant->dir = troca->esq;

    raiz->elemento = troca->elemento;
    free(troca);
    troca = NULL;
}

// Auxiliar para remoção de um nó => Função recursiva
NO *set_remover_aux(NO **raiz, int elemento)
{
    NO *p;
    // Se atingiu o filho do nó folha (raiz nula) retorna Null (elemento ausente na set)
    if (*raiz == NULL)
        return NULL;
    else if (elemento == (*raiz)->elemento)
    {
        // Caso em que o nó a ser removido é um NÓ FOLHA ou possuí apenas um filho
        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL)
        {
            p = *raiz;
            if ((*raiz)->esq == NULL)
                *raiz = (*raiz)->dir;
            else
                *raiz = (*raiz)->esq;
            free(p);
            p = NULL;
        }
        // Caso em que o nó possui ambos os filhos
        else
            troca_max_esq((*raiz)->esq, (*raiz), (*raiz));
    }
    else if (elemento < (*raiz)->elemento)
        return set_remover_aux(&(*raiz)->esq, elemento);
    else
        return set_remover_aux(&(*raiz)->dir, elemento);

    if (*raiz != NULL)
    {
        (*raiz)->altura = max(set_altura_no((*raiz)->esq), set_altura_no((*raiz)->dir)) + 1;
        int FB = set_altura_no((*raiz)->esq) - set_altura_no((*raiz)->dir);
        if (FB == -2)
        {
            if (set_altura_no((*raiz)->dir->esq) - set_altura_no((*raiz)->dir->dir) <= 0)
                *raiz = set_rotacao_esquerda(*raiz);
            else
                *raiz = set_rotacao_direita_esquerda(*raiz);
        }
        if (FB == 2)
        {
            if (set_altura_no((*raiz)->esq->esq) - set_altura_no((*raiz)->esq->dir) >= 0)
                *raiz = set_rotacao_direita(*raiz);
            else
                *raiz = set_rotacao_esquerda_direita(*raiz);
        }
    }
    return *raiz;
}

// Operação Básica => Remoção de um nó do conjunto em algoritmo PRE-ORDER
boolean set_remover(SET *set, int elemento)
{
    return ((set->raiz = set_remover_aux(&set->raiz, elemento)) != NULL);
}

// Imprime em algoritmo IN-ORDER
void set_imprimir_aux(NO *raiz)
{
    if (raiz != NULL)
    {
        set_imprimir_aux(raiz->esq);
        printf("%i ", raiz->elemento);
        set_imprimir_aux(raiz->dir);
    }
}

// Operação Básica => Impressão dos elementos de um conjunto
void set_imprimir(SET *set)
{
    set_imprimir_aux(set->raiz);
}

// Operação de Conjuntos => Verifica o pertencimento de um elemento em relação a um conjunto
boolean set_pertence(SET *set, int elemento)
{
}

// Operação de Conjuntos => União entre Conjuntos
SET *set_uniao(SET *A, SET *B)
{
}

// Operação de Conjuntos => Intersecção entre Conjuntos
SET *set_inter(SET *A, SET *B)
{
}