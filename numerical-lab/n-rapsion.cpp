#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x * x * x - 2 * x - 5;
}

double f_prime(double x) {
    return 3 * x * x - 2;
}

int main() {
    double x0, x1, fx, fpx, tolerance;
    int iteration = 1;

    cout << "Enter initial guess x0: ";
    cin >> x0;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

    cout << "\n"
         << setw(10) << "Iter"
         << setw(15) << "x"
         << setw(15) << "f(x)"
         << setw(15) << "f'(x)" << endl;

    while (true) {
        fx = f(x0);
        fpx = f_prime(x0);

        if (fpx == 0) {
            cout << "Error: Derivative is zero. Cannot continue." << endl;
            return 1;
        }

        x1 = x0 - fx / fpx;

        cout << setw(10) << iteration
             << setw(15) << fixed << setprecision(6) << x0
             << setw(15) << fx
             << setw(15) << fpx << endl;

        if (fabs(x1 - x0) < tolerance) {
            break;
        }

        x0 = x1;
        iteration++;
    }

    cout << "\nApproximate Root: " << fixed << setprecision(6) << x1 << endl;

    return 0;
}
