#include <stdio.h> // pronto

int Mullt_Rec(int n1, int n2){
    if(n2 == 1){
        return n1;
    }else{
        return n1 + Mullt_Rec(n1, n2-1);
    }
}

int main(){
    printf("%d ", Mullt_Rec(5, 6));
}