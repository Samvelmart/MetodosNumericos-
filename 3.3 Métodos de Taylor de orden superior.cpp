#include <iostream>
#include <cmath>
#include <functional>

// Second-order Taylor method
void taylorMethodSecondOrder(std::function<double(double, double)> f, 
                             std::function<double(double, double)> df, 
                             double y0, double t0, double tn, int n) {
    double h = (tn - t0) / n;
    double y = y0, t = t0;

    for (int i = 0; i < n; ++i) {
        double f_val = f(t, y);
        double df_val = df(t, y);
        y += h * f_val + (h * h / 2) * df_val;
        t += h;
        std::cout << "y(" << t << ") = " << y << std::endl;
    }
}

int main() {
    // Example ODE: y'(t) = y, y''(t) = y'
    std::function<double(double, double)> f = [](double t, double y) { return y; };
    std::function<double(double, double)> df = [](double t, double y) { return y; };

    double y0 = 1.0; // Initial condition
    double t0 = 0.0; // Start time
    double tn = 2.0; // End time
    int n = 10;      // Number of steps

    taylorMethodSecondOrder(f, df, y0, t0, tn, n);

    return 0;
}
