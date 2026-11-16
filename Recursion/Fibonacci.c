#include <stdio.h>

void fibonacci(int N, int n1, int n2);

int main() {

    int terms;

    printf("Informe quantos termos da sequência deseja mostrar: ");
    scanf("%i", &terms);

    printf("%i %i ", 0, 1);
    fibonacci(terms-2, 0, 1);

    printf("\n");

    return 0;
}

void fibonacci(int N, int n1, int n2) {
    if (N > 0) {
        int sum = n1 + n2;

        printf("%i ", sum);

        fibonacci(N-1, n2, sum);
    }
}