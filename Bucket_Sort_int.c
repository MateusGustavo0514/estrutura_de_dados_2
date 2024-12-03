#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior elemento no array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função para inserir elementos no bucket
void insertInBucket(int* bucket, int* size, int value) {
    bucket[*size] = value;
    (*size)++;
}

// Função para ordenar cada bucket individualmente usando insertion sort
void sortBucket(int* bucket, int size) {
    for (int i = 1; i < size; i++) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Função principal do Bucket Sort
void bucketSort(int arr[], int n) {
    // Encontra o maior valor no array para determinar o intervalo dos buckets
    int max = findMax(arr, n);
    int bucketCount = n; // Define o número de buckets igual ao tamanho do array
    int bucketRange = (max / bucketCount) + 1; // Intervalo de cada bucket

    // Cria buckets e inicializa contadores
    int* buckets[bucketCount];
    int bucketSizes[bucketCount];
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketRange;
        insertInBucket(buckets[bucketIndex], &bucketSizes[bucketIndex], arr[i]);
    }

    // Ordena individualmente os buckets e coleta os resultados
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            sortBucket(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
        free(buckets[i]); // Libera memória alocada para os buckets
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Array ordenado (Bucket Sort):\n");
    printArray(arr, n);

    return 0;
}