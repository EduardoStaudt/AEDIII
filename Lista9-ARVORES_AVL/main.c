#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL* avl;
    int res,i;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();

    for(i=0;i<N;i++){
        //printf("========================\n");
        //printf("Inserindo: %d\n",dados[i]);
        res = insere_ArvAVL(avl,dados[i]);
        //printf("\n\nres = %d\n",res);
        //preOrdem_ArvAVL(avl);
        //printf("\n\n");
    }
//
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");
//
//    int NR = 4, dadosR[4] = {7,51,3,5};
//    for(i=0;i<NR;i++){
//        printf("\nRemovendo: %d\n",dadosR[i]);
//        res = remove_ArvAVL(avl,dadosR[i]);
//        printf("\n\nres = %d\n",res);
//        preOrdem_ArvAVL(avl);
//        //printf("\n\n");
//    }
//
//    printf("\nAVL tree:\n");
//    preOrdem_ArvAVL(avl);
//    printf("\n\n");

    remove_ArvAVL(avl,6);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,7);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    remove_ArvAVL(avl,4);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");

    // EX1 - examina cada arvore e diz se � AVL
    // 1a) arvore com 57(22(10(0,15),-),60(-,88))
    //     � AVL, todos os fatores sao <= 1
    // 1b) arvore com 57(22(10(0,15),-),60(58(-,59),88))
    //     nao � AVL, no 10 tem fator 2 (filho esq = 0, dir nao tem)
    // 1c) arvore com so o no 57
    //     � AVL, arvore com 1 no sempre � AVL
    // 1d) arvore com 8 como raiz e bem cheia
    //     nao � AVL, o no 12 tem subarvore direita muito mais alta que a esquerda

    // EX2 - monta as AVL passo a passo
    // 2a)
    // ArvAVL* a2a = cria_ArvAVL();
    // int da[15] = {50,30,20,70,40,35,37,38,10,32,45,42,25,47,36};
    // for(i=0;i<15;i++) insere_ArvAVL(a2a,da[i]);
    // printf("2a:\n"); emOrdem_ArvAVL(a2a);
    // libera_ArvAVL(a2a);

    // 2b)
    // ArvAVL* a2b = cria_ArvAVL();
    // int db[15] = {100,80,60,40,20,70,30,50,35,45,55,75,65,73,77};
    // for(i=0;i<15;i++) insere_ArvAVL(a2b,db[i]);
    // printf("2b:\n"); emOrdem_ArvAVL(a2b);
    // libera_ArvAVL(a2b);

    // 2c)
    // ArvAVL* a2c = cria_ArvAVL();
    // int dc[8] = {41,38,31,12,19,8,27,49};
    // for(i=0;i<8;i++) insere_ArvAVL(a2c,dc[i]);
    // printf("2c:\n"); emOrdem_ArvAVL(a2c);
    // libera_ArvAVL(a2c);

    // 2d)
    // ArvAVL* a2d = cria_ArvAVL();
    // int dd[7] = {10,21,15,17,16,19,20};
    // for(i=0;i<7;i++) insere_ArvAVL(a2d,dd[i]);
    // printf("2d:\n"); emOrdem_ArvAVL(a2d);
    // libera_ArvAVL(a2d);

    // EX3 - prova que o professor amongus ta errado
    // insere {1,2,3} numa ordem e {3,2,1} em outra
    // a estrutura final � a mesma (raiz 2) por causa do balanceamento
    // mas se for {1,3,2} vs {3,1,2} o caminho de rotacao � diferente
    // ArvAVL* t1 = cria_ArvAVL();
    // ArvAVL* t2 = cria_ArvAVL();
    // int o1[3] = {3,1,2};
    // int o2[3] = {1,3,2};
    // for(i=0;i<3;i++) insere_ArvAVL(t1,o1[i]);
    // for(i=0;i<3;i++) insere_ArvAVL(t2,o2[i]);
    // printf("ordem 1:\n"); emOrdem_ArvAVL(t1);
    // printf("ordem 2:\n"); emOrdem_ArvAVL(t2);
    // libera_ArvAVL(t1);
    // libera_ArvAVL(t2);

    // EX4 - rotacao simples a esquerda
    // ver funcao RotacaoRR em ArvoreAVL.c
    // ela ja � chamada toda vez que precisa balancear pra esquerda

    // EX5 - passo a passo do insere_ArvAVL(ArvAVL *raiz, int valor)
    // 1- se *raiz == NULL cria um no novo com altura 0 e retorna 1
    // 2- se o valor � menor que o no atual chama recursivo pra esquerda
    //    depois verifica se o fator de balanceamento ficou >= 2
    //    se ficou faz RotacaoLL ou RotacaoLR dependendo do caso
    // 3- se o valor � maior chama recursivo pra direita
    //    e faz RotacaoRR ou RotacaoRL se desbalanceou
    // 4- se for igual retorna 0 (valor duplicado)
    // 5- atualiza a altura do no atual com maior(esq,dir)+1
    // usa as funcoes: altura_NO, fatorBalanceamento_NO, maior e as 4 rotacoes

    // EX6 - passo a passo do remove_ArvAVL(ArvAVL *raiz, int valor)
    // 1- se *raiz == NULL o valor nao existe, retorna 0
    // 2- se valor < raiz->info chama recursivo na esquerda
    //    e se desbalanceou faz RotacaoRR ou RotacaoRL
    // 3- se valor > raiz->info chama recursivo na direita
    //    e se desbalanceou faz RotacaoLL ou RotacaoLR
    // 4- se for igual remove o no:
    //    - se tem 0 ou 1 filho, troca pelo filho que existe
    //    - se tem 2 filhos usa procuraMenor na subarvore direita
    //      copia o valor e remove o duplicado recursivo
    // 5- atualiza a altura no final
    // usa: procuraMenor, fatorBalanceamento_NO, altura_NO e as rotacoes

    // EX7 - verifica se a arvore � AVL
    // if(ehAVL_ArvAVL(avl))
    //     printf("eh AVL\n");
    // else
    //     printf("nao eh AVL\n");

    // EX8 - transforma uma BST qualquer em AVL
    ArvAVL* nova = transforma(avl);
    printf("arvore nova (AVL):\n");
    emOrdem_ArvAVL(nova);
    libera_ArvAVL(nova);

    libera_ArvAVL(avl);


    return 0;
}