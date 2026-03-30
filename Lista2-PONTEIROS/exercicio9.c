#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int m, int n){
    int **matriz;

    matriz = (int **) malloc(m * sizeof(int *));
    if(matriz == NULL){
        return NULL;
    }

    for(int i = 0; i < m; i++){
        matriz[i] = (int *) malloc(n * sizeof(int));
        if(matriz[i] == NULL){
            for(int j = 0; j < i; j++){
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void libera_matriz(int **matriz, int m){
    for(int i = 0; i < m; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    int m, n;
    int **matriz;

    printf("Qtd Linhas: ]n");
    scanf("%d", &m);

    printf("Qtd Colunas: ]n");
    scanf("%d", &n);

    matriz = aloca_matriz(m, n);

    if(matriz == NULL){
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    libera_matriz(matriz, m);

    return 0;
}