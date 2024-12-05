#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Variável global para contagem de comparações
int comparisons = 0;

// Funções de busca
int binarySearchWrapper(int arr[], int n, int x) {
    return binarySearch(arr, 0, n - 1, x);
}

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) return mid;  // Elemento encontrado
        if (arr[mid] < x) low = mid + 1;  // Buscar na direita
        else high = mid - 1;  // Buscar na esquerda
    }
    return -1;  // Elemento não encontrado
}

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        comparisons++;
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[(step < n ? step : n) - 1] < x) {  // Garante que não ultrapasse o limite
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;  // Caso o índice extrapole o tamanho do array
    }

    for (int i = prev; i < (step < n ? step : n); i++) {  // Garante o limite aqui também
        comparisons++;
        if (arr[i] == x) return i;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) {
        comparisons++;
        return 0;
    }

    int i = 1;
    while (i < n && arr[i] <= x) {
        comparisons++;
        i *= 2;
    }

    return binarySearch(arr, i / 2, fmin(i, n - 1), x);
}

// Função para medir desempenho
void measureSearch(int (*searchFunction)(int[], int, int), int arr[], int n, int x, const char *name) {
    comparisons = 0;  // Resetar comparações
    clock_t start, end;

    start = clock();
    int result = searchFunction(arr, n, x);  // Chama a função de busca
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n%s:\n", name);
    printf("Resultado: %s (indice %d)\n", result == -1 ? "Nao encontrado" : "Encontrado", result);
    printf("Tempo de execucao: %f segundos\n", time_taken);
    printf("Numero de comparacoes: %d\n", comparisons);
}

int main() {
    int n = 500000;  // Tamanho fixo da lista
    int *arr = (int *)malloc(n * sizeof(int));

    // Gerar lista aleatória e ordenar
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  // Números aleatórios de 0 a 9999
    }

    // Ordenar a lista
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Definir o elemento a ser buscado
    int x = arr[n / 2];  // Elemento central da lista ordenada
    printf("\nTeste com %d elementos (buscando %d):\n", n, x);

    // Testar algoritmos de busca
    measureSearch(binarySearchWrapper, arr, n, x, "Binary Search");
    measureSearch(interpolationSearch, arr, n, x, "Interpolation Search");
    measureSearch(jumpSearch, arr, n, x, "Jump Search");
    measureSearch(exponentialSearch, arr, n, x, "Exponential Search");

    free(arr);  // Liberar memória
    return 0;
}
