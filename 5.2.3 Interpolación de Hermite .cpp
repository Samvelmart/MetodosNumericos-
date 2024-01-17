#include <iostream>
#include <vector>

using namespace std;

// Función para calcular el polinomio interpolador de Hermite
vector<double> hermiteInterpolation(const vector<double>& x, const vector<double>& fx, const vector<double>& dfx) {
    // Suponiendo que tenemos 2 puntos y sus derivadas
    vector<double> H(4); // Polinomio de grado 3

    // Coeficientes del polinomio interpolador de Hermite
    H[0] = fx[0];
    H[1] = dfx[0];
    H[2] = 3 * (fx[1] - fx[0]) - 2 * dfx[0] - dfx[1];
    H[3] = 2 * (fx[0] - fx[1]) + dfx[0] + dfx[1];

    return H;
}

int main() {
    vector<double> x = {1, 2}; // Puntos x
    vector<double> fx = {2, 3}; // f(x)
    vector<double> dfx = {3, 4}; // f'(x)

    vector<double> H = hermiteInterpolation(x, fx, dfx);

    // Imprimir los coeficientes del polinomio interpolador de Hermite
    cout << "Polinomio interpolador de Hermite: ";
    for (double coef : H) {
        cout << coef << " ";
    }
    cout << endl;

    return 0;
}
