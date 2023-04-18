#include <stdio.h>

#define TAMANHO_VETOR 3 // Defina o tamanho do vetor aqui

typedef struct {
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int main() {
    Aluno alunos[TAMANHO_VETOR]; // Vetor de alunos
    int i;

    printf("Digite os dados dos alunos:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Digite a matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Digite a nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("\n");
    }

    // Exibe os dados dos alunos
    printf("Dados dos alunos:\n");
    for (i = 0; i < TAMANHO_VETOR; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("\n");
    }

    return 0;
}
