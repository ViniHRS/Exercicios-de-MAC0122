#include <stdio.h>

int search(int N, int n, int array[]);

int main() {
    int size;
    printf("Informe o tamanho do array: ");
    scanf("%i", &size);

    int array[size];
    printf("Informe os elementos do seu array:\n");
    for (int i = 0; i < size; i++) {
        printf("[%i]: ", i);
        scanf("%i", &array[i]);
    }
    printf("\n");

    int number;
    printf("Informe o elemento que deseja encontrar no array: ");
    scanf("%i", &number);

    int found = search(size, number, array);
    if (found == -1) {
        printf("Elemento não encontrado no array\n");
    }
    else {
        printf("Elemento está na posição %i do array\n", found);
    }

    return 0;
}

int search(int N, int n, int array[]) {
    if (N > 0) {
        if (n == array[N-1]) {
            return N-1;
        }
        else {
            search(N-1, n, array);
        }
    }
    else {
        if (n == array[0]) {
            return 0;
        }
        else {
            return -1;
        }
    }
}