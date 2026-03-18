#include <stdio.h> // terminado
// num/10 = outros e num%10 = ultimo 
int qtdDigitos(int num){
    if(num < 10){
        return 10;
    }else{
        return 10 * qtdDigitos(num/10);
    }
}

int inverter(int num){
    if(num == 0){
        return 0;
    }
    if((num % 10) == num){
        return num;
    } else {
        int mult = qtdDigitos(num/10);
        return (num % 10) * mult + inverter((num/10));
    }
}

int main(){
    int num = 561;

    int resultado = inverter(num);
    printf("%d", resultado);
}