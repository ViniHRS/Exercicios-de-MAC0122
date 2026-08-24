#include <stdio.h>

void insertion_sort(int N, int array[]);
int binary_search(int n, int N, int A[]);

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

    int find_number;
    printf("Informe o elemento que deseja encontrar no array: ");
    scanf("%i", &find_number);

    int position = binary_search(find_number, size, array);

    if (position == -1) {
        printf("Elemento não encontrado\n");
    }
    else {
        printf("Elemento está na posição %i\n", position);
    }

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
            else {
                break;
            }
        }
    }
}

int binary_search(int n, int N, int A[]) {
    int start = 0, end = N;

    while (start < end) {
        int middle = (start + end)/2;

        if (A[middle] == n) {
            return middle;
        }
        else if (A[middle] < n) {
            start = middle;
        }
        else {
            end = middle;
        }
    }
    //Caso o número não seja encontrado
    return -1;
}