#include <stdio.h>

#define ALUNOS 5
#define PROVAS 4

int main() {
    float notas[ALUNOS][PROVAS];
    float mediaAluno[ALUNOS], mediaTurma = 0;

    printf("Digite as notas dos %d alunos:\n", ALUNOS);
    for (int i = 0; i < ALUNOS; i++) {
        float somaNotas = 0;
        printf("\nAluno %d:\n", i + 1);
        for (int j = 0; j < PROVAS; j++) {
            printf("Nota da prova %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            somaNotas += notas[i][j];
        }
        mediaAluno[i] = somaNotas / PROVAS;
        mediaTurma += mediaAluno[i];
    }

    mediaTurma /= ALUNOS;

    printf("\nMédias dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("Aluno %d: %.2f\n", i + 1, mediaAluno[i]);
    }

    printf("\nMédia da turma: %.2f\n", mediaTurma);
}