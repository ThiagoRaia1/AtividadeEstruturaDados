#include <stdio.h>

int main() {
    int x, y, *p; // Declaração das variáveis: x, y (inteiros), p (ponteiro para inteiro).
    y = 0;        // Atribuição: y = 0.
    p = &y;       // O ponteiro `p` passa a apontar para `y`.
    x = *p;       // O valor de `y` (acessado por `*p`) é atribuído a `x`. Portanto, x = 0.
    x = 4;        // O valor de `x` é atualizado para 4.
    (*p)++;       // Incrementa o valor apontado por `p` (ou seja, incrementa `y`). Agora, y = 1.
    --x;          // Decrementa `x` em 1. Agora, x = 3.
    (*p) += x;    // Soma o valor de `x` ao valor apontado por `p` (ou seja, soma a `y`). Agora, y = 1 + 3 = 4.

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("*p: %d", *p);
}