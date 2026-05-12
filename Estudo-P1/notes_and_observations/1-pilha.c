// Tipo LIFO - Last In, First Out
/* 
Inserir = empilhar = push
Remover = desempilhar = pop
Consultar = olhar o topo

STRUCTS:
struct elemento -> qque representa cada no da pilha
struct pilha -> que representa a pilha inteira

EX:
*/
// no .h eh isso e os cabesalhos das funcoes
struct aluno {           // Dados do aluno
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct elemento* Pilha;  // Pilha = ponteiro pro nó

// no .c -> sempre nos .c os elementos
struct elemento {        // Nó da pilha
    struct aluno dados;     // Informações do aluno
    struct elemento *prox;  // Ponteiro pro próximo nó
};
typedef struct elemento Elem;  // Apelido pro nó

struct pilha{
    struct elemento *topo; // TEM QUE LEMBRA DO ASTERISCO AQUI
};
typedef struct pilha Pilha;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));  // Aloca ponteiro de ponteiro //
    if(pi != NULL)
        *pi = NULL;                              // Pilha vazia aponta pra NULL
    return pi;
}

// Pilha* pi  -> aponta para a pilha inteira
// pi->topo   -> aponta para o primeiro nó
// Elem* no   -> aponta para um nó
// no->prox   -> aponta para o próximo nó

// Verifica se o molloc de criar pilha funcionou(SE ELA EXISTE)
if(pi == NULL)
    return 0;
// verifica se se a pilha ta vazia ela ta vaiza se o topo aponta pra nNULL
if(pi->topo == NULL)
    return 0;
// Verifica se o malloc do no funcionou
if(no == NULL) // verifica se o malloc funcionou; no = (Elem*) malloc(sizeof(Elem))
    return 0;

//CRIAR NO
Elem* no = (Elem*) malloc(sizeof(Elem)); // cria e reserva memória para o novo nó
if(no == NULL) // verifica se o malloc falhou
    return 0;

// REMOVER SEM PERDER PONTEIRO POP
Elem* no = pi->topo; // salva o nó que será removido
pi->topo = pi->topo->prox; // topo anda para o próximo
free(no); // libera o antigo topo

// VERIFICA SDE A PILHA TA VAZIA FUNC
int Pilha_vazia(Pilha* pi){ // verifica se a pilha está vazia
    if(pi == NULL) // se a pilha nem existe
        return 1; // considera vazia
    if(pi->topo == NULL) // se o topo aponta para NULL ou *pi se nao tiver a struct pilha
        return 1; // pilha está vazia
    return 0; // se chegou aqui, tem elemento
}

//PUSH
int insere_Pilha(Pilha* pi, struct aluno al){ // insere um aluno no topo da pilha
    if(pi == NULL) // verifica se a pilha existe
        return 0; // se não existe, retorna falha
    Elem* no; // cria um ponteiro para o novo nó
    no = (Elem*) malloc(sizeof(Elem)); // reserva memória para o novo nó
    if(no == NULL) // verifica se o malloc falhou
        return 0; // se falhou, retorna falha
    no->dados = al; // copia os dados do aluno para o novo nó
    no->prox = pi->topo; // novo nó aponta para o antigo topo
    pi->topo = no; // topo passa a ser o novo nó
    return 1; // retorna sucesso
}

//CONSULTAR TOPO
int consulta_topo_Pilha(Pilha* pi, struct aluno *al){ // consulta o aluno do topo
    if(pi == NULL) // verifica se a pilha existe
        return 0; // se não existe, retorna falha
    if(pi->topo == NULL) // verifica se a pilha está vazia
        return 0; // se vazia, não tem topo
    *al = pi->topo->dados; // copia os dados do topo para a variável apontada por al
    return 1; // retorna sucesso
}

//LIBERAR PILHA
void libera_Pilha(Pilha* pi){ // libera todos os nós e depois a pilha
    if(pi != NULL){ // só libera se a pilha existir
        Elem* no; // ponteiro auxiliar para remover os nós
        while(pi->topo != NULL){ // enquanto ainda houver nó na pilha
            no = pi->topo; // guarda o nó do topo
            pi->topo = pi->topo->prox; // topo avança para o próximo nó
            free(no); // libera o antigo topo
        }
        free(pi); // libera a estrutura da pilha
    }
}

// IMPRIME PILHA 
void imprime_Pilha(Pilha* pi){ // imprime todos os elementos da pilha
    if(pi == NULL) // verifica se a pilha existe
        return; // se não existe, sai da função
    Elem* no; // cria ponteiro auxiliar
    no = pi->topo; // começa pelo topo da pilha
    while(no != NULL){ // enquanto não chegar no fim
        printf("Matricula: %d\n", no->dados.matricula); // imprime matrícula
        printf("Nome: %s\n", no->dados.nome); // imprime nome
        printf("Notas: %f %f %f\n", no->dados.n1, no->dados.n2, no->dados.n3); // imprime notas
        printf("-----------------------------\n"); // separador visual
        no = no->prox; // avança para o próximo nó
    }
}

// TAMANHO PILHA 
int tamanho_Pilha(Pilha* pi){ // retorna a quantidade de elementos da pilha
    if(pi == NULL) // verifica se a pilha existe
        return 0; // se não existe, tamanho é 0
    int cont = 0; // contador começa em 0
    Elem* no = pi->topo; // começa no topo
    while(no != NULL){ // percorre até o final
        cont++; // conta um nó
        no = no->prox; // avança para o próximo
    }
    return cont; // retorna o total
}

// INVERTE PILHA
int inverte_Pilha(Pilha* pi){ // inverte a própria pilha
    if(pi == NULL) // verifica se a pilha existe
        return 0; // se não existe, retorna falha
    Elem* ant; // ponteiro para o nó anterior
    Elem* atual; // ponteiro para o nó atual
    Elem* prox; // ponteiro para salvar o próximo nó
    ant = NULL; // no começo, o anterior é NULL
    atual = pi->topo; // começamos pelo topo da pilha
    while(atual != NULL){ // enquanto não chegar no fim da pilha
        prox = atual->prox; // salva o próximo nó antes de quebrar a ligação
        atual->prox = ant; // inverte a seta do nó atual
        ant = atual; // o anterior passa a ser o nó atual
        atual = prox; // o atual avança para o próximo salvo
    }
    pi->topo = ant; // o topo passa a ser o último nó visitado
    return 1; // retorna sucesso
}

// WHILE PADRAO
// Elem* no = pi->topo;
// while(no != NULL){
//     // faz alguma coisa
//     no = no->prox;
// }

// Para inverter ponteiros:
// salva próximo -> inverte seta -> anda anterior -> anda atual


int invertePilha(Pilha* pi){
    if(pi == NULL) return 0;
    Elem* temp;
    Elem* no;
    if(no == NULL) return NULL;
    struct aluno al;
    while(pi->topo != NULL){
        no = pi->topo;
        pi = pi->topo->prox;
        no->prox = temp;
        temp = no;
    }
    pi->topo = temp;
    return 1;
}

// poderia me explicarcomo eu sei qual struct e qual typedef fica no .c e qual no .h
// porque nos exemplos do meu professor ele usa typedef struct elmento* Pilha ao em ves de typedef strct pilha Pilha(porque ele nao cria essa sttuct pilha?)
// eu uso o Elem* no so pra criar auxiliar neh?
// eu poderia fazer assim direto Elem* no = (Elem*) malloc(sizeof(Elem))
// Elem* no = pi->topo; aqui ta sendo apontado pro endere;o do topo atual que depois sera apagado isso?
// por ser um tipo elemento eu nao poderia fazer pi->topo = pi->topo->prox
// o que seria o no = pi* e esse pi* nao seria a mesma coisa que pi->topo?
// pi->topo = pi->topo->prox; nao seria a mesma coisa que pi->topo = no->prox? ou no->topo->prox? 
// if((*pi) == NULL) eh a mesma coisa que if(*pi == NULL)?

