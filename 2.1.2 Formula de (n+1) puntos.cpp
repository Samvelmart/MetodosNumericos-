#include <iostream>
#include <cmath>
#include <functional>

double threePointForwardDifference(std::function<double(double)> f, double x, double h) {
    return (-3.0 * f(x) + 4.0 * f(x + h) - f(x + 2.0 * h)) / (2.0 * h);
}

int main() {
    // Define your function here. For example, f(x) = x^2
    std::function<double(double)> f = [](double x) { return x * x; };

    double x = 1.0; // Point at which to approximate the derivative
    double h = 0.01; // Step size

    double derivative = threePointForwardDifference(f, x, h);

    std::cout << "Approximate derivative of f at x = " << x << " is: " << derivative << std::endl;

    return 0;
}
