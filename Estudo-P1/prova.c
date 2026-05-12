struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct fila Fila;

struct pilha{
    struct elemento *topo;
};

typedef struct pilha Pilha;

struct elementoD{
    struct aluno dados;
    struct elementoD *ant;
    struct elementoD *prox;
};

typedef struct elementoD ElemD;
typedef struct elementoD* ListaD;

//Retirar todos os ímpares de uma fila

int remove_Impares_Fila(Fila* fi){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL) return 0;

    Elem* atual = fi->inicio;
    Elem* ant = NULL;
    Elem* no;

    while(atual != NULL){
        if(atual->dados.matricula % 2 != 0){
            no = atual;
            if(ant == NULL){
                fi->inicio = atual->prox;
            }
            else{
                ant->prox = atual->prox;
            }
            atual = atual->prox;
            if(no == fi->final){
                fi->final = ant;
            }
            free(no);
            fi->qtd--;
        }
        else{
            ant = atual;
            atual = atual->prox;
        }
    }
    return 1;
}

// Inverter uma pilha P
int inverte_Pilha(Pilha* pi){
    if(pi == NULL) return 0;
    Pilha* temp = cria_Pilha();
    if(temp == NULL) return 0;
    struct aluno al;
    while(pi->topo != NULL){
        consulta_topo_Pilha(pi, &al);
        remove_Pilha(pi);
        insere_Pilha(temp, al);
    }
    pi->topo = temp->topo;
    free(temp);
    return 1;
}

int inverte_Pilha(Pilha* pi){
    if(pi == NULL) return 0;
    Elem* temp = NULL;
    Elem* no;
    while(pi->topo != NULL){
        no = pi->topo;
        pi->topo = pi->topo->prox;
        no->prox = temp;
        temp = no;
    }
    pi->topo = temp;
    return 1;
}

///////////////////////////LISTAS//////////////////////////////////
int lista_Sem_Repetidos(Lista* li){ // easy
    if(li == NULL) return 0;
    if((*li) == NULL) return 1;
    Elem* i;
    Elem* j;
    for(i = *li; i != NULL; i = i->prox){
        for(j = i->prox; j != NULL; j = j->prox){
            if(i->dados.matricula == j->dados.matricula){
                return 0;
            }
        }
    }
    return 1;
}
void lista_Remover_Repetidos(Lista* li) { // 
    if (li == NULL || (*li) == NULL) return;
    Elem* i;
    Elem* j;
    Elem* anterior;  // <-- única adição principal
    for (i = *li; i != NULL; i = i->prox) {
        anterior = i;                          // anterior começa em i
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->dados.matricula == j->dados.matricula) {
                anterior->prox = j->prox; // pula o nó duplicado
                free(j);// libera a memória
                j = anterior;// volta j para anterior para continuar corretamente
            } else {
                anterior = j;// só avança anterior se não removeu
            }
        }
    }
}

// Ordenar uma lista encadeada
int ordena_Lista(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    Elem* i;
    Elem* j;
    struct aluno temp;
    for(i = *li; i != NULL; i = i->prox){
        for(j = i->prox; j != NULL; j = j->prox){
            if(i->dados.matricula > j->dados.matricula){
                temp = i->dados;
                i->dados = j->dados;
                j->dados = temp;
            }
        }
    }
    return 1;
}
// Dois ponteiros:
// i percorre a lista.
// j percorre os próximos de i.
// Se i > j, troca os dados.


///////////////////////////PAR IMPAR//////////////////////////////////
int mantem_Par_Fila(Fila* fi){// o ant e sempre ou NULL ou par
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* ant = NULL;
    Elem* atual = fi->inicio;
    Elem* no;
    while(atual != NULL){ // tem um if com dois ifs
        no = atual;
        if(atual->dados.matricula % 2 != 0){ // lembrar que [e o atual porqie se for o fi ele seria fixo]
            if(ant == NULL){
                fi->inicio = atual->prox;
            }else{
                ant->prox = atual->prox;
            }
            atual = atual->prox; // antes do free no
            if(no == fi->final){ // 
                fi->final = ant; 
            }
            free(no);
            fi->qtd--;
        }else{ // se [e par mantem e coloca ant = atual e atual vai pro proximo]
            ant = atual;
            atual = atual->prox;
        }
    }
    return 1;
}

int mantem_Pares_Pilha(Pilha* pi){ 
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* atual = pi->topo; //==
    Elem* ant = NULL; //==
    Elem* no; //==
    while(atual != NULL){ 
        if(atual->dados.matricula % 2 != 0){ //==
            no = atual; //==
            if(ant == NULL){ //==
                pi->topo = atual->prox; //==
            }else{ 
                ant->prox = atual->prox; // anterior pula o nó atual
            }
            /*
            if(no == fi->final){ // A UNICA DIFERENCA EH ESSE IF E OS FI->INICIO TROCA POR PI->TOPO
                fi->final = ant; 
            }
            */
            atual = atual->prox; // atual anda antes do free
            free(no); // libera o nó ímpar
        }
        else{ // se for par
            ant = atual; // anterior passa a ser o nó atual
            atual = atual->prox; // atual anda para o próximo
        }
    }
    return 1;
}



///////////////////////////INVERTER//////////////////////////////////
int invertePilha(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* temp = NULL; 
    Elem* no;
    while(pi->topo != NULL){
        no = pi->topo; 
        pi->topo = no->prox; 
        no->prox = temp;
        temp = no;
    }
    pi->topo = temp;
    return 1;
}

int inverte_Fila(Fila* fi){ 
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* ant = NULL; 
    Elem* atual = fi->inicio; 
    Elem* prox; // guarda o próximo antes de inverter a seta
    fi->final = fi->inicio; // o antigo início será o novo final

    while(atual != NULL){
        prox = atual->prox; // salva o próximo nó
        atual->prox = ant; // inverte a seta do nó atual
        ant = atual; // anterior passa a ser o atual
        atual = prox; // atual anda para o próximo salvo
    }
    fi->inicio = ant; // o novo início será o último nó visitado
    return 1;
}


// TREINO 

int tira_ImparF(Fila* fi){
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* ant = NULL;
    Elem* atual = fi->inicio;
    Elem* no;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 != 0){
            if(ant == NULL){
                fi->inicio = atual->prox; //LEMBRAR
            }else{
                ant->prox = atual->prox; // PULA O QUE SE TA AGORA JA QUE ELE EH IMPAR
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
int tira_imparP(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* no;
    Elem* atual = pi->topo;
    Elem* ant = NULL;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 != 0){
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


int inverteP(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* temp = NULL;
    Elem* no;
    while(pi-> topo != NULL){
        no = pi->topo;
        pi->topo = no->prox;
        no->prox = temp;
        temp = no;
    }
    pi->topo = temp;
    return 1;
}

int inverteF(Fila* fi){
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* prox;
    Elem* atual = fi->inicio;
    Elem* ant = NULL;
    fi->final = fi->inicio; // LEMBRAR
    while(atual != NULL){
        prox = atual->prox; // (atual)->(prox) // ant = NULL
        atual->prox = ant; // NULL<-(atual)->(prox) 
        ant = atual; // NULL<-(ant, atual)->(prox)
        atual = prox; // NULL<-(ant)<-(atual, prox)
    }
    fi->inicio = ant; // 
    return 1;
}


// TREINO 2
int FPar(Fila* fi){
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* no;
    Elem* atual = fi->inicio;
    Elem* ant = NULL;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 != 0){
            if(ant == NULL){
                fi->inicio = atual->prox;
            }else{
                ant->prox = atual->prox;
            }
            atual = atual->prox;
            if(no == fi->final){ // se apaga o no aqui se perde o fim da fila sksksksk
                fi->final = ant; // DECORAR
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

int inverteF(Fila* fi){
    if(fi == NULL || fi->inicio == NULL) return 0;
    Elem* ant = NULL;
    Elem* prox;
    Elem* atual = fi->inicio;
    fi->final = fi->inicio;
    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        prox = atual;
    }
    fi->inicio = ant;
    return 1;
}

int PPar(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return;
    Elem* no;
    Elem* atual = pi->topo;
    Elem* ant = NULL;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 != 0){
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

int inverteP(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return;
    Elem* no;
    Elem* temp = NULL;
    while(no != NULL){
        no = pi->topo;
        pi->topo = no->prox;
        no->prox = temp;
        temp = no;
    }
    pi->topo = temp;
    return 1;
}


int PI(Pilha* pi){
    if(pi == NULL || pi->topo == NULL) return 0;
    Elem* no;
    Elem* atual = pi->topo;
    Elem* ant = NULL;
    while(atual != NULL){
        no = atual;
        if(atual->dados.matricula % 2 != 0){
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

int ordenaLista(Lista* li){
    if(li == NULL || (*li) == NULL)return 0;
    Elem* i;
    Elem* j;
    struct aluno temp;
    for(i = *li; i != NULL; i=i->prox){ // nao esquecer do i= e j=
        for(j= i->prox; j != NULL; j=j->prox){
            if(i->dados.matricula > j->dados.matricula){
                temp = j->dados;
                j->dados = i->dados;
                i->dados = temp;
            }
        }
    }
    return 1;
}

int removeIguais(Lista* li){
    if(li == NULL || (*li) == NULL)return 0;
    Elem* j;
    Elem* i;
    Elem* anterior;
    for(i = *li; i != NULL; i=i->prox){ // nao esquecer do i= e j=
        anterior = i;
        for(j= i->prox; j != NULL; j=j->prox){
            if(i->dados.matricula == j->dados.matricula){
                anterior->prox = j->prox;
                free(j);
                j = anterior;
            }else{
                anterior = j;
            }
        }
    }
    return 1;
}

int temIguais(Lista* li){
    if(li == NULL || (*li) == NULL)return 0;
    Elem* j;
    Elem* i;
    for(i = *li; i != NULL; i=i->prox){ // nao esquecer do i= e j=
        for(j= i->prox; j != NULL; j=j->prox){
            if(i->dados.matricula == j->dados.matricula){
                return 0;
            }
        }
    }
    return 1;
}