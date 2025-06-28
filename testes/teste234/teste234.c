/******************************************************************************
 * Arquivo: teste234.c
 *
 * Descrição: Testes unitários para a árvore 2-3-4 implementada
 *            em /algoritmos. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez da árvore 2-3-4.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 28/06/2025
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../algoritmos/Arvore234/Arvore234.h"
#include "./teste234.h"

const int NUMBER_OF_TEST_CASES = 4;
f functions[] = {
    teste1, teste2, teste3, teste4};

void teste1()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

void teste2()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

// PEGA SUCESSOR PARA DAR REPLACE NO ELEMENTO EXCLUIDO
void teste3()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {1,2,3,4,5};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(1, arv);
    imprimirPorNivel(arv);
}

// PEGA SUCESSOR PARA DAR REPLACE NO ELEMENTO EXCLUIDO
void teste4()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {1,2,3};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(2, arv);
    imprimirPorNivel(arv);
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