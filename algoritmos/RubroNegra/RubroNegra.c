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
    char cor; // 'P' para preto, 'V' para vermelho
};

// Aloca e inicializa a estrutura da árvore Rubro-Negra
rb *alocaArvoreRb()
{
    rb *arv = (rb *)malloc(sizeof(rb));

    if (!arv)
        return NULL;

    noRB *nil = (noRB *)malloc(sizeof(noRB)); // sentinela T.nil para tratamento de condicoes de fronteira (CORMEN)

    if (!nil)
        return NULL;

    nil->chave = INT_MIN;
    nil->dir = nil->esq = nil->pai = nil;
    nil->cor = 'P'; // nil é sempre preto
    arv->nil = arv->raiz = nil;

    return arv;
}

void setRaizRb(rb *T, noRB *raiz) {
    T->raiz = raiz;
}

noRB *getRaizRb(rb *arv) {
    if (!arv)
        return arv->nil;

    return arv->raiz;
}

void setDireita(noRB* no, noRB* filho) {
    if (no) no->dir = filho;
}

void setEsquerda(noRB* no, noRB* filho) {
    if (no) no->esq = filho;
}

void setPai(noRB* no, noRB* pai) {
    if (no) no->pai = pai;
}

noRB* getEsquerda(noRB* no) {
    return no ? no->esq : NULL;
}

noRB* getDireita(noRB* no) {
    return no ? no->dir : NULL;
}

noRB* getPai(noRB* no) {
    return no ? no->pai : NULL;
}

char getCor(noRB* no) {
    return no ? no->cor : 'P'; // Considere preto por padrão
}

int getChave(noRB* no) {
    return no ? no->chave : -1;
}

noRB *retornaSentinelaRb(rb *arv) {
    if (!arv)
        return NULL;

    return arv->nil;
}

// Altera a cor do nó rubro negro
noRB *alterarCorNoRb(noRB *no, char cor) {
    if (!no)
        return NULL;

    no->cor = cor;
    return no;
}

// Aloca e inicializa um novo nó com a chave fornecida
noRB *alocaNoRb(rb *arv, int chave)
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
// Insere um novo nó z na árvore T, seguindo a lógica da BST e depois ajustando com RB_Insert_Fixup
void insereNo(rb *T, noRB *z)
{
    noRB *y = T->nil;
    noRB *x = T->raiz;

    // Busca a posição correta para inserir o novo nó
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

    // Define se o novo nó será filho à esquerda ou direita
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

    // Inicializa filhos com nil e cor vermelha
    z->esq = T->nil;
    z->dir = T->nil;
    z->cor = 'V';

    // Corrige possíveis violações das propriedades da RB Tree
    RB_Insert_Fixup(T, z);
}

// RB-Insert-Fixup, Cormen - Introduction to Algorithms
// Corrige a árvore após inserção para manter as propriedades da RB Tree
void RB_Insert_Fixup(rb *T, noRB *z)
{
    while (z->pai->cor == 'V')
    {
        if (z->pai == z->pai->pai->esq)
        {
            noRB *y = z->pai->pai->dir; // tio de z
            if (y->cor == 'V') // Caso 1
            {
                z->pai->cor = 'P';
                y->cor = 'P';
                z->pai->pai->cor = 'V';
                z = z->pai->pai;
            }
            else
            {
                if (z == z->pai->dir) // Caso 2
                {
                    z = z->pai;
                    left_rotate(T, z);
                }
                // Caso 3
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
    T->raiz->cor = 'P'; // raiz sempre preta
}

// Substitui o nó u pelo nó v (usado em remoção)
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

// Retorna o nó com a menor chave na subárvore de x
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

// Percorre a árvore em pré-ordem imprimindo chave e cor dos nós
void percorrePreOrdem(rb *T, noRB *aux)
{
    if (!aux || aux == T->nil || !T)
        return;

    printf("%d -- %c\n", aux->chave, aux->cor);
    percorrePreOrdem(T, aux->esq);
    percorrePreOrdem(T, aux->dir);
};

// Percorre a árvore em inorder imprimindo chave e cor dos nós
void percorreEmOrdem(rb *T, noRB *aux)
{
    if (!aux || aux == T->nil || !T)
        return;

    percorreEmOrdem(T, aux->esq);
    printf("%d -- %c\n", aux->chave, aux->cor);
    percorreEmOrdem(T, aux->dir);
};

// Percorre a árvore em posordem imprimindo chave e cor dos nós
void percorrePosOrdem(rb *T, noRB *aux)
{
    if (!aux || aux == T->nil || !T)
        return;

    printf("%d -- %c\n", aux->chave, aux->cor);
    percorrePosOrdem(T, aux->dir);
    percorrePosOrdem(T, aux->esq);
};

// Retorna o ponteiro da raiz da árvore
noRB *retornaRaiz(rb *T)
{
    return T->raiz;
}

// RB-Delete, Cormen - Introduction to Algorithms
// Remove o nó com a chave especificada da árvore
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

    if (z == T->nil) // chave não encontrada
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

// Corrige as propriedades da árvore após remoção de um nó
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