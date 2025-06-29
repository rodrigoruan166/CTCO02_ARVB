/******************************************************************************
 * Arquivo: RubroNegra.h
 *
 * Descrição: Interface da Árvore Rubro Negra
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 19/06/2025
 ******************************************************************************/

// Definição do tipo de nó da árvore Rubro-Negra
typedef struct NO noRB;

// Definição da estrutura da árvore Rubro-Negra
typedef struct RB rb;

/**
 * Aloca e inicializa uma nova árvore Rubro-Negra com o nó nil.
 */
rb *alocaArvoreRb();

/**
 * Aloca e inicializa um novo nó com a chave fornecida.
 * O nó é inicialmente colorido como vermelho.
 */
noRB *alocaNoRb(rb *arv, int chave);

noRB *getRaizRb(rb *arv);

void setRaizRb(rb *T, noRB *raiz);

// Retorna o ponteiro para o filho esquerdo do nó RB
noRB* getEsquerda(noRB* no);

// Retorna o ponteiro para o filho direito do nó RB
noRB* getDireita(noRB* no);

void setDireita(noRB* no, noRB* filho);

void setEsquerda(noRB* no, noRB* filho);

void setPai(noRB* no, noRB* pai);

noRB* getPai(noRB* no);

char getCor(noRB* no);

int getChave(noRB* no);

// Altera a cor do nó rubro negro
noRB *alterarCorNoRb(noRB *no, char cor);

// Retorna sentinela RB
noRB *retornaSentinelaRb(rb *arv);

/**
 * Insere o nó z na árvore Rubro-Negra T, mantendo suas propriedades.
 */
void insereNo(rb *T, noRB *z);

/**
 * Corrige as propriedades da árvore após a inserção de um nó.
 */
void RB_Insert_Fixup(rb *T, noRB *z);

/**
 * Substitui o nó u pelo nó v na árvore T.
 * Usado principalmente durante a remoção de nós.
 */
void RB_Transplant(rb *T, noRB *u, noRB *v);

/**
 * Retorna o nó com o menor valor na subárvore cuja raiz é x.
 */
noRB *Tree_Minimum(rb *T, noRB *x);

/**
 * Realiza uma rotação à esquerda no nó y.
 * Utilizado para reequilibrar a árvore.
 */
void left_rotate(rb *T, noRB *y);

/**
 * Realiza uma rotação à direita no nó x.
 * Utilizado para reequilibrar a árvore.
 */
void right_rotate(rb *T, noRB *x);

/**
 * Percorre a árvore em pré-ordem a partir do nó aux, imprimindo suas chaves.
 */
void percorrePreOrdem(rb *T, noRB *aux);

/**
 * Retorna a raiz da árvore Rubro-Negra T.
 */
noRB *retornaRaiz(rb *T);

/**
 * Remove o nó com a chave fornecida da árvore T.
 * Retorna 1 se a remoção for bem-sucedida, 0 caso contrário.
 */
int removeNo(rb *T, int chave);

/**
 * Corrige a árvore Rubro-Negra após a remoção de um nó.
 */
void RB_Delete_Fixup(rb *T, noRB *x);