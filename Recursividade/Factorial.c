#include <stdio.h>

int factorial(int N);

int main() {
    int number;

    printf("Informe o fatorial a ser calculado: ");
    scanf("%i", &number);
    printf("%i! = %i\n", number, factorial(number));

    return 0;
}

int factorial(int N) {
    int result = N;

    if (N > 0) {
        result *= factorial(N-1);
    }
    else {
        return 1;
    }

    return result;
}