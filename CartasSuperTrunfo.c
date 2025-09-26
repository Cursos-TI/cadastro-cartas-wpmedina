#include <stdio.h>

typedef struct {
    char estado[4];
    char codigo[10];
    char nome[60];
    long long populacao;   // habitantes
    double area;           // km²
    double pib_bilhoes;    // bilhões de R$
    int pontos_turisticos;

    // Calculados
    float densidade;       // hab/km²
    float pib_per_capita;  // R$ por habitante
} Cidade;

void calcular(Cidade *c) {
    c->densidade     = (float)((double)c->populacao / c->area);
    c->pib_per_capita = (float)((c->pib_bilhoes * 1e9) / (double)c->populacao);
}

void exibir(const Cidade *c, int idx) {
    printf("Carta %d:\n\n", idx);
    printf("Estado: %s\n", c->estado);
    printf("Codigo: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->nome);
    printf("Populacao: %lld\n", c->populacao);
    printf("Area: %.2f km2\n", c->area);
    printf("PIB: %.2f bilhoes de reais\n", c->pib_bilhoes);
    printf("Numero de Pontos Turisticos: %d\n", c->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km2\n", c->densidade);
    printf("PIB per Capita: R$ %.2f\n\n", c->pib_per_capita);
}

int main(void) {
    // Dados fixos
    Cidade c1 = {"A", "A01", "Sao Paulo",     12325000, 1521.11, 699.28, 50};
    Cidade c2 = {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Cálculos
    calcular(&c1);
    calcular(&c2);

    // Exibição
    exibir(&c1, 1);
    exibir(&c2, 2);

    // Comparações
    printf("Comparacao de Cartas:\n\n");

    // População (maior vence)
    printf("Populacao: Carta %d venceu (%d)\n", 
           (c1.populacao > c2.populacao ? 1 : 2),
           (c1.populacao > c2.populacao ? 1 : 0));

    // Área (maior vence)
    printf("Area: Carta %d venceu (%d)\n", 
           (c1.area > c2.area ? 1 : 2),
           (c1.area > c2.area ? 1 : 0));

    // PIB (maior vence)
    printf("PIB: Carta %d venceu (%d)\n", 
           (c1.pib_bilhoes > c2.pib_bilhoes ? 1 : 2),
           (c1.pib_bilhoes > c2.pib_bilhoes ? 1 : 0));

    // Pontos turísticos (maior vence)
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", 
           (c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 2),
           (c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 0));

    // Densidade (MENOR vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
           (c1.densidade < c2.densidade ? 1 : 2),
           (c1.densidade < c2.densidade ? 1 : 0));

    // PIB per Capita (maior vence)
    printf("PIB per Capita: Carta %d venceu (%d)\n", 
           (c1.pib_per_capita > c2.pib_per_capita ? 1 : 2),
           (c1.pib_per_capita > c2.pib_per_capita ? 1 : 0));

    return 0;
}
