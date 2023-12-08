#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char rua[50];
    int numero;
} Endereco;

typedef struct{
    int id;
    char lanche[50];
    char nomeDaPessoa[50];
    float preco;
    Endereco endereco;
} Pedido;

typedef struct no{
    Pedido pedido; 
    struct no *proximo;
} No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
} Fila;

Pedido ler_pedido(){
    Pedido p;

    printf("\nDigite o Id do pedido: ");
    scanf("%d", &p.id);
    getchar();
    printf("Digite o pedido: ");
    scanf("%49[^\n]", p.lanche);
    getchar();
    printf("Digite o nome da Pessoa: ");
    scanf("%49[^\n]", p.nomeDaPessoa);
    getchar();
    printf("Digite o valor do pedido: R$ ");
    scanf("%f", &p.preco);
    getchar();
    printf("Digite o local da entrega: Rua e o numero da casa: ");
    scanf("%49[^\n]%d", p.endereco.rua, &p.endereco.numero);
    getchar();

    return p;
}

void imprimir_pedido(Pedido p){
    printf("\nId: %2d\nPedido: %s\nNome da Pessoa: %s\nValor: %.2f\nLocal da entrega: %s - %d", 
           p.id, p.lanche, p.nomeDaPessoa, p.preco, p.endereco.rua, p.endereco.numero);
    printf("\n\n");
}

// Procedimento para criar Fila
void criarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

// Função Enqueue
void enqueue(Fila *fila){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->pedido = ler_pedido();
        novo->proximo = NULL;
        
        if (fila->fim == NULL) {
            // Fila vazia, novo nó é tanto o início quanto o fim
            fila->inicio = novo;
            fila->fim = novo;
        } else {
            // Adiciona o novo nó no final da fila
            fila->fim->proximo = novo;
            fila->fim = novo;
        }

        fila->tam++;
    }
    else{
        printf("\nErro ao alocar memoria...\n");
    }
}

No* dequeue(Fila *fila){
    if (fila->inicio){
        No *remover = fila->inicio;
        fila->inicio = remover->proximo;

        if (fila->inicio == NULL) {
            // A fila ficou vazia após remover o nó, atualize o fim
            fila->fim = NULL;
        }

        fila->tam--;
        return remover;
    }
    else{
        printf("\nFila vazia\n");
    }
    return NULL;
}

void imprimir_fila(Fila *fila){
    No *aux = fila->inicio;
    printf("\n------------ PEDIDOS QUANTIDADE: %d -------------\n", fila->tam);
    while (aux){
        imprimir_pedido(aux->pedido);
        aux = aux->proximo;
    }
    printf("\n--------------- FIM DOS PEDIDOS ----------------\n");
}

// Procedimento para excluir Fila
void excluirFila(Fila *fila) {
    No *atual = fila->inicio;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;

    printf("\nFila excluida com sucesso.\n");
}

int main(){
    No *remover;
    Fila f;
    int opcao;

    criarFila(&f);

    do{
        printf("\n------- Menu da Fila -------\n");
        printf("0 - Sair\n1 - Adicionar Pedido\n2 - Remover Pedido\n");
        printf("3 - Imprimir Pedidos\n4 - Excluir Fila\n");
        printf("------- Menu da Fila -------\n");
        
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
            case 1:
                enqueue(&f);
                break;
            case 2: 
                remover = dequeue(&f);
                if(remover){
                    printf("\nElemento removido com sucesso!\n");
                    imprimir_pedido(remover->pedido);
                    free(remover);
                }
                else{
                    printf("\nSem nó a remover.\n");
                }
                break;
            case 3:
                imprimir_fila(&f);
                break;
            case 4:
                excluirFila(&f);
                break;
            default:
                if(opcao != 0){
                    printf("\nOpção Inválida!!!\n");
                }
        }
    } while(opcao != 0);

    return 0;
}
