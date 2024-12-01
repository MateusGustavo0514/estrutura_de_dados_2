#include <stdio.h>

// Função para implementar a busca binária
int binarySearch(int array[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Verifica se o alvo foi encontrado
        if (array[mid] == target) {
            return mid;
        }

        // Se o alvo for maior, ignore a metade esquerda
        if (array[mid] < target) {
            left = mid + 1;
        }
        // Se o alvo for menor, ignore a metade direita
        else {
            right = mid - 1;
        }
    }
    return -1; // Retorna -1 se o alvo não for encontrado
}

// Função para implementar o Exponential Search
int exponentialSearch(int array[], int size, int target) {
    // Verifica o primeiro elemento
    if (array[0] == target) {
        return 0;
    }

    // Encontra o maior índice em que array[i] <= target
    int i = 1;
    while (i < size && array[i] <= target) {
        i *= 2; // Dobra o valor de i
    }

    // Chama a função de busca binária no intervalo [i/2, min(i, size-1)]
    return binarySearch(array, i / 2, (i < size) ? i : size - 1, target);
}

int main() {
    // Exemplo de lista ordenada
    int array[] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int size = sizeof(array) / sizeof(array[0]); // Calcula o tamanho do array
    int target;

    // Solicita ao usuário o número a ser buscado
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &target);

    // Chama a função Exponential Search
    int result = exponentialSearch(array, size, target);

    // Exibe o resultado
    if (result != -1) {
        printf("O numero %d foi encontrado no indice %d.\n", target, result);
    } else {
        printf("O numero %d nao foi encontrado na lista.\n", target);
    }

    return 0;
}