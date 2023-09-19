#include <stdio.h>
#include <math.h>

int main() {
    int x, y, calc;
    int factorial = 1;
    int p;
    char e;
    scanf("%d %d %c", &x, &y, &e);
    switch (e) {
        case 'a':
            calc = pow(x, y);
            break;
        case 'b':
            for (int i = 1; i <= x; i++) {
                factorial *= i;
            }
            calc = factorial;
            break; // Add break here
        case 'c':
            p = pow(x, y);
            factorial = 1;
            for (int i = 1; i <= p; i++) {
                factorial *= i;
            }
            calc = factorial;
            break; // Add break here
        default:
            printf("Invalid option '%c'\n", e);
            return 1; // Exit with an error code
    }
    printf("%d", calc);
    return 0; // Return 0 to indicate successful execution
}
