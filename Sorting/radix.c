#include <stdio.h>
#include <stdlib.h>

int get_max(int A[], int N);
void counting_sort(int A[], int N, int exp);
void radix_sort(int A[], int N);

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

    radix_sort(array, size);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", array[i]);
    }
    printf("\n");

    return 0;
}

int get_max(int A[], int N) {
    int max = A[0];
    for (int i = 1; i < N; i++) {
        if (max < A[i]) {
            max = A[i];
        }
    }
    return max;
}

//Counting sort for one digit
void counting_sort(int A[], int N, int exp) {
    //Creating a vector to get the ordered array
    int *aux = (int*)malloc(N*sizeof(int));
    //Creating a vector to count the frequency of each element
    int count[10] = {0}; //Elements must be numbers from 0 to 9

    if (aux == NULL) {
        printf("Erro ao alocar memória para o vetor auxiliar.\n");
        return;
    }
    //Counting the frequency of each digit
    for (int i = 0; i < N; i++) {
        int digit = (A[i] / exp) % 10; //Getting 
        count[digit]++;
    }
    //Getting the position of each digit
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    //Sorting the sequence in vector aux
    //Warning: algorithm must be stable for radix sort to work properly
    for (int i = N-1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        int position = count[digit] - 1;

        aux[position] = A[i];
        count[digit]--;
    }
    //Coping the sorted array to the original one
    for (int i = 0; i < N; i++) {
        A[i] = aux[i];
    }
    free(aux);
}

void radix_sort(int A[], int N) {
    //Getting the maximum value
    int max = get_max(A, N);

    //Sorting the array in each unit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(A, N, exp);
    }
}