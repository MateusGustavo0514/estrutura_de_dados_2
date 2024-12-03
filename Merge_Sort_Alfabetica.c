#include <stdio.h>
#include <string.h>

#define MAX 100 // Tamanho máximo de cada string

// Função para mesclar duas sublistas ordenadas de strings
void merge(char arr[][MAX], int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamanho da primeira sublista
    int n2 = right - mid;    // Tamanho da segunda sublista

    // Arrays temporários para armazenar as strings
    char L[n1][MAX], R[n2][MAX];

    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        strcpy(L[i], arr[left + i]);
    }
    for (int j = 0; j < n2; j++) {
        strcpy(R[j], arr[mid + 1 + j]);
    }

    // Índices iniciais das sublistas e do array principal
    int i = 0, j = 0, k = left;

    // Mescla as sublistas no array principal
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }
}

// Função principal do Merge Sort para strings
void mergeSort(char arr[][MAX], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Evita estouro de int

        // Ordena as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mescla as duas metades
        merge(arr, left, mid, right);
    }
}

// Função para imprimir o array de strings
void printArray(char arr[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n;
    printf("Digite o numero de strings: ");
    scanf("%d", &n);
    getchar(); // Limpa o buffer

    char arr[n][MAX];
    printf("Digite %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove o '\n' do final
    }

    printf("\nStrings originais:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nStrings ordenadas (Merge Sort):\n");
    printArray(arr, n);

    return 0;
}
