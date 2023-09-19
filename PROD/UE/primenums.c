#include <stdio.h>

int check_prime(int);
int primeCount = 0;
int lastPrimes[10] = {0};

int main() {
    for (int i = 2; primeCount < 1010; ++i) {
        if (check_prime(i)) {
            if (primeCount >= 1000) {
                lastPrimes[primeCount - 1000] = i;
            }
            ++primeCount;
        }
    }
    for (int n = 0; n < 10; n++) {
        printf("%d\n", lastPrimes[n]);
    }
}

int check_prime(int i) {
    if (i <= 1) {
        return 0; // 0 und 1 sind keine Primzahlen
    }
    for (int c = 2; c * c <= i; ++c) {
        if (i % c == 0) {
            return 0; // i ist keine Primzahl
        }
    }
    return 1; // i ist eine Primzahl
}
