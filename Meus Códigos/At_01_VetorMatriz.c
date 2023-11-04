#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int vet[10];
    int vetQ[10];
    for(i = 0; i < 10; i++){
       printf("Digite o valor da posicao %d: ",i);
       scanf("%d", &vet[i]);
    }
    
    for(i = 0; i < 10; i++){
        vetQ[i] = vet[i] * vet[i];
    }

    printf("\n");
    printf("Esses sao os valores que digitou: ");
    for(i = 0; i < 10; i++){
        printf("%3d ", vet[i]);
    }

    printf("\n");
    printf("Esses sao os valores ao Quadrado: ");
    for (i = 0; i < 10; i++){
        printf("%3d ", vetQ[i]);
    }
    
    return 0;
}