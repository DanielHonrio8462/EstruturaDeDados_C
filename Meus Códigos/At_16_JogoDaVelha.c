#include <stdio.h>
#include <stdlib.h>

int main() {

    // Minha Estrutura
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    char jogo[3][3];
    do{
        jogador = 1;
        ganhou = 0;
        jogadas = 0;
        // Inicializando Minha Estrutura
        for(l = 0; l < 3; l++){
            for(c = 0;  c < 3; c++){
                jogo[l][c] = ' ';
            }
        }
        do{
            // Imprimir Jogo
            printf("\n\n\t 0   1   2\n\n");
            for(l = 0; l < 3; l++){
                printf("\t");
                for(c = 0;  c < 3; c++){
                    printf(" %c ", jogo[l][c]);
                    if(c < 2){
                        printf("|");   
                    }
                }
                printf("   %d", l);
                if(l < 2){
                    printf("\n\t-----------");
                }
                printf("\n");
            }
            // Ler Coordenadas
            do{
            printf("JOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
            scanf("%d%d", &linha, &coluna);
            }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');
            // Salvar Coordenadas
            if(jogador == 1){
                jogo[linha][coluna] = '0';
                jogador++;
            }else{
                jogo[linha][coluna] = 'x';
                jogador = 1;
            }
            jogadas++;
            // Alguém Ganhou por Linha
            if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
            jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
            jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O Jogador 1 Venceu por linha!\n");
                ganhou = 1;
            }
            if(jogo[0][0] == 'x' && jogo[0][1] == 'x' && jogo[0][2] == 'x' ||
            jogo[1][0] == 'x' && jogo[1][1] == 'x' && jogo[1][2] == 'x' ||
            jogo[2][0] == 'x' && jogo[2][1] == 'x' && jogo[2][2] == 'x'){
                printf("\nParabens! O Jogador 2 Venceu por linha!\n");
                ganhou = 1;
            }
            // Alguém Ganhou por Coluna
            if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
            jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
            jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O Jogador 1 Venceu por coluna!\n");
                ganhou = 1;
            }
            if(jogo[0][0] == 'x' && jogo[1][0] == 'x' && jogo[2][0] == 'x' ||
            jogo[0][1] == 'x' && jogo[1][1] == 'x' && jogo[2][1] == 'x' ||
            jogo[0][2] == 'x' && jogo[1][2] == 'x' && jogo[2][2] == 'x'){
                printf("\nParabens! O Jogador 2 Venceu por coluna!\n");
                ganhou = 1;
            }
            // Diagonal Principal
            if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O Jogador 1 Venceu por Diagonal Principal!\n");
                ganhou = 1;
            }
            if(jogo[0][0] == 'x' && jogo[1][1] == 'x' && jogo[2][2] == 'x'){
                printf("\nParabens! O Jogador 2 Venceu por Diagonal Principal!\n");
                ganhou = 1;
            }
            // Diagonal Secundaria
            if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
                printf("\nParabens! O Jogador 1 Venceu por Diagonal Secundaria!\n");
                ganhou = 1;
            }
            if(jogo[0][2] == 'x' && jogo[1][1] == 'x' && jogo[2][0] == 'x'){
                printf("\nParabens! O Jogador 2 Venceu por Diagonal Secundaria!\n");
                ganhou = 1;
            }
        }while(ganhou == 0 && jogadas < 9);
        if(ganhou == 0){
            printf("\nO jogo finalizou sem ganhador!\n");
        }
        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;
}