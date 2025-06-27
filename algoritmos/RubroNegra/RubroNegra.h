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

typedef struct NO noRB;

typedef struct RB rb;

rb *alocaArvore();

noRB *alocaNo(rb *arv, int chave);

void insereNo(rb *T, noRB *z);

void RB_Insert_Fixup(rb *T, noRB *z);

void RB_Transplant(rb *T, noRB *u, noRB *v);

noRB *Tree_Minimum(rb *T, noRB *x);

void left_rotate(rb *T, noRB *y);

void right_rotate(rb *T, noRB *x);

void percorrePreOrdem(rb *T, noRB *aux);

noRB *retornaRaiz(rb *T);

int removeNo(rb *T, int chave);

void RB_Delete_Fixup(rb *T, noRB *x);