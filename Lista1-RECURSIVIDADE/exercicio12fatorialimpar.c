#include <stdio.h> // plonto

int fatImpar(int n){
    if(n%2 == 0){
        printf("N Invalido");
        return 0;
    }

    if(n == 1){
        return 1;
    }else{
        return n * fatImpar(n-2);
    }
}

int main(){
    printf("%d", fatImpar(5));
}