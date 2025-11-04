#include <stdio.h>

#define TAM 10 
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO] = {3, 3, 3};

    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    if (colunaHorizontal + TAM_NAVIO <= TAM &&
        linhaHorizontal < TAM) {

        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }
    if (linhaVertical + TAM_NAVIO <= TAM &&
        colunaVertical < TAM) {

        int sobreposicao = 0;

        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao) {
            printf("Erro: os navios se sobrepõem!\n");
            return 1;
        }

        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Parte de navio\n");

    return 0;
}