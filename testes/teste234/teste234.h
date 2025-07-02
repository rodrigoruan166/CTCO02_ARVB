/******************************************************************************
 * Arquivo: teste234.h
 *
 * Descrição: Testes unitários para a árvore 2-3-4 implementada
 *            em /algoritmos. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez da árvore 2-3-4.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 28/06/2025
 ******************************************************************************/

typedef void (*f)();

void teste1(); // Inserção sequencial simples (10 a 100)

void teste2(); // Inserção com ordem aleatória e mistura

void teste3(); // Remoção do menor elemento (1) após inserção ordenada

void teste4(); // Remoção de valor médio (2) com 3 nós

void teste5(); // Remoção da menor chave (1) em árvore pequena

void teste6(); // Remoção da maior chave (3) em árvore pequena

void teste7(); // Remoção do menor em árvore com 4 nós

void teste8();  // Inserção simples e remoção do menor (10)

void teste9();  // Remoção de duas maiores chaves

void teste10(); // Remoção de extremos (menor e maior)

void teste11(); // Remoções alternadas em árvore maior

void teste12(); // Inserção de apenas 2 valores

void teste13(); // Inserção de 4 valores seguidos

void teste14(); // Inserção de 6 valores

void teste15(); // Inserção de 10 valores

void teste16(); // Remoção do valor central (20) com 3 nós

void teste17(); // Remoção após exibição do estado da árvore

void teste18(); // Remoção das duas maiores

void teste19(); // Remoção alternada entre meio e fim

void teste20(); // Remoção de todos os elementos

void teste21(); // Remoção de múltiplos valores sequenciais

void teste22(); // Remoções intercaladas com impressões entre elas

void teste23(); // Remoção de valores intermediários após inserção aleatória

void teste24(); // Remoção com reestruturação interna

void teste25(); // Inserção e múltiplas remoções seguidas de nova inserção e novas remoções

void teste26(); // Inserção de 100 elementos aleatórios e geração de métricas

void teste27(); // Inserção de 1.000 elementos aleatórios e geração de métricas

void teste28(); // Inserção de 10.000 elementos aleatórios e geração de métricas

void teste29(); // Inserção de 100.000 elementos aleatórios e geração de métricas

void teste30(); // Remoção de 10% após inserção de 10.000 chaves

void teste31(); // Remoção de 20% após inserção de 10.000 chaves

void teste32(); // Remoção de 35% após inserção de 10.000 chaves

void teste33(); // Remoção de 50% após inserção de 10.000 chaves

