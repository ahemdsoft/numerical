#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define the function f(x) = e^x - 3x
double f(double x) {
    return exp(x) - 3*x;
}

/*
Secant Method
Formula (from lecture slide):
x3 = x2 - f(x2) * (x2 - x1) / (f(x2) - f(x1))
Stopping criteria: |x_new - x_old| < tolerance
*/
double secant(double x1, double x2, double tol, int maxIter) {
    double f1 = f(x1), f2 = f(x2);
    double x3;

    cout << left << setw(6) << "Iter"
         << setw(12) << "x1"
         << setw(12) << "x2"
         << setw(12) << "f1"
         << setw(12) << "f2"
         << setw(12) << "x3"
         << setw(12) << "f(x3)"
         << setw(20) << "Relative error" << endl;

    for (int iter = 1; iter <= maxIter; iter++) {
        if (fabs(f2 - f1) < 1e-12) {
            cout << "Division by zero risk!" << endl;
            return NAN;
        }

        x3 = x2 - f2 * (x2 - x1) / (f2 - f1);   // secant formula
        double f3 = f(x3);
        double error = fabs(x3 - x2);

        cout << left << setw(6) << iter
             << setw(12) << x1
             << setw(12) << x2
             << setw(12) << f1
             << setw(12) << f2
             << setw(12) << x3
             << setw(12) << f3
             << setw(20) << error << endl;

        if (fabs(f3) < tol || error < tol) break;

        // update
        x1 = x2; f1 = f2;
        x2 = x3; f2 = f3;
    }

    return x3;
}

int main() {
    double x1, x0 ,tol;
    cin >> x0;
    cin >> x1;
    cin>> tol;
    int maxIter = 50;

    double root = secant(x0, x1, tol, maxIter);
    cout << "\nApproximate root (Secant Method): " << root << endl;
    return 0;
}
