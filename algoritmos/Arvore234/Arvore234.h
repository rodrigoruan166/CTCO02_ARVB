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

int getAlturaArv(arv234 *arv);

/*
Encontra o valor do sucessor para um dado nó origem
*/
no234 *encontraSucessor(no234 *origem, int posElemento);

/*Percorre a árvore*/
void imprimeArvore(arv234 *arv);

/*Retorna o vetor de chaves para um dado nó*/
int *getChaves(no234 *no);

/*Retorna a raiz*/
no234 *getRaiz(arv234 *arv);

/*Retorna o vetor de filhos para um dado nó*/
no234 **getFilhos(no234 *no);

/*Retorna número de chaves para um dado nó*/
int getOcupacaoChaves(no234 *no);

/*Retorna número de filhos para um dado nó*/
int getOcupacaoFilhos(no234 *no);

/*Retorna número chaves inseridos na árvore*/
int getTotalChaves(arv234 *arv);

void imprimirChavesNo(no234 *no, int d);

void imprimirPorNivel(arv234 *arv);

/*Empresta do irmão da esquerda para o nó desbalanceado*/
void borrowLeft(arv234 *arv, no234 *aux, no234* irmaoEsq, int pos, int posNo);

/*Empresta do irmão da direita para o nó desbalanceado*/
void borrowRight(arv234 *arv, no234 *aux, no234* irmaoDir, int pos, int posNo);

/*Realiza o merge do irmão da esquerda para o nó desbalanceado*/
void mergeLeft(arv234 *arv, no234 *aux, no234* irmaoEsq, int pos, int posNo);

/*Realiza o merge do irmão da direita para o nó desbalanceado*/
void mergeRight(arv234 *arv, no234 *aux, no234* irmaoDir, int pos, int posNo);

/*Verifica o pai do nó que estava desbalanceado para balancear recursivamente*/
void ajustarParaCima(no234 *no, arv234 *arv);

/*Retorna o total de splits realizados naquela árvore*/
int getTotalSplit(arv234 *a);

/*Retorna o total de operações borrow realizados naquela árvore*/
int getTotalBorrow(arv234 *a);

/*Retorna o total de merges realizados naquela árvore*/
int getTotalMerge(arv234 *a);

/*Retorna o total de blocos naquela árvore*/
int getTotalBlocos(arv234 *a);

/*Retorna a altura e atualiza na estrutura da árvore*/
int atualizaAltura(arv234 *a);

/*Retorna a altura e atualiza na estrutura da árvore*/
int atualizaQuantBlocos(arv234 *arv, no234 *no);

/*Libera nós recursivamente*/
void liberaNos234(no234 *no);

/*Retorna o nó que contém o valor do argumento. Atualiza pos como a posição do 
  elemento no nó e posNo com a posição relativa em relação ao seu pai */
no234 *buscaNo(int valor, int *pos, int *posNo, arv234 *arv);
