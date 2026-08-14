#include <stdio.h>
#include <math.h>

void bin_digits(int N, int p, int bin[]);

int main() {
    int digits;

    printf("How many digits do you want in your binary representation?: ");
    scanf("%i", &digits);

    int bin_numbers[digits];
    bin_digits(digits, 0, bin_numbers);

    return 0;
}

void bin_digits(int N, int p, int bin[]) {
    if (p == N) {
        for (int i = 0; i < N; i++) {
            printf("%i", bin[i]);
        }
        printf("\n");
        return;
    }

    bin[p] = 0;
    bin_digits(N, p+1, bin);

    bin[p] = 1;
    bin_digits(N, p+1, bin);
}