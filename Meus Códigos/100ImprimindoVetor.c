#include <stdio.h>
#include <Stdlib.h>

int main() {

    int i;    
    int num2[] = {1,5,9,15,43};
    char vogais[5] = {'a','e','i','o','u'};
    float notas[3] = {7.5,8.3,9.5}; 

    // Para imprimir um Vetor, se usa o comando "printf"
    // Para pular a linha, se usa o "printf("\n");"

    for(i = 0; i < 5; i++)
        printf("%d ", num2[i]);

    printf("\n\n");
    for(i = 0; i < 5; i++)
        printf("%c ", vogais[i]);

    printf("\n\n");
    for(i = 0; i < 3; i++)
        printf("%.2f, ", notas[i]);

    return 0;
}
