#include <stdio.h>
#include <string.h>

typedef struct {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para calcular densidade demográfica
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Exibir dados da carta
void exibirCarta(Carta c) {
    printf("País: %s\n", c.nomePais);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidadeDemografica);
    printf("-----------------------------------------\n");
}

int main() {
    // Duas cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213000000, 8515767, 2140.0, 30};
    carta1.densidadeDemografica = calcularDensidade(carta1.populacao, carta1.area);

    Carta carta2 = {"Canadá", 38000000, 9984670, 1640.0, 25};
    carta2.densidadeDemografica = calcularDensidade(carta2.populacao, carta2.area);

    int escolha1, escolha2;

    printf("==== SUPER TRUNFO - NÍVEL MESTRE ====\n\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Menu de atributos
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha2);

    // Validação
    if (escolha1 == escolha2 || escolha1 < 1 || escolha1 > 5 || escolha2 < 1 || escolha2 > 5) {
        printf("\nAtributos inválidos. Reinicie o programa.\n");
        return 1;
    }

    // Obtem os valores dos atributos e soma
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    // Função auxiliar para comparação (considerando regra de inversão para densidade)
    float obterValor(Carta c, int atributo) {
        switch (atributo) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.pontosTuristicos;
            case 5: return c.densidadeDemografica;
            default: return 0;
        }
    }

    // Comparar primeiro atributo
    valor1_c1 = obterValor(carta1, escolha1);
    valor1_c2 = obterValor(carta2, escolha1);
    int vencedor1;

    if (escolha1 == 5) // Densidade (menor vence)
        vencedor1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c2 < valor1_c1) ? 2 : 0;
    else
        vencedor1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c2 > valor1_c1) ? 2 : 0;

    // Comparar segundo atributo
    valor2_c1 = obterValor(carta1, escolha2);
    valor2_c2 = obterValor(carta2, escolha2);
    int vencedor2;

    if (escolha2 == 5) // Densidade (menor vence)
        vencedor2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c2 < valor2_c1) ? 2 : 0;
    else
        vencedor2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c2 > valor2_c1) ? 2 : 0;

    // Soma total dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");

    // Nome dos atributos
    char nomeAttr1[30], nomeAttr2[30];
    switch (escolha1) {
        case 1: strcpy(nomeAttr1, "População"); break;
        case 2: strcpy(nomeAttr1, "Área"); break;
        case 3: strcpy(nomeAttr1, "PIB"); break;
        case 4: strcpy(nomeAttr1, "Pontos Turísticos"); break;
        case 5: strcpy(nomeAttr1, "Densidade Demográfica"); break;
    }

    switch (escolha2) {
        case 1: strcpy(nomeAttr2, "População"); break;
        case 2: strcpy(nomeAttr2, "Área"); break;
        case 3: strcpy(nomeAttr2, "PIB"); break;
        case 4: strcpy(nomeAttr2, "Pontos Turísticos"); break;
        case 5: strcpy(nomeAttr2, "Densidade Demográfica"); break;
    }

    // Mostrar comparação dos atributos
    printf("%s:\n", nomeAttr1);
    printf("  %s: %.2f\n", carta1.nomePais, valor1_c1);
    printf("  %s: %.2f\n", carta2.nomePais, valor1_c2);
    printf("Vencedor: %s\n\n", vencedor1 == 1 ? carta1.nomePais : vencedor1 == 2 ? carta2.nomePais : "Empate");

    printf("%s:\n", nomeAttr2);
    printf("  %s: %.2f\n", carta1.nomePais, valor2_c1);
    printf("  %s: %.2f\n", carta2.nomePais, valor2_c2);
    printf("Vencedor: %s\n\n", vencedor2 == 1 ? carta1.nomePais : vencedor2 == 2 ? carta2.nomePais : "Empate");

    printf("SOMA DOS ATRIBUTOS:\n");
    printf("%s: %.2f\n", carta1.nomePais, soma1);
    printf("%s: %.2f\n", carta2.nomePais, soma2);

    if (soma1 > soma2)
        printf("\nResultado Final: %s venceu!\n", carta1.nomePais);
    else if (soma2 > soma1)
        printf("\nResultado Final: %s venceu!\n", carta2.nomePais);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
