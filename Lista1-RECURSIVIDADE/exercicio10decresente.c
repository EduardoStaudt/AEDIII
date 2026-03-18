#include <stdio.h> // pronto

void naturaisDec(int n){
    if(n < 0){
        printf("n Invalido");
    }
    if(n == 0){
        printf("%d", n);
    }else{
        printf("%d ", n);
        naturaisDec(n-1);
    }
}

int main(){
    naturaisDec(1000);
}
