#include <stdio.h>
#include <stdlib.h>

void merge_sort(int A[], int start, int end);
void merge(int A[], int start, int middle, int end);

int main() {
    int size;
    printf("Informe o tamanho do seu array: ");
    scanf("%i", &size);

    int vector[size];
    printf("Informe os elementos do seu array:\n");
    for (int i = 0; i < size; i++) {
        printf("a[%i]: ", i);
        scanf("%i", &vector[i]);
    }

    merge_sort(vector, 0, size-1);

    printf("Array ordenado:\n");
    for (int i = 0; i < size; i++) {
        printf("-[%i]-", vector[i]);
    }
    printf("\n");

    return 0;
}

void merge_sort(int A[], int start, int end) {
    if (start < end) {
        int middle = start + (end - start)/2;
        //Dividing the array
        merge_sort(A, start, middle);
        merge_sort(A, middle+1, end);
        //Merging the sorted elements
        merge(A, start, middle, end);
    }
}

void merge(int A[], int start, int middle, int end) {
    //Making a copy of both sides of the array
    int nL = middle - start + 1;
    int nR = end - middle;
    //Alocating memory for the copies
    int *left = (int*)malloc(nL*sizeof(int));
    int *right = (int*)malloc(nR*sizeof(int));

    if (left == NULL || right == NULL) {
        printf("Erro ao alocar memória para as cópias do vetor A[]\n");
        return;
    }
    else {
        for (int i = 0; i < nL; i++) {
            left[i] = A[start+i];
        }
        for (int j = 0; j < nR; j++) {
            right[j] = A[middle+1+j];
        }
    }
    //Merging both sides
    int l = 0, r = 0, k = start;
    
    while (l < nL && r < nR) {
        if (left[l] <= right[r]) {
            A[k] = left[l];
            l++;
        }
        else {
            A[k] = right[r];
            r++;
        }
        k++;
    }
    //Copying the rest of the left elements, if there's any
    while (l < nL) {
        A[k] = left[l];
        l++;
        k++;
    }
    //Copying the rest of the right elements, if there's any
    while (r < nR) {
        A[k] = right[r];
        r++;
        k++;
    } 
    //Freeing up the memory allocated
    free(left);
    free(right);
}