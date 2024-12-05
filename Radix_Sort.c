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

// Função para realizar a contagem e ordenar por dígitos
void countingSort(int arr[], int n, int exp, int base) {
    int output[n];
    int count[base];
    for (int i = 0; i < base; i++) {
        count[i] = 0;
    }

    // Conta as ocorrências de dígitos
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % base;
        count[digit]++;
    }

    // Calcula posições acumulativas
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    // Preenche o array de saída
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % base;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal do Radix Sort
void radixSort(int arr[], int n, int base) {
    // Encontra o maior valor no array
    int max = findMax(arr, n);

    // Ordena por cada dígito, aumentando a base exponencial
    for (int exp = 1; max / exp > 0; exp *= base) {
        countingSort(arr, n, exp, base);
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
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    printf("\nOrdenando em base 10:\n");
    radixSort(arr, n, 10);
    printArray(arr, n);

    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
    printf("\nOrdenando em base 2:\n");
    radixSort(arr2, n, 2);
    printArray(arr2, n);

    int arr3[] = {170, 45, 75, 90, 802, 24, 2, 66};
    printf("\nOrdenando em base 5:\n");
    radixSort(arr3, n, 5);
    printArray(arr3, n);

    return 0;
}