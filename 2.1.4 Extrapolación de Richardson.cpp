#include <iostream>
#include <cmath>
#include <functional>

double forwardDifference(std::function<double(double)> f, double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double richardsonsExtrapolation(std::function<double(double)> f, double x, double h) {
    double D1 = forwardDifference(f, x, h);
    double D2 = forwardDifference(f, x, h / 2.0);
    return (4.0 * D2 - D1) / 3.0;
}

int main() {
    // Example function: f(x) = x^2
    std::function<double(double)> f = [](double x) { return x * x; };

    double x = 1.0; // Point at which derivative is estimated
    double h = 0.01; // Initial step size

    double derivative = richardsonsExtrapolation(f, x, h);

    std::cout << "Approximate derivative using Richardson's Extrapolation at x = " << x << " is: " << derivative << std::endl;

    return 0;
}
