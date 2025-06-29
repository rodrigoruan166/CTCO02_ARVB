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
#include "./testeRubroNegra.h"

const int NUMBER_OF_TEST_CASES = 15;
f functions[] = {
    teste1, teste2, teste3, teste4, teste5, teste6, teste7, teste8, teste9,
    teste10, teste11, teste12, teste13, teste14, teste15};

void teste1()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 18, 7, 15, 16, 30, 25, 40, 60, 2, 1, 70};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste2()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 18, 7, 15, 16, 30, 25, 40};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste3()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste4()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 7, 20, 30};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 30);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste5()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 7, 20, 30};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 20);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste6()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 5, 2, 9, 30, 25, 40, 38};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 30);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste7()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {10, 5, 20, 15, 30, 40};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 40); // Deixa igual a imagem em casos/caso7
    removeNo(arv, 15);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste8()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {11, 2, 14, 1, 7, 15, 5, 8, 4};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 1);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste9()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {5, 1, 10, 2, 0, 3};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 0);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste10()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {5, 1, 10, 2, 0};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 3); // Deixa igual imagem casos/caso10
    removeNo(arv, 0);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste11()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {5, 1, 10, 2, 0, 3};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 10);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste12()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {20, 0, 40, 1, 41, 30, 25, 2};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 2);
    removeNo(arv, 0); // Deixa a árvore igual na imagem do caso 12
    removeNo(arv, 1);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste13()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {20, 0, 40, 1};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 40);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste14()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {20, 1, 40, 0};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 40);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

void teste15()
{
    rb *arv = alocaArvoreRb();

    if (!arv)
        return;

    int chaves[] = {20, 1, 40, 0};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        noRB *novoNo = alocaNoRb(arv, chaves[i]);
        insereNo(arv, novoNo);
    }

    removeNo(arv, 0); // Deixa a árvore igual na imagem do caso 15
    removeNo(arv, 40);
    percorrePreOrdem(arv, retornaRaiz(arv));
}

int main()
{
    for (int i = 0; i < NUMBER_OF_TEST_CASES; i++)
    {
        printf(" ------ CASO %d ------\n", i + 1);
        functions[i]();
    }

    return 0;
}