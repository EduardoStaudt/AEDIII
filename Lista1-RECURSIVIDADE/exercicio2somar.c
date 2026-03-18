#include <stdio.h> /// pronto

int somaVet(int vet[], int n){
    if (n == 0){
        return 0;
    }else{
        return vet[n-1] + somaVet(vet, n-1);
    }
}

int main(){
    int vetor[] = {1, 2, 43, 6, 7}; // = 59

    int resultado = somaVet(vetor, 5); // tamnho
    printf("%d", resultado); //= 59
}