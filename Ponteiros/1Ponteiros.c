# include <stdio.h>
# include <stdlib.h> 

int main() {

    int *valor1, valor2 = 50;
    char *letra1, letra2 = 'b';

    valor1 = &valor2;
    letra1 = &letra2;

    printf("Valor da varialvel valor2: %d\n", valor2);
    printf("Endereco da Variavel valor2: %p\n", &valor2);
    printf("Conteudo da Variavel valor1: %p\n", valor1);
    printf("Conteudo apontado pela Variavel valor1: %d\n", *valor1);

    printf("\nValor da varialvel letra2: %c\n", letra2);
    printf("Endereco da Variavel letra2: %p\n", &letra2);
    printf("Conteudo da Variavel letra1: %p\n", letra1);
    printf("Conteudo apontado pela Variavel letra1: %c\n", *letra1);

    /*
    Quando a Variavel é um Ponteiro:
    "nome" da Variavel mostra o endereço.
    "*nome" mostra o conteudo da variavel que ele está apontando.
    */

    return 0; 
}