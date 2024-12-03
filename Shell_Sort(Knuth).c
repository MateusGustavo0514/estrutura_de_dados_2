#include <stdio.h>

void shellSortKnuth(int arr[], int n) {
    // Gera o maior intervalo na sequência de Knuth
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1; // Knuth: 1, 4, 13, 40, ...
    }
    
    // Shell Sort usando a sequência de Knuth
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
        gap = gap / 3;
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

    shellSortKnuth(arr, n);

    printf("Array ordenado (Knuth):\n");
    printArray(arr, n);

    return 0;
}