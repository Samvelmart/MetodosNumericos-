#include <iostream>
#include <cmath>
#include <functional>

// Euler's Method
void eulerMethod(std::function<double(double, double)> f, double y0, double t0, double tn, int n) {
    double h = (tn - t0) / n;
    double y = y0, t = t0;

    for (int i = 0; i < n; ++i) {
        std::cout << "y(" << t << ") = " << y << std::endl;
        y += h * f(t, y);
        t += h;
    }
}

// Runge-Kutta Method (4th Order)
void rungeKutta4(std::function<double(double, double)> f, double y0, double t0, double tn, int n) {
    double h = (tn - t0) / n;
    double y = y0, t = t0;

    for (int i = 0; i < n; ++i) {
        double k1 = h * f(t, y);
        double k2 = h * f(t + h/2, y + k1/2);
        double k3 = h * f(t + h/2, y + k2/2);
        double k4 = h * f(t + h, y + k3);

        std::cout << "y(" << t << ") = " << y << std::endl;
        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t += h;
    }
}

int main() {
    // Define the differential equation y'(t) = f(t, y(t)). Example: y'(t) = y - t^2 + 1
    std::function<double(double, double)> f = [](double t, double y) { return y - t * t + 1; };

    double y0 = 0.5; // Initial condition
    double t0 = 0.0; // Start time
    double tn = 2.0; // End time
    int n = 10;      // Number of steps

    std::cout << "Euler's Method:" << std::endl;
    eulerMethod(f, y0, t0, tn, n);

    std::cout << "\nRunge-Kutta Method:" << std::endl;
    rungeKutta4(f, y0, t0, tn, n);

    return 0;
}
