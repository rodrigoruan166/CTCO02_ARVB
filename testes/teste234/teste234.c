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
#include <time.h>
#include "../../algoritmos/Arvore234/Arvore234.h"
#include "./teste234.h"
#include "../../utils/utils.h"

char arquivo[] = "./dataset/resultados/resultados.csv";

void teste1(arv234 *arv)
{

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

void teste2(arv234 *arv)
{

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

void teste3(arv234 *arv)
{

    if (!arv)
        return;

    // 1;2;3;4;5
    int chaves[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(1, arv);
    imprimirPorNivel(arv);
}

void teste4(arv234 *arv)
{

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

void teste5(arv234 *arv)
{

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

void teste6(arv234 *arv)
{

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

void teste7(arv234 *arv)
{

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

// 10;9;8;6;5;4;3
void teste8(arv234 *arv)
{

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

// 5;10;20;30;40;50
void teste9(arv234 *arv)
{

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

// 5;10;20;30;40;50
void teste10(arv234 *arv)
{

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

void teste11(arv234 *arv)
{

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

void teste12(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {10, 20};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

void teste13(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

void teste14(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

void teste15(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    imprimirPorNivel(arv);
}

void teste16(arv234 *arv)
{

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

void teste17(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {10, 20, 30, 40, 50};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }
    imprimirPorNivel(arv);
    removeChave(20, arv);
    imprimirPorNivel(arv);
}

void teste18(arv234 *arv)
{

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

void teste19(arv234 *arv)
{

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

void teste20(arv234 *arv)
{

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

void teste21(arv234 *arv)
{

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

void teste22(arv234 *arv)
{

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
    removeChave(22, arv);
    imprimirPorNivel(arv);
}

void teste23(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {17, 20, 25, 23, 12, 115, 55, 47, 31, 21, 43, 44, 46};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }
    imprimirPorNivel(arv);

    removeChave(12, arv);
    removeChave(21, arv);
    removeChave(17, arv);
    imprimirPorNivel(arv);
}

void teste24(arv234 *arv)
{

    if (!arv)
        return;

    int chaves[] = {3, 4, 5, 2, 1};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(4, arv);
    removeChave(5, arv);
    imprimirPorNivel(arv);
}

void teste25(arv234 *arv)
{
    if (!arv)
        return;

    int chaves[] = {10,
                    20,
                    30,
                    40,
                    50,
                    60,
                    70,
                    80,
                    90,
                    100};

    for (int i = 0; i < sizeof(chaves) / sizeof(int); i++)
    {
        insereChave(chaves[i], arv);
    }

    removeChave(40, arv);
    removeChave(70, arv);
    removeChave(100, arv);
    removeChave(50, arv);
    removeChave(60, arv);
    removeChave(20, arv);

    int c[] = {85, 54, 68, 77, 74, 75, 73, 78, 79, 88, 92, 95, 99, 94, 100, 103, 105, 109, 111, 33, 34, 37};
    for (int i = 0; i < sizeof(c) / sizeof(int); i++)
    {
        insereChave(c[i], arv);
    }

    removeChave(68, arv);
    removeChave(88, arv);
    removeChave(79, arv);
    removeChave(95, arv);
    imprimirPorNivel(arv);
}

// TAMANHO DE AMOSTRA PARA INSERÇÃO
void teste26(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 100;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "insercao_100", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

void teste27(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 1000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "insercao_1000", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

void teste28(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 10000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "insercao_10000", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

void teste29(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 100000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "insercao_100000", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

// TAMANHO DA AMOSTRA PARA REMOÇÃO (árvore com 10 mil el.)

void teste30(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 10000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    int t10_percent = qtyValores * 10 / 100;

    for (int i = 0; i < t10_percent; i++)
    {
        removeChave(chaves[i], arv);
    }

    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "remocao_10", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

void teste31(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 10000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    int t20_percent = qtyValores * 20 / 100;

    for (int i = 0; i < t20_percent; i++)
    {
        removeChave(chaves[i], arv);
    }

    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "remocao_20", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

void teste32(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 10000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    int t35_percent = qtyValores * 35 / 100;

    for (int i = 0; i < t35_percent; i++)
    {
        removeChave(chaves[i], arv);
    }

    atualizaAltura(arv);
    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "remocao_35", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

void teste33(arv234 *arv)
{
    if (!arv)
        return;

    int qtyValores = 10000;
    int *chaves = geraAleatorios(qtyValores, time(NULL));

    for (int i = 0; i < qtyValores; i++)
    {
        insereChave(chaves[i], arv);
    }

    int t50_percent = qtyValores * 50 / 100;

    for (int i = 0; i < t50_percent; i++)
    {
        removeChave(chaves[i], arv);
    }

    atualizaAltura(arv);
    atualizaQuantBlocos(arv, getRaiz(arv));
    escreveArquivo(arquivo, "remocao_50", getTotalBorrow(arv), getTotalSplit(arv), getAlturaArv(arv), getTotalBlocos(arv)); // ALTERAR ULTIMO VALOR DE BLOCO;
    imprimirPorNivel(arv);
}

const int NUMBER_OF_TEST_CASES = 8;
f functions[] = {
    /*teste1,
    teste2,
    teste3,
    teste4,
    teste5,
    teste6,
    teste7,
    teste8,
    teste9,
    teste10,
    teste11,
    teste12,
    teste13,
    teste14,
    teste15,
    teste16,
    teste17,
    teste18,
    teste19,
    teste20,
    teste21,
    teste22,
    teste23,
    teste24,
    teste25,*/
    teste26,
    teste27,
    teste28,
    teste29,
    teste30,
    teste31,
    teste32,
    teste33};

int main(arv234 *arv)
{
    for (int i = 0; i < NUMBER_OF_TEST_CASES; i++)
    {
        arv234 *arv = alocaArvore();
        printf("\n\n ######################################################## CASO %d ########\n\n", i + 1);
        functions[i](arv);

        printf("\n\n```\nTOTAL SPLIT %d \nTOTAL MERGE %d \nTOTAL BORROW %d\nTOTAL CHAVES %d\n ```", getTotalSplit(arv), getTotalMerge(arv), getTotalBorrow(arv), getTotalChaves(arv));
        liberaNos234(getRaiz(arv));
        free(arv);
    }

    printf("\nFinalizado\n");
    return 0;
}