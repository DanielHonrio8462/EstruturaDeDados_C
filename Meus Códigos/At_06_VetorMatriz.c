#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 9, i, opcao;
    float aux, vet[10];
    // Lendo o Vetor
    for(i = 0; i < 10; i++){
        printf("%d. Digite o numero: ", i + 1);
        scanf("%f", &vet[i]);
    }

    do{
    // Menu
        printf("\n0 - finaliza o programa\n1 - imprimi o vetor na ordem de inicio ao fim\n2 - Imprime o Vetor na ordem Inversa (do fim para o inicio)\nQual numero escolhe? ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao){
        case 0: 
            printf("Programa Finalizado.\n");
            break;
        case 1: 
            for (i = 0; i < 10; i++){
                printf("%.2f ", vet[i]);
            }
            printf("\n");
            break;
        case 2: 
            for ( i = 9; i >= 0; i--){
                printf("%.2f ", vet[i]);
            }
            printf("\n");
            break;
        default:
            printf("Opcao Invalida!\n");
        }
    }while(opcao != 0);
    
    return 0;
}