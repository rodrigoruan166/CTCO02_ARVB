/******************************************************************************
 * Arquivo: Conversor.h
 *
 * Descrição: Interface da conversão entre as árvores 2-3-4 e Rubro-Negra
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 19/06/2025
 ******************************************************************************/

#include "../Arvore234/Arvore234.h"
#include "../RubroNegra/RubroNegra.h"

/**
 * Wrapper para criar um novo nó para uma árvore Rubro-Negra com a chave e cor especificadas.
 * O nó é alocado e inicializado com os valores fornecidos.
 *
 * @param chave Valor inteiro a ser armazenado no novo nó.
 * @param cor Cor do nó (P ou V).
 * @param arvore Ponteiro para a árvore rubro-negra à qual o nó pertencerá.
 * @return Ponteiro para o novo nó alocado.
 */
noRB* criaNoRB(int chave, char cor, rb *arvore);

/**
 * Converte uma árvore 2-3-4 em uma árvore Rubro-Negra.
 * Realiza a conversão recursiva de um nó e seus filhos.
 *
 * @param node Ponteiro para o nó raiz da árvore 2-3-4 a ser convertida.
 * @param arvore Ponteiro para a árvore Rubro-Negra de destino.
 * @return Ponteiro para a raiz da árvore Rubro-Negra convertida.
 */
noRB* convert234ToRB(no234 *node, rb *arvore);