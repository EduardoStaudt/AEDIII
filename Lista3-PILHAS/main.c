#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int main(){
    struct aluno a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    Pilha* pi = cria_Pilha();
    int i;

    printf("Tamanho: %d\n\n", tamanho_Pilha(pi));

    for(i = 0; i < 4; i++)
        insere_Pilha(pi, a[i]);

    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n", tamanho_Pilha(pi));

    for(i = 0; i < 4; i++)
        remove_Pilha(pi);

    printf("Tamanho: %d\n\n", tamanho_Pilha(pi));
    imprime_Pilha(pi);

    for(i = 0; i < 4; i++)
        insere_Pilha(pi, a[i]);

    printf("Tamanho: %d\n\n", tamanho_Pilha(pi));
    imprime_Pilha(pi);

    libera_Pilha(pi);
    system("pause");
    return 0;
/* TESTE consulta_topo_Pilha
    struct aluno topo;
    if(consulta_topo_Pilha(pi, &topo)){
        printf("\nTopo da pilha:\n");
        printf("Matricula: %d\n", topo.matricula);
        printf("Nome: %s\n", topo.nome);
        printf("Notas: %.1f %.1f %.1f\n\n", topo.n1, topo.n2, topo.n3);
    }

    TESTE pop2
    Pilha* testePop2 = cria_Pilha();
    for(i = 0; i < 4; i++)
        insere_Pilha(testePop2, a[i]);

    printf("\nAntes do pop2:\n");
    imprime_Pilha(testePop2);

    pop2(testePop2);

    printf("\nDepois do pop2:\n");
    imprime_Pilha(testePop2);

    libera_Pilha(testePop2);
    

    TESTE popN
    Pilha* testePopN = cria_Pilha();
    for(i = 0; i < 4; i++)
        insere_Pilha(testePopN, a[i]);

    printf("\nAntes do popN:\n");
    imprime_Pilha(testePopN);

    popN(testePopN, 3);

    printf("\nDepois do popN:\n");
    imprime_Pilha(testePopN);

    libera_Pilha(testePopN);


    TESTE pilha_copia
    Pilha* copia = pilha_copia(pi);

    printf("\nPilha original:\n");
    imprime_Pilha(pi);

    printf("\nCopia da pilha:\n");
    imprime_Pilha(copia);

    libera_Pilha(copia);
    

    TESTE mmm_Pilha
    int maior, menor;
    float media;

    if(mmm_Pilha(pi, &maior, &menor, &media)){
        printf("\nMaior: %d\n", maior);
        printf("Menor: %d\n", menor);
        printf("Media: %.2f\n", media);
    }


    TESTE compara_Pilha
    Pilha* p2 = cria_Pilha();
    for(i = 0; i < 4; i++)
        insere_Pilha(p2, a[i]);

    if(compara_Pilha(pi, p2))
        printf("\nAs pilhas sao iguais.\n");
    else
        printf("\nAs pilhas sao diferentes.\n");

    libera_Pilha(p2);
    

    TESTE par_impar_Pilha
    int pares, impares;

    if(par_impar_Pilha(pi, &pares, &impares)){
        printf("\nPares: %d\n", pares);
        printf("Impares: %d\n", impares);
    }
    

    TESTE texto_inverso_e_palindromo
    texto_inverso_e_palindromo("Socorram me subi no onibus em Marrocos");
    

    TESTE xCy_Pilha
    if(xCy_Pilha("ABABCBA"))
        printf("\nA cadeia esta na forma xCy.\n");
    else
        printf("\nA cadeia nao esta na forma xCy.\n");
    

    TESTE binario_Pilha
    binario_Pilha(10);
    

    TESTE menu_pilha
    menu_pilha();
*/    
}