#include <stdio.h>
#include <math.h>

// Função para implementar o Jump Search
int jumpSearch(int array[], int size, int target) {
    int step = sqrt(size); // Tamanho do salto
    int prev = 0;

    // Salta os blocos até encontrar o intervalo onde o alvo pode estar
    while (array[step < size ? step : size - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Elemento não encontrado
        }
    }

    // Realiza a busca linear no intervalo [prev, step]
    for (int i = prev; i < (step < size ? step : size); i++) {
        if (array[i] == target) {
            return i; // Retorna o índice se encontrar o alvo
        }
    }

    return -1; // Retorna -1 se não encontrar o elemento
}

int main() {
    // Exemplo de lista ordenada
    int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int size = sizeof(array) / sizeof(array[0]); // Calcula o tamanho do array
    int target;

    // Solicita ao usuário o número a ser buscado
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &target);

    // Chama a função Jump Search
    int result = jumpSearch(array, size, target);

    // Exibe o resultado
    if (result != -1) {
        printf("O numero %d foi encontrado no indice %d.\n", target, result);
    } else {
        printf("O numero %d nao foi encontrado na lista.\n", target);
    }

    return 0;
}
