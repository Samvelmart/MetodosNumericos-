#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para calcular la inversa de una matriz utilizando descomposición LU
vector<vector<double>> inverseMatrix(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> inverse(n, vector<double>(n, 0));
    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(n, vector<double>(n, 0));

    // Descomposición LU
    for (int i = 0; i < n; i++) {
        // U: Forma triangular superior
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // L: Forma triangular inferior
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1; // Diagonal como 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    // Invertir L y U
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                inverse[i][j] = 1;
            else
                inverse[i][j] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int j = 0; j < i; j++) {
                inverse[i][k] -= L[i][j] * inverse[j][k];
            }
            inverse[i][k] /= L[i][i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int k = n - 1; k >= 0; k--) {
            for (int j = i + 1; j < n; j++) {
                inverse[k][i] -= U[j][i] * inverse[k][j];
            }
            inverse[k][i] /= U[i][i];
        }
    }

    return inverse;
}

int main() {
    // Ejemplo: Invertir una matriz 2x2
    vector<vector<double>> A = {{4, 7}, {2, 6}};

    try {
        vector<vector<double>> invA = inverseMatrix(A);
        cout << "Inversa de la matriz:" << endl;
        for (const auto& row : invA) {
            for (double elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
