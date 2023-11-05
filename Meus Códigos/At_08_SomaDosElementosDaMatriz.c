#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int i, j, soma = 0, mat[5][7];
    // Lendo Matriz
    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            mat[i][j] = rand() % 100;
        }
    }
    // Somando todos os Valores e Imprimindo a Matriz
    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            soma += mat[i][j];
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    // Imprimindo a Soma dos Valores
    printf("\n\nSoma total: %d\n\n", soma);

    return 0;
}