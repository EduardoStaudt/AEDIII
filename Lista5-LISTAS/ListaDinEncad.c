#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h" 


struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)
        return 0;

    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1,
                                    no->dados.n2,
                                    no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

// EX 1 - a)
int consulta_lista_matricula(Lista* li, int mat, struct aluno *al){
    Elemento *no;

    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    if(al == NULL)
        return 0;

    no = *li;
    while(no != NULL){
        if(no->dados.matricula == mat){
            *al = no->dados;
            return 1;
        }
        no = no->prox;
    }

    return 0;
}

// EX 1 - b)
int consulta_lista_posicao(Lista* li, int pos, struct aluno *al){
    Elemento *no;
    int cont;

    if(li == NULL)
        return 0;
    if((*li) == NULL) 
        return 0;
    if(al == NULL)
        return 0;
    if(pos <= 0)
        return 0;

    no = *li;
    cont = 1;

    while(no != NULL && cont < pos){
        no = no->prox;
        cont++;
    }

    if(no == NULL)
        return 0;

    *al = no->dados;
    return 1;
}

// Ex2
int remove_lista_recursiva(Lista* li, int mat){
    Elemento *no;

    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    if((*li)->dados.matricula == mat){
        no = *li;
        *li = (*li)->prox;
        free(no);
        return 1;
    }

    return remove_lista_recursiva(&((*li)->prox), mat);
}

int listas_iguais_recursiva(Lista* l1, Lista* l2){
    if(l1 == NULL || l2 == NULL)
        return 0;

    if((*l1) == NULL && (*l2) == NULL)
        return 1;

    if((*l1) == NULL || (*l2) == NULL)
        return 0;

    if((*l1)->dados.matricula != (*l2)->dados.matricula)
        return 0;

    return listas_iguais_recursiva(&((*l1)->prox), &((*l2)->prox));
}

// EX 3
int insere_valor(Lista* li, struct aluno al, int pos){
    Elemento *no;
    Elemento *ant;
    int cont;

    if(li == NULL)
        return 0;
    if(pos <= 0)
        return 0;

    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;

    no->dados = al;

    if(pos == 1){//insere no inicio
        no->prox = *li;
        *li = no;
        return 1;
    }

    ant = *li;
    cont = 1;

    // para no anterior da posicao desejada
    while(ant != NULL && cont < pos - 1){
        ant = ant->prox;
        cont++;
    }

    if(ant == NULL){//posicao nao existe
        free(no);
        return 0;
    }

    no->prox = ant->prox;
    ant->prox = no;
    return 1;
}

// EX 4 - lista encadeada para valores float
struct elementoFloat{
    float info;
    struct elementoFloat *prox;
};
typedef struct elementoFloat ElementoFloat;

ListaFloat* cria_lista_float(){
    ListaFloat* li = (ListaFloat*) malloc(sizeof(ListaFloat));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista_float(ListaFloat* li){
    if(li != NULL){
        ElementoFloat *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_float_final(ListaFloat* li, float valor){
    ElementoFloat *no;
    ElementoFloat *aux;

    if(li == NULL)
        return 0;

    no = (ElementoFloat*) malloc(sizeof(ElementoFloat));
    if(no == NULL)
        return 0;

    no->info = valor;
    no->prox = NULL;

    if((*li) == NULL){
        *li = no;
    }
    else{
        aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }

    return 1;
}

ListaFloat* constroi_lista_float(float v[], int n){
    ListaFloat *li;
    int i;

    if(v == NULL || n < 0)
        return NULL;

    li = cria_lista_float();
    if(li == NULL)
        return NULL;

    for(i = 0; i < n; i++){
        if(!insere_lista_float_final(li,v[i])){
            libera_lista_float(li);
            return NULL;
        }
    }

    return li;
}

void imprime_lista_float(ListaFloat* li){
    ElementoFloat *no;

    if(li == NULL)
        return;

    no = *li;
    while(no != NULL){
        printf("Valor: %.2f\n",no->info);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

// EX 5
int remove_valor_especifico(Lista* li, int valor){
    Elemento *no;
    Elemento *ant;
    int removidos;

    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    removidos = 0;

    // remove repetidos no inicio da lista
    while((*li) != NULL && (*li)->dados.matricula == valor){
        no = *li;
        *li = (*li)->prox;
        free(no);
        removidos++;
    }

    if((*li) == NULL)
        return removidos;

    ant = *li;
    no = ant->prox;

    while(no != NULL){
        if(no->dados.matricula == valor){
            ant->prox = no->prox;
            free(no);
            no = ant->prox;
            removidos++;
        }
        else{
            ant = no;
            no = no->prox;
        }
    }

    return removidos;
}

// EX 6
int concatena(Lista* l1, Lista* l2){
    Elemento *aux;

    if(l1 == NULL || l2 == NULL)
        return 0;
    if(l1 == l2)
        return 0;

    if((*l1) == NULL){
        *l1 = *l2;
        *l2 = NULL;
        return 1;
    }

    aux = *l1;
    while(aux->prox != NULL)
        aux = aux->prox;

    // ultimo da L1 aponta para o inicio da L2
    aux->prox = *l2;

    // L2 fica vazia para nao ter duas listas apontando pros mesmos nos
    *l2 = NULL;

    return 1;
}

// EX 7
int remove_repetidos(Lista* li){
    Elemento *atual;
    Elemento *ant;
    Elemento *no;
    int removidos;

    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    removidos = 0;
    atual = *li;

    while(atual != NULL){
        ant = atual;
        no = atual->prox;

        while(no != NULL){
            if(no->dados.matricula == atual->dados.matricula){
                ant->prox = no->prox;
                free(no);
                no = ant->prox;
                removidos++;
            }
            else{
                ant = no;
                no = no->prox;
            }
        }

        atual = atual->prox;
    }

    return removidos;
}

// EX 8
int fusao(Lista* l1, Lista* l2, Lista* l3){
    Elemento *no1;
    Elemento *no2;
    Elemento *menor;
    Elemento *ultimo;
    Elemento *resto;

    if(l1 == NULL || l2 == NULL || l3 == NULL)
        return 0;
    if(l1 == l2 || l1 == l3 || l2 == l3)
        return 0;
    if((*l3) != NULL)//L3 precisa estar vazia
        return 0;

    no1 = *l1;
    no2 = *l2;
    ultimo = NULL;

    while(no1 != NULL && no2 != NULL){
        if(no1->dados.matricula <= no2->dados.matricula){
            menor = no1;
            no1 = no1->prox;
        }
        else{
            menor = no2;
            no2 = no2->prox;
        }

        if((*l3) == NULL)
            *l3 = menor;
        else
            ultimo->prox = menor;

        ultimo = menor;
    }

    if(no1 != NULL)
        resto = no1;
    else
        resto = no2;

    if((*l3) == NULL)
        *l3 = resto;
    else
        ultimo->prox = resto;

    // L1 e L2 ficam vazias porque os nos foram religados em L3
    *l1 = NULL;
    *l2 = NULL;

    return 1;
}

// EX 9 
Elemento* busca_matricula(Lista* li, int mat){
    Elemento *no;

    if(li == NULL)
        return NULL;
    if((*li) == NULL)//lista vazia
        return NULL;

    no = *li;
    while(no != NULL){
        if(no->dados.matricula == mat)
            return no;
        no = no->prox;
    }

    return NULL;
}

void Troca(TipoLista* pLista, TipoCelula* p){
    TipoCelula *ant;
    TipoCelula *prox;

    if(pLista == NULL)
        return;
    if((*pLista) == NULL)//lista vazia
        return;
    if(p == NULL)
        return;
    if(p->prox == NULL)//p e o ultimo, nao tem proximo para trocar
        return;

    prox = p->prox;

    if(p == *pLista){//p e o primeiro da lista
        p->prox = prox->prox;
        prox->prox = p;
        *pLista = prox;
        return;
    }

    ant = *pLista;

    // procura o no anterior ao p
    while(ant != NULL && ant->prox != p)
        ant = ant->prox;

    if(ant == NULL)//p nao pertence a lista
        return;

    // ant -> p -> prox vira ant -> prox -> p
    ant->prox = prox;
    p->prox = prox->prox;
    prox->prox = p;
}