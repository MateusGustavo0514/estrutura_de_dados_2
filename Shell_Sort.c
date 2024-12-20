#include <stdio.h>

void shellSort(int arr[], int n) {
    // Gaps padrão: inicia em n/2 e divide por 2 em cada iteração
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Array ordenado (Shell Sort padrão):\n");
    printArray(arr, n);

    return 0;
}