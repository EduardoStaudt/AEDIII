//Arquivo ListaDinEncadDupla.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

//EX1
int remove_lista(Lista* li, int mat);

//EX2
int insere_lista_ordenada(Lista* li, struct aluno al);

//EX3
int conta_lista_nota(Lista* li, int n1);

//EX4
int insere_lista_inicio_circular(Lista* li, struct aluno al);
int insere_lista_final_circular(Lista* li, struct aluno al);
int remove_lista_inicio_circular(Lista* li);
int remove_lista_final_circular(Lista* li);
void imprime_lista_circular(Lista* li);

//EX5
struct fila{
    int info;
    struct fila *prox;
    struct fila *ant;
};

struct nodesc{
    struct fila *ini;
    struct fila *fim;
};

typedef struct nodesc* noDesc;

int inicializa_noDesc(noDesc *no);
int enfileirar(noDesc *n, int elem);
int desenfileirar(noDesc *n, int *elem);