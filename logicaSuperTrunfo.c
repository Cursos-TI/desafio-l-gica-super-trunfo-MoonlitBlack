#include <stdio.h>
int main(){

    //Dados das cartas 1
    char estado1[5];
    char codigo1[5];
    char cidade1[50];
    unsigned long int populacao1;
    int turisticos1;
    double area1;
    double pib1;

    //Dados das cartas 2
    char estado2[3];
    char codigo2[5];
    char cidade2[50];
    unsigned long int populacao2;
    int turisticos2;
    double area2;
    double pib2;

    /*
    Notas de uso 

    Especificadores de formato:
    %d: Para int (números inteiros, com sinal).
    %u: Para unsigned int (números inteiros sem sinal).
    %ld: Para long int (números inteiros com sinal).
    %lu: Para unsigned long int (números inteiros não assinados e longos).*/

    printf("\n==============================\n");
    printf("     Super Trunfo: Cidades    \n");
    printf("==============================\n\n");

    //Entrada dados carta 1
    printf("Carta 1\n\n");

    printf("Digite o estado da carta 1 (EX: SP): ");
    scanf("%2s", estado1); //%s sempre que for char[5](Char com mais de uma letra)

    printf("Digite o Código da carta 1 (EX:A01): ");
    scanf("%4s", codigo1);

    printf("Digite o nome da cidade da carta 1: ");
    scanf(" %49[^\n]", cidade1); 

    printf("Digite a população da carta 1: ");
    scanf("%lu", &populacao1); //Usa %lu para ler unsigned long int

    printf("Digite a área da carta 1 (em km²): ");
    scanf("%lf", &area1); // Usa %lf para ler double

    printf("Digite a quantidade de pontos turisticos da carta 1: ");
    scanf("%d", &turisticos1);

    printf("Digite o PIB da carta 1 em bilhões de reais: ");
    scanf("%lf", &pib1); //Usar %lf para ler double

    printf("\n\n");

    //Entrada dados carta 2
    printf("Carta 2\n\n");

    printf("Digite o estado da carta 2 (EX: SP): ");
    scanf("%2s", estado2); //%s sempre que for char[5](Char com mais de uma letra)

    printf("Digite o Código da carta 2 (EX:A01): ");
    scanf("%4s", codigo2);

    printf("Digite o nome da cidade da carta 2: ");
    scanf(" %49[^\n]", cidade2); // Lê até 49 caracteres ou até o ENTER

    printf("Digite a população da carta 2: ");
    scanf("%lu", &populacao2); //Usa %lu para ler unsigned long int

    printf("Digite a área da carta 2 (em km²): ");
    scanf("%lf", &area2); // Usa %lf para ler double

    printf("Digite a quantidade de pontos turisticos da carta 2: ");
    scanf("%d", &turisticos2);

    printf("Digite o PIB da carta 2 em bilhões de reais: ");
    scanf("%lf", &pib2); //Usar %lf para ler double

    printf("\n\n");

    //Exibição da carta 1

    printf("Dados da Carta 1\n\n");

    printf("Código da carta 1: %s\n", codigo1);
    printf("Estado da carta 1: %s\n", estado1);
    printf("Cidade da carta 1: %s\n", cidade1);
    printf("População da carta 1: %lu\n", populacao1);
    printf("Área da carta 1: %lf km²\n", area1);
    printf("Pontos turísticos da carta 1: %d\n", turisticos1);
    printf("PIB da carta 1: R$ %.2f bilhões\n", pib1);

    // Calcule a densidade populacional como um valor de ponto flutuante
    double densidade_popula1 = (double)populacao1 / area1;
    printf("Densidade populacional carta 1: %.2lf por km²\n", densidade_popula1);
    double pib_per1 = pib1 / populacao1;
    printf("PIB per capita carta 1: %.2f\n\n", pib_per1);

    //Exibição da carta 2

    printf("Dados da Carta 2\n\n");

    printf("Código da carta 2: %s\n", codigo2);
    printf("Estado da carta 2: %s\n", estado2);
    printf("Cidade da carta 2: %s\n", cidade2);
    printf("População da carta 2: %lu\n", populacao2);
    printf("Área da carta 2: %lf km²\n", area2);
    printf("Pontos turísticos da carta 2: %d\n", turisticos2);
    printf("PIB da carta 2: R$ %.2f bilhões\n", pib2);

    // Calcule a densidade populacional como um valor de ponto flutuante
    double densidade_popula2 = (double)populacao2 / area2;
    printf("Densidade populacional carta 2: %.2lf por km²\n", densidade_popula2);
    double pib_per2 = pib2 / populacao2;
    printf("PIB per capita carta 2: %.2f\n\n\n", pib_per2);


    //Comparação das cartas vencedoras
    printf("Comparação de cartas (Atributo: Área):\n\n");
    printf("Carta 1 - %s (%s): %.2lf km²\n", cidade1, estado1, area1);
    printf("Carta 2 - %s (%s): %.2lf km²\n\n", cidade2, estado2, area2);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("    A carta vencedora foi: \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    //Implementação do IF e ELSE para definir ganhador
    if (area1 > area2) // A pergunta
    {
        printf("Carta 1 com a cidade: %s, venceu com %lf km²\n\n", cidade1, area1); // Se a resposta for sim
    }
    
    else 
    {
        printf("Carta 2 com a cidade: %s, venceu com %lf km²\n\n\n", cidade2, area2); // Se a resposta for não
    }
    


    return 0;

}