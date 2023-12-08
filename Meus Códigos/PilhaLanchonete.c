#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char rua[50];
    int numero;
}Endereco;

typedef struct{
    int id;
    char lanche[50];
    char nomeDaPessoa[50];
    float preco;
    Endereco endereco;
}Pedido;

typedef struct no{
    Pedido pedido; 
    struct no *proximo;
}No;

typedef struct{
    No *topo;
    int tam;
}Pilha;

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

// Procedimento para criar Pilha da Lanchonete
void criarPilha(Pilha *pi){
    pi->topo = NULL;
    pi->tam = 0;
}

// Função Push
void empilhar(Pilha *pi){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->pedido = ler_pedido();
        novo->proximo = pi->topo;
        pi->tam++;
        pi->topo = novo;
    }
    else{
        printf("\nErro ao alocar memoria...\n");
    }
}

No* desempilhar(Pilha *pi){
    if(pi->topo){
        No *remover = pi->topo;
        pi->topo = remover->proximo;
        pi->tam--;
        return remover;
    }
    else{
        printf("\nPilhar vazia\n");
    }
    return NULL;
}

void imprimir_pilha(Pilha *pi){
    No *aux = pi->topo;

    if (pi->topo == NULL) {
        printf("\n------------ PEDIDOS QUANTIDADE: %d -------------\n", pi->tam);
        printf("\n                  Pilha vazia\n");
        printf("\n--------------- FIM DOS PEDIDOS ----------------\n");
        return;
    }

    printf("\n------------ PEDIDOS QUANTIDADE: %d -------------\n", pi->tam);
    while (aux){
        imprimir_pedido(aux->pedido);
        aux = aux->proximo;
    }
    printf("\n--------------- FIM DOS PEDIDOS ----------------\n");
}

void visualizar_topo(Pilha *pi){
    if (pi->topo){
        printf("\nPedido no Topo da Pilha:\n");
        imprimir_pedido(pi->topo->pedido);
    }
    else{
        printf("\nPilha vazia, nenhum pedido para visualizar no topo.\n");
    }
}

void excluirPilha(Pilha *pi) {
    No *atual = pi->topo;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    pi->topo = NULL;
    pi->tam = 0;

    printf("\nPilha excluida com sucesso.\n");
}

int main(){

    No *remover;
    Pilha p;
    int opcao;

    criarPilha(&p);

    do{
        printf("\n------- Menu da Pilha de Pedidos -------\n");
        printf("\n0 - Sair\n1 - Empilhar Pedido\n2 - Desempilhar Pedido\n3 - Imprimir Pedidos\n4 - Visualizar Pedido no Topo\n5 - Excluir Pilha de Pedidos\n");
         printf("\n------- Menu da Pilha de Pedidos -------\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao){
        case 1:
            empilhar(&p);
            break;
        case 2: 
            remover = desempilhar(&p);
            if(remover){
                printf("\nElemento removido com sucesso!\n");
                imprimir_pedido(remover->pedido);

                free(remover);
            }
            else{
                printf("\nSem no a remover.");
            }
            break;
        case 3:
            imprimir_pilha(&p);
            break;
        case 4:
                visualizar_topo(&p);
            break;
        case 5:
                excluirPilha(&p);
            break;
        default:
            if(opcao != 0){
                printf("\nOpcao Invalida!!!\n");
            }
        }
    }while(opcao != 0);

    return 0;
}