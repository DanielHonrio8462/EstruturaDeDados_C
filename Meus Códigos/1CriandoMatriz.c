#include <stdio.h>
#include <stdlib.h>

int main() {

    int vet[10];

    int mat1[3][3] = {1,2,3,4,5,6,7,8,9};
   /*        c0  c1  c2     
    linha 0 | 1   2   3 |
    linha 1 | 4   5   6 |
    linha 2 | 7   8   9 |
    */

   int mat2[][3] = {1,2,3,4,5,6,7}; // Na terceira linha, o restante dos valores vai ser 0
   int mat3[3][3] = {0}; // Só informei o primeiro valor, o restante vai ser 0

   float mat4[4][5]; // Exemplo
   char mat5[10][10]; // Exemplo

    return 0;
}