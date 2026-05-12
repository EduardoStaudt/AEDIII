struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
struct pilha{
    struct elemento *topo;
};
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd; 
};

typedef struct elemento Elem;
typedef struct pilha Pilha;
typedef struct fila Fila;
typedef struct elemento* Lista;

//EX1
int inverte_Pilha(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* no;
    Elem* temp;
    while(pi->topo != NULL){
        no = pi->topo;
        pi->topo = no->prox;
        no->prox = temp;
        temp = no;
    }
    return 1;
}

//EX2 
int inverte_Fila(Fila* fi){
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* prox;
    Elem* ant = NULL;
    Elem* atual = fi->inicio;
    fi->final = fi->inicio;
    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    fi->inicio = ant;
    return 1;
}

//EX3
int remove_Impares_Fila(Fila* fi){
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* ant = NULL;
    Elem* atual = fi->inicio;
    Elem* no;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 == 0){
            if(ant == NULL){
                fi->inicio = atual->prox;
            }else{
                ant->prox = atual->prox;
            }
            atual = atual->prox;
            if(no == fi->final){
                fi->final = ant;
            }
            free(no);
            fi->qtd--;
        }else{
            ant = atual;
            atual = atual->prox;
        }
    }
    return 1;
}

//EX4
int remove_Impares_Pilha(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* ant = NULL;
    Elem* atual = pi->topo;
    Elem* no;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 == 0){
            if(ant == NULL){
                pi->topo = atual->prox;
            }else{
                ant->prox = atual->prox;
            }
            atual = atual->prox;
            free(no);
        }else{
            ant = atual;
            atual = atual->prox;
        }
    }
    return 1;
}

//EX5
int lista_Sem_Repetidos(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;
    Elem* i;
    Elem* j;
    for(i = *li; i != NULL; i=i->prox){
        for(j = i->prox; j != NULL; j=j->prox){
            if(i->dados.matricula == j->dados.matricula) return 0;
        }
    }
    return 1;
} 

//EX6
int remove_Repetidos_Lista(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;
    Elem* i;
    Elem* j;
    Elem* anterior;
    for(i = *li; i != NULL; i=i->prox){
        for(j = i->prox; j != NULL; j=j->prox){
            if(i->dados.matricula == j->dados.matricula){
                anterior->prox = j->prox; 
                free(j);
                j = anterior;
            }
        }
    }
    return 1;
} 

//EX7
int ordena_Lista(Lista* li){
    if(li == NULL || (*li) == NULL) return 0;
    Elem* i;
    Elem* j;
    struct aluno temp;
    for(i = *li; i != NULL; i=i->prox){
        for(j = i->prox; j != NULL; j=j->prox){
            if(i->dados.matricula > j->dados.matricula){
                temp = i->dados;
                i->dados = j->dados;
                j->dados = temp;
            }
        }
    }
    return 1;
} 



