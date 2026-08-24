#include <stdio.h>

void bubble_sort(int N, int A[]);

int main() {
    int size;
    printf("Informe o tamanho do seu vetor: ");
    scanf("%i", &size);

    int array[size];
    printf("Informe os elementos do seu vetor:\n");
    for (int i = 0; i < size; i++) {
        printf("a[%i]: ", i);
        scanf("%i", &array[i]);
    }

    bubble_sort(size, array);
    
    printf("Vetor ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", array[i]);
    }
    printf("\n");
    
    return 0;
}

void bubble_sort(int N, int A[]) {
    for (int i = 0; i < N; i++) {
        int is_swapped = 0;

        for (int j = 0; j < N-i-1; j++) {
            if (A[j] > A[j+1]) {
                int change = A[j];
                A[j] = A[j+1];
                A[j+1] = change;
                is_swapped = 1;
            }
        }
        if (!is_swapped) {
            break;
        }
    }
}