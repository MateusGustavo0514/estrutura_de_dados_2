#include <stdio.h>
#include <string.h>

// Função para intercalar duas metades do array
void merge(char arr[][50], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char leftArray[n1][50], rightArray[n2][50];

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        strcpy(leftArray[i], arr[left + i]);
    }
    for (int j = 0; j < n2; j++) {
        strcpy(rightArray[j], arr[mid + 1 + j]);
    }

    // Mescla os arrays temporários de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(leftArray[i], rightArray[j]) <= 0) {
            strcpy(arr[k], leftArray[i]);
            i++;
        } else {
            strcpy(arr[k], rightArray[j]);
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de leftArray[], se houver
    while (i < n1) {
        strcpy(arr[k], leftArray[i]);
        i++;
        k++;
    }

    // Copia os elementos restantes de rightArray[], se houver
    while (j < n2) {
        strcpy(arr[k], rightArray[j]);
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(char arr[][50], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);        // Ordena a metade esquerda
        mergeSort(arr, mid + 1, right);  // Ordena a metade direita
        merge(arr, left, mid, right);    // Intercala as duas metades
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

    // Ordena as palavras usando Merge Sort
    mergeSort(words, 0, n - 1);

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
        printf("Palavra '%s' não encontrada.\n", target);
    }

    return 0;
}
