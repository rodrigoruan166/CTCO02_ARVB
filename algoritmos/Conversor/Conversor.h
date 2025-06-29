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

noRB* criaNoRB(int chave, char cor, rb *arvore);

noRB* convert234ToRB(no234 *node, rb *arvore);