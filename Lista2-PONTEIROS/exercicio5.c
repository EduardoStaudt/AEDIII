#include <stdio.h>// pronto
#include <stdlib.h>

/*Crie um programa para manipular vetores com ponteiros. O seu programa deve implementar uma função chamada inverte_vetor, que recebe como parâmetro dois vetores V1 e V2, ambos de tamanho N. A função deve copiar os elementos de V1 para V2 na ordem inversa. Ou seja, se a função receber V1 = {1,2,3,4,5}, a função deve copiar os elementos para V2 na seguinte ordem: V2 = {5,4,3,2,1}. Além disso, a função também deve retornar o maior valor encontrado em V1. A função deve obedecer ao seguinte protótipo: int inverte_vetor(int *v1, int *v2, int n).*/

int inverte_vetor(int *v1, int *v2, int n){
    int maior = v1[0];
    for(int i = 0; i < n; i++){
        v2[i] = v1[n - 1 - i];

        if(v1[i] > maior){
            maior = v1[i];
        }
    }
    return maior;
}

int main(){
    int V1[] = {1, 2, 3, 4, 5};
    int n = sizeof(V1) / sizeof(V1[0]);
    int V2[n]; // quando executa funciona

    int *p1, *p2;
    p1 = V1;
    p2 = V2;

    int resultados = inverte_vetor(p1, p2, n);

    printf("O maior numero eh: %d\n", resultados);
    
    printf("V1:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", V1[i]);
    }
    printf("\nV2:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", V2[i]);
    }

}