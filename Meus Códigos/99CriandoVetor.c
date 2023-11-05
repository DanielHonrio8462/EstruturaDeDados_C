#include <stdio.h>
#include <Stdlib.h>

int main() {

    // Criação de Variaveis
    int idade;
    char sexo;
    float n1;

    // Criação de Vetores
    int nun1[10]; // Esse Vetor tem 10 espaços
    int num2[] = {1,5,9,15,43}; // Esse Vetor tem a quantidade de espaço de acordo com os valores que recebeu
    int num3[5] = {4,7,5}; // Esse Vetor tem 5 espaços, porem só recebeu 3 valores, os 2 ultimos vai ser automaticamente 0
    int num4[5] = {1,2,3,4,5,6}; // Esse Vetor tem 5 espaços, porem recebeu 6 valores, o ultimo valor não sera armazenado
    int num5[5] = {0}; // Esse Vetor tem 5 espaços e todos tem o valor 0

    char letras[100];
    char vogais[5] = {'a','e','i','o','u'}; // Esse Vetor tem 5 espaços, e como é caracter, o valor tem que está entre ''

    float notas[3] = {7.5,8.3,9.5}; // Esse Vetor tem 3 espaços, e como é float, o valor tem que ser com #.#

    return 0;
}
