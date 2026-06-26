#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

// EX1
int totalFolhas_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    // se nao tem filhos é folha
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        return 1;
    int esq = totalFolhas_ArvBin(&((*raiz)->esq));
    int dir = totalFolhas_ArvBin(&((*raiz)->dir));
    return (esq + dir);
}

// EX2
void imprime_ArvBin(ArvBin *raiz, int nivel){
    if(raiz == NULL)
        return;
    if(*raiz == NULL)
        return;
    int i;
    for(i = 0; i < nivel; i++)
        printf("  ");
    if(nivel == 0)
        printf("[raiz] %d\n", (*raiz)->info);
    else if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        printf("[folha] %d\n", (*raiz)->info);
    else
        printf("[pai] %d\n", (*raiz)->info);
    imprime_ArvBin(&((*raiz)->esq), nivel + 1);
    imprime_ArvBin(&((*raiz)->dir), nivel + 1);
}

// EX3
int contaValor_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int count = 0;
    if((*raiz)->info == valor)
        count = 1;
    count += contaValor_ArvBin(&((*raiz)->esq), valor);
    count += contaValor_ArvBin(&((*raiz)->dir), valor);
    return count;
}

// EX4
void folhasDecrescente_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz == NULL)
        return;
    // visita direita primeiro pra sair decrescente
    folhasDecrescente_ArvBin(&((*raiz)->dir));
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
        printf("%d\n", (*raiz)->info);
    folhasDecrescente_ArvBin(&((*raiz)->esq));
}

// EX5
int iguais_ArvBin(ArvBin *raiz1, ArvBin *raiz2){
    if(*raiz1 == NULL && *raiz2 == NULL)
        return 1;
    if(*raiz1 == NULL || *raiz2 == NULL)
        return 0;
    if((*raiz1)->info != (*raiz2)->info)
        return 0;
    int esq = iguais_ArvBin(&((*raiz1)->esq), &((*raiz2)->esq));
    int dir = iguais_ArvBin(&((*raiz1)->dir), &((*raiz2)->dir));
    return (esq && dir);
}

// EX6
void removePares_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz == NULL)
        return;
    removePares_ArvBin(&((*raiz)->esq));
    removePares_ArvBin(&((*raiz)->dir));
    if((*raiz)->info % 2 == 0)
        remove_ArvBin(raiz, (*raiz)->info);
}

// EX7
int similares_ArvBin(ArvBin *raiz1, ArvBin *raiz2){
    if(*raiz1 == NULL && *raiz2 == NULL)
        return 1;
    if(*raiz1 == NULL || *raiz2 == NULL)
        return 0;
    // nao compara os valores, so a estrutura
    int esq = similares_ArvBin(&((*raiz1)->esq), &((*raiz2)->esq));
    int dir = similares_ArvBin(&((*raiz1)->dir), &((*raiz2)->dir));
    return (esq && dir);
}

// EX8
int insere_ArvBinChar(ArvBin* raiz, char valor){
    return insere_ArvBin(raiz, (int)valor);
}

void preOrdem_ArvBinChar(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%c\n", (char)(*raiz)->info);
        preOrdem_ArvBinChar(&((*raiz)->esq));
        preOrdem_ArvBinChar(&((*raiz)->dir));
    }
}

// EX9
struct NOExpr{
    char info;
    struct NOExpr *esq;
    struct NOExpr *dir;
};

// cria um no novo
struct NOExpr* novoNOExpr(char val, struct NOExpr* esq, struct NOExpr* dir){
    struct NOExpr* no = (struct NOExpr*) malloc(sizeof(struct NOExpr));
    no->info = val;
    no->esq  = esq;
    no->dir  = dir;
    return no;
}

void libera_NOExpr(struct NOExpr* no){
    if(no == NULL)
        return;
    libera_NOExpr(no->esq);
    libera_NOExpr(no->dir);
    free(no);
}

// EX9b
int calcula_NOExpr(struct NOExpr* no){
    if(no == NULL)
        return 0;
    // se for folha retorna o numero
    if(no->esq == NULL && no->dir == NULL)
        return (no->info - '0');
    int esq = calcula_NOExpr(no->esq);
    int dir = calcula_NOExpr(no->dir);
    if(no->info == '+') return esq + dir;
    if(no->info == '-') return esq - dir;
    if(no->info == '*') return esq * dir;
    if(no->info == '/') return esq / dir;
    return 0;
}

// EX9c
void infixa_NOExpr(struct NOExpr* no){
    if(no == NULL)
        return;
    if(no->esq != NULL) printf("(");
    infixa_NOExpr(no->esq);
    printf("%c", no->info);
    infixa_NOExpr(no->dir);
    if(no->dir != NULL) printf(")");
}

void prefixa_NOExpr(struct NOExpr* no){
    if(no == NULL)
        return;
    printf("%c ", no->info);
    prefixa_NOExpr(no->esq);
    prefixa_NOExpr(no->dir);
}

void posfixa_NOExpr(struct NOExpr* no){
    if(no == NULL)
        return;
    posfixa_NOExpr(no->esq);
    posfixa_NOExpr(no->dir);
    printf("%c ", no->info);
}