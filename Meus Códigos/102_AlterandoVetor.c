#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int num2[3];

    for(i = 0; i < 3; i++){
        printf("Digite o elemento da posicao %d: ", i);
        scanf("%d", &num2[i]);
    }

    printf("\n");   // Multipliquei cada elemento do vetor num2[] por 3          
    for(i = 0; i < 3; i++){
        num2[i] = num2[i] * 3;
    }

    printf("\n");   // Imprimir o vetor alterado
    for(i = 0; i < 3; i++){
         printf("%d ", num2[i]);
    }

    return 0;
}
