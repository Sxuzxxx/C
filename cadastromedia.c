#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 10

struct Aluno {
    char nome[100];
    char matricula[20];
    float nota1;
    float nota2;
};

void cadastrarAluno(struct Aluno alunos[], int *contador) {
    if (*contador >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }
    
    struct Aluno *aluno = &alunos[*contador];
    
    printf("Digite o nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0';
    
    printf("Digite a matricula: ");
    fgets(aluno->matricula, sizeof(aluno->matricula), stdin);
    aluno->matricula[strcspn(aluno->matricula, "\n")] = '\0';
    
    printf("Digite a nota 1: ");
    scanf("%f", &(aluno->nota1));
    
    printf("Digite a nota 2: ");
    scanf("%f", &(aluno->nota2));
    
    getchar(); 
    
    printf("Aluno cadastrado com sucesso!\n");
    
    (*contador)++;
}

void imprimirAlunos(const struct Aluno alunos[], int contador) {
    if (contador == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }
    
    for (int i = 0; i < contador; i++) {
        const struct Aluno *aluno = &alunos[i];
        printf("Aluno %d:\n", i+1);
        printf("Nome: %s\n", aluno->nome);
        printf("Matricula: %s\n", aluno->matricula);
        printf("Nota 1: %.2f\n", aluno->nota1);
        printf("Nota 2: %.2f\n", aluno->nota2);
        printf("Media: %.2f\n", (aluno->nota1 + aluno->nota2) / 2);
        printf("=====================\n");
    }
}

void alterarDados(struct Aluno alunos[], int contador) {
    if (contador == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }
    
    printf("Digite o numero do aluno que deseja alterar os dados (1-%d): ", contador);
    int num_aluno;
    scanf("%d", &num_aluno);
    getchar();
    
    if (num_aluno < 1 || num_aluno > contador) {
        printf("Numero de aluno invalido!\n");
        return;
    }
    
    struct Aluno *aluno = &alunos[num_aluno - 1];
    
    printf("Digite o novo nome: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    aluno->nome[strcspn(aluno->nome, "\n")] = '\0'; 
    
    printf("Digite a nova matricula: ");
    fgets(aluno->matricula, sizeof(aluno->matricula), stdin);
    aluno->matricula[strcspn(aluno->matricula, "\n")] = '\0'; 
    
    printf("Digite a nova nota 1: ");
    scanf("%f", &(aluno->nota1));
    
    printf("Digite a nova nota 2: ");
    scanf("%f", &(aluno->nota2));
    
    getchar(); 
    
    printf("Dados do aluno alterados com sucesso!\n");
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int contador = 0;
    int opcao;
    int sair = 0;
    
    while (!sair) {
        printf("\n==========================\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Mostrar dados cadastrados\n");
        printf("3 - Alterar dados do aluno\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &contador);
                break;
            case 2:
                imprimirAlunos(alunos, contador);
                break;
            case 3:
                alterarDados(alunos, contador);
                break;
            case 0:
                sair = 1;
                break;
            default:
                printf("Opcao invalida. Tente novamente!\n");
        }
    }
    
    return 0;
}
