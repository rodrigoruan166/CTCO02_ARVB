/******************************************************************************
 * Arquivo: utils.h
 *
 * Descrição: Biblioteca utilitária para geração de dados e operações de apoio
 *            ao sistema de benchmarking das árvores. Contém
 *            funções para criação de conjuntos de dados e auxiliares de arquivo.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 19/06/2025
 ******************************************************************************/

/* Aloca um vetor de tamanho @tam */
int *alocaVetor(int tam);

/*O sistema deve gerar conjuntos de dados ordenados de forma crescente e
decrescente. Para tanto, deve haver uma função com a assinatura abaixo, onde
tam é a quantidade de elementos e ordem define o tipo de ordenação: 0 para
ordem crescente e 1 para ordem decrescente. A função retorna o vetor
previamente preenchido.*/
int *geraOrdenados(int tam, int ordem);

/*O sistema deve gerar conjuntos de dados quase ordenados, que contém cerca
de 10% dos dados desordenados 90% ordenados. Para tanto, deve haver uma
função com a assinatura abaixo, onde tam é a quantidade de elementos que
deve ser gerada e a porcentagem é o inteiro que determina a porcentagem de
dados desordenados. A função retorna o vetor previamente preenchido.*/
int *geraQuaseOrdenados(int tam, int porcentagem);

/*O sistema deve gerar conjuntos de dados aleatórios de diferentes tamanhos.
Para tanto, deve haver uma função com a assinatura abaixo, onde tam é a
quantidade de elementos que deve ser gerada e a semente é o inteiro que
permite que esse conjunto de dados seja reproduzido posteriormente. A função
retorna o vetor previamente preenchido.*/
int *geraAleatorios(int tam, int semente);

/* Cria o arquivo de resultado final.
    Vamos usar para fazer os gráficos e a apresentação
    Deve conter:
    quantidade split
    altura arvore
    total blocos
    ...
    ..
    .
    etc
*/
void escreveArquivo(char *nomeArquivo, char *operacao, int quantidade_rotacoes, int quantidade_split, int altura_arvore, int total_blocos);

int *geraVetorPorOpcao(int op, int qtyElementos);