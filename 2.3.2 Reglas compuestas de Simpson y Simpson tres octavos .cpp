#include <iostream>
#include <cmath>
#include <functional>

double compositeSimpsonsRule(std::function<double(double)> f, double a, double b, int n) {
    if (n % 2 != 0) { ++n; } // Ensure n is even
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        sum += f(a + i * h) * (i % 2 == 0 ? 2 : 4);
    }

    return sum * h / 3.0;
}

int main() {
    std::function<double(double)> f = [](double x) { return x * x; }; // Example function
    double a = 0.0, b = 1.0;
    int n = 10; // Number of subintervals

    std::cout << "Composite Simpson's Rule result: " 
              << compositeSimpsonsRule(f, a, b, n) << std::endl;

    return 0;
}
