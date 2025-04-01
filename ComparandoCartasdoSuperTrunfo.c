#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("------------------------------\n");
}

int main() {
    // Cadastro da Carta 1
    Carta carta1 = {"SP", "C01", "São Paulo", 12300000, 1521.11, 699.3, 15};
    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);

    // Cadastro da Carta 2
    Carta carta2 = {"RJ", "C02", "Rio de Janeiro", 6710000, 1182.3, 411.5, 12};
    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Exibir os dados das cartas
    printf("CARTA 1:\n");
    exibirCarta(carta1);

    printf("CARTA 2:\n");
    exibirCarta(carta2);

    // Atributo escolhido para comparação: PIB per capita
    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    // Comparação
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
