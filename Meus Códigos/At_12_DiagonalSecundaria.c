#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int tam = 7;
    int mat[tam][tam], c, l;

    srand(time(NULL));

     for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            mat[l][c] = rand() % 100;
        }
    }

    printf("\nMatriz:\n");
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            printf("%2d ", mat[l][c]);
        }
        printf("\n");
    }

    printf("\nDiagonal Secundaria:\n");
    for(l = 0; l < tam; l++){
        printf("%2d ", mat[l][tam - l - 1]);
    }

    return 0; 
}