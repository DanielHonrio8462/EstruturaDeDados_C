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

// Procedimento para inserir no início
void inserir_no_inicio(No **lista){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->pedido = ler_pedido(); 
        novo->proximo = *lista;
        *lista = novo;
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no fim
void inserir_no_final(No **lista){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){ // Preencho meu No e depois ligo na minha Lista
        novo->pedido = ler_pedido();
        novo->proximo = NULL;

        // É o primeiro?
        if(*lista == NULL){ // Conteudo no main
            *lista = novo;
        }else{
            aux = *lista; // uso o aux para não perder o conteudo da minha lista no main
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->pedido = ler_pedido(); 
        // É o primeiro?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->pedido.id != ant && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// Procedimento para inserir Ordenado
void inserir_ordenado(No **lista){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->pedido = ler_pedido();
        // A lista está vazia
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }   // É o menor?
        else if(novo->pedido.id < (*lista)->pedido.id){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->pedido.id > aux->proximo->pedido.id){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }   
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// Função para atualizar pedido
void atualizar_pedido(No *lista, int num){
    No *aux = lista;

    while(aux && aux->pedido.id != num){
        aux = aux->proximo;
    }

    if(aux){
        // Pedido encontrado para atualização
        Pedido novoPedido = ler_pedido();
        aux->pedido = novoPedido;
        printf("\nPedido atualizado com sucesso!\n");
    }
    else{
        printf("\nPedido não encontrado\n");
    }
}

// Função para remover 
No* remover(No **lista, int num){
    No *aux, *remove = NULL;

    if(*lista){
        if((*lista)->pedido.id == num){
            remove = *lista;
            *lista = remove->proximo;
        } 
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->pedido.id != num){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remove = aux->proximo;
                aux->proximo = remove->proximo;
            }
        }
    }

    return remove;
}

// Função para buscar
No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;
    while(aux && aux->pedido.id != num){
        aux = aux->proximo;
    }
    if(aux){
        no = aux;
    }
    return no;
}

// Procedimento para imprimir
void imprimir_lista(No *no){
    printf("\n\tLista: ");
    while(no){
        imprimir_pedido(no->pedido);
        no = no->proximo;
    }
    printf("\n");
}

int main(){

    int opcao, valor, anterior;
    No * removido, *lista = NULL;
    Pedido teste;

    do{
        printf("\n------- Menu da Lista Encadeada -------\n");
        printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Meio\n\t3 - Inserir no Final\n\t4 - Inserir Ordenado\n\t5 - Remover Pedido da Lista\n\t6 - Buscar Pedido\n\t7 - Imprimir Lista\n\t8 - Atualizar Pedido\n");
        printf("\n------- Menu da Lista Encadeada -------\n");
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            inserir_no_inicio(&lista);
            break;
        case 2:
            printf("Apos qual Pedido, Digite o Id: ");
            scanf("%d", &anterior);
            inserir_no_meio(&lista, anterior);  
            break;
        case 3:
            inserir_no_final(&lista);
            break;
        case 4: 
            inserir_ordenado(&lista);
            break;
        case 5:
            printf("Digite o Id do Pedido que quer Remover: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("\nPedido a ser removido: ");
                imprimir_pedido(removido->pedido);
                printf("\n");
                free(removido);
            }
            else{
                printf("\nPedido Nao encontrado\n");
            }
            break;
        case 6:
            printf("Qual Pedido quer Buscar, Digite o Id: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido){
                printf("\nPedido encontrado: ");
                imprimir_pedido(removido->pedido);
                printf("\n");
            }
            else{
                printf("\nPedido Nao encontrado\n");
            }
            break;
        case 7:
            imprimir_lista(lista);
            break;
        case 8:
            printf("Qual Pedido quer Atualizar, Digite o Id: ");
            scanf("%d", &valor);
            atualizar_pedido(lista, valor);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);
        
    return 0;
}