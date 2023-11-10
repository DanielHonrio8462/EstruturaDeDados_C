#include <stdio.h>
#include <stdlib.h>

int main() {

    char *x;

    // x = malloc(sizeof(int));
    /*Recebe a Quantidade de bytes que vou precisar para armazenar*/ 
    x = calloc(1, sizeof(char)); 
    /*Recebe para quantos vai precisar alocar e a quantidade de bytes que vai precisar para alocar*/

    // Caso não consiga alocar, ele "return NULL"

    if(x){
        printf("Memoria alocada com sucesso\n");
        printf("x: %c\n", *x);
        *x = 'H';
        printf("x: %c\n", *x);
    }else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}