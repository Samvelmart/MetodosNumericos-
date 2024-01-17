#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

// Use pre-calculated weights and nodes for Gaussian Quadrature
std::vector<double> weights; // Fill with appropriate weights
std::vector<double> nodes;   // Fill with appropriate nodes

double gaussianQuadrature(std::function<double(double)> f, double a, double b) {
    double sum = 0.0;
    double mid = (b + a) / 2.0;
    double half_length = (b - a) / 2.0;

    for (size_t i = 0; i < nodes.size(); ++i) {
        sum += weights[i] * f(mid + half_length * nodes[i]);
    }

    return sum * half_length;
}

// Example for a double integral
double doubleIntegral(std::function<double(double, double)> f, double ax, double bx, double cy, double dy) {
    auto innerIntegral = [&](double x) {
        return gaussianQuadrature([&](double y) { return f(x, y); }, cy, dy);
    };
    return gaussianQuadrature(innerIntegral, ax, bx);
}

// Similar approach for triple integral...

int main() {
    // Example function for double integral: f(x, y) = x * y
    std::function<double(double, double)> f = [](double x, double y) { return x * y; };
    double result = doubleIntegral(f, 0.0, 1.0, 0.0, 1.0);
    std::cout << "Double integral result: " << result << std::endl;

    return 0;
}
