#include <iostream>
#include <cmath>
#include <functional>

double compositeTrapezoidal2D(std::function<double(double, double)> f, double a, double b, int n, double c, double d, int m) {
    double deltaX = (b - a) / n;
    double deltaY = (d - c) / m;
    double sum = 0.0;

    for (int i = 0; i <= n; ++i) {
        double x = a + i * deltaX;
        for (int j = 0; j <= m; ++j) {
            double y = c + j * deltaY;
            double weight = ((i == 0 || i == n) ? 1 : 2) * ((j == 0 || j == m) ? 1 : 2);
            sum += weight * f(x, y);
        }
    }

    return sum * deltaX * deltaY / 4.0;
}

int main() {
    // Example function: f(x, y) = x * y
    std::function<double(double, double)> f = [](double x, double y) { return x * y; };

    double a = 0.0, b = 1.0; // x-interval
    double c = 0.0, d = 1.0; // y-interval
    int n = 10, m = 10; // Subdivisions in x and y

    double result = compositeTrapezoidal2D(f, a, b, n, c, d, m);
    std::cout << "Result of double integral: " << result << std::endl;

    return 0;
}
