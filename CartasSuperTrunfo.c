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
    // Sem if/else: cálculo direto
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
    // Dados fixos (não há leitura do usuário)
    Cidade c1 = {"A", "A01", "Sao Paulo",     12325000, 1521.11, 699.28, 50};
    Cidade c2 = {"B", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Cálculos (sem condições)
    calcular(&c1);
    calcular(&c2);

    // Exibição (sem laços)
    exibir(&c1, 1);
    exibir(&c2, 2);

    return 0;
}
