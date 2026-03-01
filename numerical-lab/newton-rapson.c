#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x - 2 * x - 5;
}

double f_prime(double x) {
    return 3 * x * x - 2;
}

int main() {
    double x0, x1, fx, fpx, tolerance;
    int iteration = 1;

    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);

    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    printf("\n%-10s %-15s %-15s %-15s\n", "Iter", "x", "f(x)", "f'(x)");

    do {
        fx = f(x0);
        fpx = f_prime(x0);

        if (fpx == 0) {
            printf("Error: Derivative is zero. Cannot continue.\n");
            return 1;
        }

        x1 = x0 - fx / fpx;

        printf("%-10d %-15.6lf %-15.6lf %-15.6lf\n", iteration, x0, fx, fpx);

        if (fabs(x1 - x0) < tolerance) {
            break;
        }

        x0 = x1;
        iteration++;

    } while (1);

    printf("\nApproximate Root: %.6lf\n", x1);

    return 0;
}
