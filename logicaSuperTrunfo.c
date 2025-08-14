#include <stdio.h>

int main(){

    // Dados das cartas 1 (Seu código original, sem alterações)
    char estado1[5];
    char codigo1[5];
    char cidade1[50];
    unsigned long int populacao1;
    int turisticos1;
    unsigned int area1;
    double pib1;

    // Dados das cartas 2 (Seu código original, sem alterações)
    char estado2[3];
    char codigo2[5];
    char cidade2[50];
    unsigned long int populacao2;
    int turisticos2;
    unsigned int area2;
    double pib2;

    printf("\n==============================\n");
    printf("     Super Trunfo: Cidades    \n");
    printf("==============================\n\n");

    // Entrada dados carta 1 (Seu código original, sem alterações)
    printf("--- Carta 1 ---\n");
    printf("Digite o estado da carta 1 (EX: SP): ");
    scanf("%2s", estado1);
    printf("Digite o código da carta 1 (EX: A01): ");
    scanf("%4s", codigo1);
    printf("Digite o nome da cidade da carta 1: ");
    scanf(" %49[^\n]", cidade1); 
    printf("Digite a população da carta 1: ");
    scanf("%lu", &populacao1);
    printf("Digite a área da carta 1 (em km²): ");
    scanf("%u", &area1);
    printf("Digite a quantidade de pontos turísticos da carta 1: ");
    scanf("%d", &turisticos1);
    printf("Digite o PIB da carta 1 em bilhões de reais: ");
    scanf("%lf", &pib1);
    printf("\n");

    // Entrada dados carta 2 (Seu código original, sem alterações)
    printf("--- Carta 2 ---\n");
    printf("Digite o estado da carta 2 (EX: RJ): ");
    scanf("%2s", estado2);
    printf("Digite o código da carta 2 (EX: B02): ");
    scanf("%4s", codigo2);
    printf("Digite o nome da cidade da carta 2: ");
    scanf(" %49[^\n]", cidade2); 
    printf("Digite a população da carta 2: ");
    scanf("%lu", &populacao2);
    printf("Digite a área da carta 2 (em km²): ");
    scanf("%u", &area2);
    printf("Digite a quantidade de pontos turísticos da carta 2: ");
    scanf("%d", &turisticos2);
    printf("Digite o PIB da carta 2 em bilhões de reais: ");
    scanf("%lf", &pib2);
    printf("\n");

    // Cálculo da densidade e PIB per capita (Seu código original, sem alterações)
    double densidade_popula1 = (double)populacao1 / area1;
    double pib_per1 = (pib1 * 1000000000) / populacao1;
    double densidade_popula2 = (double)populacao2 / area2;
    double pib_per2 = (pib2 * 1000000000) / populacao2;

    // ===== INÍCIO DA NOVA IMPLEMENTAÇÃO SIMPLES =====

    int escolha1, escolha2;
    double valor1_carta1 = 0, valor2_carta1 = 0; // Para guardar os dois valores da carta 1
    double valor1_carta2 = 0, valor2_carta2 = 0; // Para guardar os dois valores da carta 2
    double soma_carta1, soma_carta2;

    // 1. ESCOLHER O PRIMEIRO ATRIBUTO
    printf("Escolha o PRIMEIRO atributo a ser comparado:\n");
    printf("1. População\n2. Área\n3. Pontos turísticos\n4. PIB\n5. Densidade populacional\n6. PIB per capita\n");
    printf(">> ");
    scanf("%d", &escolha1);

    // 2. ESCOLHER O SEGUNDO ATRIBUTO
    printf("\nEscolha o SEGUNDO atributo a ser comparado:\n");
    printf(">> ");
    scanf("%d", &escolha2);

    // 3. ENCONTRAR OS VALORES PARA A PRIMEIRA ESCOLHA
    // Este switch pega os valores da escolha1 para a carta1 e carta2
    switch (escolha1)
    {
        case 1:
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            break;
        case 2:
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;
        case 3:
            valor1_carta1 = turisticos1;
            valor1_carta2 = turisticos2;
            break;
        case 4:
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            break;
        case 5:
            valor1_carta1 = densidade_popula1;
            valor1_carta2 = densidade_popula2;
            break;
        case 6:
            valor1_carta1 = pib_per1;
            valor1_carta2 = pib_per2;
            break;
    }

    // 4. ENCONTRAR OS VALORES PARA A SEGUNDA ESCOLHA
    // Este switch pega os valores da escolha2 para a carta1 e carta2
    switch (escolha2)
    {
        case 1:
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            break;
        case 2:
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            break;
        case 3:
            valor2_carta1 = turisticos1;
            valor2_carta2 = turisticos2;
            break;
        case 4:
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            break;
        case 5:
            valor2_carta1 = densidade_popula1;
            valor2_carta2 = densidade_popula2;
            break;
        case 6:
            valor2_carta1 = pib_per1;
            valor2_carta2 = pib_per2;
            break;
    }
    
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("      Resultado da Comparação\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("--- Carta 1: %s (%s) ---\n", cidade1, codigo1);
    printf("Valor do atributo %d: %.2f\n", escolha1, valor1_carta1);
    printf("Valor do atributo %d: %.2f\n", escolha2, valor2_carta1);
    printf("SOMA TOTAL: %.2f\n\n", soma_carta1);

    printf("--- Carta 2: %s (%s) ---\n", cidade2, codigo2);
    printf("Valor do atributo %d: %.2f\n", escolha1, valor1_carta2);
    printf("Valor do atributo %d: %.2f\n", escolha2, valor2_carta2);
    printf("SOMA TOTAL: %.2f\n\n", soma_carta2);

    // 5. COMPARAR AS SOMAS E MOSTRAR O VENCEDOR
    if (soma_carta1 > soma_carta2) {
        printf("VENCEDOR FINAL: Carta 1 (%s)!\n\n", cidade1);
    } else if (soma_carta2 > soma_carta1) {
        printf("VENCEDOR FINAL: Carta 2 (%s)!\n\n", cidade2);
    } else {
        printf("RESULTADO FINAL: Deu empate!\n\n");
    }

    // ===== FIM DA NOVA IMPLEMENTAÇÃO =====

    // Exibição dos dados das cartas 
    printf("--- Dados Completos das Cartas ---\n\n");
    printf("Carta 1 (Cidade: %s - Estado: %s - Código: %s):\n", cidade1, estado1, codigo1);
    printf("População: %lu - Área: %u km² - Pontos turísticos: %d - PIB: R$ %.2f bilhões\n", populacao1, area1, turisticos1, pib1);
    printf("Densidade populacional: %.2f por km² - PIB per capita: R$ %.2f\n\n", densidade_popula1, pib_per1);
    printf("Carta 2 (Cidade: %s - Estado: %s - Código: %s):\n", cidade2, estado2, codigo2);
    printf("População: %lu - Área: %u km² - Pontos turísticos: %d - PIB: R$ %.2f bilhões\n", populacao2, area2, turisticos2, pib2);
    printf("Densidade populacional: %.2f por km² - PIB per capita: R$ %.2f\n\n", densidade_popula2, pib_per2);

    return 0;
}