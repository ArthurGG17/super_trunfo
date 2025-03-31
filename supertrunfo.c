#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct CartaSuperTrunfo {
    char estado[3];  // Estado (ex: "SP", "RJ")
    char codigo[20]; // Código da carta
    char nomeCidade[50]; // Nome da cidade
    unsigned long int populacao; // População
    float area; // Área em km²
    float pib; // PIB da cidade
    int pontosTuristicos; // Número de pontos turísticos
    float densidadePopulacional; // População / Área
    float pibPerCapita; // PIB / População
};

// Função para calcular Densidade Populacional e PIB per Capita
void calcularIndicadores(struct CartaSuperTrunfo* carta) {
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0; // Evita divisão por zero
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0; // Evita divisão por zero
    }
}

// Função para comparar cartas usando um atributo específico
void compararCartas(struct CartaSuperTrunfo* carta1, struct CartaSuperTrunfo* carta2) {
    printf("\n=== Comparação de Cartas (Atributo: População) ===\n");

    printf("Carta 1 - %s (%s): %lu habitantes\n", carta1->nomeCidade, carta1->estado, carta1->populacao);
    printf("Carta 2 - %s (%s): %lu habitantes\n", carta2->nomeCidade, carta2->estado, carta2->populacao);

    if (carta1->populacao > carta2->populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
    } else if (carta1->populacao < carta2->populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função principal
int main() {
    struct CartaSuperTrunfo carta[2];

    // Entrada de dados para as cartas
    for (int i = 0; i < 2; i++) {
        printf("\nDigite os dados da carta %d:\n", i + 1);

        printf("Estado (ex: SP, RJ): ");
        scanf("%s", carta[i].estado);

        printf("Código da carta: ");
        scanf("%s", carta[i].codigo);

        printf("Nome da cidade: ");
        scanf(" %[^\n]s", carta[i].nomeCidade); // Lê nome com espaços

        printf("População: ");
        scanf("%lu", &carta[i].populacao);

        printf("Área (km^2): ");
        scanf("%f", &carta[i].area);

        printf("PIB: ");
        scanf("%f", &carta[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &carta[i].pontosTuristicos);

        // Calcular os indicadores da carta
        calcularIndicadores(&carta[i]);
    }

    // Exibição das informações das cartas
    printf("\n=== Dados das Cartas ===\n");
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %s\n", carta[i].estado);
        printf("Código: %s\n", carta[i].codigo);
        printf("Cidade: %s\n", carta[i].nomeCidade);
        printf("População: %lu\n", carta[i].populacao);
        printf("Área: %.2f km^2\n", carta[i].area);
        printf("PIB: %.2f\n", carta[i].pib);
        printf("Pontos Turísticos: %d\n", carta[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", carta[i].densidadePopulacional);
        printf("PIB per Capita: %.2f reais\n", carta[i].pibPerCapita);
    }

    // Comparação das cartas
    compararCartas(&carta[0], &carta[1]);

    return 0;
}



