#include <iostream>
#include <cmath>
#include <functional>

double threePointCentralDifference(std::function<double(double)> f, double x, double h) {
    return (f(x - h) - f(x + h)) / (2.0 * h);
}

double fivePointCentralDifference(std::function<double(double)> f, double x, double h) {
    return (-f(x - 2.0 * h) + 8.0 * f(x - h) - 8.0 * f(x + h) + f(x + 2.0 * h)) / (12.0 * h);
}

int main() {
    // Example function: f(x) = x^2
    std::function<double(double)> f = [](double x) { return x * x; };

    double x = 2.0; // Point at which derivative is estimated
    double h = 0.01; // Step size

    double derivative3Point = threePointCentralDifference(f, x, h);
    double derivative5Point = fivePointCentralDifference(f, x, h);

    std::cout << "3-Point Central Difference at x = " << x << " is: " << derivative3Point << std::endl;
    std::cout << "5-Point Central Difference at x = " << x << " is: " << derivative5Point << std::endl;

    return 0;
}
