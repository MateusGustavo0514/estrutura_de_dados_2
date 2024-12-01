#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Função de Busca Binária
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Função de Jump Search
int jump_search(int arr[], int size, int target) {
    int step = sqrt(size); // Determina o "passo"
    int prev = 0;
    while (arr[step < size ? step : size - 1] < target) { // Impede ultrapassar o limite do array
        prev = step;
        step += sqrt(size);
        if (prev >= size) return -1;
    }

    for (int i = prev; i < (step < size ? step : size); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int size, target;

    // Solicitar ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &size);

    int arr[size];

    // Solicitar ao usuário para preencher o array
    printf("Digite os %d elementos do array (ordenados):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Limpar o buffer de entrada após a leitura do array
    while(getchar() != '\n'); 

    // Solicitar o valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &target);

    // Medir tempo para Busca Binária
    clock_t start_bin = clock();  // Inicia a medição de tempo
    int result_bin = binary_search(arr, size, target);
    clock_t end_bin = clock();    // Finaliza a medição de tempo
    double time_taken_bin = (double)(end_bin - start_bin) / CLOCKS_PER_SEC;  // Calcula o tempo gasto

    // Medir tempo para Jump Search
    clock_t start_jump = clock();  // Inicia a medição de tempo
    int result_jump = jump_search(arr, size, target);
    clock_t end_jump = clock();    // Finaliza a medição de tempo
    double time_taken_jump = (double)(end_jump - start_jump) / CLOCKS_PER_SEC;  // Calcula o tempo gasto

    // Exibe os resultados
    printf("Jump Search: Índice = %d, Tempo = %f segundos\n", result_jump, time_taken_jump);
    printf("Busca Binária: Índice = %d, Tempo = %f segundos\n", result_bin, time_taken_bin);

    return 0;
}