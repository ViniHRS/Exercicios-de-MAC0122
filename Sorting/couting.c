/*
 *  OBS: o algoritmo de counting sort original ordena apenas
 *  números naturais. A versão desenvolvida neste código foi
 *  expandida para ordenar números inteiros
 */
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int A[], int N);

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

    counting_sort(array, size);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", array[i]);
    }
    printf("\n");

    return 0;
}

void counting_sort(int A[], int N) {
    //Getting the smalles and the largest number
    //to find the sequence amplitude
    int min = A[0], max = A[0], amplitude;
    for (int i = 1; i < N; i++) {
        if (A[i] < min) {
            min = A[i];
        }
        if (A[i] > max) {
            max = A[i];
        }
    }
    amplitude = max - min + 1;

    //Creating and array to count the frequency of each element
    int *frequency = (int*)malloc(amplitude*sizeof(int));

    if (frequency == NULL) {
        printf("Erro ao alocar memória para o vetor de frequências.\n");
        return;
    }
    else {
        //Initializing the frequency array with 0 for each element
        for (int r = 0; r < amplitude; r++) {
            frequency[r] = 0;
        }
        //Counting the frequency of each element
        for (int i = 0; i < N; i++) {
            frequency[A[i] - min]++;
        }
    }
    //Creating and array to help the sorting
    int *aux = (int*)malloc(N*sizeof(int));

    if (aux == NULL) {
        printf("Erro ao alocar memória para o vetor auxiliar.\n");
        return;
    }
    else {
        //Calculating the sum of the previous elements
        for (int r = 1; r < amplitude; r++) {
            frequency[r] += frequency[r-1];
        }
        //Sorting the elements in aux array by using the frequency of each element
        for (int i = N-1; i >= 0; i--) {
            int current_element = A[i];
            int position = frequency[current_element - min] - 1;
            aux[position] = A[i];
            frequency[current_element - min]--;
        }
        //Coping the ordered elements in aux to the array
        for (int i = 0; i < N; i++) {
            A[i] = aux[i];
        }
    }

    //Freeing the memory allocated
    free(frequency);
    free(aux);
}