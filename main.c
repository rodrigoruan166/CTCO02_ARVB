#include <stdio.h>
#include <stdlib.h>
#include "./algoritmos/Arvore234/Arvore234.h"
#include "./algoritmos/Conversor/Conversor.h"

int main() {
    arv234 *T2 = alocaArvore();
    //,31,10,15,33,32,41,6,3
    //11,25,23,2,4,5,6,7,8,9,10,13,14
    
    int ele[] = {10, 7, 20, 30};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], T2);

    printf("TEST\n");

    rb *arvRb = alocaArvoreRb();
    setRaizRb(arvRb, convert234ToRB(getRaiz(T2), arvRb));

    percorrePreOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorreEmOrdem(arvRb, getRaizRb(arvRb));
    printf("\n");
    percorrePosOrdem(arvRb, getRaizRb(arvRb));
    
    return 0;
}

//18;14;11;4;12;16;19;20;7