#include <stdio.h>

// Função para trocar elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particionamento com o pivô no início
int partitionStart(int arr[], int low, int high) {
    int pivot = arr[low]; // Pivô no início
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

// Particionamento com o pivô no meio
int partitionMiddle(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(&arr[mid], &arr[low]); // Move o pivô do meio para o início
    return partitionStart(arr, low, high);
}

// Particionamento com o pivô no final
int partitionEnd(int arr[], int low, int high) {
    swap(&arr[high], &arr[low]); // Move o pivô do final para o início
    return partitionStart(arr, low, high);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high, int (*partition)(int[], int, int)) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1, partition);
        quickSort(arr, pivotIndex + 1, high, partition);
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
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    // Ordenação com o pivô no início
    int arr1[] = {34, 7, 23, 32, 5, 62};
    printf("\nOrdenando com pivo no inicio:\n");
    quickSort(arr1, 0, n - 1, partitionStart);
    printArray(arr1, n);

    // Ordenação com o pivô no meio
    int arr2[] = {34, 7, 23, 32, 5, 62};
    printf("\nOrdenando com pivo no meio:\n");
    quickSort(arr2, 0, n - 1, partitionMiddle);
    printArray(arr2, n);

    // Ordenação com o pivô no final
    int arr3[] = {34, 7, 23, 32, 5, 62};
    printf("\nOrdenando com pivo no final:\n");
    quickSort(arr3, 0, n - 1, partitionEnd);
    printArray(arr3, n);

    return 0;
}