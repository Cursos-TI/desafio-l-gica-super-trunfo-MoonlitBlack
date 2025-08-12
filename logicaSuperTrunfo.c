#include <stdio.h>

int main(){

    // Dados das cartas 1
    char estado1[5];
    char codigo1[5];
    char cidade1[50];
    unsigned long int populacao1;
    int turisticos1;
    unsigned int area1;
    double pib1;

    // Dados das cartas 2
    char estado2[3];
    char codigo2[5];
    char cidade2[50];
    unsigned long int populacao2;
    int turisticos2;
    unsigned int area2;
    double pib2;

    /*
    Notas de uso 

    Especificadores de formato:
    %d: Para int (números inteiros, com sinal).
    %u: Para unsigned int (números inteiros sem sinal).
    %ld: Para long int (números inteiros com sinal).
    %lu: Para unsigned long int (números inteiros não assinados e longos).
    */

    printf("\n==============================\n");
    printf("     Super Trunfo: Cidades    \n");
    printf("==============================\n\n");

    // Entrada dados carta 1
    printf("Carta 1\n\n");

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

    printf("\n\n");

    // Entrada dados carta 2
    printf("Carta 2\n\n");

    printf("Digite o estado da carta 2 (EX: SP): ");
    scanf("%2s", estado2);

    printf("Digite o código da carta 2 (EX: A01): ");
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

    printf("\n\n");


    // Cálculo da densidade populacional e PIB per capita
    double densidade_popula1 = (double)populacao1 / area1;
    double pib_per1 = pib1 / populacao1;  // PIB em bilhões dividido pela população
    double densidade_popula2 = (double)populacao2 / area2;
    double pib_per2 = pib2 / populacao2;

    int escolha;

    printf("Escolha o atributo a ser comparado:\n\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. Pontos turísticos\n");
    printf("4. PIB\n");
    printf("5. Densidade populacional\n");
    printf("6. PIB per capita\n");
    scanf("%d", &escolha);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("    A carta vencedora foi: \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    // Comparação com base na escolha do atributo
    switch (escolha)
    {
    case 1:
        printf("Comparando População:\n\n");
        if (populacao1 > populacao2)
            printf("A carta número 1 venceu (Cidade: %s - Estado: %s) com população de: %lu\n\n", cidade1, estado1, populacao1);
        else if (populacao2 > populacao1)
            printf("A carta número 2 venceu (Cidade: %s - Estado: %s) com população de: %lu\n\n", cidade2, estado2, populacao2);
        else
            printf("Deu empate! (População igual)\n\n");
        break;

    case 2:
        printf("Comparando Área:\n\n");
        if (area1 > area2)
            printf("A carta número 1 venceu (Cidade: %s - Estado: %s) com área de: %u km²\n\n", cidade1, estado1, area1);
        else if (area2 > area1)
            printf("A carta número 2 venceu (Cidade: %s - Estado: %s) com área de: %u km²\n\n", cidade2, estado2, area2);
        else
            printf("Deu empate! (Área igual)\n\n");
        break;

    case 3:
        printf("Comparando Pontos turísticos:\n\n");
        if (turisticos1 > turisticos2)
            printf("A carta número 1 venceu (Cidade: %s - Estado: %s) com %d pontos turísticos\n\n", cidade1, estado1, turisticos1);
        else if (turisticos2 > turisticos1)
            printf("A carta número 2 venceu (Cidade: %s - Estado: %s) com %d pontos turísticos\n\n", cidade2, estado2, turisticos2);
        else
            printf("Deu empate! (Pontos turísticos iguais)\n\n");
        break;

    case 4:
        printf("Comparando PIB:\n\n");
        if (pib1 > pib2)
            printf("A carta número 1 venceu (Cidade: %s - Estado: %s) com PIB de: R$ %.2f bilhões\n\n", cidade1, estado1, pib1);
        else if (pib2 > pib1)
            printf("A carta número 2 venceu (Cidade: %s - Estado: %s) com PIB de: R$ %.2f bilhões\n\n", cidade2, estado2, pib2);
        else
            printf("Deu empate! (PIB igual)\n\n");
        break;

    case 5:
        printf("Comparando Densidade populacional:\n\n"); //Aqui sera vencedor o menor 
        if (densidade_popula1 < densidade_popula2)
            printf("A carta número 1 venceu (Cidade: %s - Estado: %s) com densidade de: %.2f por km²\n\n", cidade1, estado1, densidade_popula1);
        else if (densidade_popula2 < densidade_popula1)
            printf("A carta número 2 venceu (Cidade: %s - Estado: %s) com densidade de: %.2f por km²\n\n", cidade2, estado2, densidade_popula2);
        else
            printf("Deu empate! (Densidade populacional igual)\n\n");
        break;

    // Exemplo ajustado (case 6 - PIB per capita):
    case 6:
        printf("Comparando PIB per capita:\n\n");
        if (pib_per1 > pib_per2)
            printf("A carta 1 venceu (Cidade: %s - Estado: %s) com PIB per capita de: R$ %.2f\n\n", cidade1, estado1, pib_per1);
        else if (pib_per2 > pib_per1)
            printf("A carta 2 venceu (Cidade: %s - Estado: %s) com PIB per capita de: R$ %.2f\n\n", cidade2, estado2, pib_per2);
        else
            printf("Empate! PIB per capita igual.\n\n");
        break;

    default:
        printf("Opção inválida.\n\n");
        break;
    }


    printf("    Dados das cartas: \n\n");

// Exibição dos dados da Carta 1 e Carta 2, incluindo cidade, estado e código da carta
printf("Carta 1 (Cidade: %s - Estado: %s - Código: %s):\n", cidade1, estado1, codigo1);
printf("População: %lu - Área: %u km² - Pontos turísticos: %d - PIB: R$ %.2f bilhões\n", populacao1, area1, turisticos1, pib1);
printf("Densidade populacional: %.2f por km² - PIB per capita: R$ %.2f\n\n", densidade_popula1, pib_per1);

printf("Carta 2 (Cidade: %s - Estado: %s - Código: %s):\n", cidade2, estado2, codigo2);
printf("População: %lu - Área: %u km² - Pontos turísticos: %d - PIB: R$ %.2f bilhões\n", populacao2, area2, turisticos2, pib2);
printf("Densidade populacional: %.2f por km² - PIB per capita: R$ %.2f\n\n\n", densidade_popula2, pib_per2);


    return 0;
}
