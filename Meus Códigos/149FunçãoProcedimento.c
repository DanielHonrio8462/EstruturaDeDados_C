#include <stdio.h>
#include <stdlib.h>
#define tam 5

// Procedimento para Imprimir Matriz
void imprimir(int m[][5]){
    int i, j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Função para retorna a soma de uma Linha da Matriz
int somarLinha(int m[][5], int l){
    int c, soma = 0;

    for(c = 0; c < tam; c++){
        soma += m[l][c];
    }
    return soma;
}

// Função para retorna a soma de uma Coluna da Matriz
int somarColuna(int mat[][5], int c){
    int l, soma = 0;

    for(l = 0; l < tam; l++){
        soma += mat[l][c];    
    }
    return soma;
}

int main() {

    int mat[5][5];
    int i, j;

    srand(time(NULL));

    // Lendo minha Matriz
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            mat[i][j] = rand() % 10;
        }
    }

    // Chamando meu Procedimento
    imprimir(mat);

    // Chamando minhas Funções
    printf("\n");
    for(i = 0; i < tam; i++){
        printf("Soma da linha %d: %d\n", i, somarLinha(mat, i));
    }

    printf("\n");
    for(i = 0; i < tam; i++){
        printf("Soma da coluna %d: %d\n", i, somarColuna(mat, i));
    }

    return 0;
}
