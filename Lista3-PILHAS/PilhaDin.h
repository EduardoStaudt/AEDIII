//Arquivo PilhaDin.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);

int push2(Pilha* pi, struct aluno al1, struct aluno al2);
int pop2(Pilha* pi);
int popN(Pilha* pi, int n);
Pilha *pilha_copia(Pilha* p);
int mmm_Pilha(Pilha* pi, int *maior, int *menor, float *media);
int compara_Pilha(Pilha* p1, Pilha* p2);
int par_impar_Pilha(Pilha* pi, int *pares, int *impares);
void texto_inverso_e_palindromo(const char *texto);
int xCy_Pilha(const char *str);
void menu_pilha();
void binario_Pilha(int num);