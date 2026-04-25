struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int remove_Fila_retorna(Fila* fi, struct aluno *al);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);

int separa(Fila* f1, Fila* f2, int n);

void ex2a_fila_de_filas();
void ex2b_fila_de_pilhas();
void ex2c_pilha_de_filas();

int inverter_fila(Fila* fi);
int FuraFila(Fila* fi, struct aluno al);

void pista_decolagem();

int junta_filas(Fila* f1, Fila* f2, Fila* f3);

int reverso(Fila* fi);

void menu();
void menu_continuo();