#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./algoritmos/Arvore234/Arvore234.h"
#include "./algoritmos/RubroNegra/RubroNegra.h"
#include "./algoritmos/Conversor/Conversor.h"

int carregarArquivoEntrada(arv234 *arv, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    int valor;

    if (!arquivo) {
        perror("Erro ao abrir o arquivo.\n");
        return -1;
    }

    while (fscanf(arquivo, "%d", &valor) == 1) {
        insereChave(valor, arv);
    }

    fclose(arquivo);
    return 0;
}

void menuRubroNegra(rb *arvrb) {
    int opcao, valor;

    do {
        printf("\nÁrvores Balanceadas : Menu (Rubro-Negra)\n");
        printf("1. Inserir novo elemento na árvore rubro-negra\n");
        printf("2. Remover elemento da árvore rubro-negra\n");
        printf("3. Imprimir árvore rubro-negra\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                insereNo(arvrb, alocaNoRb(arvrb, valor));
                break;
            case 2:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                removeNo(arvrb, valor);
                break;
            case 3:
                printf("Árvore Rubro-Negra:\n");
                printf("Percorrimento em Pré-Ordem.\n");
                percorrePreOrdem(arvrb, getRaizRb(arvrb));
                printf("Percorrimento em Ordem.\n");
                percorreEmOrdem(arvrb, getRaizRb(arvrb));
                printf("Percorrimento em Pós-Ordem.\n");
                percorrePosOrdem(arvrb, getRaizRb(arvrb));
                break;
            case 4:
                printf("Retornando ao menu anterior...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 4);
}

void menuArvore234(arv234 *arv_234) {
    int opcao, valor;
    rb *arvRb = NULL;

    do {
        printf("\nÁrvores Balanceadas : Menu\n");
        printf("1. Inserir novo elemento na árvore 2-3-4\n");
        printf("2. Remover elemento da árvore 2-3-4\n");
        printf("3. Imprimir árvore 2-3-4\n");
        printf("4. Converter em uma árvore rubro-negra\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                insereChave(valor, arv_234);
                break;
            case 2:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                removeChave(valor, arv_234);
                break;
            case 3:
                printf("Árvore 2-3-4:\n");
                imprimirPorNivel(arv_234);
                break;
            case 4:
                arvRb = alocaArvoreRb();

                if (!arvRb) {
                    printf("Erro ao alocar árvore rubro-negra.\n");
                    return;
                }

                setRaizRb(arvRb, convert234ToRB(getRaiz(arv_234), arvRb));
                printf("Árvore Rubro-Negra gerada a partir da 2-3-4:\n");
                printf("Percorrimento em Pré-Ordem.\n");
                percorrePreOrdem(arvRb, getRaizRb(arvRb));
                printf("Percorrimento em Ordem.\n");
                percorreEmOrdem(arvRb, getRaizRb(arvRb));
                printf("Percorrimento em Pós-Ordem.\n");
                percorrePosOrdem(arvRb, getRaizRb(arvRb));
                menuRubroNegra(arvRb);
                break;
            case 5:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 5);
}

int main() {
    arv234 *arv = alocaArvore();

    if (!arv) {
        printf("Falha ao alocar árvore 2-3-4.\n");
        return -1;
    }

    char arquivo[500];

    printf("Digite o nome do arquivo: ");
    scanf(" %s", arquivo);

    if(carregarArquivoEntrada(arv, arquivo) != 0) {
        return -1;
    }

    printf("\nÁrvore 2-3-4 construída a partir do arquivo:\n");
    imprimirPorNivel(arv);
    
    menuArvore234(arv);

    return 0;
}