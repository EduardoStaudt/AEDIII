typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// EX1
int totalFolhas_ArvBin(ArvBin *raiz);

// EX2
void imprime_ArvBin(ArvBin *raiz, int nivel);

// EX3
int contaValor_ArvBin(ArvBin *raiz, int valor);

// EX4
void folhasDecrescente_ArvBin(ArvBin *raiz);

// EX5
int iguais_ArvBin(ArvBin *raiz1, ArvBin *raiz2);

// EX6
void removePares_ArvBin(ArvBin *raiz);

// EX7
int similares_ArvBin(ArvBin *raiz1, ArvBin *raiz2);

// EX8
int insere_ArvBinChar(ArvBin* raiz, char valor);
void preOrdem_ArvBinChar(ArvBin *raiz);

// EX9
struct NOExpr* novoNOExpr(char val, struct NOExpr* esq, struct NOExpr* dir);
void libera_NOExpr(struct NOExpr* no);
int calcula_NOExpr(struct NOExpr* no);
void infixa_NOExpr(struct NOExpr* no);
void prefixa_NOExpr(struct NOExpr* no);
void posfixa_NOExpr(struct NOExpr* no);