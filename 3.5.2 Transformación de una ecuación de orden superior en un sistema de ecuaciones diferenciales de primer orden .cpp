#include <iostream>
#include <vector>

using namespace std;

// Función que representa el sistema de ecuaciones diferenciales
// Aquí, dz representa las derivadas de las variables z
void systemOfEquations(double t, const vector<double>& z, vector<double>& dz) {
    // Ejemplo con una ecuación de segundo orden convertida a un sistema de dos ecuaciones de primer orden
    // y'' = -y (como un ejemplo simple, como el oscilador armónico)
    // z1 = y, z2 = y'

    // z1' = z2
    dz[0] = z[1];

    // z2' = -z1
    dz[1] = -z[0];
}

int main() {
    // Tamaño del sistema
    int n = 2;

    // Inicialización de variables
    vector<double> z(n), dz(n);
    double t = 0; // Tiempo inicial

    // Valores iniciales para z
    z[0] = 1; // y(0) = 1
    z[1] = 0; // y'(0) = 0

    // Aquí iría el método de resolución (Euler, Runge-Kutta, etc.)
    // Por ejemplo, un paso del método de Euler podría verse así:
    double dt = 0.01; // Paso de tiempo
    systemOfEquations(t, z, dz);
    for (int i = 0; i < n; ++i) {
        z[i] += dz[i] * dt;
    }

    // Mostrar resultado (esto sería después de varios pasos en el método de resolución)
    cout << "z1 (y): " << z[0] << endl;
    cout << "z2 (y'): " << z[1] << endl;

    return 0;
}
