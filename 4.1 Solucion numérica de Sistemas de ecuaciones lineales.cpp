#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para resolver un sistema de ecuaciones lineales utilizando la eliminación de Gauss
vector<double> gaussElimination(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // Formar la matriz aumentada
    for (int i = 0; i < n; i++) {
        A[i].push_back(b[i]);
    }

    // Eliminación hacia adelante
    for (int i = 0; i < n; i++) {
        // Encontrar el pivote máximo en la columna
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }

        // Intercambiar filas
        swap(A[i], A[maxRow]);

        // Verificar si la matriz es singular
        if (abs(A[i][i]) < 1e-8) {
            throw runtime_error("La matriz es singular o casi singular");
        }

        // Hacer ceros debajo del pivote
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) {
                A[k][j] -= A[i][j] * factor;
            }
        }
    }

    // Sustitución hacia atrás
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n] / A[i][i];
        for (int j = i - 1; j >= 0; j--) {
            A[j][n] -= A[j][i] * x[i];
        }
    }
    return x;
}

int main() {
    // Ejemplo: Resolver el sistema 3x + 2y = 18, x - y = 2
    vector<vector<double>> A = {{3, 2}, {1, -1}};
    vector<double> b = {18, 2};

    try {
        vector<double> result = gaussElimination(A, b);
        cout << "Solución: ";
        for (double v : result) {
            cout << v << " ";
        }
        cout << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
