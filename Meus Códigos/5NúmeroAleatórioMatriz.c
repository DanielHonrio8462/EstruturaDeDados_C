#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
     
    srand(time(NULL)); // Função srand é a semente, por conta da Função time vai ficar variando
    int i, j;
    int mat1[3][3] = {11,12,13,14,15,16,17,18,19};

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){ 
        mat1[i][j] = 1 + rand() % 99; 
        }   
    }
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%5d ", mat1[i][j]); 
        }
        printf("\n");
    }

    return 0;
}