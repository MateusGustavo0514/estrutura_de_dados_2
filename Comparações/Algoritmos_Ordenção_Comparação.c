#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int comparisons = 0; // Variável global para contar comparações

// Função Shell Sort
void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                comparisons++;  // Contabilizando as comparações
            }
            arr[j] = temp;
        }
    }
}

// Função Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisons++;  // Contabilizando a comparação
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Função Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;  // Contabilizando a comparação
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Função Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        comparisons++;  // Contabilizando a comparação
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função Bucket Sort
void bucketSort(int arr[], int n) {
    int i, j;
    int max = arr[0], min = arr[0];

    // Encontrar o valor máximo e mínimo
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        comparisons++;  // Contabilizando a comparação
    }

    int bucketCount = (max - min) / n + 1;
    int buckets[bucketCount][n];
    int bucketSizes[bucketCount];

    for (i = 0; i < bucketCount; i++) {
        bucketSizes[i] = 0;
    }

    // Distribuindo os números nas baldes
    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / n;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
        comparisons++;  // Contabilizando a comparação
    }

    // Ordenando cada balde e juntando
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[j + i * n] = buckets[i][j];
        }
    }
}

// Função Radix Sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    int i;

    // Contando a ocorrência de cada dígito
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
        comparisons++;  // Contabilizando a comparação
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construindo o array de saída
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiando os elementos de volta para o array original
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Função para medir o tempo de execução e contar comparações
void measureAndCompare(void (*sortFunction)(int[], int), int arr[], int n) {
    comparisons = 0; // Resetando o contador de comparações
    struct timeval start, end;
    gettimeofday(&start, NULL);  // Obtém o tempo de início
    sortFunction(arr, n);
    gettimeofday(&end, NULL);    // Obtém o tempo de término
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Tempo de execucao: %f segundos\n", time_taken);
    printf("Numero de comparacoes: %d\n", comparisons);
}

void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n - 1); // Chama a função mergeSort com os índices necessários
}

void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1); // Chama a função quickSort com os índices necessários
}

int main() {
    int n = 10000; // Tamanho da lista
    int *arr = (int*)malloc(n * sizeof(int));

    // Gerar lista aleatória
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // Cópias da lista original para cada algoritmo
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));
    int *arr3 = (int*)malloc(n * sizeof(int));
    int *arr4 = (int*)malloc(n * sizeof(int));
    int *arr5 = (int*)malloc(n * sizeof(int));
    int *arr6 = (int*)malloc(n * sizeof(int));

    // Copiar a lista original para cada array
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
        arr5[i] = arr[i];
        arr6[i] = arr[i];
    }

    // Chamar a função measureAndCompare para cada algoritmo
    printf("\nShell Sort:\n");
    measureAndCompare(shellSort, arr1, n);
    
    printf("\nMerge Sort:\n");
    measureAndCompare(mergeSortWrapper, arr2, n);
    
    printf("\nSelection Sort:\n");
    measureAndCompare(selectionSort, arr3, n);
    
    printf("\nQuick Sort:\n");
    measureAndCompare(quickSortWrapper, arr4, n);
    
    printf("\nBucket Sort:\n");
    measureAndCompare(bucketSort, arr5, n);
    
    printf("\nRadix Sort:\n");
    measureAndCompare(radixSort, arr6, n);

    // Liberar memória
    free(arr);
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    free(arr5);
    free(arr6);

    return 0;
}
