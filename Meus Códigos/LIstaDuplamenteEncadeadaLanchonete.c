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
    struct no *anterior;
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
    // Preenchendo meu No
        novo->pedido = ler_pedido(); 
        novo->proximo = *lista;
        novo->anterior = NULL;
    // Colocando No na Lista no Inicio, o No que já está na Lista, o anterior dele recebe o novo No
        if (*lista){
            (*lista)->anterior = novo;
        }
    // A Lista recebe o novo No, no Inicio
        *lista = novo;
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no fim
void inserir_no_final(No **lista){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){ 
    // Preenchendo meu No
        novo->pedido = ler_pedido();
        novo->proximo = NULL;

    // Verificando se é o primeiro No, para ligar na Lista
        if(*lista == NULL){ 
            *lista = novo;
            novo->anterior = NULL;
    // Não é o primeiro No
        }else{
    // Uso o aux para não perder o conteudo da minha lista 
            aux = *lista; 
    // Percorro minha Lista até "aux->proximo = NULL"
            while(aux->proximo){
                aux = aux->proximo;
            }
    // Ligando meu No na Lista, no fim
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }
    else{
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int ref){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
    // Preenchendo meu No
        novo->pedido = ler_pedido(); 
    // Verificando se é o primeiro No, para ligar na Lista
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
    // Não é o primeiro No
        }else{
    // Uso "aux" para não perder minha Lista
            aux = *lista;
    // Percorro minha Lista ate achar minha referência
            while(aux->pedido.id != ref && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

// Procedimento para inserir Ordenado
void inserir_ordenado(No **lista){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
    // Preenchendo meu No
        novo->pedido = ler_pedido();
    // Verificando se é o Primeiro No, para ligar na Lista
        if(*lista == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
    // Lista não está vazia, Verificando se o novo No é menor do que o Primeiro No da Lista
        }else if(novo->pedido.id < (*lista)->pedido.id){
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista =  novo; 
        }else{
    // Uso "aux" para não perder minha Lista 
            aux = *lista;
    // Verificando se o novo No, é maior que os Nos que estão na Lista
            while(aux->proximo && novo->pedido.id > aux->proximo->pedido.id){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            if(aux->proximo){
                aux->proximo->anterior = novo;
            }
            novo->anterior = aux;
            aux->proximo = novo; // Não posso começar com esse, se não cria um lupi
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
No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
    // Verificando se o primeiro No, é o que eu quero Remover
        if((*lista)->pedido.id == num){
            remover = *lista;
            *lista = remover->proximo;
    // Verificando se após removido o primeiro No, ainda tem No na Lista
            if(*lista){
                (*lista)->anterior = NULL;
            }
    // Verificando se o No que quero Remover está na Lista
        }else{
    // Uso "aux" para não perder minha Lista
            aux = *lista;
            while(aux->proximo && aux->proximo->pedido.id != num){
                aux = aux->proximo;
            }
    // Verificando se o No é o Ultimo
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
    // Verificando se "aux->proximo == NULL" 
                if(aux->proximo){
                    aux->proximo->anterior = aux;
                }
            }
        }
    }

    return remover;
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
void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        imprimir_pedido(no->pedido);
        no = no->proximo;
    }
    printf("\n\n");
}

// Função para retorna o último No
No* ultimoNo(No **lista){
    No *aux = *lista;
    while(aux->proximo){
        aux = aux->proximo;
    }
    return aux; 
}

// Procedimento para Imprimir ao Contrario
void imprimirContrario(No *no){
    printf("\n\tLista: ");
    while(no){
        imprimir_pedido(no->pedido);
        no = no->anterior;
    }
    printf("\n\n");
}

// Procedimento para contar e mostrar a quantidade de nós
void quantidade_de_pedidos(No *lista){
    int count = 0;
    No *aux = lista;

    while(aux){
        count++;
        aux = aux->proximo;
    }
    printf("\nQuantidade de Pedidos na lista: %d\n", count);
}

// Função para excluir todos os nós da lista
void excluir_todos_pedidos(No **lista) {
    No *atual = *lista;
    No *aux;
// Percorro todos os nós, enquanto a cada loop deleto 1
    while (atual != NULL) {
        aux = atual->proximo;
        free(atual);
        atual = aux;
    }

    *lista = NULL; // Atualiza a cabeça da lista para NULL após excluir todos os nós
    printf("\nTodos os Pedidos foram excluidos com sucesso!\n");
}

int main() {

    int opcao, valor, anterior;
    No *removido, *lista = NULL;

    do{
        printf("\n------- Menu da Lista Duplamente Encadeada -------\n");
        printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Final\n\t3 - Inserir no Meio\n\t4 - Inserir Ordenado\n\t5 - Remover Pedido\n\t6 - Imprimir Lista de Pedidos\n\t7 - Buscar Pedido\n\t8 - Imprimir Lista de pedidos ao Contrario\n\t9 - Atualizar Pedido\n\t10 - Quantidade de Pedidos na Lista\n\t11 - Excluir todos os Pedidos\n");
        printf("\n------- Menu da Lista Duplamente Encadeada -------\n");
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
            imprimirContrario(ultimoNo(&lista));
            break;
        case 9:
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
        case 10:
            quantidade_de_pedidos(lista);
            break;
        case 11:
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