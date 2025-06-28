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
#include <limits.h>
#include "Arvore234.h"

/*
Cálculo:
    1. Max. Filhos = m -> 4
    2. Min. Filhos = ceil(m/2) -> 4/2 = 2     
*/
#define MAX_FILHOS 4
#define MIN_FILHOS 2

/*
Cálculo:
    1. Max. Chaves = m - 1 -> 4 - 1 = 3
    2. Min. Chaves = ceil(m/2) - 1 = 4/2 -> 2 - 1 = 1      
*/
#define MAX_CHAVES 3
#define MIN_CHAVES 1

// Define a estrutura do nó de uma árvore-b 2-3-4
struct NO {
    no234 **vetFilho;
    int *vetChaves;
    int ocupacaoFilhos;
    int ocupacaoChaves;
    int folha;
    no234 *noPai;
};

// Define a estrutura básica da árvore
struct arv {
    no234 *raiz;
    int ordem;
};

// Aloca o nó 
no234 *alocaNo() {
    no234* n = (no234 *)malloc(sizeof(no234)); 
    if (!n) return NULL;

    // O vetor de chaves é alocado com 1 posição a mais que a quantidade permitida
    // Razão: Se detectarmos que ele ultrapassou, faremos um cálculo com o valor médio da esquerda
    //        para escolher qual chave será passado ao nó de cima. Mas a chave deve ser considerada nesse cálculo
    int *vetChaves = (int*) malloc((MAX_CHAVES + 1) * sizeof(int));
    no234 **vetFilhos = (no234**) malloc(MAX_FILHOS * sizeof(no234*));

    for (int i = 0; i < MAX_CHAVES+1; i++)
        vetChaves[i] = INT_MIN;

    // Adiciona todos os atributos
    n->ocupacaoChaves = n->ocupacaoFilhos = 0;
    n->folha = 0;
    n->noPai = NULL;
    n->vetFilho = vetFilhos;
    n->vetChaves = vetChaves;

    return n;
}

arv234 *alocaArvore() {
    arv234 *arv = (arv234 *)malloc(sizeof(arv234));

    if (!arv)
        return NULL;

    // Cria o nó para a raiz. Não modificamos nada, porque
    // ele inicialmente está vazio e seu pai é NULL.
    no234 *r = alocaNo();

    arv->raiz = r;

    // Inicialmente, o nó raiz é uma folha
    arv->raiz->folha = 1;
    arv->ordem = 4;

    return arv;
}

/* Split executa recursivamente caso o nó tenha ultrapassado o máximo de chaves permitidas. */
no234 *split(no234 *noCheio, arv234 *arv) {
    // Inserindo um elemento "fantasma", o nó fica com 4 elementos
    // O meio será o elemento da posição 1 ou 2, como escolhemos sempre o da esquerda, será 1
    int posicaoRisingNode = 1;

    no234 *novoDir = alocaNo();
    // O NÓ CHEIO VIRA O DA ESQUERDA APÓS O SPLIT

    noCheio->ocupacaoChaves = 1;
    novoDir->ocupacaoChaves = 2;

    if(noCheio->folha) novoDir->folha = 1;
    

    for (int j = posicaoRisingNode + 1; j < MAX_CHAVES + 1; j++) {
        if (noCheio->vetChaves[j] != INT_MIN) {
            novoDir->vetChaves[j - 2] = noCheio->vetChaves[j];
            noCheio->vetChaves[j] = INT_MIN;
        }
    }

    if (!noCheio->folha) {
        for (int k = posicaoRisingNode + 1; k < MAX_FILHOS; k++) {
            if (noCheio->vetFilho[k] != NULL) {
                novoDir->vetFilho[k - 2] = noCheio->vetFilho[k];
                novoDir->vetFilho[k - 2]->noPai = novoDir;  // Atualizar pai
                noCheio->vetFilho[k] = NULL;
            }
        }
        // Atualizar ocupacaoFilhos
        noCheio->ocupacaoFilhos = 2;  // Filhos 0 e 1
        novoDir->ocupacaoFilhos = 2;  // Filhos que recebeu
    }
        

    // Caso em que o split ocorre na raiz.
    if(noCheio->noPai == NULL) {
        no234 *novoNoPai = alocaNo();
        // Obs: o nó já inicia com folha = 0, portanto não há necessidade de setar
        // Preenche a nova raiz (pós split) com os dados
        arv->raiz = novoNoPai;
        arv->raiz->ocupacaoChaves = 1;
        arv->raiz->ocupacaoFilhos = 2;
        arv->raiz->vetChaves[0] = noCheio->vetChaves[1];
        arv->raiz->vetFilho[0] = noCheio;
        arv->raiz->vetFilho[1] = novoDir;
        // Adiciona o novo nó como pai do resultado do split
        novoDir->noPai = novoNoPai;
        noCheio->noPai = novoNoPai;

        if(arv->raiz->ocupacaoChaves > MAX_CHAVES)
            return split(arv->raiz, arv);
        return arv->raiz;
    } else {
        // Casos em que o noPai não é nulo (não é raiz)

        // Busca a posição em que vamos inserir
        no234 *pai = noCheio->noPai;
        int i = pai->ocupacaoChaves;
        int valorChaveRisingNode = noCheio->vetChaves[posicaoRisingNode];
        while(i > 0 && valorChaveRisingNode < pai->vetChaves[i]) {
            pai->vetChaves[i] = pai->vetChaves[i-1];
            pai->vetFilho[i+1] = pai->vetFilho[i];
            i--;
        }

        // Inclui o rising node no pai e incrementa a ocupação de chaves
        pai->vetChaves[i] = valorChaveRisingNode;
        pai->vetFilho[i+1] = novoDir;
        pai->ocupacaoChaves++;
        pai->ocupacaoFilhos++;

        novoDir->noPai = pai;

        // Reseta o valor da posição que subiu para o pai
        noCheio->vetChaves[posicaoRisingNode] = INT_MIN;

        if(pai->ocupacaoChaves > MAX_CHAVES)
            return split(pai, arv);

        return pai;
    }     
};

void imprimeArvore(arv234 *arv) {
    if(!arv || !arv->raiz) return;
    no234 *aux = 
    while(aux->ocupacaoFilhos > 0) {

    }
};

void insereChave(int valor, arv234 *arv) {
    no234 *aux = arv->raiz;
    
    // Navegar até a folha
    while (!aux->folha) {
        int i = 0;
        while (i < aux->ocupacaoChaves && valor > aux->vetChaves[i]) {
            i++;
        }
        aux = aux->vetFilho[i];
    }
    
    // Inserir na folha
    int i = aux->ocupacaoChaves;
    while (i > 0 && valor < aux->vetChaves[i-1]) {
        aux->vetChaves[i] = aux->vetChaves[i-1];
        i--;
    }
    aux->vetChaves[i] = valor;
    aux->ocupacaoChaves++;
    
    // Verificar se precisa dividir
    if (aux->ocupacaoChaves > MAX_CHAVES) {
        split(aux, arv);
    }
}