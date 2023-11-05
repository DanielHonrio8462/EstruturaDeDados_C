#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int mat[5][5], c, l;

    srand(time(NULL));
    // Lendo a Matriz 5x5
    for(l = 0; l < 5; l++){
        for(c = 0; c < 5; c++){
            mat[l][c] = rand() % 100;
        }
    }
    // Imprimindo a Matriz 
    printf("\nMatriz:\n");
    for(l = 0; l < 5; l++){
        for(c = 0; c < 5; c++){
            printf("%2d ", mat[l][c]);
        }
        printf("\n");
    }
    // Imprimindo a Diagonal Principal
    printf("\nDiagonal Principal:\n");
    for(l = 0; l < 5; l++){
        for(c = 0; c < 5; c++){
            if(l == c){
                printf("%2d ", mat[l][c]);
            } 
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    /*
    Outra forma de Imprimir a Diagonal Principal
        for(l = 0; l < 5; l++){
            printf("%2d ", mat[l][l]);
        }
    */

    return 0; 
}