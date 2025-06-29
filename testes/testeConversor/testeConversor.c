/******************************************************************************
 * Arquivo: testeConversor.c
 *
 * Descrição: Testes unitários para a conversão implementada
 *            em /algoritmos. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez da conversão.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 29/06/2025
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../algoritmos/Arvore234/Arvore234.h"
#include "../../algoritmos/RubroNegra/RubroNegra.h"
#include "../../algoritmos/Conversor/Conversor.h"
#include "testeConversor.h"

const int NUMBER_OF_TEST_CASES = 12;
f functions[] = {
    teste1, teste2, teste3, teste4, teste5, teste6, teste7, teste8, teste9,
    teste10, teste11, teste12};

void teste1()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste2()
{
   arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste3()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste4()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {10, 7, 20, 30};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste5()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {10, 5, 2, 9, 30, 25, 40, 38};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste6()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {10, 5, 20, 15, 30, 40};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste7()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {11, 2, 14, 1, 7, 15, 5, 8, 4};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste8()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {5, 1, 10, 2, 0, 3};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste9()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {20, 0, 40, 1, 41, 30, 25, 2};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste10()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {3, 4, 5, 2, 1};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste11()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {17, 20, 25, 23, 12, 115, 55, 47, 31, 21, 43, 44, 46};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
}

void teste12()
{
    arv234 *arv = alocaArvore();

    if (!arv)
        return;

    int ele[] = {18, 14, 11, 4, 12, 16, 19, 20, 7, 21, 22};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], arv);

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(arv), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
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