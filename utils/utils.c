/******************************************************************************
 * Arquivo: utils.c
 *
 * Descrição: Implementação das funções utilitárias para geração de dados e
 *            operações de arquivo do sistema de benchmarking.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 19/06/2025
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utils.h"

/* Aloca um vetor de tamanho @tam */
int *alocaVetor(int tam)
{
    if (tam <= 0)
        return NULL;

    int *vetor = (int *)malloc(sizeof(int) * tam);

    if (!vetor)
        return NULL;

    return vetor;
}

/*O sistema deve gerar conjuntos de dados ordenados de forma crescente e
decrescente. Para tanto, deve haver uma função com a assinatura abaixo, onde
tam é a quantidade de elementos e ordem define o tipo de ordenação: 0 para
ordem crescente e 1 para ordem decrescente. A função retorna o vetor
previamente preenchido.*/
int *geraOrdenados(int tam, int ordem)
{
    if (tam <= 0 || (ordem != 1 && ordem != 0))
        return NULL;

    int *vetor = alocaVetor(tam);
    if (!vetor)
        return NULL;

    for (int i = 0; i < tam; i++)
        vetor[i] = (ordem == 0 ? i + 1 : tam - i);

    return vetor;
}

/*O sistema deve gerar conjuntos de dados quase ordenados, que contém cerca
de 10% dos dados desordenados 90% ordenados. Para tanto, deve haver uma
função com a assinatura abaixo, onde tam é a quantidade de elementos que
deve ser gerada e a porcentagem é o inteiro que determina a porcentagem de
dados desordenados. A função retorna o vetor previamente preenchido.*/
int *geraQuaseOrdenados(int tam, int porcentagem)
{
    int *vet, numDesordenados, idx1, idx2, temp;
    if (tam <= 0 || porcentagem < 0 || porcentagem > 100)
        return NULL;

    vet = geraOrdenados(tam, 0);
    if (!vet)
        return NULL;

    numDesordenados = (tam * porcentagem) / 100;

    srand(time(NULL));

    for (int i = 0; i < numDesordenados; i++)
    {
        idx1 = rand() % tam, idx2 = rand() % tam;
        temp = vet[idx1];
        vet[idx1] = vet[idx2];
        vet[idx2] = temp;
    }

    return vet;
}

/*O sistema deve gerar conjuntos de dados aleatórios de diferentes tamanhos.
Para tanto, deve haver uma função com a assinatura abaixo, onde tam é a
quantidade de elementos que deve ser gerada e a semente é o inteiro que
permite que esse conjunto de dados seja reproduzido posteriormente. A função
retorna o vetor previamente preenchido.*/
int *geraAleatorios(int tam, int semente)
{
    if (tam <= 0)
        return NULL;

    srand(semente);

    int *vetor = alocaVetor(tam);
    if (!vetor)
        return NULL;

    for (int i = 0; i < tam; i++)
    // Para permitir valores superiores a 32768
        vetor[i] = i + (rand() % tam);

    return vetor;
}