#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    preOrdem_ArvBin(raiz);
    //emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

    if(remove_ArvBin(raiz,50)){
        printf("removido\n");
        preOrdem_ArvBin(raiz);
    }else
        printf("NAO removido\n");


//    printf("altura: %d\n",altura_ArvBin(raiz));
//    printf("total NOs: %d\n",totalNO_ArvBin(raiz));
//
//    if (consulta_ArvBin(raiz, 4))
//        printf("achou\n");

    // EX1
    printf("total de folhas: %d\n", totalFolhas_ArvBin(raiz));

    // EX2
    imprime_ArvBin(raiz, 0);

    // EX3
    printf("apareceu %d vezes\n", contaValor_ArvBin(raiz, 40));

    // EX4
    folhasDecrescente_ArvBin(raiz);

    // EX5
    ArvBin* raiz2 = cria_ArvBin();
    int dados2[8] = {50,100,30,20,40,45,35,37};
    for(i=0; i < 8; i++) insere_ArvBin(raiz2, dados2[i]);
    if(iguais_ArvBin(raiz, raiz2))
        printf("sao iguais\n");
    else
        printf("sao diferentes\n");
    libera_ArvBin(raiz2);

    // EX6
    removePares_ArvBin(raiz);
    preOrdem_ArvBin(raiz);

    // EX7
    ArvBin* raiz3 = cria_ArvBin();
    int dados3[8] = {10,200,5,1,8,9,7,6};
    for(i=0; i < 8; i++) insere_ArvBin(raiz3, dados3[i]);
    if(similares_ArvBin(raiz, raiz3))
        printf("sao similares\n");
    else
        printf("nao sao similares\n");
    libera_ArvBin(raiz3);

    // EX8
    ArvBin* raizChar = cria_ArvBin();
    char letras[] = {'M','F','S','D','J','P','U','A','E','H','Q','T','W','K'};
    int nLetras = 14;
    for(i=0; i < nLetras; i++)
        insere_ArvBinChar(raizChar, letras[i]);
    preOrdem_ArvBinChar(raizChar);
    libera_ArvBin(raizChar);

    // EX9
    struct NOExpr* n6   = novoNOExpr('6', NULL, NULL);
    struct NOExpr* n3   = novoNOExpr('3', NULL, NULL);
    struct NOExpr* n4   = novoNOExpr('4', NULL, NULL);
    struct NOExpr* n1   = novoNOExpr('1', NULL, NULL);
    struct NOExpr* n5   = novoNOExpr('5', NULL, NULL);
    struct NOExpr* sub1 = novoNOExpr('-', n6, n3);
    struct NOExpr* sub2 = novoNOExpr('+', n4, n1);
    struct NOExpr* mul  = novoNOExpr('*', sub1, sub2);
    struct NOExpr* raizExpr = novoNOExpr('+', mul, n5);
    printf("resultado: %d\n", calcula_NOExpr(raizExpr));
    printf("infixa: ");
    infixa_NOExpr(raizExpr);
    printf("\n");
    printf("prefixa: ");
    prefixa_NOExpr(raizExpr);
    printf("\n");
    printf("posfixa: ");
    posfixa_NOExpr(raizExpr);
    printf("\n");
    libera_NOExpr(raizExpr);

    libera_ArvBin(raiz);
    printf("\nGood Good kskss!\n");
    return 0;
}