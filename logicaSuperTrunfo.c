#include <stdio.h>

int main(){

    // Dados das cartas 1 e 2 (Estrutura original mantida)
    char estado1[5], codigo1[5], cidade1[50];
    unsigned long int populacao1;
    int turisticos1;
    unsigned int area1;
    double pib1;

    char estado2[3], codigo2[5], cidade2[50];
    unsigned long int populacao2;
    int turisticos2;
    unsigned int area2;
    double pib2;
    
    // Variáveis para a lógica do jogo
    int escolha1, escolha2;
    double valor1_carta1, valor2_carta1; // Valores do atributo 1 e 2 para a carta 1
    double valor1_carta2, valor2_carta2; // Valores do atributo 1 e 2 para a carta 2
    
    // Variáveis para guardar o resultado de cada comparação
    int resultado_attr1 = 0; // 0=Empate, 1=Carta1 Venceu, 2=Carta2 Venceu
    int resultado_attr2 = 0; // 0=Empate, 1=Carta1 Venceu, 2=Carta2 Venceu

    printf("\n==============================\n");
    printf("     Super Trunfo: Cidades    \n");
    printf("==============================\n\n");

    // --- ENTRADA DE DADOS ---
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

    // --- CÁLCULO DE ATRIBUTOS DERIVADOS ---
    double densidade_popula1, pib_per1, densidade_popula2, pib_per2;
    
    // Verificação de divisão por zero
    if (area1 != 0) {
        densidade_popula1 = (double)populacao1 / area1;
    } else {
        densidade_popula1 = 0.0;
    }
    if (populacao1 != 0) {
        pib_per1 = (pib1 * 1000000000.0) / populacao1;
    } else {
        pib_per1 = 0.0;
    }
    if (area2 != 0) {
        densidade_popula2 = (double)populacao2 / area2;
    } else {
        densidade_popula2 = 0.0;
    }
    if (populacao2 != 0) {
        pib_per2 = (pib2 * 1000000000.0) / populacao2;
    } else {
        pib_per2 = 0.0;
    }
    
    // --- LÓGICA DE ESCOLHA DOS ATRIBUTOS ---
    printf("Escolha o PRIMEIRO atributo a ser comparado:\n");
    printf("1. População\n2. Área\n3. Pontos turísticos\n4. PIB\n5. Densidade populacional (menor vence)\n6. PIB per capita\n");
    printf(">> ");
    scanf("%d", &escolha1);
    
    // Garantir que os atributos sejam diferentes e válidos
    do {
        printf("\nEscolha o SEGUNDO atributo a ser comparado:\n");
        printf(">> ");
        scanf("%d", &escolha2);
        if (escolha1 == escolha2) {
            printf("Erro: Os atributos devem ser DIFERENTES. Tente novamente.\n");
        }
        if (escolha2 < 1 || escolha2 > 6) {
            printf("Erro: Opção inválida. Escolha um número de 1 a 6.\n");
        }
    } while (escolha1 == escolha2 || escolha2 < 1 || escolha2 > 6);

    // --- OBTENÇÃO DOS VALORES ESCOLHIDOS ---
    switch (escolha1)
    {
        case 1:
            valor1_carta1 = (double)populacao1;
            valor1_carta2 = (double)populacao2;
            break;
        case 2:
            valor1_carta1 = (double)area1;
            valor1_carta2 = (double)area2;
            break;
        case 3:
            valor1_carta1 = (double)turisticos1;
            valor1_carta2 = (double)turisticos2;
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

    switch (escolha2)
    {
        case 1:
            valor2_carta1 = (double)populacao1;
            valor2_carta2 = (double)populacao2;
            break;
        case 2:
            valor2_carta1 = (double)area1;
            valor2_carta2 = (double)area2;
            break;
        case 3:
            valor2_carta1 = (double)turisticos1;
            valor2_carta2 = (double)turisticos2;
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

    // --- COMPARAÇÃO INDIVIDUAL DE CADA ATRIBUTO ---
    // Comparação do primeiro atributo
    if (escolha1 == 5) { // Regra especial para densidade: menor vence
        resultado_attr1 = (valor1_carta1 < valor1_carta2) ? 1 : (valor1_carta2 < valor1_carta1) ? 2 : 0;
    } else { // Regra normal: maior vence
        resultado_attr1 = (valor1_carta1 > valor1_carta2) ? 1 : (valor1_carta2 > valor1_carta1) ? 2 : 0;
    }

    // Comparação do segundo atributo
    if (escolha2 == 5) { // Regra especial para densidade: menor vence
        resultado_attr2 = (valor2_carta1 < valor2_carta2) ? 1 : (valor2_carta2 < valor2_carta1) ? 2 : 0;
    } else { // Regra normal: maior vence
        resultado_attr2 = (valor2_carta1 > valor2_carta2) ? 1 : (valor2_carta2 > valor2_carta1) ? 2 : 0;
    }

    // --- EXIBIÇÃO DOS RESULTADOS ---
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("      Resultado da Comparação\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("--- Resultados Individuais ---\n");
    printf("Atributo %d: ", escolha1);
    if(resultado_attr1 == 1) {
        printf("Carta 1 Venceu (%.2f vs %.2f)\n", valor1_carta1, valor1_carta2);
    } else if(resultado_attr1 == 2) {
        printf("Carta 2 Venceu (%.2f vs %.2f)\n", valor1_carta2, valor1_carta1);
    } else {
        printf("Empate (%.2f vs %.2f)\n", valor1_carta1, valor1_carta2);
    }
    
    printf("Atributo %d: ", escolha2);
    if(resultado_attr2 == 1) {
        printf("Carta 1 Venceu (%.2f vs %.2f)\n", valor2_carta1, valor2_carta2);
    } else if(resultado_attr2 == 2) {
        printf("Carta 2 Venceu (%.2f vs %.2f)\n", valor2_carta2, valor2_carta1);
    } else {
        printf("Empate (%.2f vs %.2f)\n", valor2_carta1, valor2_carta2);
    }

    printf("\n--- Resultado da Rodada ---\n");
    
    // Lógica final do vencedor da rodada
    if (resultado_attr1 == 1 && resultado_attr2 == 1) {
        printf("VENCEDOR FINAL: Carta 1 (%s) venceu nos dois atributos!\n\n", cidade1);
    } else if (resultado_attr1 == 2 && resultado_attr2 == 2) {
        printf("VENCEDOR FINAL: Carta 2 (%s) venceu nos dois atributos!\n\n", cidade2);
    } else {
        printf("RESULTADO FINAL: Deu empate na rodada!\n\n");
    }

    return 0;
}