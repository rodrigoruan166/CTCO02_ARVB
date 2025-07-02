/******************************************************************************
 * Arquivo: RubroNegra.h
 *
 * Descrição: Interface da Árvore Rubro-Negra
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
 * Aloca e inicializa uma nova árvore Rubro-Negra com o nó sentinela (nil).
 * A raiz é inicializada como nil e a árvore é retornada pronta para uso.
 */
rb *alocaArvoreRb();

/**
 * Aloca e inicializa um novo nó com a chave fornecida.
 * O nó é inicialmente colorido como vermelho e seus filhos e pai apontam para nil.
 *
 * @param arv Ponteiro para a árvore rubro-negra à qual o nó pertencerá.
 * @param chave Valor inteiro a ser armazenado no novo nó.
 * @return Ponteiro para o novo nó alocado.
 */
noRB *alocaNoRb(rb *arv, int chave);

/**
 * Retorna o ponteiro para a raiz da árvore Rubro-Negra.
 *
 * @param arv Ponteiro para a árvore rubro-negra.
 * @return Ponteiro para o nó raiz.
 */
noRB *getRaizRb(rb *arv);

/**
 * Define a raiz da árvore Rubro-Negra.
 *
 * @param T Ponteiro para a árvore.
 * @param raiz Ponteiro para o novo nó raiz.
 */
void setRaizRb(rb *T, noRB *raiz);

/**
 * Retorna o ponteiro para o filho esquerdo do nó especificado.
 *
 * @param no Ponteiro para o nó.
 * @return Ponteiro para o filho esquerdo.
 */
noRB* getEsquerda(noRB* no);

/**
 * Retorna o ponteiro para o filho direito do nó especificado.
 *
 * @param no Ponteiro para o nó.
 * @return Ponteiro para o filho direito.
 */
noRB* getDireita(noRB* no);

/**
 * Define o ponteiro do filho direito do nó.
 *
 * @param no Ponteiro para o nó pai.
 * @param filho Ponteiro para o novo filho direito.
 */
void setDireita(noRB* no, noRB* filho);

/**
 * Define o ponteiro do filho esquerdo do nó.
 *
 * @param no Ponteiro para o nó pai.
 * @param filho Ponteiro para o novo filho esquerdo.
 */
void setEsquerda(noRB* no, noRB* filho);

/**
 * Define o ponteiro para o pai do nó.
 *
 * @param no Ponteiro para o nó filho.
 * @param pai Ponteiro para o novo pai.
 */
void setPai(noRB* no, noRB* pai);

/**
 * Retorna o ponteiro para o pai do nó.
 *
 * @param no Ponteiro para o nó.
 * @return Ponteiro para o pai do nó.
 */
noRB* getPai(noRB* no);

/**
 * Retorna a cor do nó ('P' para preto, 'V' para vermelho).
 *
 * @param no Ponteiro para o nó.
 * @return Caractere representando a cor.
 */
char getCor(noRB* no);

/**
 * Retorna a chave armazenada no nó.
 *
 * @param no Ponteiro para o nó.
 * @return Valor inteiro da chave.
 */
int getChave(noRB* no);

/**
 * Altera a cor do nó rubro-negro.
 *
 * @param no Ponteiro para o nó a ser alterado.
 * @param cor Nova cor ('P' ou 'V').
 * @return Ponteiro para o nó com a cor modificada.
 */
noRB *alterarCorNoRb(noRB *no, char cor);

/**
 * Retorna o ponteiro para o nó sentinela (nil) da árvore.
 *
 * @param arv Ponteiro para a árvore rubro-negra.
 * @return Ponteiro para o nó sentinela.
 */
noRB *retornaSentinelaRb(rb *arv);

/**
 * Insere o nó z na árvore Rubro-Negra T, mantendo as propriedades da árvore.
 * A função realiza a inserção binária seguida da chamada para RB_Insert_Fixup.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param z Ponteiro para o nó a ser inserido.
 */
void insereNo(rb *T, noRB *z);

/**
 * Corrige as propriedades da árvore Rubro-Negra após a inserção de um nó.
 * Utiliza rotações e recolorimentos para manter o balanceamento.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param z Ponteiro para o nó recém-inserido.
 */
void RB_Insert_Fixup(rb *T, noRB *z);

/**
 * Substitui o nó u pelo nó v na árvore T.
 * Essa função não altera os filhos de v.
 * Usada principalmente durante o processo de remoção.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param u Ponteiro para o nó a ser substituído.
 * @param v Ponteiro para o nó substituto.
 */
void RB_Transplant(rb *T, noRB *u, noRB *v);

/**
 * Retorna o nó com o menor valor da subárvore cuja raiz é x.
 * Usado na remoção para encontrar o sucessor.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param x Ponteiro para o nó raiz da subárvore.
 * @return Ponteiro para o nó com o menor valor.
 */
noRB *Tree_Minimum(rb *T, noRB *x);

/**
 * Realiza uma rotação à esquerda no nó x.
 * Reorganiza os ponteiros para manter a propriedade de balanceamento.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param x Ponteiro para o nó em torno do qual a rotação será feita.
 */
void left_rotate(rb *T, noRB *x);

/**
 * Realiza uma rotação à direita no nó y.
 * Reorganiza os ponteiros para manter a propriedade de balanceamento.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param y Ponteiro para o nó em torno do qual a rotação será feita.
 */
void right_rotate(rb *T, noRB *y);

/**
 * Percorre a árvore em pré-ordem a partir do nó aux, imprimindo suas chaves.
 * Formato: raiz, esquerda, direita.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param aux Ponteiro para o nó atual do percurso.
 */
void percorrePreOrdem(rb *T, noRB *aux);

/**
 * Percorre a árvore em ordem (inorder), imprimindo chave e cor dos nós.
 * Formato: esquerda, raiz, direita.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param aux Ponteiro para o nó atual do percurso.
 */
void percorreEmOrdem(rb *T, noRB *aux);

/**
 * Percorre a árvore em pós-ordem, imprimindo chave e cor dos nós.
 * Formato: esquerda, direita, raiz.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param aux Ponteiro para o nó atual do percurso.
 */
void percorrePosOrdem(rb *T, noRB *aux);

/**
 * Retorna a raiz da árvore Rubro-Negra.
 * Equivalente a getRaizRb.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @return Ponteiro para o nó raiz.
 */
noRB *retornaRaiz(rb *T);

/**
 * Remove da árvore o nó com a chave fornecida, se existir.
 * Realiza ajustes estruturais e de cores para manter as propriedades rubro-negras.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param chave Valor da chave a ser removida.
 * @return 1 se a remoção foi realizada com sucesso, 0 caso contrário.
 */
int removeNo(rb *T, int chave);

/**
 * Corrige a árvore Rubro-Negra após a remoção de um nó.
 * Restaura as propriedades de cor e balanceamento por meio de rotações e recolorimentos.
 *
 * @param T Ponteiro para a árvore rubro-negra.
 * @param x Ponteiro para o nó que substituiu o nó removido.
 */
void RB_Delete_Fixup(rb *T, noRB *x);
