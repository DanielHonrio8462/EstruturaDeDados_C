#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i;
    int num2[3];

    srand(time(NULL)); // "srand"-> Função Semente
                       // "time"-> Função passa a hora do relogio do PC, dessa forma o "rand" sempre vai mudar

    for(i = 0; i < 3; i++){
        num2[i] = 1 + rand() % 10; // "rand" -> Função Vai gerar um valor aleatorio padrão, de acordo com sua Semente
                                   // Para limitar o número aleatório, "# + rand() % 10", está entre 1 e 10
    }

    printf("\n");   
    for(i = 0; i < 3; i++){
         printf("%d ", num2[i]);
    }

    return 0;
}