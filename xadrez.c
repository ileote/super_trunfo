#include <stdio.h>

void mover_torre(int casas) {
    if (casas == 0) return;
    printf("direita\n");
    mover_torre(casas - 1);
}

void mover_rainha(int casas) {
    if (casas == 0) return;
    printf("esquerda\n");
    mover_rainha(casas - 1);
}

void mover_bispo_recursivo(int casas) {
    if (casas == 0) return;
    printf("cima direita\n");
    mover_bispo_recursivo(casas - 1);
}

void mover_bispo_com_loops(int casas) {
    int i, j;
    for (i = 0; i < casas; i++) {
        for (j = 0; j < 1; j++) {
            printf("cima direita\n");
        }
    }
}

int main() {
    int casas_torre = 5;
    int casas_bispo = 5;
    int casas_rainha = 8;

    printf("movimento da torre:\n");
    mover_torre(casas_torre);

    printf("\nmovimento do bispo recursivo:\n");
    mover_bispo_recursivo(casas_bispo);
    printf("\nmovimento do bispo loops:\n");
    mover_bispo_com_loops(casas_bispo);

    printf("\nmovimento da rainha:\n");
    mover_rainha(casas_rainha);

    printf("\nmovimento do cavalo:\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        if (i == 2) break;
        printf("cima\n");

        for (j = 0; j < 2; j++) {
            if (j == 1) continue;
        }
    }
    printf("direita\n");

    return 0;
}
