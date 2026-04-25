#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDin.h" //inclui os Prototipos

//Definicao do tipo Fila
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

//Definicao do No Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

struct elementoPilha{
    struct aluno dados;
    struct elementoPilha *prox;
};
typedef struct elementoPilha ElemPilha;

static int push_simples(ElemPilha **pi, struct aluno al){
    ElemPilha *no;
    no = (ElemPilha*) malloc(sizeof(ElemPilha));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = *pi;
    *pi = no;
    return 1;
}

static int pop_simples(ElemPilha **pi, struct aluno *al){
    ElemPilha *no;
    if(pi == NULL || *pi == NULL)
        return 0;
    no = *pi;
    if(al != NULL)
        *al = no->dados;
    *pi = no->prox;
    free(no);
    return 1;
}

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        if(fi->inicio != NULL){
            fi->final->prox = NULL;
            while(fi->inicio != NULL){
                no = fi->inicio;
                fi->inicio = fi->inicio->prox;
                free(no);
            }
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    Elem *no;
    if(fi == NULL)
        return 0;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(fi->final == NULL){
        no->prox = no;
        fi->inicio = no;
        fi->final = no;
    }
    else{
        no->prox = fi->inicio;
        fi->final->prox = no;
        fi->final = no;
    }
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    Elem *no;
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    no = fi->inicio;
    if(fi->inicio == fi->final){
        fi->inicio = NULL;
        fi->final = NULL;
    }
    else{
        fi->inicio = fi->inicio->prox;
        fi->final->prox = fi->inicio;
    }
    free(no);
    fi->qtd--;
    return 1;
}

int remove_Fila_retorna(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)
        return 0;
    if(al != NULL)
        *al = fi->inicio->dados;
    return remove_Fila(fi);
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    (void)fi;
    return 0;
}

void imprime_Fila(Fila* fi){
    Elem* no;
    int i;
    if(fi == NULL)
        return;
    if(fi->inicio == NULL)
        return;
    no = fi->inicio;
    for(i = 0; i < fi->qtd; i++){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                    no->dados.n2,
                                    no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

// EX 1
int separa(Fila* f1, Fila* f2, int n){
    Elem *aux;
    Elem *inicio2;
    int i;
    int cont;

    if(f1 == NULL || f2 == NULL)
        return 0;
    if(f1 == f2)
        return 0;
    if(f1->inicio == NULL)
        return 0;

    while(remove_Fila(f2));

    aux = f1->inicio;
    cont = 0;

    for(i = 0; i < f1->qtd; i++){
        cont++;
        if(aux->dados.matricula == n)
            break;
        aux = aux->prox;
    }

    if(i == f1->qtd)
        return 0;

    if(aux == f1->final)
        return 1;

    inicio2 = aux->prox;

    f2->inicio = inicio2;
    f2->final = f1->final;
    f2->qtd = f1->qtd - cont;

    // nao mexe tudo mexe so o comeco
    f1->final = aux;
    f1->final->prox = f1->inicio;
    f1->qtd = cont;

    f2->final->prox = f2->inicio;

    return 1;
}

// EX 2 - a)
void ex2a_fila_de_filas(){
    struct noFilaFila{
        Fila *fila;
        struct noFilaFila *prox;
    };

    struct noFilaFila *inicio = NULL;
    struct noFilaFila *final = NULL;
    struct noFilaFila *novo;
    Fila *f1;
    Fila *f2;
    struct aluno a1 = {1,"Ana",7,8,9};
    struct aluno a2 = {2,"Bia",8,8,8};

    f1 = cria_Fila();
    f2 = cria_Fila();
    insere_Fila(f1,a1);
    insere_Fila(f2,a2);

    novo = (struct noFilaFila*) malloc(sizeof(struct noFilaFila));
    novo->fila = f1;
    novo->prox = NULL;
    inicio = novo;
    final = novo;

    novo = (struct noFilaFila*) malloc(sizeof(struct noFilaFila));
    novo->fila = f2;
    novo->prox = NULL;
    final->prox = novo;
    final = novo;

    printf("Fila de filas:\n");
    while(inicio != NULL){
        imprime_Fila(inicio->fila);
        printf("=======\n");
        novo = inicio;
        inicio = inicio->prox;
        free(novo);
    }

    libera_Fila(f1);
    libera_Fila(f2);
}

// EX 2 - b)
void ex2b_fila_de_pilhas(){
    struct noPilha{
        struct aluno dados;
        struct noPilha *prox;
    };

    struct noFilaPilha{
        struct noPilha *topo;
        struct noFilaPilha *prox;
    };

    struct noFilaPilha *inicio = NULL;
    struct noFilaPilha *final = NULL;
    struct noFilaPilha *novoFila;
    struct noPilha *p1 = NULL;
    struct noPilha *p2 = NULL;
    struct noPilha *novoPilha;
    struct aluno a1 = {1,"Ana",7,8,9};
    struct aluno a2 = {2,"Bia",8,8,8};

    novoPilha = (struct noPilha*) malloc(sizeof(struct noPilha));
    novoPilha->dados = a1;
    novoPilha->prox = p1;
    p1 = novoPilha;

    novoPilha = (struct noPilha*) malloc(sizeof(struct noPilha));
    novoPilha->dados = a2;
    novoPilha->prox = p2;
    p2 = novoPilha;

    novoFila = (struct noFilaPilha*) malloc(sizeof(struct noFilaPilha));
    novoFila->topo = p1;
    novoFila->prox = NULL;
    inicio = novoFila;
    final = novoFila;

    novoFila = (struct noFilaPilha*) malloc(sizeof(struct noFilaPilha));
    novoFila->topo = p2;
    novoFila->prox = NULL;
    final->prox = novoFila;
    final = novoFila;

    printf("Fila de pilhas:\n");
    while(inicio != NULL){
        if(inicio->topo != NULL)
            printf("Topo da pilha: %d - %s\n",inicio->topo->dados.matricula,inicio->topo->dados.nome);
        else
            printf("Pilha vazia\n");
        novoFila = inicio;
        inicio = inicio->prox;
        free(novoFila);
    }

    while(p1 != NULL){
        novoPilha = p1;
        p1 = p1->prox;
        free(novoPilha);
    }
    while(p2 != NULL){
        novoPilha = p2;
        p2 = p2->prox;
        free(novoPilha);
    }
}

// EX 2 - c)
void ex2c_pilha_de_filas(){
    struct noPilhaFila{
        Fila *fila;
        struct noPilhaFila *prox;
    };

    struct noPilhaFila *topo = NULL;
    struct noPilhaFila *novo;
    Fila *f1;
    Fila *f2;
    struct aluno a1 = {1,"Ana",7,8,9};
    struct aluno a2 = {2,"Bia",8,8,8};

    f1 = cria_Fila();
    f2 = cria_Fila();
    insere_Fila(f1,a1);
    insere_Fila(f2,a2);

    novo = (struct noPilhaFila*) malloc(sizeof(struct noPilhaFila));
    novo->fila = f1;
    novo->prox = topo;
    topo = novo;

    novo = (struct noPilhaFila*) malloc(sizeof(struct noPilhaFila));
    novo->fila = f2;
    novo->prox = topo;
    topo = novo;

    printf("Pilha de filas:\n");
    while(topo != NULL){
        imprime_Fila(topo->fila);
        printf("=======\n");
        novo = topo;
        topo = topo->prox;
        free(novo);
    }

    libera_Fila(f1);
    libera_Fila(f2);
}

// EX 3
int inverter_fila(Fila* fi){
    ElemPilha *pi = NULL;
    struct aluno al;

    if(fi == NULL)
        return 0;

    while(!Fila_vazia(fi)){
        remove_Fila_retorna(fi,&al);
        push_simples(&pi,al);
    }

    while(pi != NULL){
        pop_simples(&pi,&al);
        insere_Fila(fi,al);
    }

    return 1;
}

// EX 4
int FuraFila(Fila* fi, struct aluno al){
    Elem *no;
    if(fi == NULL)
        return 0;

    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    no->dados = al;

    if(fi->inicio == NULL){
        no->prox = no;
        fi->inicio = no;
        fi->final = no;
    }
    else{
        // nao mexe tudo mexe so o comeco
        no->prox = fi->inicio;
        fi->inicio = no;
        fi->final->prox = fi->inicio;
    }
    fi->qtd++;
    return 1;
}

// EX 5
void pista_decolagem(){
    struct aviao{
        int id;
        char nome[30];
        char modelo[30];
    };

    struct noAviao{
        struct aviao dados;
        struct noAviao *prox;
    };

    struct noAviao *inicio = NULL;
    struct noAviao *final = NULL;
    struct noAviao *no;
    struct aviao av;
    int op;
    int qtd = 0;

    do{
        printf("\n1-Listar numero de avioes aguardando\n");
        printf("2-Autorizar a decolagem do primeiro aviao\n");
        printf("3-Adicionar um aviao\n");
        printf("4-Listar todos os avioes\n");
        printf("5-Listar o primeiro aviao\n");
        printf("0-Sair\n");
        printf("Opcao: ");
        scanf("%d",&op);

        if(op == 1){
            printf("Tem %d avioes na fila\n",qtd);
        }
        else if(op == 2){
            if(inicio == NULL)
                printf("Nao tem aviao na fila\n");
            else{
                no = inicio;
                printf("Decolando aviao %d - %s\n",no->dados.id,no->dados.nome);
                inicio = inicio->prox;
                if(inicio == NULL)
                    final = NULL;
                free(no);
                qtd--;
            }
        }
        else if(op == 3){
            no = (struct noAviao*) malloc(sizeof(struct noAviao));
            if(no != NULL){
                printf("Id: ");
                scanf("%d",&av.id);
                printf("Nome: ");
                scanf(" %29[^\n]",av.nome);
                printf("Modelo: ");
                scanf(" %29[^\n]",av.modelo);
                no->dados = av;
                no->prox = NULL;
                if(final == NULL)
                    inicio = no;
                else
                    final->prox = no;
                final = no;
                qtd++;
            }
        }
        else if(op == 4){
            no = inicio;
            while(no != NULL){
                printf("Id: %d\n",no->dados.id);
                printf("Nome: %s\n",no->dados.nome);
                printf("Modelo: %s\n",no->dados.modelo);
                printf("---------------------\n");
                no = no->prox;
            }
        }
        else if(op == 5){
            if(inicio == NULL)
                printf("Nao tem aviao na fila\n");
            else{
                printf("Id: %d\n",inicio->dados.id);
                printf("Nome: %s\n",inicio->dados.nome);
                printf("Modelo: %s\n",inicio->dados.modelo);
            }
        }
    }while(op != 0);

    while(inicio != NULL){
        no = inicio;
        inicio = inicio->prox;
        free(no);
    }
}

// EX 6
int junta_filas(Fila* f1, Fila* f2, Fila* f3){
    Elem *no1;
    Elem *no2;
    int i;
    int j;

    if(f1 == NULL || f2 == NULL || f3 == NULL)
        return 0;
    if(f3 == f1 || f3 == f2)
        return 0;

    while(remove_Fila(f3));

    no1 = f1->inicio;
    no2 = f2->inicio;
    i = 0;
    j = 0;

    while(i < f1->qtd && j < f2->qtd){
        if(no1->dados.matricula < no2->dados.matricula){
            insere_Fila(f3,no1->dados);
            no1 = no1->prox;
            i++;
        }
        else{
            insere_Fila(f3,no2->dados);
            no2 = no2->prox;
            j++;
        }
    }

    while(i < f1->qtd){
        insere_Fila(f3,no1->dados);
        no1 = no1->prox;
        i++;
    }

    while(j < f2->qtd){
        insere_Fila(f3,no2->dados);
        no2 = no2->prox;
        j++;
    }

    return 1;
}

// EX 7
int reverso(Fila* fi){
    // faz igual a inversao
    return inverter_fila(fi);
}

// EX 8
void menu(){
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila e vazia.\n");
    printf("3-Verifica se a fila e cheia.\n");
    printf("4-Enfileira o elemento na fila.\n");
    printf("5-Desefileira elemento da fila.\n");
    printf("6-Le o numero no inicio da fila.\n");
    printf("7-Testar qual fila possui mais elementos .\n");
    printf("8-Furar a fila .\n");
    printf("9-Sair.\n");
}

void menu_continuo(){
    Fila *f1 = NULL;
    Fila *f2 = NULL;
    Fila *fi;
    struct aluno al;
    int op;
    int qual;

    do{
        printf("\n");
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d",&op);

        if(op == 1){
            if(f1 != NULL)
                libera_Fila(f1);
            if(f2 != NULL)
                libera_Fila(f2);
            f1 = cria_Fila();
            f2 = cria_Fila();
            printf("Filas inicializadas\n");
        }
        else if(op >= 2 && op <= 8){
            if(f1 == NULL || f2 == NULL){
                printf("Inicie as filas primeiro\n");
                continue;
            }
        }

        if(op == 2){
            printf("Qal fila voce quer testar? 1 ou 2: ");
            scanf("%d",&qual);
            fi = (qual == 1) ? f1 : f2;
            if(Fila_vazia(fi))
                printf("Fila vazia\n");
            else
                printf("Fila nao vazia\n");
        }
        else if(op == 3){
            printf("Qal fila voce quer testar? 1 ou 2: ");
            scanf("%d",&qual);
            fi = (qual == 1) ? f1 : f2;
            if(Fila_cheia(fi))
                printf("Fila cheia\n");
            else
                printf("Fila nao cheia\n");
        }
        else if(op == 4){
            printf("Qal fila voce quer usar? 1 ou 2: ");
            scanf("%d",&qual);
            fi = (qual == 1) ? f1 : f2;
            printf("Matricula: ");
            scanf("%d",&al.matricula);
            printf("Nome: ");
            scanf(" %29[^\n]",al.nome);
            printf("N1: ");
            scanf("%f",&al.n1);
            printf("N2: ");
            scanf("%f",&al.n2);
            printf("N3: ");
            scanf("%f",&al.n3);
            insere_Fila(fi,al);
            printf("Elemento inserido\n");
        }
        else if(op == 5){
            printf("Qal fila voce quer usar? 1 ou 2: ");
            scanf("%d",&qual);
            fi = (qual == 1) ? f1 : f2;
            if(remove_Fila_retorna(fi,&al))
                printf("Saiu da fila: %d - %s\n",al.matricula,al.nome);
            else
                printf("Fila vazia\n");
        }
        else if(op == 6){
            printf("Qal fila voce quer usar? 1 ou 2: ");
            scanf("%d",&qual);
            fi = (qual == 1) ? f1 : f2;
            if(consulta_Fila(fi,&al)){
                printf("Inicio da fila:\n");
                printf("Matricula: %d\n",al.matricula);
                printf("Nome: %s\n",al.nome);
            }
            else
                printf("Fila vazia\n");
        }
        else if(op == 7){
            if(tamanho_Fila(f1) > tamanho_Fila(f2))
                printf("Fila 1 tem mais elementos\n");
            else if(tamanho_Fila(f2) > tamanho_Fila(f1))
                printf("Fila 2 tem mais elementos\n");
            else
                printf("As duas filas tem o mesmo tamanho\n");
        }
        else if(op == 8){
            printf("Qal fila voce quer furar? 1 ou 2: ");
            scanf("%d",&qual);
            fi = (qual == 1) ? f1 : f2;
            printf("Matricula: ");
            scanf("%d",&al.matricula);
            printf("Nome: ");
            scanf(" %29[^\n]",al.nome);
            printf("N1: ");
            scanf("%f",&al.n1);
            printf("N2: ");
            scanf("%f",&al.n2);
            printf("N3: ");
            scanf("%f",&al.n3);
            FuraFila(fi,al);
            printf("Elemento entrou na frente\n");
        }

    }while(op != 9);

    if(f1 != NULL)
        libera_Fila(f1);
    if(f2 != NULL)
        libera_Fila(f2);
}