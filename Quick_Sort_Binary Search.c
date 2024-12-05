#include <stdio.h>
#include <string.h>

// Função para trocar duas palavras
void swap(char arr[][50], int i, int j) {
    char temp[50];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[j]);
    strcpy(arr[j], temp);
}

// Partição do Quick Sort
int partition(char arr[][50], int low, int high) {
    char pivot[50];
    strcpy(pivot, arr[high]); // Pivô é o último elemento
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

// Função Quick Sort
void quickSort(char arr[][50], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Índice do pivô
        quickSort(arr, low, pi - 1);       // Ordena antes do pivô
        quickSort(arr, pi + 1, high);      // Ordena depois do pivô
    }
}

// Função de Binary Search
int binarySearch(char arr[][50], int n, char target[]) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(arr[mid], target);

        if (cmp == 0) {
            return mid; // Palavra encontrada
        } else if (cmp < 0) {
            left = mid + 1; // Busca na metade direita
        } else {
            right = mid - 1; // Busca na metade esquerda
        }
    }

    return -1; // Palavra não encontrada
}

// Função principal
int main() {
    int n;

    printf("Digite o numero de palavras: ");
    scanf("%d", &n);

    char words[n][50];
    printf("Digite as palavras:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    // Ordena as palavras usando Quick Sort
    quickSort(words, 0, n - 1);

    printf("\nPalavras ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    // Busca por uma palavra específica
    char target[50];
    printf("\nDigite a palavra a ser buscada: ");
    scanf("%s", target);

    int result = binarySearch(words, n, target);
    if (result != -1) {
        printf("Palavra '%s' encontrada na posicao %d.\n", target, result);
    } else {
        printf("Palavra '%s' nao encontrada.\n", target);
    }

    return 0;
}
