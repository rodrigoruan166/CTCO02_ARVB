/******************************************************************************
 * Arquivo: RubroNegra.c
 *
 * Descrição: Implementação do Árvore Rubro Negra
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 19/06/2025
 ******************************************************************************/

// Fonte de consulta principal: CORMEN - Introduction to Algorithms

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "RubroNegra.h"

struct RB
{
    noRB *nil, *raiz;
};

struct NO
{
    int chave;
    noRB *dir, *esq, *pai;
    char cor;
};

rb *alocaArvore()
{
    rb *arv = (rb *)malloc(sizeof(rb));

    if (!arv)
        return NULL;

    noRB *nil = (noRB *)malloc(sizeof(noRB)); // sentinela T.nil para tratamento de condicoes de fronteira (CORMEN)

    if (!nil)
        return NULL;

    nil->chave = INT_MIN;
    nil->dir = nil->esq = nil->pai = nil;
    nil->cor = 'P';
    arv->nil = arv->raiz = nil;

    return arv;
}

noRB *alocaNo(rb *arv, int chave)
{
    if (!arv)
        return NULL;

    noRB *novoNo = (noRB *)malloc(sizeof(noRB));

    if (!novoNo)
        return NULL;

    novoNo->chave = chave;
    novoNo->cor = 'V'; // Nó quando inserido é sempre vermelho
    novoNo->esq = novoNo->dir = novoNo->pai = arv->nil;

    return novoNo;
}

// RB-Insert, Cormen - Introduction to Algorithms
void insereNo(rb *T, noRB *z)
{
    noRB *y = T->nil;
    noRB *x = T->raiz;

    while (x != T->nil)
    {
        y = x;
        if (z->chave < x->chave)
        {
            x = x->esq;
        }
        else
        {
            x = x->dir;
        }
    }

    z->pai = y;

    if (y == T->nil)
    {
        T->raiz = z;
    }
    else if (z->chave < y->chave)
    {
        y->esq = z;
    }
    else
    {
        y->dir = z;
    }

    z->esq = T->nil;
    z->dir = T->nil;
    z->cor = 'V';
    RB_Insert_Fixup(T, z);
}

// RB-Insert-Fixup, Cormen - Introduction to Algorithms
void RB_Insert_Fixup(rb *T, noRB *z)
{
    while (z->pai->cor == 'V')
    {
        if (z->pai == z->pai->pai->esq)
        {
            noRB *y = z->pai->pai->dir;
            if (y->cor == 'V')
            {
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->dir)
                {
                    z = z->pai;
                    left_rotate(T, z);
                }
                z->pai->cor = 'P';
                z->pai->pai->cor = 'V';
                right_rotate(T, z->pai->pai);
            }
        }
        else
        { // mesmo que acima, trocando "left" por "right"
            noRB *y = z->pai->pai->esq;
            if (y->cor == 'V')
            {
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->esq)
                {
                    z = z->pai;
                    right_rotate(T, z);
                }
                z->pai->cor = 'P';
                z->pai->pai->cor = 'V';
                left_rotate(T, z->pai->pai);
            }
        }
    }
    T->raiz->cor = 'P';
}

void RB_Transplant(rb *T, noRB *u, noRB *v)
{
    if (u->pai == T->nil)
    {
        T->raiz = v;
    }
    else if (u == u->pai->esq)
    {
        u->pai->esq = v;
    }
    else
    {
        u->pai->dir = v;
    }
    v->pai = u->pai;
}

noRB *Tree_Minimum(rb *T, noRB *x)
{
    while (x->esq != T->nil)
        x = x->esq;
    return x;
}

void left_rotate(rb *T, noRB *x) {
    noRB *y = x->dir;
    x->dir = y->esq;
    if (y->esq != T->nil)
        y->esq->pai = x;

    y->pai = x->pai;
    if (x->pai == T->nil)
        T->raiz = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;

    y->esq = x;
    x->pai = y;
}

void right_rotate(rb *T, noRB *y) {
    noRB *x = y->esq;
    y->esq = x->dir;
    if (x->dir != T->nil)
        x->dir->pai = y;

    x->pai = y->pai;
    if (y->pai == T->nil)
        T->raiz = x;
    else if (y == y->pai->esq)
        y->pai->esq = x;
    else
        y->pai->dir = x;

    x->dir = y;
    y->pai = x;
}

void percorrePreOrdem(rb *T, noRB *aux)
{
    if (!aux || aux == T->nil || !T)
        return;

    printf("%d -- %c\n", aux->chave, aux->cor);
    percorrePreOrdem(T, aux->esq);
    percorrePreOrdem(T, aux->dir);
};

noRB *retornaRaiz(rb *T)
{
    return T->raiz;
}

// RB-Delete, Cormen - Introduction to Algorithms
int removeNo(rb *T, int chave)
{
    if (!T)
    {
        return 0;
    }

    noRB *z = retornaRaiz(T);

    while (z != T->nil && z->chave != chave)
    {
        z = chave < z->chave ? z->esq : z->dir;
    }

    if (z == T->nil) // Elemento não encontrado
        return 0;

    noRB *y = z, *x;
    char y_cor_original = y->cor;

    if (z->esq == T->nil)
    {
        x = z->dir;
        RB_Transplant(T, z, z->dir);
    }
    else if (z->dir == T->nil)
    {
        x = z->esq;
        RB_Transplant(T, z, z->esq);
    }
    else
    {
        y = Tree_Minimum(T, z->dir);
        y_cor_original = y->cor;
        x = y->dir;
        if (y->pai == z)
            x->pai = y;
        else
        {
            RB_Transplant(T, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        RB_Transplant(T, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }

    if (y_cor_original == 'P')
    {
        RB_Delete_Fixup(T, x);
    }

    free(z);

    return 1;
};

void RB_Delete_Fixup(rb *T, noRB *x)
{
    noRB *w;
    while (x != T->raiz && x->cor == 'P')
    {
        if (x == x->pai->esq)
        {
            w = x->pai->dir;
            if (w->cor == 'V')
            {
                w->cor = 'P';
                x->pai->cor = 'V';
                left_rotate(T, x->pai);
                w = x->pai->dir;
            }
            if (w->esq->cor == 'P' && w->dir->cor == 'P')
            {
                w->cor = 'V';
                x = x->pai;
            }
            else
            {
                if (w->dir->cor == 'P')
                {
                    w->esq->cor = 'P';
                    w->cor = 'V';
                    right_rotate(T, w);
                    w = x->pai->dir;
                }
                w->cor = x->pai->cor;
                x->pai->cor = 'P';
                w->dir->cor = 'P';
                left_rotate(T, x->pai);
                x = T->raiz;
            }
        }
        else
        {
            w = x->pai->esq;
            if (w->cor == 'V')
            {
                w->cor = 'P';
                x->pai->cor = 'V';
                right_rotate(T, x->pai);
                w = x->pai->esq;
            }
            if (w->dir->cor == 'P' && w->esq->cor == 'P')
            {
                w->cor = 'V';
                x = x->pai;
            }
            else
            {
                if (w->esq->cor == 'P')
                {
                    w->dir->cor = 'P';
                    w->cor = 'V';
                    left_rotate(T, w);
                    w = x->pai->esq;
                }
                w->cor = x->pai->cor;
                x->pai->cor = 'P';
                w->esq->cor = 'P';
                right_rotate(T, x->pai);
                x = T->raiz;
            }
        }
    }
    x->cor = 'P';
}