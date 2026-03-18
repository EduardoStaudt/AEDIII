#include <stdio.h> // pronto

int somatorio(int n){
    if(n < 1){
        printf("n invalido");
        return 0;
    }
    if(n == 1){
        return 1;
    }else{
        return n+=somatorio(n-1);
    }
}

int main(){
    int resultado = somatorio(3);
    printf("%d", resultado); // 6 vai ser igual a do fat da aula
}