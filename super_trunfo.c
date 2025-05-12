#include <stdio.h>

int main() {
    char estado1, estado2;
    char codigo1[3], codigo2[3];
    char cidade1[100], cidade2[100];
    unsigned long int pop1, pop2;
    float area1, area2, pib1, pib2;
    int pt1, pt2;
    float dens1, dens2;
    float ppc1, ppc2;
    float sp1, sp2;
    int v1 = 0, v2 = 0;

    printf("digite a letra do estado carta 1: ");
    scanf(" %c", &estado1);
    printf("digite o codigo da carta carta 1: ");
    scanf("%s", codigo1);
    printf("digite o nome da cidade carta 1: ");
    scanf("%s", cidade1);
    printf("digite a populacao carta 1: ");
    scanf("%lu", &pop1);
    printf("digite a area carta 1: ");
    scanf("%f", &area1);
    printf("digite o pib carta 1: ");
    scanf("%f", &pib1);
    printf("digite o numero de pontos turisticos carta 1: ");
    scanf("%d", &pt1);

    printf("digite a letra do estado carta 2: ");
    scanf(" %c", &estado2);
    printf("digite o codigo da carta carta 2: ");
    scanf("%s", codigo2);
    printf("digite o nome da cidade carta 2: ");
    scanf("%s", cidade2);
    printf("digite a populacao carta 2: ");
    scanf("%lu", &pop2);
    printf("digite a area carta 2: ");
    scanf("%f", &area2);
    printf("digite o pib carta 2: ");
    scanf("%f", &pib2);
    printf("digite o numero de pontos turisticos carta 2: ");
    scanf("%d", &pt2);

    dens1 = pop1 / area1;
    dens2 = pop2 / area2;
    ppc1 = pib1 / pop1;
    ppc2 = pib2 / pop2;
    sp1 = pop1 + area1 + pib1 + pt1 + ppc1 + (1.0 / dens1);
    sp2 = pop2 + area2 + pib2 + pt2 + ppc2 + (1.0 / dens2);

    printf("\ncomparacao de cartas:\n");

    if (pop1 > pop2) {
        printf("populacao: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("populacao: carta 2 venceu (0)\n");
        v2++;
    }

    if (area1 > area2) {
        printf("area: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("area: carta 2 venceu (0)\n");
        v2++;
    }

    if (pib1 > pib2) {
        printf("pib: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("pib: carta 2 venceu (0)\n");
        v2++;
    }

    if (pt1 > pt2) {
        printf("pontos turisticos: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("pontos turisticos: carta 2 venceu (0)\n");
        v2++;
    }

    if (dens1 < dens2) {
        printf("densidade populacional: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("densidade populacional: carta 2 venceu (0)\n");
        v2++;
    }

    if (ppc1 > ppc2) {
        printf("pib per capita: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("pib per capita: carta 2 venceu (0)\n");
        v2++;
    }

    if (sp1 > sp2) {
        printf("super poder: carta 1 venceu (1)\n");
        v1++;
    } else {
        printf("super poder: carta 2 venceu (0)\n");
        v2++;
    }

    printf("\nresultado final: ");
    if (v1 > v2) {
        printf("carta 1 venceu com %d atributos\n", v1);
    } else if (v2 > v1) {
        printf("carta 2 venceu com %d atributos\n", v2);
    } else {
        printf("empate\n");
    }

    return 0;
}
