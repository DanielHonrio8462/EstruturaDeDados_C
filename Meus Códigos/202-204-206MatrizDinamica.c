#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int **mat, i, j;

    // Recebe memoria para Ponteiro de inteiros
    mat = malloc(5 * sizeof(int*));
    // Recebe memoria para inteiro
    for(i = 0; i < 5; i++){
        mat[i] = malloc(5 * sizeof(int));
    }
    srand(time(NULL));
    // Lendo a Matriz 
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            *(*(mat + i) + j) = rand() % 100;
            //mat[i][j] = rand() % 100;
        }
    }
    // Imprimindo a Matriz
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%2d ", *(*(mat + i) + j));
           //printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i = 0; i < 5; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}