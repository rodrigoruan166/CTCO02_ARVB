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

no234 *split(no234 *noCheio, arv234 *arv) {
    // Inserindo um elemento "fantasma", o nó fica com 4 elementos
    // O meio será o elemento da posição 1 ou 2, como escolhemos sempre o da esquerda, será 1
    int posicaoValorMeio = 1;
     
};

void insereChave(int valor, arv234 *arv){

    // Declaração de variaveis
    no234 *aux = arv->raiz;
    int i = 0; // varre o vetor de chaves
    int p = -1; // varre o vetor de ponteiros

    // Encontrar a folha correta
    while (i != p && i < arv->ordem){
        if (valor > aux->vetChaves[i])
            i++;
    }
    p = i;
    
    aux = &aux->vetFilho[p];

    // Encontra a posição do novo elemento inicialmente
    i = aux->ocupacaoChaves;
    while(valor < aux->vetChaves[i]) {
        aux->vetChaves[i] = aux->vetChaves[i-1];
        i--;
    }
    aux->vetChaves[i] = valor;

    // Se o nó não estiver cheio, já inserimos na folha, portanto podemos ignorar
    if (aux->ocupacaoChaves < MAX_CHAVES) {
        aux->ocupacaoChaves++;
        return;
    } else {
        // Caso tenhamos inserido um elemento a mais, devemos fazer o split utilizando o elemento
        // extra contindo dentro do array de chaves.
        split(aux, arv);
    }

}