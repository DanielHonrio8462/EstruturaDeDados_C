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
    No *inicio;
    No *fim;
    int tam;
}Lista;
    
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

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

// Procedimento para inserir no início
void inserir_no_inicio(Lista *lista){
    No *novo = malloc(sizeof(No));

    if(novo){
    // Preenchendo meu No
        novo->pedido = ler_pedido(); 
        novo->proximo = lista->inicio;
        lista->inicio = novo;

    // Verificando se o novo No é o ultimo e add no Ponteiro "fim"
        if (lista->fim == NULL){
            lista->fim = novo;
        }
    // Ligando ao inicio da Lista
        lista->fim->proximo = lista->inicio;
        lista->tam++;
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no fim
void inserir_no_final(Lista *lista){
    No *novo = malloc(sizeof(No));

    if(novo){ 
    // Preenchendo meu No
        novo->pedido = ler_pedido();
        
    // Verificando se é o primeiro No, para ligar na Lista
        if(lista->inicio == NULL){ 
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
    // Não é o primeiro No, add o novo No ao ultimo No e ligando ao ponteiro fim e ponteiro inicio
        }else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            // lista->fim->proximo = lista->inicio;
            novo->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no meio
void inserir_no_meio(Lista *lista, int ref){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
    // Preenchendo meu No
        novo->pedido = ler_pedido(); 
    // Verificando se é o primeiro No, para ligar na Lista
        if(lista->inicio == NULL){
    // Se a lista está vazia, o novo nó será o início e o fim
           inserir_no_inicio(lista);
        }else{
    // Uso "aux" para não perder minha Lista
            aux = lista->inicio;
    // Percorro minha Lista ate achar minha referência
            while(aux->pedido.id != ref && aux->proximo != lista->inicio){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
    // Atualizar o fim se o novo nó for inserido no final da lista
            if(aux == lista->inicio){
                lista->fim = novo;
           }
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

// Procedimento para inserir Ordenado
void inserir_ordenado(Lista *lista){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
    // Preenchendo meu No
        novo->pedido = ler_pedido();
    // Verificando se é o Primeiro No, para ligar na Lista
        if(lista->inicio == NULL){
            inserir_no_inicio(lista);
    // Lista não está vazia, Verificando se o novo No é menor do que o Primeiro No da Lista
        }else if(novo->pedido.id < lista->inicio->pedido.id){
            inserir_no_inicio(lista);
        }else{
    // Uso "aux" para não perder minha Lista 
            aux = lista->inicio;
    // Verificando se o novo No, é maior que os Nos que estão na Lista
            while(aux->proximo != lista->inicio && novo->pedido.id > aux->proximo->pedido.id){
                aux = aux->proximo;
            }
            if(aux->proximo == lista->inicio){
                inserir_no_final(lista);
            }else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
        }   
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

// Função para atualizar nó
void atualizar_no(No *no){
    if(no){
        no->pedido = ler_pedido();
        printf("\nPedido atualizado com sucesso!\n");
    }
    else{
        printf("\nPedido nao encontrado\n");
    }
}

// Função para remover 
No* remover(Lista *lista, int num){
    No *aux, *remover = NULL;

    if(lista->inicio){
    // Removendo o único Nó que tem na Lista
        if(lista->inicio == lista->fim && lista->inicio->pedido.id == num){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
    // Removendo o Primeiro Nó da Lista
        }else if(lista->inicio->pedido.id == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }else{
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->pedido.id != num){
                aux = aux->proximo;
            }
            if(aux->proximo->pedido.id == num){
    // Removendo no fim
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
    // Removendo no meio
                }else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
        }
    }

    return remover;
}

// Função para buscar
No* buscar(Lista *lista, int num){
    No *aux = lista->inicio;
// Faz primeiro, depois verifica
    if(aux){
        do{
            if(aux->pedido.id == num){
                return aux;
            }
            aux = aux->proximo;
        }while(aux != lista->inicio);
    }
    return NULL;
}

// Procedimento para imprimir
void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\n\tLista -> Quantidade de Pedidos : %d\n", lista.tam);
    if(no){
        do{
            imprimir_pedido(no->pedido);
            no = no->proximo;
        }while(no != lista.inicio);
    }
    printf("\n\n");
}

// Procedimento para excluir todos os pedidos
void excluir_todos_pedidos(Lista *lista) {
    No *atual = lista->inicio;
    No *proximo;

    if (atual != NULL) {
        do {
            proximo = atual->proximo;  // Salva o próximo nó antes de liberar a memória
            free(atual);  // Libera a memória do nó atual
            atual = proximo;  // Move para o próximo nó
        } while (atual != lista->inicio);
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;

    printf("Todos os pedidos foram excluidos.\n");
}

int main() {

    int opcao, valor, anterior;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do{
        printf("\n------- Menu da Lista Circular -------\n");
        printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Final\n\t3 - Inserir no Meio\n\t4 - Inserir Ordenado\n\t5 - Remover Pedido\n\t6 - Imprimir Lista de Pedidos\n\t7 - Buscar Pedido\n\t8 - Atualizar Pedido\n\t9 - Excluir todos os Pedidos\n");
        printf("\n------- Menu da Lista Circular -------\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            inserir_no_inicio(&lista);
            break;
        case 2: 
            inserir_no_final(&lista);
            break;
        case 3:
            printf("Depois de qual Pedido quer Adicionar o novo Pedido, Digite o Id: ");
            scanf("%d", &anterior);
            inserir_no_meio(&lista, anterior);
            break;
        case 4:
            inserir_ordenado(&lista);
            break;
        case 5:
            printf("Qual Pedido quer Remover, Digite o Id: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Pedido a ser Removido: \n");
                imprimir_pedido(removido->pedido);
                free(removido);
            }
            break;
        case 6:
            imprimir(lista);
            break;
        case 7:
            printf("Qual Pedido quer Buscar, Digite o Id: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido){
                printf("Pedido encontrado: \n");
                imprimir_pedido(removido->pedido);
            }
            else{
                printf("Pedido Nao encontrado\n");
            }
            break;
        case 8:
            printf("Qual Pedido quer Atualizar, Digite o Id: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido){
                printf("Atualize o Pedido: ");
                atualizar_no(removido);
            }
            else{
                printf("Pedido nao encontrado\n");
            }
            break;
        case 9:
            excluir_todos_pedidos(&lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}