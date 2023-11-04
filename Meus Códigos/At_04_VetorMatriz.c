#include <stdio.h>
#include <stdlib.h>

int main() {
    // Criando as Variáveis e Vetores
    int i, maisVendido = 0, quant[4];
    float valorTotal = 0, comissao = 0, valorParcial = 0, valor[4];
    // Lendo a Quantidade e o Valor do pedido
    for(i = 0; i < 4; i++){
        printf("Digite o valor unitario e a quantidade vendida do Produto %d: ", i);
        scanf("%f%d", &valor[i], &quant[i]);
    }
    // Imprimindo a Quantidade comprada, o Valor de cada Produto e o Valor Parcial
    for(i = 0; i < 4; i++){
        valorParcial = quant[i] * valor[i];
        printf("Vendido: %d\tValor unitario R$%.2f\tValor total R$%.2f\n", quant[i], valor[i],  valorParcial);
    // Processamento do Valor Total
        valorTotal = valorTotal + valorParcial;
    }
    // Imprimindo o Valor Total 
    printf("Valor total das Vendas: R$ %.2f\n", valorTotal);
    // Comissão do Vendedor
    comissao = valorTotal * 0.05;
    printf("Comissao do Vendedor: R$ %.2f\n", comissao);
    // Verificando qual o produto mais Vendido
    for(i = 0; i < 4; i++){
        if (quant[i] > maisVendido){
            maisVendido = quant[i];
        }
    }
    // Imprimindo  a Posição e o Valor do Produto mais Vendido
    printf("O produto mais vendido foi: ");
    for(i = 0; i < 4; i++){
        if (quant[i] == maisVendido){
            printf("Posicao: %d\tValor R$%.2f\n", i, valor[i]);
        }
    }

    return 0;
}