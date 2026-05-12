// PRIMEIRO QUE ENTRA PRIMEIRO QUE SAI
//.h
struct aluno{
    int matricula;
    char noem[30];
    float n1, n2, n3;
};
typedef struct fila Fila;

//.c
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct fila{
    struct elemento *inicio;// aponta para o primeiro nó da fila
    struct elemento *final;// aponta para o último nó da fila
    int qtd;// guarda a quantidade de elementos
};


//CRIA
Fila* cria_Fila(){ // função que cria uma fila e retorna o endereço dela
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){ // testa o malloc
        fi->inicio = NULL; // fila começa vazia, então inicio aponta para NULL
        fi->final = NULL; // fila começa vazia, então final aponta para NULL
        fi->qtd = 0; // quantidade começa em zero
    }
    return fi; // retorna a fila criada
}

// VERIFICA SE TA VAZIA
int Fila_vazia(Fila* fi){ // verifica se a fila está vazia
    if(fi == NULL) return 1; // se nao existe ta vazia
    if(fi->inicio == NULL) return 1; // inicio null entao nao tem nada dentro
    return 0; // se chegou aqui, tem elemento
}

// PUSH
int insere_Fila(Fila* fi, struct aluno al){ // insere aluno no final da fila
    if(fi == NULL) // verifica se a fila existe
        return 0; // se não existe, retorna falha
    Elem* no = (Elem*) malloc(sizeof(Elem)); // reserva memória para o novo nó
    if(no == NULL) return 0; // testa o malloc
    no->dados = al; // copia os dados do aluno para o novo nó
    no->prox = NULL; // como ele será o último, aponta para NULL
    if(fi->final == NULL){ // se final é NULL, a fila está vazia
        fi->inicio = no; // o novo nó também será o primeiro
    }
    else{ // se for final != de NULL entao nao eh o fim
        fi->final->prox = no; // o antigo último aponta para o novo nó
    }
    fi->final = no; // o final da fila passa a ser o novo nó
    fi->qtd++; // aumenta a quantidade
    return 1; // sucesso
}


// Fila* fi       -> aponta para a estrutura da fila inteira
// fi->inicio     -> aponta para o primeiro nó
// fi->final      -> aponta para o último nó
// Elem* no       -> aponta para um nó
// no->prox       -> aponta para o próximo nó

// VERIFICAR EXISTENCIA
//    if(fi == NULL)
//       return 0;

// VERIFICAR SE ESTA VAZIA
//     if(fi->inicio == NULL)
//       return 0;