# include <stdio.h>
# include <stdlib.h>
# define tam 4 // Constante definida

int main() {

    int l, c, total, soma, falhou = 0;
    int mat[tam][tam] = {16, 3, 2, 13, 5, 10, 11, 8, 9, 6, 7, 12, 4, 15, 14, 1};

    /*Diagonal Principal*/
    soma = 0;
    for(l = 0; l < tam; l++){
        soma += mat[l][l];
    }
    printf("\nDiagonal Principal: %d\n", soma);
    total = soma;

    /*Diagonal Secundaria*/
    soma = 0;
    for(l = 0; l < tam; l++){
        soma += mat[l][tam - 1 - l];
    }
    printf("\nDiagonal Secundaria: %d\n", soma);
    if(total != soma){
        printf("Diagonal Secundaria e Diferente\n");
        falhou = 1;
    }

    /*Linhas*/
    for(l = 0; l < tam; l++){
        soma = 0;
        for(c = 0; c < tam; c++){
            soma += mat[l][c];
        }
        printf("\nLinha %d: %d\n", l, soma);
        if(total != soma){
            printf("A linha %d e Diferente!\n");
            falhou = 1;
        }
    }

    /*Colunas*/
    for(l = 0; l < tam; l++){
        soma = 0; 
        for(c = 0; c < tam; c++){
            soma += mat[c][l];
        }
        printf("\nColuna %d: %d\n", c, soma);
        if(total != soma){
            printf("A linha %d e Diferente!\n");
            falhou = 1;
        }
    }

    /*Matriz*/
    printf("\nMatriz:\n");
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            printf("%2d ", mat[l][c]);
        }
        printf("\n");
    }
    
    /*Verificando se é um Quadrado Magico*/
    if(falhou == 0){
        printf("\nE um Quadrado Magico!\n");
    }else{
        printf("\nNao e um Quadrado Magico!\n");
    }

    return 0;
}