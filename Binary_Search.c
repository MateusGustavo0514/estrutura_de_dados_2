#include <stdio.h>

// Função para implementar o Binary Search
int binarySearch(int array[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calcula o índice do meio
        
        // Verifica se o elemento está no meio
        if (array[mid] == target) {
            return mid;
        }
        // Se o alvo é maior, ignora a metade esquerda
        if (array[mid] < target) {
            left = mid + 1;
        } else { // Ignora a metade direita
            right = mid - 1;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

int main() {
    // Exemplo de lista ordenada
    int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 10};
    int size = sizeof(array) / sizeof(array[0]); // Calcula o tamanho do array
    int target;

    // Solicita ao usuário o número a ser buscado
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &target);

    // Chama a função Binary Search
    int result = binarySearch(array, size, target);

    // Exibe o resultado
    if (result != -1) {
        printf("O numero %d foi encontrado no indice %d.\n", target, result);
    } else {
        printf("O numero %d nao foi encontrado na lista.\n", target);
    }

    return 0;
}

/* Explicação de por que a lista deve ser ordenada:
    O Binary Search possui a capacidade de realizar buscas rápidas dividindo a lista em duas 
    partes repetidas vezes até encontrar o elemento desejado ou concluir que o elemento não existe 
    naquela lista, para realizar tais divisões primeiro é necessário colocar um ponteiro no inicio e 
    um ponteiro no final da lista, com os ponteiros colocados em ambas as extremidades é possível encontrar
    o indice do meio da lista, ai entra a importancia da lista estar ordenada, o algoritmo compara o valor do meio,
    caso o valor seja menor que o valor do meio o algoritmo descarta a metade da direita, caso o valor seja 
    maior o algoritmo descarta a metade da esquerda. Se a lista de valores não estiver ordenada, o algoritmo
    não vai conseguir fazer essas comparações.
*/

