#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(){

    // EX 1 - a)
    // Lista *li = cria_lista();
    // struct aluno al;
    // struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4},
    //                      {3,"Ana",5.7,6.1,7.4}};
    // int i;
    // for(i = 0; i < 4; i++)
    //     insere_lista_final(li,a[i]);
    // if(consulta_lista_matricula(li,4,&al)){
    //     printf("Aluno encontrado:\n");
    //     printf("Matricula: %d\n",al.matricula);
    //     printf("Nome: %s\n",al.nome);
    //     printf("Notas: %.2f %.2f %.2f\n",al.n1,al.n2,al.n3);
    // }
    // else{
    //     printf("Aluno nao encontrado\n");
    // }
    // libera_lista(li);


    // EX 1 - b)
    // Lista *li = cria_lista();
    // struct aluno al;
    // struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4},
    //                      {3,"Ana",5.7,6.1,7.4}};
    // int i;
    // for(i = 0; i < 4; i++)
    //     insere_lista_final(li,a[i]);
    // if(consulta_lista_posicao(li,2,&al)){
    //     printf("Aluno encontrado na posicao:\n");
    //     printf("Matricula: %d\n",al.matricula);
    //     printf("Nome: %s\n",al.nome);
    //     printf("Notas: %.2f %.2f %.2f\n",al.n1,al.n2,al.n3);
    // }
    // else{
    //     printf("Posicao invalida\n");
    // }
    // libera_lista(li);


    // EX 2 - primeira funcao recursiva
    // Lista *li = cria_lista();
    // struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4},
    //                      {3,"Ana",5.7,6.1,7.4}};
    // int i;
    // for(i = 0; i < 4; i++)
    //     insere_lista_final(li,a[i]);
    // printf("Lista antes:\n");
    // imprime_lista(li);
    // remove_lista_recursiva(li,4);
    // printf("Lista depois:\n");
    // imprime_lista(li);
    // libera_lista(li);


    // EX 2 - segunda funcao recursiva
    // Lista *l1 = cria_lista();
    // Lista *l2 = cria_lista();
    // struct aluno a[3] = {{1,"A",0,0,0},
    //                      {2,"B",0,0,0},
    //                      {3,"C",0,0,0}};
    // int i;
    // for(i = 0; i < 3; i++){
    //     insere_lista_final(l1,a[i]);
    //     insere_lista_final(l2,a[i]);
    // }
    // if(listas_iguais_recursiva(l1,l2))
    //     printf("As listas sao iguais\n");
    // else
    //     printf("As listas sao diferentes\n");
    // libera_lista(l1);
    // libera_lista(l2);


    // EX 3
    // Lista *li = cria_lista();
    // struct aluno a[3] = {{1,"A",0,0,0},
    //                      {3,"C",0,0,0},
    //                      {4,"D",0,0,0}};
    // struct aluno novo = {2,"B",0,0,0};
    // int i;
    // for(i = 0; i < 3; i++)
    //     insere_lista_final(li,a[i]);
    // insere_valor(li,novo,2);
    // imprime_lista(li);
    // libera_lista(li);


    // EX 4
    // float v[4] = {5.5,8,9.1,25};
    // ListaFloat *li = constroi_lista_float(v,4);
    // imprime_lista_float(li);
    // libera_lista_float(li);


    // EX 5
    // Lista *li = cria_lista();
    // struct aluno a[6] = {{1,"A",0,0,0},
    //                      {2,"B",0,0,0},
    //                      {2,"C",0,0,0},
    //                      {3,"D",0,0,0},
    //                      {2,"E",0,0,0},
    //                      {4,"F",0,0,0}};
    // int i;
    // for(i = 0; i < 6; i++)
    //     insere_lista_final(li,a[i]);
    // printf("Lista antes:\n");
    // imprime_lista(li);
    // printf("Removidos: %d\n",remove_valor_especifico(li,2));
    // printf("Lista depois:\n");
    // imprime_lista(li);
    // libera_lista(li);


    // EX 6
    // Lista *l1 = cria_lista();
    // Lista *l2 = cria_lista();
    // struct aluno a[2] = {{1,"A",0,0,0},
    //                      {2,"B",0,0,0}};
    // struct aluno b[2] = {{3,"C",0,0,0},
    //                      {4,"D",0,0,0}};
    // int i;
    // for(i = 0; i < 2; i++){
    //     insere_lista_final(l1,a[i]);
    //     insere_lista_final(l2,b[i]);
    // }
    // concatena(l1,l2);
    // printf("Lista concatenada:\n");
    // imprime_lista(l1);
    // libera_lista(l1);
    // libera_lista(l2);


    // EX 7
    // Lista *li = cria_lista();
    // struct aluno a[6] = {{1,"A",0,0,0},
    //                      {2,"B",0,0,0},
    //                      {1,"A2",0,0,0},
    //                      {3,"C",0,0,0},
    //                      {2,"B2",0,0,0},
    //                      {4,"D",0,0,0}};
    // int i;
    // for(i = 0; i < 6; i++)
    //     insere_lista_final(li,a[i]);
    // printf("Lista antes:\n");
    // imprime_lista(li);
    // printf("Repetidos removidos: %d\n",remove_repetidos(li));
    // printf("Lista depois:\n");
    // imprime_lista(li);
    // libera_lista(li);


    // EX 8
    // Lista *l1 = cria_lista();
    // Lista *l2 = cria_lista();
    // Lista *l3 = cria_lista();
    // struct aluno a[3] = {{1,"A",0,0,0},
    //                      {3,"C",0,0,0},
    //                      {5,"E",0,0,0}};
    // struct aluno b[3] = {{2,"B",0,0,0},
    //                      {4,"D",0,0,0},
    //                      {6,"F",0,0,0}};
    // int i;
    // for(i = 0; i < 3; i++){
    //     insere_lista_final(l1,a[i]);
    //     insere_lista_final(l2,b[i]);
    // }
    // fusao(l1,l2,l3);
    // printf("Lista ordenada final:\n");
    // imprime_lista(l3);
    // libera_lista(l1);
    // libera_lista(l2);
    // libera_lista(l3);


    // EX 9
    Lista *li = cria_lista();
    TipoCelula *p;
    struct aluno a[5] = {{1,"A",0,0,0},
                            {2,"B",0,0,0},
                            {3,"C",0,0,0},
                            {4,"D",0,0,0},
                            {5,"E",0,0,0}};
    int i;

    for(i = 0; i < 5; i++)
        insere_lista_final(li,a[i]);

    printf("Lista antes:\n");
    imprime_lista(li);

    p = busca_matricula(li,3);

    Troca(li,p);

    printf("Lista depois:\n");
    imprime_lista(li);

    libera_lista(li);

    system("pause");
    return 0;
}


// gcc main.c ListaDinEncad.c -o main.exe
// .\main.exe