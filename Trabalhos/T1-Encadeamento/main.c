#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main() {
// 1 - ALOCA A MATRIZ
    printf("+++ Alocando a matriz +++\n");
    Matriz *m = alocar_matriz(5, 5);
    if (m == NULL) {
        printf("Erro ao alocar matriz!\n");
        return 1;
    }
    printf("Matriz alocada com %d linhas e %d colunas.\n\n", m->linhas, m->colunas);


// 2 - INSERINDO VALORES
    printf("+++ Inserindo valores +++\n");
    inserir_valor(m, 0, 0, 10);
    inserir_valor(m, 0, 1, 20);
    inserir_valor(m, 1, 1, 50);
    inserir_valor(m, 1, 2, 70);
    inserir_valor(m, 2, 3, 99);
    inserir_valor(m, 2, 0, -5);
    inserir_valor(m, 4, 4, 1000);

    int valor_buscado = 1000;
    Elem *busca1 = buscar_valor(m, valor_buscado);
    if (busca1 != NULL)
        printf("Valor %d encontrado em (%d,%d).\n", valor_buscado, busca1->x, busca1->y);
    else
        printf("Valor %d nao encontrado\n", valor_buscado);

    valor_buscado = 2000;
    Elem *busca2 = buscar_valor(m, valor_buscado);
    if (busca2 != NULL)
        printf("Valor %d encontrado em (%d,%d).\n", valor_buscado, busca2->x, busca2->y);
    else
        printf("Valor %d nao encontrado\n", valor_buscado);

// 3 - IMPRIMINDO TUDO - EXTRA
    printf("+++ Matriz atual +++\n");
    imprimir_matriz(m);
    printf("\n");

// 4 - PROCURANDO POSI��ES
    printf("+++ Consultando posicoes +++\n");
    Elem *no;
    int linha = 1;
    int coluna = 1;

    no = consultar_valor(m, linha, coluna);
    if (no != NULL)
        printf("Valor em (%d,%d) = %d\n", linha, coluna, no->valor);
    else
        printf("Valor em (%d,%d) = NULL\n", linha, coluna);

    linha = 2;
    coluna = 3;

    no = consultar_valor(m, linha, coluna);
    if (no != NULL)
        printf("Valor em (%d,%d) = %d\n", linha, coluna, no->valor);
    else
        printf("Valor em (%d,%d) = NULL\n", linha, coluna);

    linha = 9;
    coluna = 9;

    no = consultar_valor(m, linha, coluna);
    if (no != NULL)
        printf("Valor em (%d,%d) = %d\n", linha, coluna, no->valor);
    else
        printf("Valor em (%d,%d) = NULL\n", linha, coluna);

    printf("\n");


// 5 - BUSCA NA MATRIZ
    printf("+++ Buscando valores +++\n");

    Elem *busca;

    valor_buscado = 70;
    busca = buscar_valor(m, valor_buscado);
    if (busca != NULL)
        printf("Valor %d encontrado em (%d,%d).\n", valor_buscado, busca->x, busca->y);
    else
        printf("Valor %d nao encontrado = NULL\n", valor_buscado);

    valor_buscado = -5;
    busca = buscar_valor(m, valor_buscado);
    if (busca != NULL)
        printf("Valor %d encontrado em (%d,%d).\n", valor_buscado, busca->x, busca->y);
    else
        printf("Valor %d nao encontrado = NULL\n", valor_buscado);

    valor_buscado = 1000;
    busca = buscar_valor(m, valor_buscado);
    if (busca != NULL)
        printf("Valor %d encontrado em (%d,%d).\n", valor_buscado, busca->x, busca->y);
    else
        printf("Valor %d nao encontrado = NULL\n", valor_buscado);

    printf("\n");


// 6 - IMPRIME OS 4 VIZINHOS DE ALGUNS N�S
    printf("+++ Vizinhos de cada noh +++\n");

    imprimir_vizinhos(m, 1, 1);
    printf("\n");

    imprimir_vizinhos(m, 0, 0);
    printf("\n");

    imprimir_vizinhos(m, 2, 3);
    printf("\n");

// 7 - SE DESLOCANDO NA MATRIZ - EXTRA
    printf("+++ Testando movimentacao pelos ponteiros +++\n");

    Elem *atual = consultar_valor(m, 0, 0);

    int opcao;

do {
    printf("\n+++ POSICAO ATUAL +++\n");
    printf("Estou na posicao (%d,%d), valor = %d\n", atual->x, atual->y, atual->valor);

    printf("\n+++ MENU DE MOVIMENTO +++\n");
    printf("1 - Descer\n");
    printf("2 - Subir\n");
    printf("3 - Ir para direita\n");
    printf("4 - Ir para esquerda\n");
    printf("5 - Imprimir matriz\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (deslocar(&atual, opcao) == 0)
                printf("Desceu para a posicao (%d,%d), valor = %d\n", atual->x, atual->y, atual->valor);
            else
                printf("Nao foi possivel descer. Retornou NULL.\n");
            break;
        case 2:
            if (deslocar(&atual, opcao) == 0)
                printf("Subiu para a posicao (%d,%d), valor = %d\n", atual->x, atual->y, atual->valor);
            else
                printf("Nao foi possivel subir. Retornou NULL.\n");
            break;
        case 3:
            if (deslocar(&atual, opcao) == 0)
                printf("Foi para direita na posicao (%d,%d), valor = %d\n", atual->x, atual->y, atual->valor);
            else
                printf("Nao foi possivel ir para direita. Retornou NULL.\n");
            break;
        case 4:
            if (deslocar(&atual, opcao) == 0)
                printf("Foi para esquerda na posicao (%d,%d), valor = %d\n", atual->x, atual->y, atual->valor);
            else
                printf("Nao foi possivel ir para esquerda. Retornou NULL.\n");
            break;
        case 5:
            printf("\n+++ MATRIZ ATUAL +++\n");
            imprimir_matriz(m);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

} while (opcao != 0);

// 8 - DESLOCA A MATRIZ
    printf("+++ Desalocando matriz +++\n");
    int r = desalocar_matriz(m);
    if (r == 0)
        printf("Matriz desalocada com sucessso.\n");
    else
        printf("Erro ao desalocar.\n");

    return 0;
}