#include <stdio.h>

void selection_sort(int N, int A[]);
int sequential_search(int n, int N, int A[]);

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

    selection_sort(size, array);

    int find;
    printf("Informe o elemento que deseja encontrar: ");
    scanf("%i", &find);

    int position = sequential_search(find, size, array);

    if (position == -1) {
        printf("Elemento não encontrado.\n");
    }
    else {
        printf("Elemento está na posição %i\n", position);
    }

    return 0;
}

void selection_sort(int N, int A[]) {
    int position;

    for (int i = 0; i < N; i++) {
        position = i;
        for (int j = i+1; j < N; j++) {
            if (A[j] < A[position]) {
                position = j;
            }
        }
        //Changing variables
        if (position != i) {
            int change = A[i];
            A[i] = A[position];
            A[position] = change;
        }
    }
}

int sequential_search(int n, int N, int A[]) {
    int position = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == n) {
            position = i;
        }
    }
    return position;
}