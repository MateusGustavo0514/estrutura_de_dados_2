#include <stdio.h>

int main()
{
    printf(" --- valores inseridos ---\n");   
    printf(" valor 29 = %d\n", 29/10);
    printf(" valor 25 = %d\n", 25/10);
    printf(" valor 3 = %d\n", 3/10);
    printf(" valor 49 = %d\n", 49/10);
    printf(" valor 9 = %d\n", 9/10);
    printf(" valor 37 = %d\n", 37/10);
    printf(" valor 21 = %d\n", 21/10);
    printf(" valor 43 = %d\n", 43/10);
    printf(" valor 31 = %d\n", 31/10);
    printf(" valor 5 = %d\n\n", 5/10);
    
    printf(" --- divisao em cada bucket ---\n bucket 0 = 3, 9, 5\n bucket 1 = nenhum valor\n bucket 2 = 29, 25, 21\n bucket 3 = 37, 31\n bucket 4 = 49, 43\n\n");
    
    printf(" --- array final ---\n [3 5 9 21 25 29 31 37 43 49]");
    return 0;
}