#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, vet1[20], vet2[20], vet3[20];
    srand(time(NULL));

    for(i = 0; i < 20; i++){
        vet1[i] = rand() % 100;
        vet2[i] = rand() % 100;
    }

    for(i = 0; i < 20; i++){
        vet3[i] = vet2[i] + vet1[i];
    }

    printf("\n\nVetor 1: ");
    for(i = 0; i < 20; i++){
        printf("%3d ", vet1[i]);
    }

    printf("\n\nVetor 2: ");
    for(i = 0; i < 20; i++){
        printf("%3d ", vet2[i]);
    }

    printf("\n\nVetor 3: ");
    for(i = 0; i < 20; i++){
        printf("%3d ", vet3[i]);
    }
    return 0;
}
