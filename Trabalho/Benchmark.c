#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar(int arr[], int n) {
    // Encontra o valor máximo no array
    int max = arr[0]; // Inicializa com o primeiro elemento
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Aloca dinamicamente memória para o array de contagem
    int *count = (int *)malloc((max + 1) * sizeof(int));
    if (count == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa o array de contagem com zeros
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Conta a ocorrência de cada número
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Imprime os números em ordem crescente com base na contagem
    int k = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = i;
        }
    }

    // Libera a memória alocada para o array de contagem
    free(count);
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {1000000, 10000000, 100000000, 5000000, 20000000}; // tamanhos dos conjuntos de dados
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(EXIT_FAILURE);
        }

        // Preenche o vetor com números aleatórios entre 0 e 999
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % 1000;
        }

        // Realiza 3 testes de tempo
        printf("Tamanho de dados: %d\n", n);
        for (int teste = 0; teste < 3; teste++) {
            clock_t inicio = clock();
            ordenar(arr, n);
            clock_t fim = clock();
            double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("Teste %d - Tempo de execucao: %.6f segundos\n", teste + 1, tempo_execucao);
        }

        free(arr); // Libera a memória alocada para o vetor
        printf("\n");
    }

    return 0;
}
