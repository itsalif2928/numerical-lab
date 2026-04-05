#include <iostream>
using namespace std;

int main() {
    int i, j, k, n;
    float a[20][20], c, x[20], sum;

    cout << "Enter number of variables: ";
    cin >> n;

    cout << "Enter augmented matrix:\n";
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n+1; j++) {
            cin >> a[i][j];
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
    cout << "\nSolution:\n";
    for(i = 1; i <= n; i++) {
        cout << "x" << i << " = " << x[i] << endl;
    }

    return 0;
}