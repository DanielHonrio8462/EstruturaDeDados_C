#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int tamL = 10, tamC = 10;
    int l, c, mat[tamL][tamC];

    srand(time(NULL));
    // Lendo Matriz
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            mat[l][c] = rand() % 100;
        }
    }
    // Imprimindo Matriz
    printf("\nMatriz:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%2d ", mat[l][c]);
        }
        printf("\n");
    }
    // Imprimindo Abaixo da Diagonal Principal
    printf("\nAbaixo da Diagonal Principal:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            if(l > c){
                printf("%2d ", mat[l][c]);
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}