/******************************************************************************
 * Arquivo: Arvore234.h
 *
 * Descrição: Interface da Árvore 2-3-4
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 19/06/2025
 ******************************************************************************/

typedef struct NO no234;
typedef struct arv arv234;

/*
Aloca uma árvore 2-3-4 (árvore-b de ordem 4)
*/
arv234 *alocaArvore();

/*
Aloca um novo nó seguindo a estrutura de requisitos de ordem 4
*/
no234 *alocaNo();
/*
Retira uma chave da árvore a partir do valor
 Fluxo: 
    1. Busca
    2. Encontra a posição
    3. Insere o elemento
    4. Rebalanceia se necessário
*/ 
void insereChave(int valor, arv234 *arv);
/*
Realiza um split em um nó com o número máximo de chaves.
Retorna o nó pai
*/ 
no234 *split(no234 *noCheio, arv234 *arv);
/*
Retira uma chave da árvore a partir do valor
 Fluxo: 
    1. Busca
    2. Encontra o valor
    3. Retira o elemento
    4. Rebalanceia se necessário
*/ 
void removeChave(int valor, arv234 *arv);
/*
Pega "emprestado" do irmão (imediatamente a esquerda ou imediatamente a direita dele), 
caso seja possível, para rebalancear o nó 
*/
void borrow(no234 *noDesbalanceado, no234 *irmao);
/*
Executa a rotina de merge para rebalancear o nó
*/
void merge(no234 *noDesbalanceado, no234 *irmao);
/*
Encontra o valor do predecessor para um dado nó origem
*/
no234 *encontraPredecessor(no234 *origem, int posElemento, int *posicaoRel);
/*
Encontra o valor do sucessor para um dado nó origem
*/
no234 *encontraSucessor(no234 *origem, int posElemento);

/*Percorre a árvore*/
void imprimeArvore(arv234 *arv);

void preOrdemRec(no234 *no);

int *getChaves(no234 *no);

no234 *getRaiz(arv234 *arv);

no234 **getFilhos(no234 *no);

int getOcupacaoChaves(no234 *no);

int getOcupacaoFilhos(no234 *no);

void preOrdem(arv234 *arv);

void imprimirChavesNo(no234 *no, int d);

void imprimirPorNivel(arv234 *arv);

void borrowLeft(arv234 *arv, no234 *aux, no234* irmaoEsq, int pos, int posNo);

void borrowRight(arv234 *arv, no234 *aux, no234* irmaoDir, int pos, int posNo);

void mergeLeft(arv234 *arv, no234 *aux, no234* irmaoEsq, int pos, int posNo);

void mergeRight(arv234 *arv, no234 *aux, no234* irmaoDir, int pos, int posNo);

void ajustarParaCima(no234 *no, arv234 *arv);

int getTotalSplit(arv234 *a);

int getTotalBorrow(arv234 *a);

int getTotalMerge(arv234 *a);

no234 *buscaNo(int valor, int *pos, int *posNo, arv234 *arv);
