#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
int main(){
    int eh_digrafo = 1;
    Grafo* gr = cria_Grafo(5, 5, 0);

    insereAresta(gr, 0, 1, eh_digrafo, 0);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    insereAresta(gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo(gr);
    printf("\nBusca \n");

    // EX1 - exemplos de grafos
    // 1a) direcionado: V={A,B,C}, E={(A,B),(B,C),(C,A)}
    //     nao direcionado: V={A,B,C}, E={{A,B},{B,C},{A,C}}
    // 1b) sequencia (1,1,2,3,3,4,4,6) soma=24, 24/2=12 arestas, possivel
    //     sequencia (3,3,3,3,3,5,5,5) soma=30, 15 arestas, possivel
    //     (Fiz no excalidraw é o arquivo Aeropoto anexado aqui na tarefa)

    // EX2 - grafo dos aeroportos (BOS,JFK,ORD,SFO,LAX,DFW,MIA)
    // a) 11 arestas
    // b) 7 vertices
    // c) sim, da pra ir de DFW pra JFK passando por DFW->ORD->... ou direto se tiver
    // d) caminho mais curto MIA->LAX = 611 (direto)
    // e) matriz 7x7 com pesos (desenho feito a mao)
    // f) lista de adjacencia por vertice (desenho feito a mao)
    // g) AGM por PRIM (Fiz no excalidraw é o arquivo Aeropoto anexado aqui na tarefa)

    // EX3 - explicacao das funcoes do Grafo.c
    // a) cria_Grafo: aloca struct, define nro_vertices/grau_max/eh_ponderado
    //    aloca o vetor grau zerado com calloc
    //    aloca matriz arestas[nro_vertices][grau_max]
    //    se for ponderado aloca tambem matriz pesos
    // b) libera_Grafo: libera cada linha de arestas, depois o vetor
    //    se for ponderado libera pesos tambem, depois grau e o struct
    // c) insereAresta: valida limites, coloca dest em arestas[orig][grau[orig]]
    //    se ponderado salva o peso, incrementa grau[orig]
    //    se nao for digrafo chama recursivo trocando orig/dest
    // d) removeAresta: procura dest em arestas[orig], se nao acha retorna 0
    //    decrementa grau e move o ultimo pro lugar do removido
    //    se nao for digrafo chama recursivo

    // EX4 - nova estrutura proposta:
    // typedef struct{
    //     Lista **vet;   // vetor de listas de adjacencia
    //     int nos;       // numero de nos
    //     int ponderado; // flag se tem peso
    // } Grafo;
    // funcoes refeitas:
    // cria_Grafo(nos): aloca vet com nos posicoes, cada uma comeca NULL
    // insereAresta(gr,orig,dest,peso): cria no de lista e coloca no inicio de vet[orig]
    // removeAresta(gr,orig,dest): percorre vet[orig], desliga o no que tem dest
    // vantagem: nao precisa de grau_max fixo, usa so o espaco necessario

    // EX5 - testa PRIM num grafo pequeno ponderado
    // Grafo* gp = cria_Grafo(5, 5, 1);
    // insereAresta(gp, 0, 1, 0, 2);
    // insereAresta(gp, 0, 3, 0, 6);
    // insereAresta(gp, 1, 2, 0, 3);
    // insereAresta(gp, 1, 3, 0, 8);
    // insereAresta(gp, 1, 4, 0, 5);
    // insereAresta(gp, 2, 4, 0, 7);
    // insereAresta(gp, 3, 4, 0, 9);
    // prim_Grafo(gp, 0);
    // libera_Grafo(gp);

    // EX6 - testa encontrar vertice e menor aresta
    Grafo* g6 = cria_Grafo(5, 5, 1);
    insereAresta(g6, 0, 1, 0, 4);
    insereAresta(g6, 0, 2, 0, 2);
    insereAresta(g6, 1, 2, 0, 1);
    insereAresta(g6, 2, 3, 0, 7);
    insereAresta(g6, 3, 4, 0, 3);

    if(encontraVertice_Grafo(g6, 2))
        printf("vertice 2 existe\n");
    else
        printf("vertice 2 nao existe\n");

    if(encontraVertice_Grafo(g6, 10))
        printf("vertice 10 existe\n");
    else
        printf("vertice 10 nao existe\n");

    printf("menor aresta: %.2f\n", arestaMenorPeso_Grafo(g6));
    libera_Grafo(g6);

    libera_Grafo(gr);

    system("pause");
    return 0;
}