#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main(){
    // EX 1
    // Fila *f1 = cria_Fila();
    // Fila *f2 = cria_Fila();
    // struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4},
    //                      {3,"Ana",5.7,6.1,7.4}};
    // int i;
    // for(i = 0; i < 4; i++)
    //     insere_Fila(f1,a[i]);
    // separa(f1,f2,4);
    // printf("Fila 1:\n");
    // imprime_Fila(f1);
    // printf("Fila 2:\n");
    // imprime_Fila(f2);
    // libera_Fila(f1);
    // libera_Fila(f2);

    // EX 2 - a)
    // ex2a_fila_de_filas();

    // EX 2 - b)
    // ex2b_fila_de_pilhas();

    // EX 2 - c)
    // ex2c_pilha_de_filas();

    // EX 3
    // Fila *fi = cria_Fila();
    // struct aluno b[4] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4},
    //                      {3,"Ana",5.7,6.1,7.4}};
    // int j;
    // for(j = 0; j < 4; j++)
    //     insere_Fila(fi,b[j]);
    // inverter_fila(fi);
    // imprime_Fila(fi);
    // libera_Fila(fi);

    // EX 4
    // Fila *fi2 = cria_Fila();
    // struct aluno c[3] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4}};
    // struct aluno x = {99,"FuraFila",10,10,10};
    // int k;
    // for(k = 0; k < 3; k++)
    //     insere_Fila(fi2,c[k]);
    // FuraFila(fi2,x);
    // imprime_Fila(fi2);
    // libera_Fila(fi2);

    // EX 5
    // pista_decolagem();

    // EX 6
    // Fila *fa = cria_Fila();
    // Fila *fb = cria_Fila();
    // Fila *fc = cria_Fila();
    // struct aluno a1 = {1,"A",0,0,0};
    // struct aluno a2 = {3,"B",0,0,0};
    // struct aluno a3 = {2,"C",0,0,0};
    // struct aluno a4 = {4,"D",0,0,0};
    // insere_Fila(fa,a1);
    // insere_Fila(fa,a2);
    // insere_Fila(fb,a3);
    // insere_Fila(fb,a4);
    // junta_filas(fa,fb,fc);
    // imprime_Fila(fc);
    // libera_Fila(fa);
    // libera_Fila(fb);
    // libera_Fila(fc);

    // EX 7
    // Fila *fi3 = cria_Fila();
    // struct aluno d[4] = {{2,"Andre",9.5,7.8,8.5},
    //                      {4,"Ricardo",7.5,8.7,6.8},
    //                      {1,"Bianca",9.7,6.7,8.4},
    //                      {3,"Ana",5.7,6.1,7.4}};
    // int m;
    // for(m = 0; m < 4; m++)
    //     insere_Fila(fi3,d[m]);
    // reverso(fi3);
    // imprime_Fila(fi3);
    // libera_Fila(fi3);

    // EX 8
    printf("MENU:\n");
    menu_continuo();

    return 0;
}
// pra rodar
//cd ..
// gcc main.c FilaDin.c -o ProjFilaDin.exe
// .\ProjFilaDin.exe