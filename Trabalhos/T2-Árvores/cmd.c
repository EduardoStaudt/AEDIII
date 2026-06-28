#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmd.h"

No* criarNo(char nome[], TipoNo tipo) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->tipo = tipo;
    novo->primeiroFilho = NULL;
    novo->proximoIrmao = NULL;
    novo->pai = NULL;
    return novo;
}

No* criarRaiz() {
    No *raiz = criarNo("/", PASTA);
    return raiz;
}

TipoNo descobrirTipo(char nome[]) {
    int i;
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '.') {
            return ARQUIVO;
        }
    }
    return PASTA;
}

No* buscarFilho(No *pasta, char nome[]) {
    No *filho = pasta->primeiroFilho;
    while (filho != NULL) {
        if (strcmp(filho->nome, nome) == 0) {
            return filho;
        }
        filho = filho->proximoIrmao;
    }
    return NULL;
}

void adicionarFilho(No *pai, No *filho) {
    filho->pai = pai;
    if (pai->primeiroFilho == NULL) {
        pai->primeiroFilho = filho;
        return;
    }
    No *atual = pai->primeiroFilho;
    while (atual->proximoIrmao != NULL) {
        atual = atual->proximoIrmao;
    }
    atual->proximoIrmao = filho;
}

No* inserirCaminho(No *raiz, char caminho[]) {
    No *atual = raiz;
    char copia[TAMANHO_LINHA];
    strcpy(copia, caminho);

    char *parte = strtok(copia, "/");
    while (parte != NULL) {
        No *filho = buscarFilho(atual, parte);
        if (filho == NULL) {
            filho = criarNo(parte, descobrirTipo(parte));
            adicionarFilho(atual, filho);
        }
        atual = filho;
        parte = strtok(NULL, "/");
    }
    return atual;
}

void lerArquivo(No *raiz, char nomeArquivo[]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    char linha[TAMANHO_LINHA];
    while (fgets(linha, TAMANHO_LINHA, arquivo) != NULL) {
        int tamanho = strlen(linha);
        while (tamanho > 0 && (linha[tamanho - 1] == '\n' || linha[tamanho - 1] == '\r')) {
            linha[tamanho - 1] = '\0';
            tamanho--;
        }
        if (tamanho > 0) {
            inserirCaminho(raiz, linha);
        }
    }
    fclose(arquivo);
}

void montarCaminho(No *no, char destino[]) {
    if (no->pai == NULL) {
        strcpy(destino, "/");
        return;
    }
    montarCaminho(no->pai, destino);
    if (strcmp(destino, "/") != 0) {
        strcat(destino, "/");
    }
    strcat(destino, no->nome);
}

void comandoCd(No **atual, char argumento[]) {
    if (strcmp(argumento, "..") == 0) {
        if ((*atual)->pai != NULL) {
            *atual = (*atual)->pai;
        }
        return;
    }

    No *destino = buscarFilho(*atual, argumento);

    if (destino != NULL && destino->tipo == PASTA) {
        *atual = destino;
        return;
    }
    if (destino != NULL && destino->tipo == ARQUIVO) {
        printf("%s e um arquivo, nao uma pasta\n", argumento);
        return;
    }

    int encontrouAlternativa = 0;
    int tamanhoArgumento = strlen(argumento);
    No *filho = (*atual)->primeiroFilho;
    while (filho != NULL) {
        if (filho->tipo == PASTA && strncmp(filho->nome, argumento, tamanhoArgumento) == 0) {
            if (encontrouAlternativa == 0) {
                printf("Diretorio nao encontrado. Voce quis dizer:\n");
            }
            printf("  %s\n", filho->nome);
            encontrouAlternativa = 1;
        }
        filho = filho->proximoIrmao;
    }

    if (encontrouAlternativa == 0) {
        printf("Diretorio nao encontrado\n");
    }
}

void comandoList(No *atual) {
    No *filho = atual->primeiroFilho;
    if (filho == NULL) {
        printf("Pasta vazia\n");
        return;
    }
    while (filho != NULL) {
        if (filho->tipo == PASTA) {
            printf("[PASTA]   %s\n", filho->nome);
        } else {
            printf("[ARQUIVO] %s\n", filho->nome);
        }
        filho = filho->proximoIrmao;
    }
}

void comandoMkdir(No *atual, char argumento[]) {
    if (strlen(argumento) == 0) {
        printf("Informe o nome da pasta. Uso: mkdir <nome>\n");
        return;
    }
    No *existente = buscarFilho(atual, argumento);
    if (existente != NULL) {
        printf("Ja existe um item chamado %s nesta pasta\n", argumento);
        return;
    }
    No *nova = criarNo(argumento, PASTA);
    adicionarFilho(atual, nova);
    printf("Pasta %s criada\n", argumento);
}

void buscarRecursivo(No *atual, char alvo[], int *contador) {
    No *filho = atual->primeiroFilho;
    while (filho != NULL) {
        if (strcmp(filho->nome, alvo) == 0) {
            char caminho[TAMANHO_LINHA];
            montarCaminho(filho, caminho);
            printf("  %s\n", caminho);
            *contador = *contador + 1;
        }
        buscarRecursivo(filho, alvo, contador);
        filho = filho->proximoIrmao;
    }
}

void comandoSearch(No *raiz, char argumento[]) {
    if (strlen(argumento) == 0) {
        printf("Informe o que buscar. Uso: search <nome>\n");
        return;
    }
    int contador = 0;
    printf("Resultados para \"%s\":\n", argumento);
    buscarRecursivo(raiz, argumento, &contador);
    if (contador == 0) {
        printf("  Nenhum arquivo ou pasta encontrado\n");
    }
}

void comandoRm(No *atual, char argumento[]) {
    if (strlen(argumento) == 0) {
        printf("Informe o que remover. Uso: rm <nome>\n");
        return;
    }
    No *alvo = buscarFilho(atual, argumento);
    if (alvo == NULL) {
        printf("Item %s nao encontrado nesta pasta\n", argumento);
        return;
    }

    if (atual->primeiroFilho == alvo) {
        atual->primeiroFilho = alvo->proximoIrmao;
    } else {
        No *anterior = atual->primeiroFilho;
        while (anterior->proximoIrmao != alvo) {
            anterior = anterior->proximoIrmao;
        }
        anterior->proximoIrmao = alvo->proximoIrmao;
    }

    alvo->proximoIrmao = NULL;
    liberarArvore(alvo);
    printf("%s removido\n", argumento);
}

void comandoOpen(No *atual, char argumento[]) {
    if (strlen(argumento) == 0) {
        printf("Informe o arquivo. Uso: open <arquivo>\n");
        return;
    }
    No *alvo = buscarFilho(atual, argumento);
    if (alvo == NULL) {
        printf("Arquivo %s nao encontrado nesta pasta\n", argumento);
        return;
    }
    if (alvo->tipo == PASTA) {
        printf("%s e uma pasta, nao um arquivo\n", argumento);
        return;
    }

    char comando[TAMANHO_LINHA + 50];
    #ifdef _WIN32
        sprintf(comando, "start \"\" \"%s\"", argumento);
    #elif __APPLE__
        sprintf(comando, "open \"%s\"", argumento);
    #else
        sprintf(comando, "xdg-open \"%s\"", argumento);
    #endif

    system(comando);
    printf("Abrindo %s\n", argumento);
}

void comandoClear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void comandoHelp() {
    printf("Comandos disponiveis:\n\n");
    printf("cd <pasta>     Entra na pasta indicada. Use cd .. para voltar uma pasta.\n");
    printf("               Se a pasta nao existir, mostra as que comecam igual.\n");
    printf("search <nome>  Procura um arquivo ou pasta na arvore inteira e mostra o caminho.\n");
    printf("rm <nome>      Remove uma pasta ou arquivo da pasta atual liberando tudo dentro.\n");
    printf("open <arquivo> Abre um arquivo da pasta atual no programa padrao do sistema.\n");
    printf("list           Lista as pastas e arquivos da pasta atual.\n");
    printf("mkdir <nome>   Cria uma pasta nova dentro da pasta atual.\n");
    printf("clear          Limpa a tela.\n");
    printf("help           Mostra esta lista de comandos.\n");
    printf("exit           Libera a memoria e fecha o programa.\n");
}

void liberarArvore(No *no) {
    if (no == NULL) {
        return;
    }
    No *filho = no->primeiroFilho;
    while (filho != NULL) {
        No *proximo = filho->proximoIrmao;
        liberarArvore(filho);
        filho = proximo;
    }
    free(no);
}
