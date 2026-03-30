#include <stdio.h> // pronto
#include <stdlib.h>
/* Crie um vetor V com n inteiros, onde n é um valor inteiro fornecido pelo usuário. O vetor só deve ser alocado na memória depois que o usuário fornecer o valor de n */
int main(){
    
    int n, *V;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    V = (int *) malloc(n * sizeof(int));

    //Comecei coloando ponteiro porque quando o programa usa malloc ele cria o vetor na memória e devolve o endereço inicial dele dai uso o ponteiro para guardar esse endereço e conseguir acessar as posições do vetor depois.
    if (V == NULL) {
        printf("F\n"); 
        return 1;
    }else{
        printf("Funcionou"); // o vetor nao [e null]
    }
    free(V);
}