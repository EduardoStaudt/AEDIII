#include <stdio.h> // pronto 
#include <string.h>

int main(){
    char s[10] = "abcde";
    char* cptr;

    cptr = &s[strlen(s) -1];   //&s[9]
    // se nao precisa se importar com os /0 dava pra te feito sem o strlen so com um &s[9] ja que ja tem o tamanho maximo da string
    while(cptr >= s){
        printf("%c", *(cptr--));
    }
}