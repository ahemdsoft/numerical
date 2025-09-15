    #include <iostream>
    #include <cmath>
    #include <iomanip>
    using namespace std;
// Define the function f(x) = e^x - 3x
    double f(double x) {
        return exp(x) - 3*x;
    }

    int main() {
        double x1, x2, tol;
        cout<<"enter guese-1 gause-2 and error-tolerance: ";
        cin >> x1 >> x2 >> tol;

        if (f(x1) * f(x2) > 0) {
            cout << "Wrong guesses! f(x1) and f(x2) must have opposite signs." << endl;
            return 1;
        }

        double x0 = x1;
        double f0;
        double f1 = f(x1), f2 = f(x2);
        int iter = 1;

        cout << left << setw(6) << "Iter"
             << setw(12) << "x1"
             << setw(12) << "x2"
             << setw(12) << "x0"
             << setw(12) << "f(x0)"
              << setw(12) << "f(x1)"
              << setw(12) << "f(x2)"
             << setw(16) << "Relative Error" << endl;


             /*
modified-false postion methode Formula:
x_new = (x1*f2 - x2*f1) / (f2 - f1);
Stopping criteria: |x_new - x_old| < tolerance
*/

        while (true) {
            double x_new = (x1*f2 - x2*f1) / (f2 - f1); //modified false postion formula.
            f0 = f(x_new);

            double rel_error = fabs(x_new - x0) / fabs(x_new); 

            cout << left << setw(6) << iter
                 << setw(12) << x1
                 << setw(12) << x2
                 << setw(12) << x_new
                 << setw(12) << f0
                 << setw(12) << f1
                 << setw(12) << f2
                 << setw(16) << rel_error << endl;

            if (fabs(f0) < tol || rel_error < tol) {
                cout << "\nRoot found at x = " << x_new << " after " << iter << " iterations." << endl;
                break;
            }

            if (f1 * f0 < 0) {
                x2 = x_new;
                f2 = f0 / 2;   // update
            } else {
                x1 = x_new;
                f1 = f0 / 2;
            }

            x0 = x_new;
            iter++;
        }

        return 0;
    }
