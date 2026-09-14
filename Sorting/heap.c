#include <stdio.h>

void heap_sort(int A[], int N);

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

    heap_sort(array, size);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", array[i]);
    }
    printf("\n");

    return 0;
}

void max_heap(int A[], int N) {
    for (int k = 0; k < N-1; k++) {
        int child = k+1;
        while (child > 0 && A[(child-1)/2] < A[child]) {
            //Swapping father and child if father is less than child
            int swapp = A[(child-1)/2];
            A[(child-1)/2] = A[child];
            A[child] = swapp;

            child = (child-1)/2;
        }
    }
}

void heapify(int A[], int N) {
    int p = 0, child = 1, swapp = A[0];
    while (child <= N) {
        //Checking who is the greater child
        if (child < N && A[child] < A[child+1])
            child++;
        //Stoping the loop if the element arrived in the right position
        if (swapp >= A[child])
            break;
        A[p] = A[child];
        p = child;
        child = 2*p + 1;
    }
    //'swapp' arrived in the right position to heapify the array
    A[p] = swapp;
}

void heap_sort(int A[], int N) {
    //Creating a heap
    max_heap(A, N);
    //Swapping the last element with the first in the heap and repeating the process
    for (int i = N-1; i >= 1; i--) {
        int swapp = A[0];
        A[0] = A[i];
        A[i] = swapp;
        heapify(A, i-1);
    }
}