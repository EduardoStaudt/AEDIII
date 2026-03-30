#include <stdio.h> // pronto

//2) Escreva um comentário em cada comando de atribuição explicando o que
//ele faz e o valor da variável à esquerda do '=' após sua execução.

int main()
{
    int y, *p, x;  // declara duas variaveis x e y int e um ponteiro int *p
    y = 0; // atribui a variavel int y o valor 0
    p = &y; // o ponteiro p recebe o enereco de y
    x = *p; // a varivel x recebe o valor interno apontado pelo *p no caso o valor de y que eh 0
    x = 4; // agora x deixa de valer 0 e passa a valer 4
    (*p)++; // aqui o valor interno *p = y que eh 0, recebe um incremento, fazendo o seu valor interno ser 1 agora
    x--; // agora x que possui o valor de 4 eh decrementado passando a ser 3
    (*p) += x; // agora o valor interno apontado por p recebe a adicao do valor armazendo em x (1(*p e y) + 3(x) = 4(novo valor de y))
    printf ("y = %d\n", y); // printa na tela o valor armazenado em y que eh 4
    return(0); // encerra o programa
} 