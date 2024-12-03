#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de busca binária
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Função de busca exponencial
int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;

    return binarySearch(arr, i / 2, (i < n ? i : n - 1), x);
}

int main() {
    // Criando listas de tamanhos diferentes
    int smallList[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int largeList[100000];
    for (int i = 0; i < 100000; i++)
        largeList[i] = i * 2;

    int x = 13; // Valor a ser buscado

    // Medindo tempo para a lista pequena
    clock_t startSmall = clock();
    int resultSmall = exponentialSearch(smallList, sizeof(smallList) / sizeof(smallList[0]), x);
    clock_t endSmall = clock();

    // Medindo tempo para a lista grande
    clock_t startLarge = clock();
    int resultLarge = exponentialSearch(largeList, 100000, x);
    clock_t endLarge = clock();

    // Calculando os tempos
    double timeSmall = (double)(endSmall - startSmall) / CLOCKS_PER_SEC;
    double timeLarge = (double)(endLarge - startLarge) / CLOCKS_PER_SEC;

    // Exibindo os resultados
    printf("Resultado para a lista pequena: %d (tempo: %.6f segundos)\n", resultSmall, timeSmall);
    printf("Resultado para a lista grande: %d (tempo: %.6f segundos)\n", resultLarge, timeLarge);

    return 0;
}