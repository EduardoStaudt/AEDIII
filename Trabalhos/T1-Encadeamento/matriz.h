#ifndef MATRIZ_H 
#define MATRIZ_H

typedef struct elemento Elem;

struct elemento {
    int x;             // linha do nó (0 até linhas-1)
    int y;             // coluna do nó (0 até colunas-1)
    int valor;         // valor inteiro armazenado no nó
    Elem *cima;        // ponteiro para o vizinho de cima (NULL se borda superior)
    Elem *baixo;       // ponteiro para o vizinho de baixo (NULL se borda inferior)
    Elem *esq;         // ponteiro para o vizinho da esquerda (NULL se borda esquerda)
    Elem *dir;         // ponteiro para o vizinho da direita (NULL se borda direita)
};

typedef struct matriz Matriz;

struct matriz {
    int linhas;        // quantidade de linhas da matriz
    int colunas;       // quantidade de colunas da matriz
    Elem *inicio;      // ponteiro para a coordenada (0,0)
};

// DECLARACOES
Matriz* alocar_matriz(int linhas, int colunas);
int desalocar_matriz(Matriz *m);
int inserir_valor(Matriz *m, int x, int y, int valor);
Elem* consultar_valor(Matriz *m, int x, int y);
Elem* buscar_valor(Matriz *m, int valor);
int imprimir_vizinhos(Matriz *m, int x, int y);
int deslocar(Elem **atual, int opcao);
int imprimir_matriz(Matriz *m);

#endif 