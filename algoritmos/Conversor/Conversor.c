/******************************************************************************
 * Arquivo: Conversor.c
 *
 * Descrição: Implementação da conversão entre as árvores 2-3-4 e Rubro-Negra
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
#include "../Arvore234/Arvore234.h"
#include "../RubroNegra/RubroNegra.h"

noRB* criaNoRB(int chave, char cor, rb *arvore) {
    noRB *novo = alocaNoRb(arvore, chave);
    alterarCorNoRb(novo, cor);
    return novo;
}

noRB* convert234ToRB(no234 *node, rb *arvore) {
    if (node == NULL) return retornaSentinelaRb(arvore);

    int *chaves = getChaves(node);
    no234 **filhos = getFilhos(node);
    int ocupacao = getOcupacaoChaves(node);

    if (ocupacao == 1) {
        // 1 Nó -> nó preto
        noRB *raiz = criaNoRB(chaves[0], 'P', arvore);
        noRB *esq = convert234ToRB(filhos[0], arvore);
        noRB *dir = convert234ToRB(filhos[1], arvore);
        setEsquerda(raiz, esq);
        setDireita(raiz, dir);

        if (esq != retornaSentinelaRb(arvore)) setPai(esq, raiz);
        if (dir != retornaSentinelaRb(arvore)) setPai(dir, raiz);

        return raiz;
    } else if (ocupacao == 2) {
        // 2 Nós -> preto com filho vermelho à direita
        noRB *raiz = criaNoRB(chaves[0], 'P', arvore);
        noRB *filhoDir = criaNoRB(chaves[1], 'V', arvore);

        noRB *f0 = convert234ToRB(filhos[0], arvore);
        noRB *f1 = convert234ToRB(filhos[1], arvore);
        noRB *f2 = convert234ToRB(filhos[2], arvore);

        setEsquerda(filhoDir, f1);
        setDireita(filhoDir, f2);
        setPai(filhoDir, raiz);
        if (f1 != retornaSentinelaRb(arvore)) setPai(f1, filhoDir);
        if (f2 != retornaSentinelaRb(arvore)) setPai(f2, filhoDir);

        setEsquerda(raiz, f0);
        setDireita(raiz, filhoDir);
        if (f0 != retornaSentinelaRb(arvore)) setPai(f0, raiz);

        return raiz;

    } else if (ocupacao == 3) {
        // 3 Nós → preto com dois filhos vermelhos
        noRB *raiz = criaNoRB(chaves[1], 'P', arvore);
        noRB *filhoEsq = criaNoRB(chaves[0], 'V', arvore);
        noRB *filhoDir = criaNoRB(chaves[2], 'V', arvore);

        noRB *f0 = convert234ToRB(filhos[0], arvore);
        noRB *f1 = convert234ToRB(filhos[1], arvore);
        noRB *f2 = convert234ToRB(filhos[2], arvore);
        noRB *f3 = convert234ToRB(filhos[3], arvore);

        setEsquerda(filhoEsq, f0);
        setDireita(filhoEsq, f1);
        setEsquerda(filhoDir, f2);
        setDireita(filhoDir, f3);

        if (f0 != retornaSentinelaRb(arvore)) setPai(f0, filhoEsq);
        if (f1 != retornaSentinelaRb(arvore)) setPai(f1, filhoEsq);
        if (f2 != retornaSentinelaRb(arvore)) setPai(f2, filhoDir);
        if (f3 != retornaSentinelaRb(arvore)) setPai(f3, filhoDir);

        setEsquerda(raiz, filhoEsq);
        setDireita(raiz, filhoDir);
        setPai(filhoEsq, raiz);
        setPai(filhoDir, raiz);

        return raiz;
    }

    return retornaSentinelaRb(arvore); // caso inválido
}