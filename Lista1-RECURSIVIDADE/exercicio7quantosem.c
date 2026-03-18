#include <stdio.h> // pronto

int quantosTem(int n, int k){
    if(n < 10){
        if(n%10 == k){return 1; }else{return 0; };
    }else{
        if(n%10 == k){return 1 + quantosTem(n/10, k); }else{return quantosTem(n/10, k); };
    }
}

int main(){
    printf("%d", quantosTem(1534554321, 5)); // 3
}