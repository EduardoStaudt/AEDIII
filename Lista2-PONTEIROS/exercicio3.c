#include <stdio.h> // pronto

/* 3) Verifique o programa abaixo. Encontre o seu erro e corrija-o para que escreva o número 10 na tela. */
int main(){
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10;
    printf("\n%d\n", **q);
    return(0);
    // o erro do codigo era que q aponta para p e p aponta para x, mas o que o codigo quer eh o valor 10, que eh o valor de x. Entao *p eh 10 e *q eh p, por isso **q = 10, pois q aponta para p que apontas para o valor de x
}