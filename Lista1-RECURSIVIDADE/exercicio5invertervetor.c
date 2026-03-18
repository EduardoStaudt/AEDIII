#include <stdio.h>

float inverterVet(float vetor[],int n, int m){
    float temp;

    if(n <= m){
        return 0;
    } else {
        temp = vetor[n];
        vetor[n] = vetor[m];
        vetor[m] = temp;
        return inverterVet(vetor, n-1, m+1);
    }
}

int main(){
    float vet[100];

    for(int i = 0; i<100; i++){
        vet[i] = i+1;
    }
    for (int i = 0; i < 100; i++) {
        printf("%.2f \n", vet[i]);
    }

    inverterVet(vet, 99, 0);

    for (int i = 0; i < 100; i++) {
        printf("%.2f \n", vet[i]);
    }
}