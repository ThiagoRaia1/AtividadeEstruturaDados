#include <stdio.h>

main() {
    int matriz[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, maior = matriz[0][0], menor = matriz[0][0];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }
    printf("\nMaior: %d\n", maior);
    printf("\nMenor: %d\n", menor);
}