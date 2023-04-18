#include <stdio.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    int i, j, num;

    printf("Digite os %d números inteiros distintos para preencher o vetor:\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &num);

        // Verifica se o número já existe no vetor
        for (j = 0; j < i; j++) {
            if (vetor[j] == num) {
                printf("Número repetido. Digite novamente.\n");
                i--;
                break;
            }
        }
        // Se não houver repetição, adiciona o número ao vetor
        if (j == i) {
            vetor[i] = num;
        }
    }

    printf("O vetor preenchido é: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
