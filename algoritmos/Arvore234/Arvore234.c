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
    int totalSplit;
    int totalBorrow;
    int totalMerge;
};

// Aloca o nó 
no234 *alocaNo() {
    no234* n = (no234 *)malloc(sizeof(no234)); 
    if (!n) return NULL;

    // O vetor de chaves é alocado com 1 posição a mais que a quantidade permitida
    // Razão: Se detectarmos que ele ultrapassou, faremos um cálculo com o valor médio da esquerda
    //        para escolher qual chave será passado ao nó de cima. Mas a chave deve ser considerada nesse cálculo
    int *vetChaves = (int*) malloc((MAX_CHAVES + 1) * sizeof(int));
    no234 **vetFilhos = (no234**) malloc((MAX_FILHOS + 1) * sizeof(no234*));

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
    arv->totalBorrow = arv->totalMerge = arv->totalSplit = 0;
    arv->ordem = 4;

    return arv;
}

int *getChaves(no234 *no) {
    if (!no)
        return NULL;
    return no->vetChaves;
}

no234 **getFilhos(no234 *no) {
    if (!no)
        return NULL;
    return no->vetFilho;
}

no234 *getRaiz(arv234 *arv) {
    if (!arv)
        return NULL;

    return arv->raiz;
}

int getOcupacaoChaves(no234 *no) {
    if (!no)
        return 0;
    return no->ocupacaoChaves;
}

int getOcupacaoFilhos(no234 *no) {
    if (!no)
        return 0;
    return no->ocupacaoFilhos;
}

int getTotalSplit(arv234 *a) {
    if (!a)
        return 0;
    return a->totalSplit;
}

int getTotalBorrow(arv234 *a) {
    if (!a)
        return 0;
    return a->totalBorrow;
}

int getTotalMerge(arv234 *a) {
    if (!a)
        return 0;
    return a->totalMerge;
}

/* Split executa recursivamente caso o nó tenha ultrapassado o máximo de chaves permitidas. */
no234 *split(no234 *noCheio, arv234 *arv) {
    arv->totalSplit++;
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
        printf("Condicao no cheio nao e folha\n");
        int count = 0;
        for (int k = posicaoRisingNode + 1; k < MAX_FILHOS + 1; k++) {
            if (noCheio->vetFilho[k] != NULL) {
                count++;
                novoDir->vetFilho[k - 2] = noCheio->vetFilho[k];
                novoDir->vetFilho[k - 2]->noPai = novoDir;  // Atualizar pai
                noCheio->vetFilho[k] = NULL;
            }
        }
        // Atualizar ocupacaoFilhos
        noCheio->ocupacaoFilhos = 2;  // Filhos 0 e 1
        novoDir->ocupacaoFilhos = count;  // Filhos que recebeu
    }
        

    // Caso em que o split ocorre na raiz.
    if(noCheio->noPai == NULL) {
        printf("Condicao noCheio e RAIZ\n");
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
        printf("    caiu nesse caso??\n");
        // Busca a posição em que vamos inserir
        no234 *pai = noCheio->noPai;
        int i = pai->ocupacaoChaves;
        int valorChaveRisingNode = noCheio->vetChaves[posicaoRisingNode];
        while(i > 0 && valorChaveRisingNode < pai->vetChaves[i-1]) {
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

void preOrdemRec(no234 *no) {
    if (no == NULL) {
        return;
    }
    
    // Em uma árvore 2-3-4, o percurso pré-ordem segue o padrão:
    // 1. Visita primeira chave
    // 2. Percorre primeiro filho
    // 3. Visita segunda chave (se existir)  
    // 4. Percorre segundo filho (se existir)
    // 5. Visita terceira chave (se existir)
    // 6. Percorre terceiro filho (se existir)
    // 7. Percorre quarto filho (se existir)
    
    for (int i = 0; i < no->ocupacaoChaves; i++) {
        // Percorre filho à esquerda da chave atual
        if (!no->folha && i < no->ocupacaoFilhos) {
            preOrdemRec(no->vetFilho[i]);
        }
        
        // Visita a chave atual
        if (no->vetChaves[i] != INT_MIN) {
            printf("%d ", no->vetChaves[i]);
        }
    }
    
    // Percorre o último filho (mais à direita)
    if (!no->folha && no->ocupacaoFilhos > no->ocupacaoChaves) {
        preOrdemRec(no->vetFilho[no->ocupacaoChaves]);
    }
}

// Função principal para percurso pré-ordem
void preOrdem(arv234 *arv) {
    if (arv == NULL || arv->raiz == NULL) {
        printf("Árvore vazia!\n");
        return;
    }
    
    printf("Percurso Pré-Ordem: ");
    preOrdemRec(arv->raiz);
    printf("\n");
}

void imprimirChavesNo(no234 *no, int d) {
    if (no == NULL) {
        printf("[NULL]");
        return;
    }
    
    printf("[", d);
    for (int i = 0; i < no->ocupacaoChaves; i++) {
        if (i > 0) printf(",");
        printf("%d", no->vetChaves[i]);
    }
    printf("]");
}

void imprimirPorNivel(arv234 *arv) {
    if (arv == NULL || arv->raiz == NULL) {
        printf("Árvore vazia!\n");
        return;
    }

    printf("kfdksfdsk\n");

    no234 *fila[1000];
    int niveis[1000];
    int noRelativo[1000];
    int inicio = 0, fim = 0;
    int nivelAtual = 0;

    fila[fim] = arv->raiz;
    niveis[fim] = 0;
    fim++;

    printf("Árvore por níveis:\n");
    printf("Nível 0: ");
    
    no234 *ultimoPai = NULL;

    while (inicio < fim) {
        no234 *noAtual = fila[inicio];
        int nivelNo = niveis[inicio];
        inicio++;

        if (nivelNo > nivelAtual) {
            printf("\nNível %d: ", nivelNo);
            nivelAtual = nivelNo;
            ultimoPai = NULL; // Reset para o novo nível
        }

        // Se o pai for diferente do anterior, imprime " || "
        if (ultimoPai != NULL && noAtual->noPai != ultimoPai) {
            printf(" || ");
        } else if (ultimoPai != NULL) {
            printf(" ");
        }

        imprimirChavesNo(noAtual, noRelativo[inicio]);
        ultimoPai = noAtual->noPai;

        if (!noAtual->folha) {
            for (int i = 0; i < noAtual->ocupacaoFilhos; i++) {
                if (noAtual->vetFilho[i] != NULL) {
                    fila[fim] = noAtual->vetFilho[i];
                    noRelativo[fim] = i;
                    niveis[fim] = nivelNo + 1;
                    fim++;
                }
            }
        }
    }

    printf("\n");
}

no234 *buscaNo(int valor, int *pos, int *posNo, arv234 *arv) {
    no234 *aux = arv->raiz;
    while(aux != NULL) {
        int flag = 0, i;

        printf("[");
        for(int i = 0; i < aux->ocupacaoChaves; i++) {
            printf(" %d ", aux->vetChaves[i]);
        }
        printf("]\n");
        for(i = 0; i < aux->ocupacaoChaves; i++) {
            if (aux->vetChaves[i] == valor) {
                flag = 1;
                break;
            }
            
            if (aux->vetChaves[i] > valor)
                break;
        }
        
        if(flag) {
            *pos = i;
            printf("Achou na posicao %d\n", *pos);
            printf("Encontrado: [");
            for(int i = 0; i < aux->ocupacaoChaves; i++) {
                printf(" %d ", aux->vetChaves[i]);
            }
            printf("]\n");
            break;
        } 

        if (aux->ocupacaoFilhos == 0) {
            aux = NULL;
            break;
        }   
        else {
            printf(" > Indo para o filho %d\n", i);
            *posNo = i;
            aux = aux->vetFilho[i];
        } 
    }

    return aux;
}

void borrowLeft(arv234 *arv, no234 *aux, no234* irmaoEsq, int pos, int posNo) {
    arv->totalBorrow++;
    int chaveIrmao = irmaoEsq->vetChaves[irmaoEsq->ocupacaoChaves-1];
    printf("> Chave do irmao encontrada: %d\n", chaveIrmao);
    int chavePai = aux->noPai->vetChaves[posNo-1];
    printf("> Chave do PAI encontrada (pos: %d): %d\n", posNo, chavePai);

    // Deslocar chaves no nó atual para abrir espaço
    for (int i = aux->ocupacaoChaves; i > 0; i--) {
        aux->vetChaves[i] = aux->vetChaves[i-1];
    }
    aux->vetChaves[0] = chavePai;

    if (aux->ocupacaoChaves == 0) { // CASO DA INSERCAO
        printf("Incrementando ocupacao chaves\n");
        aux->ocupacaoChaves++;
    }

    aux->noPai->vetChaves[posNo-1] = chaveIrmao;

    if (!aux->folha) {
        for (int i = aux->ocupacaoFilhos; i > 0; i--) {
            aux->vetFilho[i] = aux->vetFilho[i-1];
        }
        aux->vetFilho[0] = irmaoEsq->vetFilho[irmaoEsq->ocupacaoFilhos-1];
        if (aux->vetFilho[0]) {
            aux->vetFilho[0]->noPai = aux;
        }
        aux->ocupacaoFilhos++;
        irmaoEsq->vetFilho[irmaoEsq->ocupacaoFilhos-1] = NULL;
        irmaoEsq->ocupacaoFilhos--;
    }

    irmaoEsq->vetChaves[irmaoEsq->ocupacaoChaves-1] = INT_MIN;
    irmaoEsq->ocupacaoChaves--;
}

void borrowRight(arv234 *arv, no234 *aux, no234* irmaoDir, int pos, int posNo) {
    arv->totalBorrow++;
    int chaveIrmao = irmaoDir->vetChaves[0];
    printf("> Chave do irmao encontrada: %d\n", chaveIrmao);
    int chavePai = aux->noPai->vetChaves[posNo];
    printf("> Chave do PAI encontrada (pos: %d): %d\n", posNo, chavePai);

    aux->vetChaves[0] = chavePai;
    if (aux->ocupacaoChaves == 0) { // CASO DA INSERCAO
        printf("Incrementando ocupacao chaves\n");
        aux->ocupacaoChaves++;
    }

    aux->noPai->vetChaves[posNo] = chaveIrmao;

    if (!aux->folha) {
        aux->vetFilho[aux->ocupacaoFilhos] = irmaoDir->vetFilho[0];
        if (aux->vetFilho[aux->ocupacaoFilhos]) {
            aux->vetFilho[aux->ocupacaoFilhos]->noPai = aux;
        }
        aux->ocupacaoFilhos++;
        for (int i = 0; i < irmaoDir->ocupacaoFilhos-1; i++) {
            irmaoDir->vetFilho[i] = irmaoDir->vetFilho[i+1];
        }
        irmaoDir->vetFilho[irmaoDir->ocupacaoFilhos-1] = NULL;
        irmaoDir->ocupacaoFilhos--;
    }

    for (int i = 0; i < irmaoDir->ocupacaoChaves-1; i++) {
        irmaoDir->vetChaves[i] = irmaoDir->vetChaves[i+1];
    }
    irmaoDir->vetChaves[irmaoDir->ocupacaoChaves-1] = INT_MIN;
    irmaoDir->ocupacaoChaves--;
}

void mergeLeft(arv234 *arv, no234 *aux, no234* irmaoEsq, int pos, int posNo) {
    arv->totalMerge++;
    for(int i = 0; i < aux->noPai->ocupacaoChaves; i++)
        printf(" %d ", aux->noPai->vetChaves[i]);
                
    printf("\n\tFILHOS\n\n");
    for(int i = 0; i < aux->noPai->ocupacaoFilhos; i++) {
        //printf("(%d) %d ", i, aux->noPai->vetFilho[i]);
        printf("  %d  [", i);
        for(int j = 0; j < aux->noPai->vetFilho[i]->ocupacaoChaves; j++)
            printf(" %d ", aux->noPai->vetFilho[i]->vetChaves[j]);
        printf("]");

    }
    printf("\n\n\n");

    int chavePai = aux->noPai->vetChaves[posNo-1];
    printf("Pai encontrado: %d\n", chavePai);

    irmaoEsq->vetChaves[irmaoEsq->ocupacaoChaves] = chavePai;
    irmaoEsq->ocupacaoChaves++;

    // Transferir filhos de aux para irmaoEsq, se não for folha
    if (!aux->folha) {
        for (int i = 0; i < aux->ocupacaoFilhos; i++) {
            irmaoEsq->vetFilho[irmaoEsq->ocupacaoFilhos] = aux->vetFilho[i];
            if (irmaoEsq->vetFilho[irmaoEsq->ocupacaoFilhos]) {
                irmaoEsq->vetFilho[irmaoEsq->ocupacaoFilhos]->noPai = irmaoEsq;
            }
            irmaoEsq->ocupacaoFilhos++;
        }
    }

    // Shift nas chaves pai
    for(int index = posNo-1; index < aux->noPai->ocupacaoChaves-1; index++) 
        aux->noPai->vetChaves[index] = aux->noPai->vetChaves[index+1];
    
    // Shift nos filhos do pai
    for(int index = posNo; index < aux->noPai->ocupacaoFilhos-1; index++) 
        aux->noPai->vetFilho[index] = aux->noPai->vetFilho[index+1];

    aux->noPai->ocupacaoFilhos--;
    aux->noPai->ocupacaoChaves--;

    free(aux);
}

void mergeRight(arv234 *arv, no234 *aux, no234* irmaoDir, int pos, int posNo) {
    arv->totalMerge++;
    for(int i = 0; i < aux->noPai->ocupacaoChaves; i++)
        printf(" %d ", aux->noPai->vetChaves[i]);
    
    printf("\n\tFILHOS\n\n");
    for(int i = 0; i < aux->noPai->ocupacaoFilhos; i++) {
        //printf("(%d) %d ", i, aux->noPai->vetFilho[i]);
        printf("  %d  [", i);
        for(int j = 0; j < aux->noPai->vetFilho[i]->ocupacaoChaves; j++)
            printf(" %d ", aux->noPai->vetFilho[i]->vetChaves[j]);
        printf("]");

    }
    printf("\n\n\n");

    int chavePai = aux->noPai->vetChaves[posNo];
    printf("Pai encontrado: %d\n", chavePai);

    irmaoDir->vetChaves[1] = irmaoDir->vetChaves[0];
    irmaoDir->vetChaves[0] = chavePai;
    irmaoDir->ocupacaoChaves++;

    // Shift nas chaves pai
    for(int index = posNo; index < aux->noPai->ocupacaoChaves-1; index++) 
        aux->noPai->vetChaves[index] = aux->noPai->vetChaves[index+1];
    
    // Shift nos filhos do pai
    for(int index = posNo; index < aux->noPai->ocupacaoFilhos-1; index++) 
        aux->noPai->vetFilho[index] = aux->noPai->vetFilho[index+1];
    
        // Transferir filhos de aux para irmaoDir, se não for folha
    if (!aux->folha) {
        for (int i = irmaoDir->ocupacaoFilhos - 1; i >= 0; i--) {
            irmaoDir->vetFilho[i + aux->ocupacaoFilhos] = irmaoDir->vetFilho[i];
        }

        for (int i = 0; i < aux->ocupacaoFilhos; i++) {
            irmaoDir->vetFilho[i] = aux->vetFilho[i];
            if (irmaoDir->vetFilho[i]) {
                irmaoDir->vetFilho[i]->noPai = irmaoDir;
            }
        }
        irmaoDir->ocupacaoFilhos += aux->ocupacaoFilhos;
    }
    
    aux->noPai->ocupacaoFilhos--;
    aux->noPai->ocupacaoChaves--;

    free(aux);
}

no234 *encontraPredecessor(no234 *origem, int posElemento, int *posicaoRel) {
    no234 *aux = origem->vetFilho[posElemento];
    *posicaoRel = posElemento;
    while(aux->ocupacaoFilhos > 0) {
        *posicaoRel = aux->ocupacaoFilhos-1;
        aux = aux->vetFilho[aux->ocupacaoFilhos-1];
    }
        
    return aux;
};

no234 *encontraSucessor(no234 *origem, int posElemento) {
    no234 *aux = origem->vetFilho[posElemento+1];

    while(aux->ocupacaoFilhos > 0)
        aux = aux->vetFilho[0];

    return aux;
};

void ajustarParaCima(no234 *no, arv234 *arv) {
    if (no == NULL) return;

    // Caso especial: é a raiz
    if (no->noPai == NULL) {
        if (no->ocupacaoChaves == 0) {
            if (no->ocupacaoFilhos == 1) {
                // Único filho vira nova raiz
                arv->raiz = no->vetFilho[0];
                arv->raiz->noPai = NULL;
                free(no);
            } else if (no->ocupacaoFilhos == 0) {
                // Árvore ficou vazia
                arv->raiz = NULL;
                free(no);
            }
        }
        return;
    }

    no234 *pai = no->noPai;
    int posNo = -1;

    // Encontrar a posição de no no pai
    for (int i = 0; i < pai->ocupacaoFilhos; i++) {
        if (pai->vetFilho[i] == no) {
            posNo = i;
            break;
        }
    }

    if (posNo == -1) {
        printf("Erro: filho não encontrado no pai!\n");
        return;
    }

    no234 *irmaoEsq = (posNo > 0) ? pai->vetFilho[posNo - 1] : NULL;
    no234 *irmaoDir = (posNo < pai->ocupacaoFilhos - 1) ? pai->vetFilho[posNo + 1] : NULL;

    if (irmaoEsq && irmaoEsq->ocupacaoChaves > MIN_CHAVES) {
        printf("Ajuste: emprestando da esquerda\n");
        borrowLeft(arv, no, irmaoEsq, 0, posNo);
    } else if (irmaoDir && irmaoDir->ocupacaoChaves > MIN_CHAVES) {
        printf("Ajuste: emprestando da direita\n");
        borrowRight(arv, no, irmaoDir, 0, posNo);
    } else if (irmaoEsq) {
        printf("Ajuste: merge com esquerda\n");
        mergeLeft(arv, no, irmaoEsq, 0, posNo);
        ajustarParaCima(pai, arv);
    } else if (irmaoDir) {
        printf("Ajuste: merge com direita\n");
        mergeRight(arv, no, irmaoDir, 0, posNo);
        ajustarParaCima(pai, arv);
    }
}

void removeChave(int valor, arv234 *arv) {
    // Faz uma busca para encontrar o nó em que o valor está.
    printf(">>>>>>>>>>>>> TENTANDO TIRAR %d <<<<<<<<<<<<<<<<<\n", valor);
    int pos, posNo;
    no234 *aux = buscaNo(valor, &pos, &posNo, arv);
    if(!aux) {
        printf("Chave não encontrada.\n");
        return;
    }
        
    if(aux->folha) {
        printf("Nó é folha\n");

        // Caso 1 (Folha) : Quantidade de chaves é maior que MIN_CHAVES
        if(aux->ocupacaoChaves > MIN_CHAVES) {
            printf("c e pos: %d\n", pos);
            // Faz o shift caso o elemento seja no meio do vetor
            for(int index = pos; index < aux->ocupacaoChaves-1; index++) {
                aux->vetChaves[index] = aux->vetChaves[index + 1];
            }
            
            // Atualiza o ultimo indice para INT_MIN
            aux->vetChaves[aux->ocupacaoChaves-1] = INT_MIN;
            aux->ocupacaoChaves--;
        }
        // Caso em que a raiz é o único nó e possui o mínimo de chaves, a árvore deixa de existir
        else if(aux->noPai == NULL) {
            arv->raiz->vetChaves[0] = INT_MIN;
            arv->raiz->ocupacaoChaves = 0;
            arv->raiz->ocupacaoFilhos = 0;
        }
        // Caso 2 (Folha) : Quantidade de chaves é menor ou igual a MIN_CHAVES
        else {
            no234 *irmaoEsq = ((posNo-1) >= 0 && aux->noPai->vetFilho[posNo-1] != NULL) ? aux->noPai->vetFilho[posNo-1] : NULL;
            no234 *irmaoDir = ((posNo+1) <= MAX_FILHOS-1 && aux->noPai->vetFilho[posNo+1] != NULL) ? aux->noPai->vetFilho[posNo+1] : NULL;
            
            // Se for possível, EMPRESTAR DA ESQ
            if(irmaoEsq && irmaoEsq->ocupacaoChaves > MIN_CHAVES) {
                printf("Emprestando do irmao da esquerda.\n");
                borrowLeft(arv, aux, irmaoEsq, pos, posNo);
            }
            // Se for possível, EMPRESTAR DA DIR
            else if(irmaoDir && irmaoDir->ocupacaoChaves > MIN_CHAVES) {
                printf("Emprestando do irmao da direita.\n");
                borrowRight(arv, aux, irmaoDir, pos, posNo);
            }
            // Se for possível, MERGE DA ESQ
            else if(irmaoEsq) {
                printf("Merging do irmao da esquerda.\n");
                mergeLeft(arv, aux, irmaoEsq, pos, posNo);
            }
            // Se NÃO, MERGE DA DIR
            else {
                printf("Merging do irmao da direita.\n");
                mergeRight(arv, aux, irmaoDir, pos, posNo);
            }
        }
        if (aux->noPai && aux->noPai->ocupacaoChaves < MIN_CHAVES)
            ajustarParaCima(aux->noPai, arv);
    }
    
    // Casos para quando o elemento está em um nó interno
    else {
        no234 *a = encontraPredecessor(aux, pos, &posNo);
        no234 *irmaoEsq = ((posNo-1) >= 0 && a->noPai->vetFilho[posNo-1] != NULL) ? a->noPai->vetFilho[posNo-1] : NULL;
        no234 *irmaoDir = ((posNo+1) <= MAX_FILHOS-1 && a->noPai->vetFilho[posNo+1] != NULL) ? a->noPai->vetFilho[posNo+1] : NULL;
        int valorPred = a->vetChaves[a->ocupacaoChaves-1];

        printf("O valor de pred %d para a chave é %d\n", valorPred, valor);
        
        //
        // Caso 1: Nó do predecessor tem mais do que MIN_KEYS
        if(a->ocupacaoChaves > MIN_CHAVES) {
            aux->vetChaves[pos] = valorPred;
            a->vetChaves[a->ocupacaoChaves-1] = INT_MIN;
            a->ocupacaoChaves--;
        } else {
            aux->vetChaves[pos] = valorPred;
            a->vetChaves[a->ocupacaoChaves-1] = INT_MIN;
            a->ocupacaoChaves--;

            pos = a->ocupacaoChaves-1;
            if(irmaoEsq && irmaoEsq->ocupacaoChaves > MIN_CHAVES) {
                printf("Emprestando do irmao da esquerda.\n");
                borrowLeft(arv, a, irmaoEsq, pos, posNo);
                //a->ocupacaoChaves++;

            }
            // Se for possível, EMPRESTAR DA DIR
            else if(irmaoDir && irmaoDir->ocupacaoChaves > MIN_CHAVES) {
                printf("Emprestando do irmao da direita.\n");
                printf("Posicao %d e posNo %d\n", pos, posNo);
                borrowRight(arv, a, irmaoDir, pos, posNo);
                //a->ocupacaoChaves++;
            }
            else {
                // Se for possível, MERGE DA ESQ
                if(irmaoEsq) {
                    printf("Merging do irmao da esquerda.\n");
                    mergeLeft(arv, a, irmaoEsq, pos, posNo);
                }
                // Se NÃO, MERGE DA DIR
                else {
                    printf("Merging do irmao da direita.\n");
                    mergeRight(arv, a, irmaoDir, pos, posNo);
                }

                if(aux->noPai && a->noPai->ocupacaoChaves < MIN_CHAVES)
                    ajustarParaCima(a->noPai, arv);
            }
        }

    }
}

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
        printf("Iniciando split\n");
        split(aux, arv);
    } 
}