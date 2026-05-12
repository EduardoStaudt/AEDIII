//Arquivo ListaDinEncad.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);

// EX 1
int consulta_lista_matricula(Lista* li, int mat, struct aluno *al);
int consulta_lista_posicao(Lista* li, int pos, struct aluno *al);

// EX 2
typedef struct elemento Elemento;
int remove_lista_recursiva(Lista* li, int mat);
int listas_iguais_recursiva(Lista* l1, Lista* l2);

// EX 3
int insere_valor(Lista* li, struct aluno al, int pos);

// EX 4
typedef struct elementoFloat* ListaFloat;
ListaFloat* cria_lista_float();
void libera_lista_float(ListaFloat* li);
int insere_lista_float_final(ListaFloat* li, float valor);
ListaFloat* constroi_lista_float(float v[], int n);
void imprime_lista_float(ListaFloat* li);

// EX 5
int remove_valor_especifico(Lista* li, int valor);

// EX 6
int concatena(Lista* l1, Lista* l2);

// EX 7
int remove_repetidos(Lista* li);

// EX 8
int fusao(Lista* l1, Lista* l2, Lista* l3);

// EX 9
typedef Lista TipoLista;
typedef struct elemento TipoCelula;

TipoCelula* busca_matricula(Lista* li, int mat);
void Troca(TipoLista* pLista, TipoCelula* p);