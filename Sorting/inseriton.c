#include <stdio.h>

void insertion_sort(int N, int array[]);

int main() {
    int size;
    printf("Informe o tamanho do array: ");
    scanf("%i", &size);

    int array[size];
    printf("Informe os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        printf("[%i]: ", i);
        scanf("%i", &array[i]);
    }

    insertion_sort(size, array);
    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", array[i]);
    }
    printf("\n");

    return 0;
}

void insertion_sort(int N, int array[]) {
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
                int change = array[j];
                array[j] = array[j-1];
                array[j-1] = change;
            }
        }
    }
}