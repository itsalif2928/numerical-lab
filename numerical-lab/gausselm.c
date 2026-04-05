#include <stdio.h>

int main() {
    int i, j, k, n;
    float a[20][20], c, x[20], sum;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter augmented matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n+1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination
    for(j = 1; j <= n; j++) {
        for(i = 1; i <= n; i++) {
            if(i > j) {
                c = a[i][j] / a[j][j];
                for(k = 1; k <= n+1; k++) {
                    a[i][k] = a[i][k] - c * a[j][k];
                }
            }
        }
    }

    // Back Substitution
    for(i = n; i >= 1; i--) {
        sum = 0;
        for(j = i+1; j <= n; j++) {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (a[i][n+1] - sum) / a[i][i];
    }

    // Print Solution
    printf("\nSolution:\n");
    for(i = 1; i <= n; i++) {
        printf("x%d = %f\n", i, x[i]);
    }

    return 0;
}
