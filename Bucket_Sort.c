#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó na lista encadeada do bucket
typedef struct Node {
    float value;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um valor em um bucket
void insertInBucket(Node** bucket, float value) {
    Node* newNode = createNode(value);

    // Insere no início se o bucket está vazio ou o valor é menor que o primeiro elemento
    if (*bucket == NULL || value < (*bucket)->value) {
        newNode->next = *bucket;
        *bucket = newNode;
        return;
    }

    // Caso contrário, insere na posição correta
    Node* current = *bucket;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Função para mover os elementos dos buckets para o array
void collectFromBuckets(Node** buckets, int n, float arr[]) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            Node* temp = current;
            current = current->next;
            free(temp); // Libera a memória do nó processado
        }
    }
}

// Função do Bucket Sort
void bucketSort(float arr[], int n) {
    // Cria n buckets vazios
    Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]); // Calcula o índice do bucket
        insertInBucket(&buckets[bucketIndex], arr[i]);
    }

    // Coleta os elementos ordenados dos buckets de volta para o array
    collectFromBuckets(buckets, n, arr);
}

// Função para imprimir o array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Array ordenado (Bucket Sort):\n");
    printArray(arr, n);

    return 0;
}
