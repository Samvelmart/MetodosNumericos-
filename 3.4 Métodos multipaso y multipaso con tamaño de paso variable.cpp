#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

void adamsBashforth2Step(std::function<double(double, double)> f, double y0, double y1, double t0, double tEnd, double h) {
    double t = t0 + 2 * h; // Starting point for the method
    double yPrev = y0;
    double yCurr = y1;

    while (t <= tEnd) {
        double yNext = yCurr + h * (1.5 * f(t, yCurr) - 0.5 * f(t - h, yPrev));
        yPrev = yCurr;
        yCurr = yNext;
        t += h;
        std::cout << "y(" << t << ") = " << yCurr << std::endl;
    }
}

int main() {
    std::function<double(double, double)> f = [](double t, double y) { return y; }; // Example ODE: y'(t) = y

    double y0 = 1.0; // Initial value at t0
    double h = 0.1;  // Step size
    double t0 = 0.0; // Start time
    double tEnd = 2.0; // End time

    // For the 2-step method, we need a second starting value, which could be obtained using another method (e.g., Euler's)
    double y1 = y0 + h * f(t0, y0); // Approximate using Euler's method for simplicity

    adamsBashforth2Step(f, y0, y1, t0, tEnd, h);

    return 0;
}
