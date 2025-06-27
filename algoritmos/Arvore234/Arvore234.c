/******************************************************************************
 * Arquivo: Arvore234.c
 *
 * Descrição: Implementação do Árvore 2-3-4
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
#include "Arvore234.h"

struct no {
    no234 *vetFilho;
    int *vetChaves;
    int ocupacaoFilhos;
    int ocupacaoChaves;
    int folha;
    no234 *noPai;
};

struct arv {
    no234 *raiz;
    int ordem;
};  