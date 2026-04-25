#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PilhaDin.h" //inclui os Prot�tipos

//Defini��o do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct elementoChar{
    char dado;
    struct elementoChar *prox;
};
typedef struct elementoChar ElemChar;

struct elementoInt{
    int dado;
    struct elementoInt *prox;
};
typedef struct elementoInt ElemInt;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1, no->dados.n2, no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}
//EX1//////////////////////////////////////////////////
int push2(Pilha* pi, struct aluno al1, struct aluno al2){
    if(pi == NULL)
        return 0;

    Elem *no1, *no2;

    no1 = (Elem*) malloc(sizeof(Elem));
    if(no1 == NULL)
        return 0;

    no2 = (Elem*) malloc(sizeof(Elem));
    if(no2 == NULL){
        free(no1);
        return 0;
    }

    no1->dados = al1;
    no2->dados = al2;

    no1->prox = *pi;
    no2->prox = no1;
    *pi = no2;

    return 1;
}

int pop2(Pilha* pi){
    if(pi == NULL || *pi == NULL || (*pi)->prox == NULL)
        return 0;

    Elem *no;

    no = *pi;
    *pi = no->prox;
    free(no);

    no = *pi;
    *pi = no->prox;
    free(no);

    return 1;
}


//EX2/////////////////////////////////////////////////////
int popN(Pilha* pi, int n){
    if(pi == NULL || *pi == NULL || n <= 0)
        return 0;

    Elem *no;
    int i;

    for(i = 0; i < n && *pi != NULL; i++){
        no = *pi;
        *pi = no->prox;
        free(no);
    }

    return 1;
}

//EX3//////////////////////////////////////////////////////////
Pilha *pilha_copia(Pilha *pi){
    if(pi == NULL){
        return NULL;
    }

    Pilha *pi2 = cria_Pilha();
    if(pi2 == NULL){
        return NULL;
    }

    int tam = tamanho_Pilha(pi);
    struct aluno *estudantes = (struct aluno*) malloc(tam * sizeof(struct aluno));
    if(estudantes == NULL){
        libera_Pilha(pi2);
        return NULL;
    }

    Elem *no;
    no = *pi;
    int i = 0;

    while(no != NULL){
        estudantes[i++] = no->dados;
        no = no->prox;
    }

    for(i = tam - 1; i >= 0; i--){
        insere_Pilha(pi2, estudantes[i]);
    }

    free(estudantes);
    return pi2;
}

// EX 4///////////////////////////////////////////////////////////
int mmm_Pilha(Pilha* pi, int *maior, int *menor, float *media){
    if(pi == NULL || *pi == NULL || maior == NULL || menor == NULL || media == NULL)
        return 0;

    Elem *no = *pi;
    int soma = 0, cont = 0;

    *maior = no->dados.matricula;
    *menor = no->dados.matricula;

    while(no != NULL){
        int valor = no->dados.matricula;

        if(valor > *maior) *maior = valor;
        if(valor < *menor) *menor = valor;

        soma += valor;
        cont++;
        no = no->prox;
    }

    *media = (float)soma / cont;
    return 1;
}

// EX 5/////////////////////////////////////////////////////////
int compara_Pilha(Pilha* p1, Pilha* p2){
    if(p1 == NULL || p2 == NULL)
        return 0;

    Elem *no1 = *p1;
    Elem *no2 = *p2;

    while(no1 != NULL && no2 != NULL){
        if(no1->dados.matricula != no2->dados.matricula ||
            strcmp(no1->dados.nome, no2->dados.nome) != 0 ||
            no1->dados.n1 != no2->dados.n1 ||
            no1->dados.n2 != no2->dados.n2 ||
            no1->dados.n3 != no2->dados.n3){
            return 0;
        }

        no1 = no1->prox;
        no2 = no2->prox;
    }

    return (no1 == NULL && no2 == NULL);
}

//EX6/////////////////////////////////////////////////////////////////
void texto_inverso_e_palindromo(const char *texto){
    if(texto == NULL)
        return;

    ElemChar *pilhaTexto = NULL;
    ElemChar *pilhaPal = NULL;
    ElemChar *no;
    char *normal;
    int i, j = 0;
    int palindromo = 1;
    char c;

    normal = (char*) malloc((strlen(texto) + 1) * sizeof(char));
    if(normal == NULL)
        return;

    for(i = 0; texto[i] != '\0'; i++){
        no = (ElemChar*) malloc(sizeof(ElemChar));
        if(no == NULL){
            free(normal);
            while(pilhaTexto != NULL){
                no = pilhaTexto;
                pilhaTexto = pilhaTexto->prox;
                free(no);
            }
            while(pilhaPal != NULL){
                no = pilhaPal;
                pilhaPal = pilhaPal->prox;
                free(no);
            }
            return;
        }

        no->dado = texto[i];
        no->prox = pilhaTexto;
        pilhaTexto = no;

        if(texto[i] != ' ' && texto[i] != '.'){
            c = toupper((unsigned char)texto[i]);
            normal[j++] = c;

            no = (ElemChar*) malloc(sizeof(ElemChar));
            if(no == NULL){
                free(normal);
                while(pilhaTexto != NULL){
                    no = pilhaTexto;
                    pilhaTexto = pilhaTexto->prox;
                    free(no);
                }
                while(pilhaPal != NULL){
                    no = pilhaPal;
                    pilhaPal = pilhaPal->prox;
                    free(no);
                }
                return;
            }

            no->dado = c;
            no->prox = pilhaPal;
            pilhaPal = no;
        }
    }
    normal[j] = '\0';

    printf("Texto invertido: ");
    while(pilhaTexto != NULL){
        no = pilhaTexto;
        printf("%c", no->dado);
        pilhaTexto = pilhaTexto->prox;
        free(no);
    }
    printf("\n");

    for(i = 0; i < j; i++){
        if(pilhaPal == NULL || normal[i] != pilhaPal->dado)
            palindromo = 0;

        if(pilhaPal != NULL){
            no = pilhaPal;
            pilhaPal = pilhaPal->prox;
            free(no);
        }
    }

    if(pilhaPal != NULL)
        palindromo = 0;

    while(pilhaPal != NULL){
        no = pilhaPal;
        pilhaPal = pilhaPal->prox;
        free(no);
    }

    if(palindromo)
        printf("O texto eh palindromo.\n");
    else
        printf("O texto nao eh palindromo.\n");

    free(normal);
}

// EX 7///////////////////////////////////////////////////////////////b
int par_impar_Pilha(Pilha* pi, int *pares, int *impares){
    if(pi == NULL || *pi == NULL || pares == NULL || impares == NULL)
        return 0;

    *pares = 0;
    *impares = 0;

    Elem *no = *pi;

    while(no != NULL){
        if(no->dados.matricula % 2 == 0)
            (*pares)++;
        else
            (*impares)++;

        no = no->prox;
    }

    return 1;
}


// EX 8 ////////////////////////////////////////////////////
int xCy_Pilha(const char *str){
    if(str == NULL)
        return 0;

    ElemChar *pilha = NULL;
    ElemChar *no;
    int i = 0;

    while(str[i] != '\0' && str[i] != 'C'){
        if(str[i] != 'A' && str[i] != 'B'){
            while(pilha != NULL){
                no = pilha;
                pilha = pilha->prox;
                free(no);
            }
            return 0;
        }

        no = (ElemChar*) malloc(sizeof(ElemChar));
        if(no == NULL){
            while(pilha != NULL){
                no = pilha;
                pilha = pilha->prox;
                free(no);
            }
            return 0;
        }

        no->dado = str[i];
        no->prox = pilha;
        pilha = no;
        i++;
    }

    if(str[i] != 'C'){
        while(pilha != NULL){
            no = pilha;
            pilha = pilha->prox;
            free(no);
        }
        return 0;
    }

    i++;

    while(str[i] != '\0'){
        if(str[i] != 'A' && str[i] != 'B'){
            while(pilha != NULL){
                no = pilha;
                pilha = pilha->prox;
                free(no);
            }
            return 0;
        }

        if(pilha == NULL || pilha->dado != str[i]){
            while(pilha != NULL){
                no = pilha;
                pilha = pilha->prox;
                free(no);
            }
            return 0;
        }

        no = pilha;
        pilha = pilha->prox;
        free(no);
        i++;
    }

    if(pilha != NULL){
        while(pilha != NULL){
            no = pilha;
            pilha = pilha->prox;
            free(no);
        }
        return 0;
    }

    return 1;
}

// EX 9 
// EX 9
void binario_Pilha(int num){
    ElemInt *pilha = NULL;
    ElemInt *no;

    if(num < 0){
        printf("Digite um numero inteiro nao negativo.\n");
        return;
    }

    if(num == 0){
        printf("Binario: 0\n");
        return;
    }

    while(num > 0){
        no = (ElemInt*) malloc(sizeof(ElemInt));
        if(no == NULL){
            while(pilha != NULL){
                no = pilha;
                pilha = pilha->prox;
                free(no);
            }
            return;
        }

        no->dado = num % 2;
        no->prox = pilha;
        pilha = no;
        num = num / 2;
    }

    printf("Binario: ");
    while(pilha != NULL){
        no = pilha;
        printf("%d", no->dado);
        pilha = pilha->prox;
        free(no);
    }
    printf("\n");
}

void menu_pilha(){
    Pilha *pi = NULL;
    int op, num;
    struct aluno al;

    do{
        printf("\n1-Inicializa pilha.\n");
        printf("2-Verifica se a pilha e vazia.\n");
        printf("3-Verifica se a pilha e cheia.\n");
        printf("4-Empilha o elemento na pilha.\n");
        printf("5-Desempilha elemento da pilha.\n");
        printf("6-Le topo de uma pilha.\n");
        printf("7-Converte um numero decimal em binario.\n");
        printf("8-Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                if(pi != NULL)
                    libera_Pilha(pi);
                pi = cria_Pilha();
                printf("Pilha inicializada.\n");
                break;

            case 2:
                if(pi == NULL)
                    printf("A pilha ainda nao foi criada.\n");
                else if(Pilha_vazia(pi))
                    printf("A pilha esta vazia.\n");
                else
                    printf("A pilha nao esta vazia.\n");
                break;

            case 3:
                if(pi == NULL)
                    printf("A pilha ainda nao foi criada.\n");
                else if(Pilha_cheia(pi))
                    printf("A pilha esta cheia.\n");
                else
                    printf("A pilha nao esta cheia.\n");
                break;

            case 4:
                if(pi == NULL){
                    printf("Crie a pilha primeiro.\n");
                    break;
                }

                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);

                printf("Digite o nome: ");
                scanf(" %29[^\n]", al.nome);

                printf("Digite a nota 1: ");
                scanf("%f", &al.n1);

                printf("Digite a nota 2: ");
                scanf("%f", &al.n2);

                printf("Digite a nota 3: ");
                scanf("%f", &al.n3);

                if(insere_Pilha(pi, al))
                    printf("Elemento empilhado com sucesso.\n");
                else
                    printf("Erro ao empilhar elemento.\n");
                break;

            case 5:
                if(pi == NULL){
                    printf("Crie a pilha primeiro.\n");
                    break;
                }

                if(remove_Pilha(pi))
                    printf("Elemento removido com sucesso.\n");
                else
                    printf("A pilha esta vazia.\n");
                break;

            case 6:
                if(pi == NULL){
                    printf("Crie a pilha primeiro.\n");
                    break;
                }

                if(consulta_topo_Pilha(pi, &al)){
                    printf("Topo da pilha:\n");
                    printf("Matricula: %d\n", al.matricula);
                    printf("Nome: %s\n", al.nome);
                    printf("Notas: %.2f %.2f %.2f\n", al.n1, al.n2, al.n3);
                }
                else
                    printf("A pilha esta vazia.\n");
                break;

            case 7:
                printf("Digite um numero decimal: ");
                scanf("%d", &num);
                binario_Pilha(num);
                break;

            case 8:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    }while(op != 8);

    if(pi != NULL)
        libera_Pilha(pi);
}