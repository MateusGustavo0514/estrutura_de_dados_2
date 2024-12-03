#include <stdio.h>

void shellSortHibbard(int arr[], int n) {
    // Gera a maior potência de 2 menos 1 (Hibbard)
    int gap = 1;
    while (gap < n) {
        gap = 2 * gap + 1; // Hibbard: 1, 3, 7, 15, ...
    }
    gap = (gap - 1) / 2; // Ajusta para o maior gap inicial
    
    // Shell Sort usando a sequência de Hibbard
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap = (gap - 1) / 2;
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

    shellSortHibbard(arr, n);

    printf("Array ordenado (Hibbard):\n");
    printArray(arr, n);

    return 0;
}