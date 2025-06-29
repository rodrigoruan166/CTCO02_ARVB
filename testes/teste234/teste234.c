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

void teste1()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    // 10;20;30;40;50;60;70;80;90;100
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

    // 5;3;21;9;1;13;2;7;10;12;4;8
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

    //1;2;3;4;5
    int chaves[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(1, arv);
    imprimirPorNivel(arv);
}

// REMOVE DO FOLHA do meio, KEYS > MIN_KEYS
void teste4()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {1, 2, 3};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(2, arv);
    imprimirPorNivel(arv);
}

// REMOVE DO FOLHA do canto esquerdo, KEYS > MIN_KEYS
void teste5()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {1, 2, 3};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(1, arv);
    imprimirPorNivel(arv);
}

// REMOVE DO FOLHA do canto direito, KEYS > MIN_KEYS
void teste6()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {1, 2, 3};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(3, arv);
    imprimirPorNivel(arv);
}

// REMOVE FOLHA COM MERGE À DIREITA
void teste7()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {1, 2, 3, 4};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(1, arv);
    imprimirPorNivel(arv);
}

// ROTAÇÃO À ESQUERDA
// 10;9;8;6;5;4;3
void teste8()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(10, arv);
    imprimirPorNivel(arv);
}

// MERGE à ESQUERDA
// 5;10;20;30;40;50
void teste9()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {5, 10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(50, arv);
    removeChave(40, arv);
    imprimirPorNivel(arv);
}

// MERGE à DIREITA
// 5;10;20;30;40;50
void teste10()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {5, 10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(50, arv);
    removeChave(5, arv);
    imprimirPorNivel(arv);
}

void teste11()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60, 70, 80};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(80, arv);
    removeChave(50, arv);
    imprimirPorNivel(arv);
}

// Inserção em nó folha sem split
void teste12()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

// Inserção em nó gerando split na folha
void teste13()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

// Inserção causa split em folha e propagação para raiz
void teste14()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

// Inserção com split em um nó interno
// Folha faz split e o pai tem 3 chaves
void teste15()
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

// Remoção de uma chave de um nó folha com mais de 1 chave
void teste16()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(20, arv);
    imprimirPorNivel(arv);
}

// Remoção de uma chave de um nó interno (redistribuição)
void teste17()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(20, arv);
    imprimirPorNivel(arv);
}

// Remoção de nó folha com 1 chave, merge com pai
void teste18()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(60, arv);
    removeChave(50, arv);
    imprimirPorNivel(arv);
}

// Remoção de nó folha com 1 chave, merge com pai
void teste19()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(60, arv);
    removeChave(40, arv);
    imprimirPorNivel(arv);
}

// Remoção da última chave da raiz (altura diminui)
void teste20()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(10, arv);
    removeChave(20, arv);
    removeChave(30, arv);
    imprimirPorNivel(arv);
}

// Remoção da última chave da raiz (altura diminui)
void teste21()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60, 70, 80};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(10, arv);
    removeChave(20, arv);
    removeChave(30, arv);
    imprimirPorNivel(arv);
}

void teste22()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(10, arv);
    removeChave(30, arv);
    removeChave(40, arv);
    removeChave(50, arv);
    insereChave(10, arv);
    insereChave(30, arv);
    insereChave(40, arv);
    insereChave(50, arv);
    insereChave(60, arv);

    imprimirPorNivel(arv);
}

// 18;14;11;4;12;16;19;20;7;21;22
void teste23()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {18, 14, 11, 4, 12, 16, 19, 20, 7, 21, 22};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(21, arv);
    imprimirPorNivel(arv);
    removeChave(18, arv);
    imprimirPorNivel(arv);
    removeChave(19, arv);
    imprimirPorNivel(arv);
    removeChave(7, arv);
    imprimirPorNivel(arv);
    removeChave(4, arv);
    imprimirPorNivel(arv);
}

// 17;20;25;23;12;115;55;47;31;21;43;44;46
void teste24()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int chaves[] = {17, 20, 25, 23, 12, 115, 55, 47, 31, 21, 43, 44, 46};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(12, arv);
    removeChave(21, arv);
    removeChave(17, arv);
    imprimirPorNivel(arv);
}

const int NUMBER_OF_TEST_CASES = 1;
f functions[] = {
    //teste1,
    //teste2,
    //teste3,
    //teste4,
    // teste5,
    // teste6,
    // teste7,
    // teste8,
    // teste9,
    //teste10,
    // teste11,
    // teste12,
    // teste13,
    // teste14,
    // teste15,
    // teste16,
    // teste17,
    // teste18,
    // teste19,
    // teste20,
    // teste21,
    // teste22,
     teste23,
    //teste24
};

int main()
{
    for (int i = 0; i < NUMBER_OF_TEST_CASES; i++)
    {
        printf(" ------ CASO %d ------\n", i + 1);
        functions[i]();
    }

    return 0;
}