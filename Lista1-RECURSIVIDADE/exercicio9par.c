#include <stdio.h> // pronto

int par(int n, int m){
    if(n % 2 != 0){
        printf("n Invalido");
        return 0;
    }
    if(n == m){
        printf("%d ", m);
    }else{
        printf("%d ", par(n, m+2));
    }
}

int main(){
    par(10, 0);
}