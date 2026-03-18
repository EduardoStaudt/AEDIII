#include <stdio.h> // pronto

void par(int n){
    if(n % 2 != 0){
        printf("n Invalido");
    }
    if(n == 0){
        printf("%d", n);
    }else{
        printf("%d ", n);
        par(n-2);
    }
}

int main(){
    par(10);
}