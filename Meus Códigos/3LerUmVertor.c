#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int num2[10];

    // Para ler um vetor se usa o comando "scanf"

    for(i = 0; i < 10; i++){
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &num2[i]);
    }

    printf("\n");
    for(i = 0; i < 10; i++){
         printf("%d ", num2[i]);
    }
       
    return 0;
}