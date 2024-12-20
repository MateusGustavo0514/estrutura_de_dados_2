#include <stdio.h>

// Função para mesclar duas sublistas ordenadas
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho da primeira sublista
    int n2 = right - mid;    // Tamanho da segunda sublista

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Índices iniciais das sublistas e do array principal
    int i = 0, j = 0, k = left;

    // Mescla as sublistas no array principal
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Evita estouro de int

        // Ordena as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
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
    int arr[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado (Merge Sort):\n");
    printArray(arr, n);

    return 0;
}
