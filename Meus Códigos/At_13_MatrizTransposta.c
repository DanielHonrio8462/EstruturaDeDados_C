#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int tamL = 5, tamC = 4;
    int l, c, mat[tamL][tamC], trans[tamC][tamL];

    srand(time(NULL));
    // Lendo Matriz
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            mat[l][c] = rand() % 500;
        }
    }
    // Imprimindo Matriz
    printf("\nMatriz Original:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }
    // Calculando Matriz Transposta
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            trans[c][l] = mat[l][c];
        }
    }
    // Imprimindo Matriz Transposta
    printf("\nMatriz Transposta:\n");
    for(l = 0; l < tamC; l++){
        for(c = 0; c < tamL; c++){
            printf("%3d ", trans[l][c]);
        }
        printf("\n");
    }

    return 0;
}