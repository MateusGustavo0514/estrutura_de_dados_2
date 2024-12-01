#include <stdio.h>

// Função para implementar o Interpolation Search
int interpolationSearch(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;

    // Enquanto o intervalo for válido e os valores do alvo estiverem dentro do intervalo
    while (low <= high && target >= array[low] && target <= array[high]) {
        // Evitar divisão por zero
        if (array[high] == array[low]) {
            if (array[low] == target) {
                return low;
            } else {
                return -1;
            }
        }

        // Estimativa da posição do alvo
        int pos = low + ((double)(high - low) / (array[high] - array[low])) * (target - array[low]);

        // Se o alvo estiver na posição estimada
        if (array[pos] == target) {
            return pos; // Retorna o índice
        }
        
        // Se o alvo for maior, ignoramos a metade inferior
        if (array[pos] < target) {
            low = pos + 1;
        }
        // Se o alvo for menor, ignoramos a metade superior
        else {
            high = pos - 1;
        }
    }

    return -1; // Retorna -1 se não encontrar o alvo
}

int main() {
    // Exemplo de lista ordenada
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = sizeof(array) / sizeof(array[0]); // Calcula o tamanho do array
    int target;

    // Solicita ao usuário o número a ser buscado
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &target);

    // Chama a função Interpolation Search
    int result = interpolationSearch(array, size, target);

    // Exibe o resultado
    if (result != -1) {
        printf("O numero %d foi encontrado no indice %d.\n", target, result);
    } else {
        printf("O numero %d não foi encontrado na lista.\n", target);
    }

    return 0;
}