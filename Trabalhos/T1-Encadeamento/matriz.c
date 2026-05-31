#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

// PRA CRIAR A MATRIZ E FAZER TODAS AS ALOCACOES
Matriz* alocar_matriz(int linhas, int colunas) {
    if (linhas <= 0 || colunas <= 0) return NULL;

    // Aloca a estrutura principal da matriz
    Matriz *m = (Matriz*) malloc(sizeof(Matriz));
    if (m == NULL) return NULL;

    m->linhas = linhas;
    m->colunas = colunas;
    m->inicio = NULL;

    Elem *linha_ant = NULL; // Ponteiro para o primeiro elemento da linha anterior

    for (int i = 0; i < linhas; i++) {
        Elem *primeiro = NULL; // Primeiro elemento da linha atual
        Elem *ant = NULL; // Elemento anterior na mesma linha
        Elem *acima = linha_ant; // Elemento acima na linha anterior

        for (int j = 0; j < colunas; j++) {
            Elem *no = (Elem*) malloc(sizeof(Elem));
            if (no == NULL) {
                // --- FALHA DE ALOCA��O: LIBERA TUDO QUE J� FOI ALOCADO ---
                // Libera os n�s da linha atual (j� alocados at� agora)
                Elem *atual = primeiro;
                while (atual != NULL) {
                    Elem *prox = atual->dir;
                    free(atual);
                    atual = prox;
                }
                // Libera todas as linhas completas que foram alocadas anteriormente
                Elem *linha = m->inicio;
                while (linha != NULL) {
                    Elem *prox_linha = linha->baixo;
                    Elem *elem = linha;
                    while (elem != NULL) {
                        Elem *prox_elem = elem->dir;
                        free(elem);
                        elem = prox_elem;
                    }
                    linha = prox_linha;
                }
                // Libera a estrutura Matriz
                free(m);
                return NULL;
            }

            // Inicializa o n�
            no->x = i;
            no->y = j;
            no->valor = 0;
            no->cima = NULL;
            no->baixo = NULL;
            no->esq = NULL;
            no->dir = NULL;

            // Liga��es horizontais (esquerda/direita)
            if (ant != NULL) {
                ant->dir = no;
                no->esq = ant;
            }

            // Liga��es verticais (cima/baixo)
            if (acima != NULL) {
                acima->baixo = no;
                no->cima = acima;
                acima = acima->dir; // Move o ponteiro "acima" para o pr�ximo da linha de cima
            }

            if (j == 0) primeiro = no; // Guarda o primeiro da linha
            ant = no; // Atualiza o anterior para o pr�ximo n�
        }

        // Ao final da linha, guarda o primeiro elemento desta linha para a pr�xima itera��o
        if (i == 0) m->inicio = primeiro;
        linha_ant = primeiro;
    }

    return m;
}

// PARA DESALOCAR TODA A MATRIZ
int desalocar_matriz(Matriz *m) {

    if (m == NULL) return 1;
    Elem *linha = m->inicio;
    while (linha != NULL) {
        Elem *prox_linha = linha->baixo;
        Elem *atual = linha;
        while (atual != NULL) {
            Elem *no = atual;
            atual = atual->dir;
            free(no);
        }
        linha = prox_linha;
    }
    free(m);
    return 0;
}

// PARA INSERIR ALGUM VALOR
int inserir_valor(Matriz *m, int x, int y, int valor) {
    if (m == NULL) return 1;
    if (x < 0 || x >= m->linhas) return 1;
    if (y < 0 || y >= m->colunas) return 1;
    Elem *atual = m->inicio;
    for (int i = 0; i < x; i++) {
        atual = atual->baixo;
    }
    for (int j = 0; j < y; j++) {
        atual = atual->dir;
    }
    atual->valor = valor;
    return 0;
}

// PARA BUSCAR UM VALOR EM ALGUMA POSICAO
Elem* consultar_valor(Matriz *m, int x, int y) {
    if (m == NULL) return NULL;
    if (x < 0 || x >= m->linhas) return NULL;
    if (y < 0 || y >= m->colunas) return NULL;
    Elem *atual = m->inicio;
    for (int i = 0; i < x; i++) {
        atual = atual->baixo;
    }
    for (int j = 0; j < y; j++) {
        atual = atual->dir;
    }
    return atual;
}

// PARA BUSCAR UM VALOR ESPECIFICO
Elem* buscar_valor(Matriz *m, int valor) {
    if (m == NULL) return NULL;
    Elem *linha = m->inicio;
    while (linha != NULL) {
        Elem *atual = linha;
        while (atual != NULL) {
            if (atual->valor == valor) {
                return atual;
            }
            atual = atual->dir;
        }
        linha = linha->baixo;
    }
    return NULL;
}

// PARA IMPRIMIR OS VIZINHOS
int imprimir_vizinhos(Matriz *m, int x, int y) {
    Elem *no = consultar_valor(m, x, y);
    if (no == NULL) return 1;
    printf("Vizinhos do noh (%d,%d) com valor %d:\n", no->x, no->y, no->valor);
    // CIMA
    if (no->cima != NULL)
        printf("  Cima:     %d\n", no->cima->valor);
    else
        printf("  Cima:     NULL\n");
    // BAIXO
    if (no->baixo != NULL)
        printf("  Baixo:    %d\n", no->baixo->valor);
    else
        printf("  Baixo:    NULL\n");
    // ESQUERDA
    if (no->esq != NULL)
        printf("  Esquerda: %d\n", no->esq->valor);
    else
        printf("  Esquerda: NULL\n");
    // DIREITA
    if (no->dir != NULL)
        printf("  Direita:  %d\n", no->dir->valor);
    else
        printf("  Direita:  NULL\n");
    return 0;
}

// PARA SE DESLOCAR ENTRE OS PONTEIROS- EXTRA
int deslocar(Elem **atual, int opcao) {
    if (atual == NULL || *atual == NULL) return 1;
    Elem *proximo = NULL;
    if (opcao == 1) {
        proximo = (*atual)->baixo;
    }
    else if (opcao == 2) {
        proximo = (*atual)->cima;
    }
    else if (opcao == 3) {
        proximo = (*atual)->dir;
    }
    else if (opcao == 4) {
        proximo = (*atual)->esq;
    }
    else {
        return 1;
    }
    if (proximo == NULL) {
        return 1;
    }
    *atual = proximo;
    return 0;
}

// PARA IMPRIMIR A MATRIZ INTEIRA- EXTRA
int imprimir_matriz(Matriz *m) { 
    if (m == NULL) return 1;
    Elem *linha = m->inicio;
    while (linha != NULL) {
        Elem *atual = linha;
        while (atual != NULL) {
            printf("%5d ", atual->valor);
            atual = atual->dir;
        }
        printf("\n");
        linha = linha->baixo;
    }
    return 0;
}
