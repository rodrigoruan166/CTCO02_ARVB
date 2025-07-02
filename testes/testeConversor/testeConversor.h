/******************************************************************************
 * Arquivo: testeConversor.h
 *
 * Descrição: Testes unitários para a conversão implementada
 *            em /algoritmos. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez da conversão.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 29/06/2025
 ******************************************************************************/

typedef void (*f)();

// Testes de conversão 2-3-4 em Rubro-Negra com padrões variados

void teste1();  // Conversão com mistura de inserções à esquerda e à direita, testando chaves internas e externas

void teste2();  // Conversão com inserção sequencial (10 a 100), testa balanceamento e cor após muitos splits

void teste3();  // Inserção complexa e balanceada, com muitos splits e múltiplos níveis

void teste4();  // Inserção de 4 chaves que forçam criação de um nó 3 e depois 4: testa divisão simples

void teste5();  // Inserções que formam subárvores profundas e forçam conversões com nós internos complexos

void teste6();  // Inserções com padrão binário clássico (como uma árvore AVL simples) - testa estrutura simétrica

void teste7();  // Cenário típico de livro (ex: CLRS) para formar árvore rubro-negra de altura razoável

void teste8();  // Inserção em ordem quase reversa, força balanceamento pela esquerda

void teste9();  // Inserções com dispersão de chaves e simulações de nós 4 distribuídos entre vários níveis

void teste10(); // Inserções em ordem reversa, formando uma árvore degenerada e testando conversão em profundidade

void teste11(); // Inserção de chaves com muitos valores intermediários: testa conversão com vários filhos por nó

void teste12(); // Conversão com remoções planejadas no teste da 2-3-4 original, seguida de conversão e ordenações
