#include <stdio.h>

int partitioning(int A[], int start, int end);
void quick_sort(int A[], int start, int end);


int main() {
    int size;
    printf("Informe o tamanho do array: ");
    scanf("%i", &size);

    int array[size];
    printf("Informe os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        printf("a[%i]: ", i);
        scanf("%i", &array[i]);
    }

    quick_sort(array, 0, size-1);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", array[i]);
    }
    printf("\n");

    return 0;
}

int partitioning(int A[], int start, int end) {
    int pivot = A[end];
    int p = start, swapp;

    //Partitioning the array
    for (int i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swapp = A[p];
            A[p] = A[i];
            A[i] = swapp;
            p++;
        }
    }
    //Moving the pivot to its position
    swapp = A[p];
    A[p] = A[end];
    A[end] = swapp;

    return p;
}

void quick_sort(int A[], int start, int end) {
    if (start < end) {
        int pivot_position = partitioning(A, start, end);

        quick_sort(A, start, pivot_position-1);
        quick_sort(A, pivot_position+1, end);
    }
}