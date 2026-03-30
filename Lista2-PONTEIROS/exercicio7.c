#include <stdio.h> // pronto
#include <string.h>

struct produto{
    int ID;
    char name[50];
    float price;
};

int main(){
    struct produto lanches[3];
    int IDpedido;

    lanches[0].ID = 1;
    lanches[1].ID = 2;
    lanches[2].ID = 3;

    strcpy(lanches[0].name, "Salada");
    strcpy(lanches[1].name, "Naruto Lamen");
    strcpy(lanches[2].name, "X ratao");

    lanches[0].price = 20.8888;
    lanches[1].price = 10;
    lanches[2].price = 35.99;

    printf("Opcoes\n");
    for(int i = 0; i < 3; i++){
        printf("ID: %d | Nome: %s\n", lanches[i].ID, lanches[i].name);
    }

    printf("Qual o ID do produto que vc quer?\n");
    scanf("%d", &IDpedido);

    for(int i = 0; i < 3; i++){
        if(lanches[i].ID == IDpedido){
            printf("O/A %s custa R$ %.2f\n", lanches[i].name, lanches[i].price);
        }
    }

    return 0;
}