#include <iostream>
#include <cmath>
#include <functional>

double compositeMidpointRule(std::function<double(double)> f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double midPoint = a + h * i + h / 2.0;
        sum += f(midPoint);
    }

    return sum * h;
}

int main() {
    // Example function: f(x) = x^2
    std::function<double(double)> f = [](double x) { return x * x; };

    double a = 0.0; // Lower limit of integration
    double b = 1.0; // Upper limit of integration
    int n = 10; // Number of subintervals

    double result = compositeMidpointRule(f, a, b, n);
    std::cout << "Composite Midpoint Rule result: " << result << std::endl;

    return 0;
}
