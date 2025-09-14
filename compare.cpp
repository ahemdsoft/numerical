#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

// ---------------------- Common function -------------------------
double f(double x) {
    return exp(x) - 3 * x;
}

// ---------------------- Secant method ---------------------------
vector<double> secant_errors(double x0, double x1, double tol, int maxIter) {
    vector<double> err;
    double f0 = f(x0), f1 = f(x1);
    for (int i = 0; i < maxIter; i++) {
        if (fabs(f1 - f0) < 1e-14) break;
        double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
        double e = fabs(x2 - x1);
        err.push_back(e);
        if (e < tol || fabs(f(x2)) < tol) break;
        x0 = x1; f0 = f1;
        x1 = x2; f1 = f(x2);
    }
    return err;
}

// ---------------------- Modified false position -----------------
vector<double> mfp_errors(double a, double b, double tol, int maxIter) {
    vector<double> err;
    double fa = f(a), fb = f(b);
    double prev = a;
    for (int i = 0; i < maxIter; i++) {
        if (fa * fb > 0) break;
        double c = (a * fb - b * fa) / (fb - fa);
        double fc = f(c);
        double e = fabs(c - prev);
        err.push_back(e);
        if (fabs(fc) < tol || e < tol) break;

        if (fa * fc < 0) {
            b = c;
            fb = fc / 2.0;   // keep author’s original update rule
        } else {
            a = c;
            fa = fc / 2.0;
        }
        prev = c;
    }
    return err;
}

// ---------------------- Main comparison -------------------------
int main() {
    double x0, x1, tol;
    cout << "Enter first guess, second guess, tolerance: ";
    cin >> x0 >> x1 >> tol;

    int maxIter = 50;

    vector<double> e_secant = secant_errors(x0, x1, tol, maxIter);
    vector<double> e_mfp    = mfp_errors(x0, x1, tol, maxIter);

    size_t n = max(e_secant.size(), e_mfp.size());

    cout << "\nComparison of log10(errors):\n";
    cout << left << setw(8) << "Iter"
         << setw(18) << "Secant log10(err)"
         << setw(18) << "MFP log10(err)" << endl;
    cout << string(44, '-') << endl;

    for (size_t i = 0; i < n; i++) {
        cout << left << setw(8) << (i + 1);
        if (i < e_secant.size())
            cout << setw(18) << log10(e_secant[i]);
        else
            cout << setw(18) << "-";
        if (i < e_mfp.size())
            cout << setw(18) << log10(e_mfp[i]);
        else
            cout << setw(18) << "-";
        cout << endl;
    }

    // Decide which converged faster (smaller final error)
    double final_sec = e_secant.empty() ? 1e99 : e_secant.back();
    double final_mfp = e_mfp.empty()    ? 1e99 : e_mfp.back();

    cout << "\nFinal absolute error:\n";
    cout << "Secant           = " << final_sec << endl;
    cout << "Modified FP      = " << final_mfp << endl;

    if (final_sec < final_mfp)
        cout << "\n Secant method converged faster.\n";
    else if (final_mfp < final_sec)
        cout << "\n Modified false position converged faster.\n";
    else
        cout << "\n Both have similar convergence.\n";

    return 0;
}
