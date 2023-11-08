# include <stdio.h>
# include <stdlib.h> 

// Meu No
typedef struct no{
    int valor;
    struct no *proximo;
}No; 

// Minha Lista
typedef struct{
    No *inicio;
    int tam;
}Lista;

// Passando um Endereço/Ponteiro para não perder as modificações
// Inserção no início da lista
void inserirInicio(Lista *lista, int valor){
    No *novo = (No*)malloc((sizeof(No))); 
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
    /*
    "malloc" -> Alocação Dinamica. Espaço suficiente que vou precisar na memoria 
    "sizeof" -> Função. Para o Tamanho de um "No".
    Preciso dizer qual é o retorno dele "(No*)" -> Você está alocando espaço de memoria para um tipo "No" que é um "Ponteiro"
    */
}

// Inserir no final da lista
void inserirFim(Lista *lista, int valor){
    No *no, *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        no = lista->inicio;
        while(no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = novo;
    }
    lista->tam++;
}

// Imprimir a lista 
void imprimir(Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int main() {

    Lista lista;
    int opcao, valor;

    lista.inicio = NULL;
    lista.tam = 0;

    do {
        printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n5 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            printf("Digite um Valor a se Inserido: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            imprimir(&lista);
            break;
        case 3:
            printf("Digite um Valor a se Inserido: ");
            scanf("%d", &valor);
            inserirFim(&lista, valor);
            break;
        case 5: 
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao != 5);

    return 0;
}