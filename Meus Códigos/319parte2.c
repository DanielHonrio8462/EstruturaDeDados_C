#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No* inserir(No *inicio, int x){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x; // novo é um ponteiro do tipo No ->
        novo->proximo = inicio;
    }else{
        printf("Erro ao Alocar espaco!");
    }
    return novo;
}

void inserir2(No **inicio, int x){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x; // novo é um ponteiro do tipo No ->
        novo->proximo = *inicio;
        *inicio = novo;
    }else{
        printf("Erro ao Alocar espaco!");
    }
    return novo;
}

void imprimir(No *inicio){
    if(inicio){
        printf("%d ", inicio->valor);
        imprimir(inicio->proximo);
    }
}

int main() {

    /*
    No x; 
    x.valor = 50; // x é uma variavel do tipo No .
    */

    No *lista = NULL;

    lista = inserir(lista, 10);
    lista = inserir(lista, 50);
    lista = inserir(lista, 100);

    inserir2(&lista, 17);
    inserir2(&lista, 57);
    inserir2(&lista, 107);

    imprimir(lista);

    return 0;
}