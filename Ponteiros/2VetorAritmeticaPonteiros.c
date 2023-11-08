# include <stdio.h>
# include <stdlib.h> 

void imprimirVetor(int *v, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d ", *(v + i));
    }
    printf("\n");
}

void imprimirVetorLetras(char *v, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%c ", *(v + i));
    }
    printf("\n");
}

void preencherVetorInt(int *v, int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Digite um valor Qualquer: ");
        scanf("%d", v + i);
    }
    printf("\n");
}

int main() {

    int vet[10] = {0,1,2,3,4,5,6,7,8,9};
    char letras[10] = {'a','b','c','d','e','f','g','h','i','j'};

    // printf("%p\t%p\n", vet, &vet[0]);

    // "Vet" tem o Endereço de Memoria Igual ao da Primeira Posição do Vetor
    
    // Chamando Procedimento
    preencherVetorInt(vet, 10); 
    /*
    Quando passo "vet", estou passando o endereço, pois é um ponteiro, 
    então o que for modificado lá muda no código todo 
    */
    imprimirVetorLetras(letras, 10);

    return 0;
}