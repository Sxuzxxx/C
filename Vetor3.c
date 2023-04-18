#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

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

    // Ordena o vetor em ordem crescente
    bubbleSort(vetor, tamanho);

    printf("O vetor preenchido e ordenado é: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
