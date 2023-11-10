#include <stdio.h>
#include <stdlib.h>

int main() {

    int *vet1, *vet2, i;

    vet1 = malloc(10 * sizeof(int)); // malloc separa espaço de memoria
    vet2 = calloc(10, sizeof(int)); // calloc separa espaço de memoria e limpa esse espaço

    printf("\nCom malloc: ");
    for(i = 0; i < 10; i++){
        printf("%d ", vet1[i]);
    }

    printf("\nCom calloc: ");
    for(i = 0; i < 10; i++){
        printf("%d ", vet2[i]);
    }

    return 0;
}

