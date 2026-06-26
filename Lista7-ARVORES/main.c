#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    // EX1
    // preOrdem_ArvBin(raiz);
    // if(remove_ArvBin(raiz,40))
    //     printf("removido\n");
    // else
    //     printf("NAO removido\n");

    // EX2 
    // printf("Pre-ordem:\n");
    // preOrdem_ArvBin(raiz);
    // printf("Em-ordem:\n");
    // emOrdem_ArvBin(raiz);
    // printf("Pos-ordem:\n");
    // posOrdem_ArvBin(raiz);

    // EX3
    // printf("Total de nos: %d\n", totalNO_ArvBin(raiz));

    // EX4
    // if(consulta_ArvBin(raiz, 45))
    //     printf("Achou o 45\n");
    // else
    //     printf("Nao achou o 45\n");

    // EX5
    preOrdem_ArvBin(raiz);
    if(remove_ArvBin(raiz,50)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");

    libera_ArvBin(raiz);
    printf("\nFim!\n");
    return 0;
}
