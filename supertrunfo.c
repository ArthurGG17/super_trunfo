#include <stdio.h>

struct CartaSuperTrunfo {
    char codigo[20];
    char estado;
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float superPoder;
    float densidadePopulacional;
    float pibPct;
};

void calcularSuperPoder(struct CartaSuperTrunfo* carta) {
    // Calculando a densidade populacional e PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPct = carta->pib / carta->populacao;

    // Calculando o Super Poder
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib + carta->pontosTuristicos +
                        (1.0 / carta->densidadePopulacional) + carta->pibPct;
}

void compararCartas(struct CartaSuperTrunfo* carta1, struct CartaSuperTrunfo* carta2) {
    printf("Comparacao de Cartas:\n");

    // Comparando a População
    printf("População: ");
    printf("Carta 1 venceu (%d)\n", carta1->populacao > carta2->populacao);

    // Comparando a Área
    printf("Área: ");
    printf("Carta 1 venceu (%d)\n", carta1->area > carta2->area);

    // Comparando o PIB
    printf("PIB: ");
    printf("Carta 1 venceu (%d)\n", carta1->pib > carta2->pib);

    // Comparando os Pontos Turísticos
    printf("Pontos Turísticos: ");
    printf("Carta 1 venceu (%d)\n", carta1->pontosTuristicos > carta2->pontosTuristicos);

    // Comparando a Densidade Populacional (menor valor vence)
    printf("Densidade Populacional: ");
    printf("Carta 1 venceu (%d)\n", carta1->densidadePopulacional < carta2->densidadePopulacional);

    // Comparando o PIB per Capita
    printf("PIB per Capita: ");
    printf("Carta 1 venceu (%d)\n", carta1->pibPct > carta2->pibPct);

    // Comparando o Super Poder
    printf("Super Poder: ");
    printf("Carta 1 venceu (%d)\n", carta1->superPoder > carta2->superPoder);
}

int main() {
    struct CartaSuperTrunfo carta[2];

    for (int i = 0; i < 2; i++) {
        printf("\nColoque os dados da carta %d:\n", i + 1);

        // Estado
        printf("Estado (A-H): ");
        scanf(" %c", &carta[i].estado);

        // Codigo da carta
        printf("Código da carta: ");
        scanf("%s", carta[i].codigo);

        // Nome da cidade
        printf("\nNome da cidade: ");
        scanf("%s", carta[i].nomeCidade);

        // Populacao (agora usando unsigned long int)
        printf("População: ");
        scanf("%lu", &carta[i].populacao);

        // Area km^2
        printf("Área (km^2): ");
        scanf("%f", &carta[i].area);

        // PIB
        printf("PIB: ");
        scanf("%f", &carta[i].pib);

        // Pontos turisticos
        printf("Número de pontos turísticos: ");
        scanf("%d", &carta[i].pontosTuristicos);

        // Calcular Super Poder e outros valores derivados
        calcularSuperPoder(&carta[i]);
    }

    // Exibindo os dados das cartas com os cálculos
    printf("Dados das cartas:\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", carta[i].estado);
        printf("Código: %s\n", carta[i].codigo);
        printf("Cidade: %s\n", carta[i].nomeCidade);
        printf("População: %lu\n", carta[i].populacao);
        printf("Area: %.2f km^2\n", carta[i].area);
        printf("PIB: %.2f\n", carta[i].pib);
        printf("Pontos Turísticos: %d\n", carta[i].pontosTuristicos);
        printf("Densidade populacional: %.2f\n", carta[i].densidadePopulacional);
        printf("PIB per Capita: %.2f reais\n", carta[i].pibPct);
        printf("Super Poder: %.2f\n", carta[i].superPoder);
    }

    // Comparando as cartas
    compararCartas(&carta[0], &carta[1]);

    return 0;
}



