#include <stdio.h> // pronto

int potencia(int k, int n){
    if(n == 1){
        return k;
    }else{
        return k * potencia(k, (n-1));    
    }
}

int main(){
    int resultado = potencia(10, 4);
    printf("%d", resultado); // 1000
}