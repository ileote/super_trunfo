#include <stdio.h>

int main() {
    char pais1[50], pais2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2;
    int escolha1 = 0, escolha2 = 0;
    int valido1 = 0, valido2 = 0;

    printf("digite o nome do pais da carta 1:\n");
    scanf("%s", pais1);
    printf("digite a populacao da carta 1:\n");
    scanf("%lu", &populacao1);
    printf("digite a area da carta 1:\n");
    scanf("%f", &area1);
    printf("digite o pib da carta 1:\n");
    scanf("%f", &pib1);
    printf("digite os pontos turisticos da carta 1:\n");
    scanf("%d", &pontos1);

    printf("digite o nome do pais da carta 2:\n");
    scanf("%s", pais2);
    printf("digite a populacao da carta 2:\n");
    scanf("%lu", &populacao2);
    printf("digite a area da carta 2:\n");
    scanf("%f", &area2);
    printf("digite o pib da carta 2:\n");
    scanf("%f", &pib2);
    printf("digite os pontos turisticos da carta 2:\n");
    scanf("%d", &pontos2);

    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    do {
        printf("\nescolha o primeiro atributo:\n");
        printf("1 - populacao\n");
        printf("2 - area\n");
        printf("3 - pib\n");
        printf("4 - pontos turisticos\n");
        printf("5 - densidade demografica\n");
        scanf("%d", &escolha1);
        if (escolha1 >= 1 && escolha1 <= 5) valido1 = 1;
        else printf("opcao invalida. tente novamente.\n");
    } while (!valido1);

    do {
        printf("\nescolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != escolha1) {
                switch (i) {
                    case 1: printf("1 - populacao\n"); break;
                    case 2: printf("2 - area\n"); break;
                    case 3: printf("3 - pib\n"); break;
                    case 4: printf("4 - pontos turisticos\n"); break;
                    case 5: printf("5 - densidade demografica\n"); break;
                }
            }
        }
        scanf("%d", &escolha2);
        if (escolha2 >= 1 && escolha2 <= 5 && escolha2 != escolha1) valido2 = 1;
        else printf("opcao invalida ou repetida. tente novamente.\n");
    } while (!valido2);

    float valor1_attr1 = 0, valor2_attr1 = 0;
    float valor1_attr2 = 0, valor2_attr2 = 0;

    switch (escolha1) {
        case 1: valor1_attr1 = populacao1; valor2_attr1 = populacao2; break;
        case 2: valor1_attr1 = area1; valor2_attr1 = area2; break;
        case 3: valor1_attr1 = pib1; valor2_attr1 = pib2; break;
        case 4: valor1_attr1 = pontos1; valor2_attr1 = pontos2; break;
        case 5: valor1_attr1 = densidade1; valor2_attr1 = densidade2; break;
    }

    switch (escolha2) {
        case 1: valor1_attr2 = populacao1; valor2_attr2 = populacao2; break;
        case 2: valor1_attr2 = area1; valor2_attr2 = area2; break;
        case 3: valor1_attr2 = pib1; valor2_attr2 = pib2; break;
        case 4: valor1_attr2 = pontos1; valor2_attr2 = pontos2; break;
        case 5: valor1_attr2 = densidade1; valor2_attr2 = densidade2; break;
    }

    float resultado1 = 0, resultado2 = 0;

    if (escolha1 == 5) {
        resultado1 += (valor1_attr1 < valor2_attr1) ? 1 : (valor1_attr1 > valor2_attr1) ? 0 : 0.5;
        resultado2 += (valor2_attr1 < valor1_attr1) ? 1 : (valor2_attr1 > valor1_attr1) ? 0 : 0.5;
    } else {
        resultado1 += (valor1_attr1 > valor2_attr1) ? 1 : (valor1_attr1 < valor2_attr1) ? 0 : 0.5;
        resultado2 += (valor2_attr1 > valor1_attr1) ? 1 : (valor2_attr1 < valor1_attr1) ? 0 : 0.5;
    }

    if (escolha2 == 5) {
        resultado1 += (valor1_attr2 < valor2_attr2) ? 1 : (valor1_attr2 > valor2_attr2) ? 0 : 0.5;
        resultado2 += (valor2_attr2 < valor1_attr2) ? 1 : (valor2_attr2 > valor1_attr2) ? 0 : 0.5;
    } else {
        resultado1 += (valor1_attr2 > valor2_attr2) ? 1 : (valor1_attr2 < valor2_attr2) ? 0 : 0.5;
        resultado2 += (valor2_attr2 > valor1_attr2) ? 1 : (valor2_attr2 < valor1_attr2) ? 0 : 0.5;
    }

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\nresultado da comparacao entre %s e %s\n", pais1, pais2);
    printf("atributo %d: %s = %.2f | %s = %.2f\n", escolha1, pais1, valor1_attr1, pais2, valor2_attr1);
    printf("atributo %d: %s = %.2f | %s = %.2f\n", escolha2, pais1, valor1_attr2, pais2, valor2_attr2);
    printf("soma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    if (soma1 > soma2) printf("resultado: %s venceu!\n", pais1);
    else if (soma2 > soma1) printf("resultado: %s venceu!\n", pais2);
    else printf("resultado: empate!\n");

    return 0;
}
