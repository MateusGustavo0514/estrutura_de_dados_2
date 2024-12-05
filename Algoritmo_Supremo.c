#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Funções de ordenação
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void radixSort(int arr[], int n, int max);
void shellSort(int arr[], int n);
void bucketSort(int arr[], int n);

// Funções de busca
int binarySearch(int arr[], int low, int high, int x);
int exponentialSearch(int arr[], int n, int x);
int interpolationSearch(int arr[], int n, int x);
int jumpSearch(int arr[], int n, int x);
int ternarySearch(int arr[], int low, int high, int x);

// Funções de ordenação
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // merge(arr, left, mid, right); // Implementar merge
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
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
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

void radixSort(int arr[], int n, int max) {
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // countSort(arr, n, exp); // Implementar countSort
    }
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void bucketSort(int arr[], int n) {
    // Implementar Bucket Sort
}

// Funções de busca
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) return 0;
    int i = 1;
    while (i < n && arr[i] <= x) i *= 2;
    return binarySearch(arr, i / 2, fmin(i, n - 1), x);
}

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
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

    // Modificado para corrigir o erro de fmin
    while (arr[(step < n ? step : n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1; // Elemento não encontrado
    }

    // Realiza a busca linear dentro do bloco
    for (int i = prev; i < (step < n ? step : n); i++) {
        if (arr[i] == x)
            return i;
    }

    return -1; // Elemento não encontrado
}

int ternarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (arr[mid1] == x) return mid1;
        if (arr[mid2] == x) return mid2;
        if (x < arr[mid1]) return ternarySearch(arr, low, mid1 - 1, x);
        if (x > arr[mid2]) return ternarySearch(arr, mid2 + 1, high, x);
        return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
    }
    return -1;
}

int main() {
    int n = 10;
    int arr[] = {9, 7, 5, 11, 12, 10, 3, 6, 4, 8};

    printf("Escolha um algoritmo de ordenacao:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Radix Sort\n");
    printf("6. Shell Sort\n");
    printf("7. Bucket Sort\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertionSort(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            break;
        case 3:
            mergeSort(arr, 0, n - 1);
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            break;
        case 5:
            radixSort(arr, n, 12); // Exemplo de max para radixSort
            break;
        case 6:
            shellSort(arr, n);
            break;
        case 7:
            bucketSort(arr, n);
            break;
        default:
            printf("Opcao invalida\n");
            return 0;
    }

    printf("Lista ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nEscolha um algoritmo de busca:\n");
    printf("1. Binary Search\n");
    printf("2. Exponential Search\n");
    printf("3. Interpolation Search\n");
    printf("4. Jump Search\n");
    printf("5. Ternary Search\n");

    scanf("%d", &choice);

    int target;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &target);

    int result = -1;

    switch (choice) {
        case 1:
            result = binarySearch(arr, 0, n - 1, target);
            break;
        case 2:
            result = exponentialSearch(arr, n, target);
            break;
        case 3:
            result = interpolationSearch(arr, n, target);
            break;
        case 4:
            result = jumpSearch(arr, n, target);
            break;
        case 5:
            result = ternarySearch(arr, 0, n - 1, target);
            break;
        default:
            printf("Opção inválida\n");
            return 0;
    }

    if (result != -1) {
        printf("Elemento encontrado no indice %d.\n", result);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}
