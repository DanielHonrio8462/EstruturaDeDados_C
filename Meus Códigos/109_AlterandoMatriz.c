#include <stdio.h>
#include <stdlib.h>

int main() {
     
    int i, j;
    int mat1[3][3] = {11,12,13,14,15,16,17,18,1 9}, mat2[3][3] = {1,2,3,4,5,6,7,8,9}, mat3[3][3];
    char mat5[3][4] = {'a','b','c','d','e','f','g','h','i','j','k','l'};

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){ // mat1[i][j] = mat1[i][j] * 2 Multiplicando por 2
        mat3[i][j] = mat1[i][j] + mat2[i][j]; // Somatório de elementos de Matrizes
        }   
    }
    

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%2d ", mat3[i][j]); // %2d -> O 2 diz que esse número inteiro vai ser um decimal de 2
        }
        printf("\n");
    }

    return 0;
}
