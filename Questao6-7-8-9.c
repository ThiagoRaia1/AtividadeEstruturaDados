#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Voo {
    int numeroVoo;
    int dataVoo;         // 1: seg, 2: ter, ..., 8: diário
    int hora, minuto;    // Horário do voo
    int aeroportoSaida;  // ID do aeroporto de saída
    int aeroportoChegada; // ID do aeroporto de chegada
    int rota;            // ID da rota
    float tempoEstimado; // Tempo estimado de voo em horas
    int passageiros;     // Número de passageiros a bordo
    struct Voo* proximo; // Ponteiro para o próximo voo na lista
} Voo;

// Função para criar um novo voo
Voo* criarVoo(int numeroVoo, int dataVoo, int hora, int minuto, int aeroportoSaida,
              int aeroportoChegada, int rota, float tempoEstimado, int passageiros) {
    Voo* novoVoo = (Voo*)malloc(sizeof(Voo));
    if (!novoVoo) {
        printf("Erro ao alocar memória para o voo.\n");
        exit(1);
    }
    novoVoo->numeroVoo = numeroVoo;
    novoVoo->dataVoo = dataVoo;
    novoVoo->hora = hora;
    novoVoo->minuto = minuto;
    novoVoo->aeroportoSaida = aeroportoSaida;
    novoVoo->aeroportoChegada = aeroportoChegada;
    novoVoo->rota = rota;
    novoVoo->tempoEstimado = tempoEstimado;
    novoVoo->passageiros = passageiros;
    novoVoo->proximo = NULL;
    return novoVoo;
}

// Função para cadastrar um novo voo na lista
Voo* cadastrarVoo(Voo* lista) {
    int numeroVoo, dataVoo, hora, minuto, aeroportoSaida, aeroportoChegada, rota, passageiros;
    float tempoEstimado;

    printf("\n=== Cadastro de Voo ===\n");
    printf("Número do Voo: ");
    scanf("%d", &numeroVoo);

    printf("Data do Voo (1-Seg, 2-Ter, ..., 8-Diário): ");
    scanf("%d", &dataVoo);

    printf("Horário do Voo\n");
    printf("  Hora (0-23): ");
    scanf("%d", &hora);
    printf("  Minuto (0-59): ");
    scanf("%d", &minuto);

    printf("Aeroporto de Saída (ID): ");
    scanf("%d", &aeroportoSaida);

    printf("Aeroporto de Chegada (ID): ");
    scanf("%d", &aeroportoChegada);

    printf("Rota (ID): ");
    scanf("%d", &rota);

    printf("Tempo Estimado de Voo (em horas): ");
    scanf("%f", &tempoEstimado);

    printf("Passageiros a Bordo: ");
    scanf("%d", &passageiros);

    Voo* novoVoo = criarVoo(numeroVoo, dataVoo, hora, minuto, aeroportoSaida, aeroportoChegada, rota, tempoEstimado, passageiros);

    // Inserção no início da lista
    novoVoo->proximo = lista;
    return novoVoo;
}

// Função para consultar um voo pelo número
void consultaVoo(Voo* lista, int numeroVoo) {
    Voo* atual = lista;
    while (atual != NULL) {
        if (atual->numeroVoo == numeroVoo) {
            printf("\n--- Detalhes do Voo ---\n");
            printf("Número do Voo: %d\n", atual->numeroVoo);
            printf("Data do Voo: %d\n", atual->dataVoo);
            printf("Horário do Voo: %02d:%02d\n", atual->hora, atual->minuto);
            printf("Aeroporto de Saída: %d\n", atual->aeroportoSaida);
            printf("Aeroporto de Chegada: %d\n", atual->aeroportoChegada);
            printf("Rota: %d\n", atual->rota);
            printf("Tempo Estimado de Voo: %.2f horas\n", atual->tempoEstimado);
            printf("Passageiros a Bordo: %d\n", atual->passageiros);
            printf("-----------------------\n");
            return;
        }
        atual = atual->proximo;
    }
    printf("Voo com número %d não encontrado.\n", numeroVoo);
}

// Função para remover um voo pelo número
Voo* removeVoo(Voo* lista, int numeroVoo) {
    Voo* atual = lista;
    Voo* anterior = NULL;

    while (atual != NULL) {
        if (atual->numeroVoo == numeroVoo) {
            if (anterior == NULL) {
                lista = atual->proximo; // Remove do início da lista
            } else {
                anterior->proximo = atual->proximo; // Remove do meio ou fim
            }
            free(atual);
            printf("Voo com número %d removido com sucesso.\n", numeroVoo);
            return lista;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Voo com número %d não encontrado.\n", numeroVoo);
    return lista;
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    Voo* listaVoos = NULL;
    int opcao, numeroVoo;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Cadastrar Voo\n");
        printf("2. Consultar Voo\n");
        printf("3. Remover Voo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listaVoos = cadastrarVoo(listaVoos);
                break;
            case 2:
                printf("Digite o número do voo para consulta: ");
                scanf("%d", &numeroVoo);
                consultaVoo(listaVoos, numeroVoo);
                break;
            case 3:
                printf("Digite o número do voo para remover: ");
                scanf("%d", &numeroVoo);
                listaVoos = removeVoo(listaVoos, numeroVoo);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    // Liberação da memória de todos os voos na lista
    while (listaVoos != NULL) {
        Voo* temp = listaVoos;
        listaVoos = listaVoos->proximo;
        free(temp);
    }

    return 0;
}
