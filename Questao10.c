#include <stdio.h>
#include <locale.h>

// Função recursiva para calcular a somatória de 1 até N
int somatoria(int n) {
    if (n == 0) {
        return 0; // Caso base: a somatória de 0 é 0
    }
    return n + somatoria(n - 1); // Passo recursivo
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, insira um número positivo.\n");
        return 1;
    }

    int resultado = somatoria(n);
    printf("A somatória dos números de 1 a %d é: %d\n", n, resultado);

    return 0;
}
