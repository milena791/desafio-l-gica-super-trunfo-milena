#include <stdio.h>

// Estrutura para armazenar informações das cartas
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para exibir informações de uma carta
void exibirCarta(Carta c) {
    printf("\nCidade: %s (%s)\n", c.nome, c.estado);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", c.densidade_populacional);
    printf("PIB per capita: %.2f\n", c.pib_per_capita);
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparacao de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s: %.2f\n", c1.nome, c1.pib_per_capita);
    printf("Carta 2 - %s: %.2f\n", c2.nome, c2.pib_per_capita);
    
    if (c1.pib_per_capita > c2.pib_per_capita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (c1.pib_per_capita < c2.pib_per_capita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Definição das cartas com novos exemplos
    Carta carta1 = {"MG", "101", "Belo Horizonte", 2527000, 331.40, 88.73, 12, 0, 0};
    Carta carta2 = {"PR", "202", "Curitiba", 1963000, 435.04, 94.80, 15, 0, 0};
    
    // Calcular atributos derivados
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
    
    // Exibir cartas
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Comparar cartas
    compararCartas(carta1, carta2);
    
    return 0;
}
