
#include <stdio.h>

struct CartaSuperTrunfo {
    char codigo[20];
    char estado;
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct CartaSuperTrunfo carta[2];

    for (int i = 0; i < 2; i++) {
        printf("\nColoque os dados da carta %d:\n", i + 1);

        // Estado
        printf("Estado (A-H): ");
        scanf(" %c", &carta[i].estado);

        // Codigo da carta
        printf("Codigo da carta: ");
        scanf("%s", carta[i].codigo);

        // Nome da cidade
        printf("\nNome da cidade: ");
        scanf("%s", carta[i].nomeCidade);

        // Populacao
        printf("Populacao: ");
        scanf("%d", &carta[i].populacao);

        // Area km^2
        printf("Area (km^2): ");
        scanf("%f", &carta[i].area);

        // PIB
        printf("PIB: ");
        scanf("%f", &carta[i].pib);

        // Pontos turisticos
        printf("Numero de pontos turisticos: ");
        scanf("%d", &carta[i].pontosTuristicos);
    }

    // Dados das cartas
    printf("\nDados das cartas:\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", carta[i].estado);
        printf("Codigo: %s\n", carta[i].codigo);
        printf("Cidade: %s\n", carta[i].nomeCidade);
        printf("Populacao: %d\n", carta[i].populacao);
        printf("Area: %.2f km^2\n", carta[i].area);
        printf("PIB: %.2f\n", carta[i].pib);
        printf("Pontos Turisticos: %d\n", carta[i].pontosTuristicos);
    }

    return 0;
}


