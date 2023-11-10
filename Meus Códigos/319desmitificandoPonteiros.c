#include <stdio.h>
#include <stdlib.h>

void descobrirValores(int *v, int *me, int *ma, int tam){
    int i;
    *me = v[0]; /*Se eu quiser Acessar ou Alterar o Contéudo Apontado devo usar "*" */
    *ma = v[0];

    for(i = 1; i < tam; i++){
        if(v[i] < *me){
            *me = v[i];
        }
        if(v[i] > *ma){
            *ma = v[i];
        }
    }
    printf("Na Funcao: Menor: %d\tMaior: %d\n\n", *me, *ma);
    printf("End de me: %p\tEnd de maior: %p\n\n", &me, &ma);
    printf("Cont de me: %p\tCont de maior: %p\n\n", me, ma);
}

int main() {

    int valor = 10, vet[10] = {50,10,250,500,25}, menor, maior;
    int *p;

    p = &valor;

    printf("\n\n");
    printf("Valor: %d\tEndereco de Valor: %p\n", valor, &valor);
    printf("Endereco de p: %p\n", &p); // Endereço de P
    printf("Conteudo de p: %p\n", p); // Endereço que P recebeu
    printf("Conteudo apontado por p: %d\n\n", *p); // Conteúdo que P a ponta

    descobrirValores(vet, &menor, &maior, 5);

    printf("Em main: Menor: %d\tMaior: %d\n\n", menor, maior);
    printf("End de menor: %p\tEnd de maior: %p\n\n", &menor, &maior);

    return 0;
}