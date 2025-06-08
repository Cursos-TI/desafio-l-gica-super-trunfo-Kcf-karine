#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função para mostrar atributos disponíveis
void mostrarAtributosDisponiveis(int escolhido) {
    printf("\nEscolha um atributo:\n");
    if (escolhido != 1) printf("1 - População\n");
    if (escolhido != 2) printf("2 - Área\n");
    if (escolhido != 3) printf("3 - PIB\n");
    if (escolhido != 4) printf("4 - Pontos Turísticos\n");
    if (escolhido != 5) printf("5 - Densidade Demográfica (menor vence)\n");
    if (escolhido != 6) printf("6 - PIB per capita\n");
}

float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        case 6: return carta.pibPerCapita;
        default: return -1; // erro
    }
}

int atributoMenorVence(int atributo) {
    return atributo == 5;
}

int main() {
    // Cartas cadastradas
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 780.5, 15, 8000, 63500};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6700000, 1200.40, 600.2, 20, 5583, 55000};

    int atributo1 = 0, atributo2 = 0;
    float valor1_a1, valor2_a1, valor1_a2, valor2_a2;
    float soma1, soma2;

    printf("Super Trunfo - Comparação Avançada!\n");
    printf("Carta 1: %s\n", carta1.cidade);
    printf("Carta 2: %s\n", carta2.cidade);

    // Escolha do primeiro atributo
    do {
        mostrarAtributosDisponiveis(0);
        printf("Escolha o primeiro atributo (1-6): ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 6) {
            printf("Atributo inválido. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 6);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        mostrarAtributosDisponiveis(atributo1);
        printf("Escolha o segundo atributo (1-6, diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1) {
            printf("Atributo inválido ou repetido. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 6 || atributo2 == atributo1);

    // Obtenção dos valores
    valor1_a1 = obterValorAtributo(carta1, atributo1);
    valor2_a1 = obterValorAtributo(carta2, atributo1);
    valor1_a2 = obterValorAtributo(carta1, atributo2);
    valor2_a2 = obterValorAtributo(carta2, atributo2);

    // Soma dos atributos
    soma1 = valor1_a1 + valor1_a2;
    soma2 = valor2_a1 + valor2_a2;

    // Exibição dos resultados
    printf("\n--- Resultado da Rodada ---\n");
    printf("%s:\n", carta1.cidade);
    printf("  Atributo %d: %.2f\n", atributo1, valor1_a1);
    printf("  Atributo %d: %.2f\n", atributo2, valor1_a2);
    printf("  Soma total: %.2f\n", soma1);

    printf("\n%s:\n", carta2.cidade);
    printf("  Atributo %d: %.2f\n", atributo1, valor2_a1);
    printf("  Atributo %d: %.2f\n", atributo2, valor2_a2);
    printf("  Soma total: %.2f\n", soma2);

    // Comparação da soma
    if (soma1 == soma2) {
        printf("\nResultado: Empate!\n");
    } else {
        int vencedor = soma1 > soma2 ? 1 : 2;
        printf("\nResultado: %s venceu!\n", vencedor == 1 ? carta1.cidade : carta2.cidade);
    }

    return 0;
}
