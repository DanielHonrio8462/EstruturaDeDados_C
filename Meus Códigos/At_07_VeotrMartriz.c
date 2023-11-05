#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int i, a, aux, vet[100];

    // Lendo Vetor
    for(i = 0; i < 100; i++){
        vet[i] = rand() % 100;
    }
    // Imprimindo Vetor
    printf("\n");
    printf("Vetor de 100 espacos.\n");
    for(i = 0; i < 100; i++){
        printf("%d ", vet[i]);
    }
    // Ordenando Vetor
    for(i = 0; i < 99; i++){
        for(a = i; a < 100; a++){
            if(vet[i] > vet[a + 1]){
                aux = vet[i];
                vet[i] = vet[a + 1];
                vet[a + 1] = aux;
        }
        } 
    }
    // Imprimindo Vetor Ordenado
    printf("\n\nVetor Ordenado:\n");
    for(i = 0; i < 100; i++){
        printf("%d ", vet[i]);
    }
    
    return 0;
}