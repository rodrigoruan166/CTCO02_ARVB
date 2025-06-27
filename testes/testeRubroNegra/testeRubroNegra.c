/******************************************************************************
 * Arquivo: testeRubroNegra.c
 *
 * Descrição: Testes unitários para a árvore rubro-negra implementada
 *            em /algoritmos. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez da árvore rubro-negra.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 27/06/2025
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../algoritmos/RubroNegra/RubroNegra.h"

typedef void (*f)();

// https://www.youtube.com/watch?v=qA02XWRTBdw - CASO 1 - INSERÇÃO
void caso1() {
    printf(" ---------- CASO 1 ----------\n");
    rb *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 18, 7, 15, 16, 30, 25, 40, 60, 2, 1, 70};

    for (int i = 0; i < sizeof(chaves)/sizeof(int); i++) {
        noRB *novoNo = alocaNo(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    percorrePreOrdem(arv, retornaRaiz(arv));
}

// https://www.youtube.com/watch?v=UFrg_XKFZ7M - CASO 2 - INSERÇÃO
void caso2() {
    printf(" ---------- CASO 2 ----------\n");
    rb *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 18, 7, 15, 16, 30, 25, 40};

    for (int i = 0; i < sizeof(chaves)/sizeof(int); i++) {
        noRB *novoNo = alocaNo(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    percorrePreOrdem(arv, retornaRaiz(arv));
}

// https://cs.valdosta.edu/~dgibson/courses/cs3410/notes/ch19_5.pdf - CASO 3 - INSERÇÃO (Ex. 9)
void caso3() {
    printf(" ---------- CASO 3 ----------\n");
    rb *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55};

    for (int i = 0; i < sizeof(chaves)/sizeof(int); i++) {
        noRB *novoNo = alocaNo(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    percorrePreOrdem(arv, retornaRaiz(arv));
}

// https://www.youtube.com/watch?v=w5cvkTXY0vQ 9:00 - CASO 4 - REMOÇÃO
// Nó que vai ser deletado é vermelho
void caso4() {
    printf(" ---------- CASO 4 ----------\n");
    rb *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 7, 20, 30};

    for (int i = 0; i < sizeof(chaves)/sizeof(int); i++) {
        noRB *novoNo = alocaNo(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 30);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

// https://www.youtube.com/watch?v=w5cvkTXY0vQ 12:00 - CASO 5 - REMOÇÃO
// Nó a ser deletado é vermelho, pegar inorder sucessor
void caso5() {
    printf(" ---------- CASO 5 ----------\n");
    rb *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 7, 20, 30};

    for (int i = 0; i < sizeof(chaves)/sizeof(int); i++) {
        noRB *novoNo = alocaNo(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 20);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

// https://www.youtube.com/watch?v=w5cvkTXY0vQ 12:51 - CASO 6 - REMOÇÃO
void caso6() {
    printf(" ---------- CASO 6 ----------\n");
    rb *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 5, 2, 9, 30, 25, 40, 38};

    for (int i = 0; i < sizeof(chaves)/sizeof(int); i++) {
        noRB *novoNo = alocaNo(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 30);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

const int NUMBER_OF_TEST_CASES = 6;
f functions[] = {
    caso1, caso2, caso3, caso4, caso5, caso6
};

int main()
{
    for (int i = 0; i < NUMBER_OF_TEST_CASES; i++) {
        functions[i]();
    }

    return 0;
}