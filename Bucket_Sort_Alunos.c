#include <stdio.h>
#include <stdlib.h>

// Função para inserir elementos em um bucket
void bucketSort(int arr[], int n) {
    int i, j, k;

    // Número de buckets
    int bucketCount = 10;
    int buckets[bucketCount][n]; // Cada linha é um bucket
    int bucketSizes[bucketCount];

    // Inicializa os tamanhos dos buckets
    for (i = 0; i < bucketCount; i++) {
        bucketSizes[i] = 0;
    }

    // Distribui os elementos nos buckets com base na faixa
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 10; // Índice do bucket (0-9)
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Ordena os buckets individualmente (usando Insertion Sort)
    for (i = 0; i < bucketCount; i++) {
        for (j = 1; j < bucketSizes[i]; j++) {
            int key = buckets[i][j];
            k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Junta os elementos dos buckets de volta ao array original
    k = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

// Função de Interpolation Search
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Fórmula para calcular a posição provável
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        // Verifica se o elemento foi encontrado
        if (arr[pos] == target) {
            return pos;
        }

        // Ajusta os limites de busca
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1; // Elemento não encontrado
}

// Função principal
int main() {
    int n;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    int notas[n];
    printf("Digite as notas dos alunos (0-100):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &notas[i]);
    }

    // Ordena as notas usando Bucket Sort
    bucketSort(notas, n);

    printf("\nNotas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", notas[i]);
    }
    printf("\n");

    // Busca uma nota específica usando Interpolation Search
    int target;
    printf("Digite a nota a ser procurada: ");
    scanf("%d", &target);

    int result = interpolationSearch(notas, n, target);
    if (result != -1) {
        printf("Nota %d encontrada na posiçao %d.\n", target, result);
    } else {
        printf("Nota %d nao encontrada.\n", target);
    }

    return 0;
}
