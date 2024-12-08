#include <stdio.h>

#define CIDADES 7
#define MESES 6

int main() {
    float pluviosidade[CIDADES][MESES];
    float mediaMensalCidade[CIDADES] = {0};
    float mediaMensalRegiao[MESES] = {0};

    printf("Digite os índices pluviométricos (em mm):\n");
    for (int cidade = 0; cidade < CIDADES; cidade++) {
        printf("\nCidade %d:\n", cidade + 1);
        for (int mes = 0; mes < MESES; mes++) {
            printf("Mês %d: ", mes + 1);
            scanf("%f", &pluviosidade[cidade][mes]);
            mediaMensalCidade[cidade] += pluviosidade[cidade][mes];
            mediaMensalRegiao[mes] += pluviosidade[cidade][mes];
        }
    }

    for (int cidade = 0; cidade < CIDADES; cidade++) {
        mediaMensalCidade[cidade] /= MESES;
    }
    for (int mes = 0; mes < MESES; mes++) {
        mediaMensalRegiao[mes] /= CIDADES;
    }

    printf("\nMédia mensal de pluviosidade por cidade:\n");
    for (int cidade = 0; cidade < CIDADES; cidade++) {
        printf("Cidade %d: %.2f mm\n", cidade + 1, mediaMensalCidade[cidade]);
    }

    printf("\nMédia de pluviosidade por mês na região:\n");
    for (int mes = 0; mes < MESES; mes++) {
        printf("Mês %d: %.2f mm\n", mes + 1, mediaMensalRegiao[mes]);
    }
}