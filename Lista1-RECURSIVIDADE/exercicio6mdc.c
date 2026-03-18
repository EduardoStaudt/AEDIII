#include <stdio.h> // ready

int mdc(int n, int m){
    if(n == m){
        return n;
    }else{
        if(n < m){
            return mdc(n, m - n);
        }else{
            return mdc(n - m, m);
        }
    }
}

int main(){
    printf("MMC = %d ", mdc(12, 36));
}