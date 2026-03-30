#include <stdio.h> // pronto
#include <stdlib.h>
/*Faça um programa que leia um valor n e crie dinamicamente um vetor de n
elementos e passe esse vetor para uma função que vai ler os elementos
desse vetor. Depois, no programa principal, o vetor preenchido deve ser
impresso. Além disso, antes de finalizar o programa, deve-se liberar a área
de memória alocada.*/

void leitura(int V[], int n){
    for(int i = 0; i < n; i++){
        printf("Qual o valor que vc quer colocar na posicao %d: ", i);
        scanf("%d", &V[i]);
    }
}

int main(){    
    int n, *V;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    V = (int *) malloc(n * sizeof(int));

    leitura(V, n);

    for(int i = 0; i < n; i++){
        printf("%d \n", V[i]);
    }
    free(V); // liberasndo o espaco de memoria
    return 0;
}