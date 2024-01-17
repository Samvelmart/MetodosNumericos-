#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

struct State {
    double t; // Time
    double y; // Solution
};

State rungeKuttaFehlberg(std::function<double(double, double)> f, State initialState, double tEnd, double h, double tolerance) {
    double t = initialState.t;
    double y = initialState.y;
    double hMax = h;
    double hMin = h / 64; // Minimum step size

    while (t < tEnd) {
        double k1 = h * f(t, y);
        double k2 = h * f(t + 0.25 * h, y + 0.25 * k1);
        // ... more k's for the higher-order terms

        double y4 = y + (some combination of k's); // 4th order estimate
        double y5 = y + (another combination of k's); // 5th order estimate

        double error = std::abs(y4 - y5);
        double hNext = 0.84 * h * std::pow(tolerance / error, 0.25);

        if (error < tolerance) { // Step is accepted
            t += h;
            y = y4; // or y5, depending on the desired accuracy
            if (hNext > hMax) hNext = hMax;
