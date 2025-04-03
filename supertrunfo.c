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

// Função para comparar cartas baseado no atributo
void compararCartas(struct CartaSuperTrunfo* carta1, struct CartaSuperTrunfo* carta2, int atributo) {
    printf("\n=== Comparação de Cartas ===\n");

    // Exibir os detalhes das cartas
    printf("Carta 1 - %s (%s):\n", carta1->nomeCidade, carta1->estado);
    printf("Carta 2 - %s (%s):\n", carta2->nomeCidade, carta2->estado);

    switch (atributo) {
        case 1: // População
            printf("Atributo: População\n");
            printf("Carta 1: %lu habitantes\n", carta1->populacao);
            printf("Carta 2: %lu habitantes\n", carta2->populacao);

            if (carta1->populacao > carta2->populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
            } else if (carta1->populacao < carta2->populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área (km²)\n");
            printf("Carta 1: %.2f km²\n", carta1->area);
            printf("Carta 2: %.2f km²\n", carta2->area);

            if (carta1->area > carta2->area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
            } else if (carta1->area < carta2->area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Carta 1: %.2f\n", carta1->pib);
            printf("Carta 2: %.2f\n", carta2->pib);

            if (carta1->pib > carta2->pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
            } else if (carta1->pib < carta2->pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1: %d pontos\n", carta1->pontosTuristicos);
            printf("Carta 2: %d pontos\n", carta2->pontosTuristicos);

            if (carta1->pontosTuristicos > carta2->pontosTuristicos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
            } else if (carta1->pontosTuristicos < carta2->pontosTuristicos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Populacional
            printf("Atributo: Densidade Populacional\n");
            printf("Carta 1: %.2f hab/km²\n", carta1->densidadePopulacional);
            printf("Carta 2: %.2f hab/km²\n", carta2->densidadePopulacional);

            if (carta1->densidadePopulacional < carta2->densidadePopulacional) { // Menor valor vence
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
            } else if (carta1->densidadePopulacional > carta2->densidadePopulacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
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

    // Menu interativo
    int opcao;
    do {
        printf("\n=== Menu de Comparação ===\n");
        printf("Escolha o atributo para comparação:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao != 0) {
            compararCartas(&carta[0], &carta[1], opcao);
        }

    } while (opcao != 0);

    return 0;
}


