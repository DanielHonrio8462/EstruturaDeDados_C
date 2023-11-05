#include <stdio.h>
#include <stdlib.h>

int main() {

    int indiceMaior, indiceMenor, i;
    float maior, menor = 9999, temp[12];
    // Lendo a Temperatura do Mês
    for(i = 0; i < 12; i++){
        printf("Qual a Temperatura do mes %d em Graus Celsus? ", i + 1);
        scanf("%f", &temp[i]);
    }
    printf("\n\n");
    // Descobrindo qual Mês tem a Maior Temperatura
    for(i = 0; i < 12; i++){
        if (temp[i] > maior){
            maior = temp[i];
            indiceMaior = i;
        }
    // Descobrindo qual Mês tem a Menor Temperatura
        if (menor > temp[i]){
            menor = temp[i];
            indiceMenor = i;
        }
    } 
    // Imprimindo a Menor Temperatura
    printf("A Menor Temperatura foi %.2f e ocorreu no mes de ", menor);   
    switch (indiceMenor){
    case 0: 
        printf("Janeiro\n");
        break;
    case 1: 
        printf("Fevereir\n");
        break;
    case 2: 
        printf("Marco\n");
        break;
    case 3: 
        printf("Abril\n");
        break;
    case 4: 
        printf("Maio\n");
        break;
    case 5: 
        printf("Junho\n");
        break;
    case 6: 
        printf("Julho\n");
        break;
    case 7: 
        printf("Agosto\n");
        break;
    case 8: 
        printf("Setembro\n");
        break;
    case 9: 
        printf("Outubro\n");
        break;
    case 10: 
        printf("Novembro\n");
        break;
    case 11: 
        printf("Dezembro\n");
        break;
    }
    // Imprimindo a Maior Temperatura
    printf("A Maior Temperatura foi %.2f e ocorreu no mes de ", maior);
    switch (indiceMaior){
    case 0: 
        printf("Janeiro\n");
        break;
    case 1: 
        printf("Fevereir\n");
        break;
    case 2: 
        printf("Marco\n");
        break;
    case 3: 
        printf("Abril\n");
        break;
    case 4: 
        printf("Maio\n");
        break;
    case 5: 
        printf("Junho\n");
        break;
    case 6: 
        printf("Julho\n");
        break;
    case 7: 
        printf("Agosto\n");
        break;
    case 8: 
        printf("Setembro\n");
        break;
    case 9: 
        printf("Outubro\n");
        break;
    case 10: 
        printf("Novembro\n");
        break;
    case 11: 
        printf("Dezembro\n");
        break;
    }

    return 0;
}
