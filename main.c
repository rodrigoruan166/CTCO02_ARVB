#include <stdio.h>
#include <stdlib.h>
#include "./algoritmos/Arvore234/Arvore234.h"

int main() {
    arv234 *T2 = alocaArvore();
    //,31,10,15,33,32,41,6,3
    //11,25,23,2,4,5,6,7,8,9,10,13,14
    
    int ele[] = {11,25,23,2,35,37, 39, 40, 41, 42};
    int tam = sizeof(ele) / sizeof(int);
    printf("%d", tam);
    for(int i = 0; i < tam; i++)
        insereChave(ele[i], T2);

    imprimirPorNivel(T2);
    return 0;
}
