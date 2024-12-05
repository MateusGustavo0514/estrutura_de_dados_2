#include <stdio.h>
#include <string.h>

typedef struct {
    int ISBN;
    char title[100];
    char author[100];
} Book;

// Função Binary Search
int binarySearch(Book books[], int size, int targetISBN) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Verifica se o ISBN é igual ao valor central
        if (books[mid].ISBN == targetISBN) {
            return mid; // Retorna o índice do livro encontrado
        }
        
        // Se o ISBN alvo for maior, ignore a metade esquerda
        if (books[mid].ISBN < targetISBN) {
            low = mid + 1;
        }
        // Se o ISBN alvo for menor, ignore a metade direita
        else {
            high = mid - 1;
        }
    }
    return -1; // Retorna -1 se não encontrar o livro
}

void printBooks(Book books[], int size) {
    printf("\nLista de Livros:\n");
    for (int i = 0; i < size; i++) {
        printf("ISBN: %d | Titulo: %s | Autor: %s\n", books[i].ISBN, books[i].title, books[i].author);
    }
}

int main() {
    // Lista de livros com ISBN, título e autor
    Book library[] = {
        {1001, "The Great Gatsby", "F. Scott Fitzgerald"},
        {1002, "To Kill a Mockingbird", "Harper Lee"},
        {1003, "1984", "George Orwell"},
        {1004, "Moby Dick", "Herman Melville"},
        {1005, "Pride and Prejudice", "Jane Austen"},
        {1006, "War and Peace", "Leo Tolstoy"},
        {1007, "The Catcher in the Rye", "J.D. Salinger"},
        {1008, "The Odyssey", "Homer"},
        {1009, "The Hobbit", "J.R.R. Tolkien"},
        {1010, "The Lord of the Rings", "J.R.R. Tolkien"},
        {1011, "Brave New World", "Aldous Huxley"},
        {1012, "Animal Farm", "George Orwell"},
        {1013, "The Bible", "Various Authors"},
        {1014, "The Alchemist", "Paulo Coelho"},
        {1015, "The Brothers Karamazov", "Fyodor Dostoevsky"},
        {1016, "Crime and Punishment", "Fyodor Dostoevsky"},
        {1017, "The Divine Comedy", "Dante Alighieri"},
        {1018, "Les Misérables", "Victor Hugo"},
        {1019, "Don Quixote", "Miguel de Cervantes"},
        {1020, "The Stranger", "Albert Camus"}
    };

    int size = sizeof(library) / sizeof(library[0]);
    int targetISBN;
    
    // Exibe a lista de livros
    printBooks(library, size);
    
    // Solicita o ISBN para busca
    printf("\nDigite o ISBN do livro que deseja buscar: ");
    scanf("%d", &targetISBN);
    
    int result = binarySearch(library, size, targetISBN);
    
    if (result != -1) {
        printf("\nLivro encontrado:\n");
        printf("Titulo: %s\n", library[result].title);
        printf("Autor: %s\n", library[result].author);
    } else {
        printf("\nLivro não encontrado.\n");
    }
    
    return 0;
}
