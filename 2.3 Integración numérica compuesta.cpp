#include <iostream>
#include <cmath>
#include <functional>

// Function for Composite Trapezoidal Rule
double compositeTrapezoidalRule(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double integral = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; ++i) {
        integral += f(a + i * h);
    }

    integral *= h;
    return integral;
}

// Function for Composite Simpson's 1/3 Rule
double compositeSimpsonsRule(std::function<double(double)> f, double a, double b, int n) {
    if (n % 2 != 0) { n++; } // Adjust n to be even
    double h = (b - a) / n;
    double integral = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        integral += 4.0 * f(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        integral += 2.0 * f(a + i * h);
    }

    integral *= h / 3.0;
    return integral;
}

int main() {
    // Example function: f(x) = x^2
    std::function<double(double)> f = [](double x) { return x * x; };

    double a = 0.0; // Lower limit of integration
    double b = 1.0; // Upper limit of integration
    int n = 10; // Number of subintervals

    double trapezoidalResult = compositeTrapezoidalRule(f, a, b, n);
    double simpsonsResult = compositeSimpsonsRule(f, a, b, n);

    std::cout << "Composite Trapezoidal Rule result: " << trapezoidalResult << std::endl;
    std::cout << "Composite Simpson's Rule result: " << simpsonsResult << std::endl;

    return 0;
}
