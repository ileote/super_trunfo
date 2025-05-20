#include <stdio.h>

int main() {
    char tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    int lh = 2, ch = 4;
    if (ch + 2 < 10 &&
        tabuleiro[lh][ch] == '0' &&
        tabuleiro[lh][ch + 1] == '0' &&
        tabuleiro[lh][ch + 2] == '0') {
        tabuleiro[lh][ch] = '3';
        tabuleiro[lh][ch + 1] = '3';
        tabuleiro[lh][ch + 2] = '3';
    }

    int lv = 5, cv = 1;
    if (lv + 2 < 10 &&
        tabuleiro[lv][cv] == '0' &&
        tabuleiro[lv + 1][cv] == '0' &&
        tabuleiro[lv + 2][cv] == '0') {
        tabuleiro[lv][cv] = '3';
        tabuleiro[lv + 1][cv] = '3';
        tabuleiro[lv + 2][cv] = '3';
    }

    int ld1 = 0, cd1 = 0;
    if (ld1 + 2 < 10 && cd1 + 2 < 10 &&
        tabuleiro[ld1][cd1] == '0' &&
        tabuleiro[ld1 + 1][cd1 + 1] == '0' &&
        tabuleiro[ld1 + 2][cd1 + 2] == '0') {
        tabuleiro[ld1][cd1] = '3';
        tabuleiro[ld1 + 1][cd1 + 1] = '3';
        tabuleiro[ld1 + 2][cd1 + 2] = '3';
    }

    int ld2 = 0, cd2 = 9;
    if (ld2 + 2 < 10 && cd2 - 2 >= 0 &&
        tabuleiro[ld2][cd2] == '0' &&
        tabuleiro[ld2 + 1][cd2 - 1] == '0' &&
        tabuleiro[ld2 + 2][cd2 - 2] == '0') {
        tabuleiro[ld2][cd2] = '3';
        tabuleiro[ld2 + 1][cd2 - 1] = '3';
        tabuleiro[ld2 + 2][cd2 - 2] = '3';
    }

    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };
    int origem_linha = 3;
    int origem_coluna = 3;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int l = origem_linha + i - 1;
            int c = origem_coluna + j - 2;
            if (l >= 0 && l < 10 && c >= 0 && c < 10 &&
                cone[i][j] == 1 && tabuleiro[l][c] == '0') {
                tabuleiro[l][c] = 'C';
            }
        }
    }

    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };
    origem_linha = 6;
    origem_coluna = 6;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int l = origem_linha + i - 1;
            int c = origem_coluna + j - 2;
            if (l >= 0 && l < 10 && c >= 0 && c < 10 &&
                cruz[i][j] == 1 && tabuleiro[l][c] == '0') {
                tabuleiro[l][c] = '+';
            }
        }
    }

    int octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    origem_linha = 1;
    origem_coluna = 7;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            int l = origem_linha + i - 1;
            int c = origem_coluna + j - 2;
            if (l >= 0 && l < 10 && c >= 0 && c < 10 &&
                octaedro[i][j] == 1 && tabuleiro[l][c] == '0') {
                tabuleiro[l][c] = '*';
            }
        }
    }

    printf("tabuleiro batalha naval com habilidades\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
