#include <stdio.h>

// Função Ternary Search
int ternarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        // Divide o array em três partes
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Verifica se o elemento alvo está em uma das divisões
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        // Decide em qual parte continuar a busca
        if (target < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, target); // Parte esquerda
        } else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, target); // Parte direita
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target); // Parte do meio
        }
    }

    // Elemento não encontrado
    return -1;
}

// Função principal
int main() {
    int arr[] = {2, 4, 7, 10, 14, 19, 23, 27, 31, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Array ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nDigite o numero a ser procurado: ");
    scanf("%d", &target);

    int result = ternarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Elemento encontrado no indice: %d\n", result);
    } else {
        printf("Elemento nao encontrado no array.\n");
    }

    return 0;
}
