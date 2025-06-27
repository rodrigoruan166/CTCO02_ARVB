/******************************************************************************
 * Arquivo: testeRubroNegra.h
 *
 * Descrição: Testes unitários para a árvore rubro-negra implementada
 *            em /algoritmos. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez da árvore rubro-negra.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 27/06/2025
 ******************************************************************************/

typedef void (*f)();

// https://www.youtube.com/watch?v=qA02XWRTBdw - CASO 1 - INSERÇÃO
void teste1();

// https://www.youtube.com/watch?v=UFrg_XKFZ7M - CASO 2 - INSERÇÃO
void teste2();

// https://cs.valdosta.edu/~dgibson/courses/cs3410/notes/ch19_5.pdf - CASO 3 - INSERÇÃO (Ex. 9)
void teste3();

// https://www.youtube.com/watch?v=w5cvkTXY0vQ 9:00 - CASO 4 - REMOÇÃO
void teste4();

// https://www.youtube.com/watch?v=w5cvkTXY0vQ 12:00 - CASO 5 - REMOÇÃO
void teste5();

// https://www.youtube.com/watch?v=w5cvkTXY0vQ 12:51 - CASO 6 - REMOÇÃO
void teste6();

// https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea 12:51 - CASO 7 - REMOÇÃO
void teste7();

// Z à esquerda do pai, Z preto, Y preto, Irmão preto e filho da esquerda é vermelho (3º caso irmão)
void teste8();

// Z à esquerda do pai, Z preto, Y preto, Irmão preto e filho da direita é vermelho (4º caso irmão)
void teste9();

// Z à esquerda do pai, Z preto, Y preto, Irmão preto e ambos filhos pretos (2º caso irmão)
void teste10();

// Z à direita do pai, Z preto, Y preto, Irmão vermelho (1º caso irmão - 2 tabela)
void teste11();

// Z à esquerda do pai, Z preto, Y preto, Irmão vermelho (1º caso irmão)
void teste12();

// Z à direita do pai, Z preto, Y preto, Irmão preto e filho da direita vermelho (2º caso irmão - 2 tabela)
void teste13();

// Z à direita do pai, Z preto, Y preto, Irmão preto e filho da esquerda vermelho (3º caso irmão - 2 tabela)
void teste14();

// Z à direita do pai, Z preto, Y preto, irmão e filhos do irmão pretos (2º caso irmão - 2 tabela)
void teste15();