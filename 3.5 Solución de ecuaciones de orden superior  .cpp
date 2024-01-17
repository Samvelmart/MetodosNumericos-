#include <iostream>
#include <cmath>

using namespace std;

// Función que representa la ecuación polinómica
double f(double x) {
    // Ejemplo: x^3 - x - 2 = 0
    return pow(x, 3) - x - 2;
}

// Derivada de la función
double df(double x) {
    // Derivada de x^3 - x - 2
    return 3 * pow(x, 2) - 1;
}

// Método de Newton-Raphson
double newtonRaphson(double initialGuess, int maxIter, double tolerance) {
    double x0 = initialGuess;
    double x1;
    
    for (int i = 0; i < maxIter; i++) {
        double f0 = f(x0);
        double df0 = df(x0);

        if (abs(df0) < tolerance) {
            cout << "Derivada muy pequeña." << endl;
            return x0;
        }

        x1 = x0 - f0 / df0;

        if (abs(x1 - x0) < tolerance)
            return x1;

        x0 = x1;
    }

    cout << "No se encontró una solución en " << maxIter << " iteraciones." << endl;
    return x1;
}

int main() {
    double initialGuess = 1.5;
    int maxIter = 100;
    double tolerance = 1e-6;

    double root = newtonRaphson(initialGuess, maxIter, tolerance);
    cout << "La raíz encontrada es: " << root << endl;

    return 0;
}
