#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int soma, somaColuna[10], somaLinha[5], l, c, mat[5][10];

    srand(time(NULL));

    for(l = 0; l < 5; l++){
        for(c = 0; c < 10; c++){
            mat[l][c] = rand() % 100;
        }
    }

    // Letra A = Soma das Linhas
    for(l = 0; l < 5; l++){
        soma = 0;
        for(c = 0; c < 10; c++){
             soma += mat[l][c];
        }
        somaLinha[l] = soma;
    }

    // Letra B = Soma das Colunas
    for(c = 0; c < 10; c++){
        soma = 0;
        for(l = 0; l < 5; l++){
             soma += mat[l][c];
        }
        somaColuna[c] = soma;
    }
    // Imprimindo a Matriz
    printf("\nMatriz:\n");
    for(l = 0; l < 5; l++){
        for(c = 0; c < 10; c++){
           printf("%2d ", mat[l][c]);
        }
        printf("\n");
    }
    // Imprimindo Soma das Linhas
    printf("\nVetor com a Soma das Linhas:\n");
    for(l = 0; l < 5; l++){
        printf("Linha %d: %2d\n", l, somaLinha[l]);
    }
    // Imprimindo Soma das Colunas
    printf("\nVetor com a soma das Colunas:\n");
    for(c = 0; c < 10; c++){
        printf("Coluna %d: %2d\n", c, somaColuna[c]);
    }

    return 0;
}