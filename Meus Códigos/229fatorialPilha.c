#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;


No* empilhar(No *pilha, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->prox = pilha;
        return novo;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->prox;
    }else{
        printf("Pilhar vazia!\n");
    }
    return remover;
}

void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%d\n", pilha->valor);
        pilha = pilha->prox;
    }
    printf("\n");
}

int fatorial(int num){
    No *remover, *pilha = NULL;

    while(num > 1){
        pilha = empilhar(pilha, num);
        num--;
    }

    imprimir(pilha);

    while(pilha){
        remover = desempilhar(&pilha);
        num = num * remover->valor;
        free(remover);
    }
    return num;
}

int main(){
    int valor;

    printf("Digite um valor maior que zero para o fatorial: ");
    scanf("%d", &valor);
    printf("\tFatorial de %d: %d\n", valor, fatorial(valor));

    return 0;
}