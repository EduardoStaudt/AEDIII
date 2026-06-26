#ifndef CMD_H
#define CMD_H

#define TAMANHO_NOME 256
#define TAMANHO_LINHA 1024

typedef enum {
    PASTA,
    ARQUIVO
} TipoNo;

typedef struct No {
    char nome[TAMANHO_NOME];
    TipoNo tipo;
    struct No *primeiroFilho;
    struct No *proximoIrmao;
    struct No *pai;
} No;

No* criarNo(char nome[], TipoNo tipo);
No* criarRaiz();
TipoNo descobrirTipo(char nome[]);
No* buscarFilho(No *pasta, char nome[]);
void adicionarFilho(No *pai, No *filho);
No* inserirCaminho(No *raiz, char caminho[]);
void lerArquivo(No *raiz, char nomeArquivo[]);
void montarCaminho(No *no, char destino[]);

void comandoCd(No **atual, char argumento[]);
void comandoList(No *atual);
void comandoMkdir(No *atual, char argumento[]);
void buscarRecursivo(No *atual, char alvo[], int *contador);
void comandoSearch(No *raiz, char argumento[]);
void comandoRm(No *atual, char argumento[]);
void comandoClear();
void comandoHelp();

void liberarArvore(No *no);

#endif
