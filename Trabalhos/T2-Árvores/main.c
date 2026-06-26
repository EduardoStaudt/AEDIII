#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmd.h"

int main() {
    No *raiz = criarRaiz();
    lerArquivo(raiz, "in.txt");

    No *atual = raiz;
    char linha[TAMANHO_LINHA];
    char comando[TAMANHO_LINHA];
    char argumento[TAMANHO_LINHA];
    int rodando = 1;

    printf("Simulador de diretorios. Digite help para ver os comandos.\n");

    do {
        char caminho[TAMANHO_LINHA];
        montarCaminho(atual, caminho);
        printf("\n%s> ", caminho);

        if (fgets(linha, TAMANHO_LINHA, stdin) == NULL) {
            break;
        }

        int tamanho = strlen(linha);
        while (tamanho > 0 && (linha[tamanho - 1] == '\n' || linha[tamanho - 1] == '\r')) {
            linha[tamanho - 1] = '\0';
            tamanho--;
        }

        int i = 0;
        int j = 0;
        while (linha[i] != '\0' && linha[i] != ' ') {
            comando[j] = linha[i];
            i++;
            j++;
        }
        comando[j] = '\0';

        while (linha[i] == ' ') {
            i++;
        }

        j = 0;
        while (linha[i] != '\0') {
            argumento[j] = linha[i];
            i++;
            j++;
        }
        argumento[j] = '\0';

        if (strcmp(comando, "cd") == 0) {
            comandoCd(&atual, argumento);
        } else if (strcmp(comando, "search") == 0) {
            comandoSearch(raiz, argumento);
        } else if (strcmp(comando, "rm") == 0) {
            comandoRm(atual, argumento);
        } else if (strcmp(comando, "list") == 0) {
            comandoList(atual);
        } else if (strcmp(comando, "mkdir") == 0) {
            comandoMkdir(atual, argumento);
        } else if (strcmp(comando, "clear") == 0) {
            comandoClear();
        } else if (strcmp(comando, "help") == 0) {
            comandoHelp();
        } else if (strcmp(comando, "exit") == 0) {
            rodando = 0;
        } else if (strcmp(comando, "") == 0) {
            rodando = 1;
        } else {
            printf("Comando desconhecido: %s. Digite help.\n", comando);
        }

    } while (rodando == 1);

    liberarArvore(raiz);
    printf("Memoria liberada. Programa encerrado.\n");
    return 0;
}
