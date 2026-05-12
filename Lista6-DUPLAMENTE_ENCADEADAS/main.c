#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

int main(){
    struct aluno a[5] = {
        {2, "Andre", 9.0, 7.8, 8.5},
        {4, "Ricardo", 7.0, 8.7, 6.8},
        {1, "Bianca", 9.0, 6.7, 8.4},
        {3, "Ana", 5.0, 6.1, 7.4},
        {5, "Carlos", 9.0, 8.1, 7.2}
    };

    int i;

    /*
    //EX1

    Lista* li = cria_lista();

    for(i = 0; i < 5; i++){
        insere_lista_final(li, a[i]);
    }

    printf("Lista antes de remover:\n");
    imprime_lista(li);

    remove_lista(li, 3);

    printf("Lista depois de remover a matricula 3:\n");
    imprime_lista(li);

    libera_lista(li);
    */

    /*
    // EX2

    Lista* li = cria_lista();

    for(i = 0; i < 5; i++){
        insere_lista_ordenada(li, a[i]);
    }

    printf("Lista ordenada:\n");
    imprime_lista(li);

    libera_lista(li);
    */

    /*
    //EX3

    Lista* li = cria_lista();

    for(i = 0; i < 5; i++){
        insere_lista_final(li, a[i]);
    }

    printf("Lista:\n");
    imprime_lista(li);

    printf("Quantidade com n1 igual a 9: %d\n", conta_lista_nota(li, 9));

    libera_lista(li);
    */

    /*
    // EX4
    Lista* lc = cria_lista();

    for(i = 0; i < 5; i++){
        insere_lista_final_circular(lc, a[i]);
    }

    printf("Lista circular:\n");
    imprime_lista_circular(lc);

    remove_lista_inicio_circular(lc);

    printf("Depois de remover no inicio:\n");
    imprime_lista_circular(lc);

    remove_lista_final_circular(lc);

    printf("Depois de remover no final:\n");
    imprime_lista_circular(lc);

    while(lc != NULL && (*lc) != NULL){
        remove_lista_inicio_circular(lc);
    }

    free(lc);
    */

    //EX5
    noDesc fila;
    int valor;
    if(inicializa_noDesc(&fila)){
        enfileirar(&fila, 10);
        enfileirar(&fila, 20);
        enfileirar(&fila, 30);
        enfileirar(&fila, 40);
        printf("Desenfileirando:\n");

        while(desenfileirar(&fila, &valor)){
            printf("Saiu: %d\n", valor);
        }
        free(fila);
    }
    else{
        printf("Erro ao criar fila\n");
    }

    system("pause");

    return 0;
}
