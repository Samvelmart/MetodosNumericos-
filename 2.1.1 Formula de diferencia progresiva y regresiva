#include <iostream>
#include <cmath>
#include <functional>

double progressiveDifference(std::function<double(double)> f, double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double regressiveDifference(std::function<double(double)> f, double x, double h) {
    return (f(x) - f(x - h)) / h;
}

int main() {
    // Example function: f(x) = x^2
    std::function<double(double)> f = [](double x) { return x * x; };

    double x = 2.0; // Point at which derivative is estimated
    double h = 0.01; // Step size

    double progDiff = progressiveDifference(f, x, h);
    double regDiff = regressiveDifference(f, x, h);

    std::cout << "Progressive Difference at x = " << x << " is: " << progDiff << std::endl;
    std::cout << "Regressive Difference at x = " << x << " is: " << regDiff << std::endl;

    return 0;
}
