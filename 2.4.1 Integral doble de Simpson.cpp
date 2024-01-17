#include <iostream>
#include <cmath>
#include <functional>

double simpsonsRule(std::function<double(double)> f, double a, double b, int n) {
    if (n % 2 != 0) { ++n; } // Ensure n is even
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h) * (i % 2 == 0 ? 2 : 4);
    }

    return sum * h / 3.0;
}

double compositeSimpsons2D(std::function<double(double, double)> f, double a, double b, int n, double c, double d, int m) {
    auto simpsonY = [&](double x) {
        return simpsonsRule([&](double y) { return f(x, y); }, c, d, m);
    };
    
    return simpsonsRule(simpsonY, a, b, n);
}

int main() {
    // Example function: f(x, y) = x^2 + y^2
    std::function<double(double, double)> f = [](double x, double y) { return x * x + y * y; };

    double a = 0.0, b = 1.0; // x-interval
    double c = 0.0, d = 1.0; // y-interval
    int n = 10, m = 10; // Subdivisions in x and y

    double result = compositeSimpsons2D(f, a, b, n, c, d, m);
    std::cout << "Result of double integral using Simpson's Rule: " << result << std::endl;

    return 0;
}
