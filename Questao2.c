#include <stdio.h>

#define TAM 3

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAM - 1) printf("|");
        }
        printf("\n");
        if (i < TAM - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int verificarVitoria(char tabuleiro[TAM][TAM], char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAM; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) || 
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1;
        }
    }

    // Verificar diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1;
    }

    return 0;
}

int verificarEmpate(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == ' ') return 0; // Ainda há espaços vazios
        }
    }
    return 1; // Todos os espaços foram preenchidos
}

int main() {
    char tabuleiro[TAM][TAM];
    char jogadorAtual = 'X';
    int linha, coluna, jogando = 1;

    inicializarTabuleiro(tabuleiro);

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (jogando) {
        exibirTabuleiro(tabuleiro);
        printf("Jogador %c, digite a linha e a coluna (0-2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVitoria(tabuleiro, jogadorAtual)) {
            exibirTabuleiro(tabuleiro);
            printf("Parabéns! O jogador %c venceu!\n", jogadorAtual);
            jogando = 0;
        } else if (verificarEmpate(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate! O jogo terminou sem vencedor.\n");
            jogando = 0;
        } else {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
