#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int tam, *vet, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    srand(time(NULL));

    vet = malloc(tam * sizeof(int));
    // Verifica se a alocação foi bem sucedida (malloc)
    if(vet){
        printf("Memoria alocada com Sucesso!\n");
        // Lendo Ponteiro vet
        for(i = 0; i < tam; i++){
            *(vet + i) = rand() % 100;
        }
        // Imprimindo Ponteiro vet
        for(i = 0; i < tam; i++){
            printf("%d ", *(vet + i)); 
        }
        printf("\n");
        // (realloc) Pega o vet existente e coloca em outra área da memoria
    	printf("Digite o novo tamanho do vetor: ");
        scanf("%d", &tam);

        vet = realloc(vet, tam * (sizeof(int)));

        printf("\nVetor realocado:\n");
        for(i = 0; i < tam; i++){
            printf("%d ", *(vet + i)); 
        }
        printf("\n");
        // Recebe o Ponteiro, Ela vai liberar memoria 
        free(vet); 

    }else{
        printf("Erro ao alocar memoria!\n");
    }

    return 0;
}