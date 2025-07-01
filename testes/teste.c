#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../algoritmos/Arvore234/Arvore234.h"
#include "./teste234/teste234.h"
#include "../utils/utils.h"

char arquivo[] = "./dataset/resultados/resultados.csv";

int main() {
    int qtyValores, percentage_removal, op;

    printf("Deseja inserir valores em ordem crescente (1), decrescente (2) ou aleatórios (3): ");
    scanf("%d", &op);

    if (op < 1 || op > 3) {
        printf("Opção inválida.\n");
        return -1;
    }

    printf("Digite a quantidade de valores que deseja inserir na árvore 2-3-4: ");
    scanf("%d", &qtyValores);

    if (qtyValores < 0) {
        printf("Quantidade de valores inválida.\n");
        return -1;
    }

    printf("Digite a porcentagem de valores que deseja remover: ");
    scanf("%d", &percentage_removal);

    if (percentage_removal < 0 || percentage_removal > 100) {
        printf("Porcentagem de remoção inválida.\n");
        return -1;
    }

    arv234 *arv = alocaArvore();

    if (!arv) {
        printf("Erro ao alocar estrutura da árvore.\n");
        return -2;
    }

    int *chaves = geraVetorPorOpcao(op, qtyValores);
    if (!chaves) {
        printf("Erro ao alocar vetor de dados.\n");
        return -1;
    }

    printf("\nInserindo %d valores na árvore...\n", qtyValores);
    for (int i = 0; i < qtyValores; i++) {
        insereChave(chaves[i], arv);
    }
    printf("Inserção concluída.\n");

    int t_percent = qtyValores * percentage_removal / 100;

    printf("Removendo %d valores da árvore...\n", t_percent);
    for (int i = 0; i < t_percent; i++) {
        removeChave(chaves[i], arv);
    }
    printf("Remoção concluída.\n");

    char tipoOperacao[100];
    char tipoInsercao[20];

    // Definindo tipo de inserção com base na opção escolhida
    switch (op) {
        case 1: strcpy(tipoInsercao, "crescente"); break;
        case 2: strcpy(tipoInsercao, "decrescente"); break;
        case 3: strcpy(tipoInsercao, "aleatorio"); break;
        default: strcpy(tipoInsercao, "desconhecido"); break;
    }

    // Ajustando o nome da operação para refletir a inserção e a quantidade
    if (t_percent == 0) {
        snprintf(tipoOperacao, sizeof(tipoOperacao), "insercao_%s_%d", tipoInsercao, qtyValores);
    } else {
        snprintf(tipoOperacao, sizeof(tipoOperacao), "remocao_%s_%d", tipoInsercao, percentage_removal);
    }

    atualizaAltura(arv);
    atualizaQuantBlocos(arv, getRaiz(arv));

    escreveArquivo(
        arquivo,
        tipoOperacao,
        getTotalBorrow(arv),
        getTotalSplit(arv),
        getAlturaArv(arv),
        getTotalBlocos(arv)
    );

    printf("\nÁrvore final (por nível):\n");
    imprimirPorNivel(arv);

    free(chaves);

    return 0;
}
