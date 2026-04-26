#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    float A[10][10], b[10], x[10] = {0}, x_old[10];
    float tol = 0.0001;
    int maxIter = 50;

    // Input matrix
    cout << "Enter coefficients of matrix A:" << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    // Input RHS vector
    cout << "Enter RHS vector b:" << endl;
    for(int i = 0; i < n; i++)
        cin >> b[i];

    // Gauss-Seidel iteration
    for(int iter = 0; iter < maxIter; iter++) {
        // Save old values
        for(int i = 0; i < n; i++)
            x_old[i] = x[i];

        // Update each variable
        for(int i = 0; i < n; i++) {
            float sum = 0;
            for(int j = 0; j < n; j++) {
                if(j != i)
                    sum += A[i][j] * x[j];  // Uses updated x[j] for j < i
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        // Check convergence
        float error = 0;
        for(int i = 0; i < n; i++)
            error = max(error, fabs(x[i] - x_old[i]));

        // Print iteration results
        cout << "Iteration " << iter + 1 << ": ";
        for(int i = 0; i < n; i++)
            cout << "x" << i+1 << " = " << x[i] << " ";
        cout << " (Error: " << error << ")" << endl;

        if(error < tol) {
            cout << "\nConverged!" << endl;
            break;
        }
    }

    // Final answer
    cout << "\nFinal Solution:" << endl;
    for(int i = 0; i < n; i++)
        cout << "x" << i+1 << " = " << x[i] << endl;

    return 0;
}
