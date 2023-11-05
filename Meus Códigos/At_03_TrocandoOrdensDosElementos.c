#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, a, copia, vet[10];
    srand(time(NULL));

    // Lendo o Vetor
    for(i = 0; i < 10; i++){
        printf("Digite %d: ", i);
        scanf("%d", &vet[i]);
    }

    // Imprimindo o  Vetor
    for(i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    };

    // Invertendo o Vetor
    i = 9;
    printf("\n\n");
    for(a = 0 ; a < 5; a++){
        copia = vet[a];
        vet[a] = vet[i];
        vet[i] = copia;
        i--;
    }
    
    // Imprimindo Vetor Invertido
    printf("Vetor trocado: \n");
    for(i = 0; i < 10; i++){
        printf("%d ", vet[i]);
    };

    return 0;
}
