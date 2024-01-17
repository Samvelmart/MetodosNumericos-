#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Realiza la factorización LU de una matriz A
// Asume que la factorización es posible sin pivotamiento
void luFactorization(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Inicializar L y U como matrices de ceros de tamaño n x n
    L = vector<vector<double>>(n, vector<double>(n, 0));
    U = vector<vector<double>>(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        // Construir la matriz superior U
        for (int j = i; j < n; j++) {
            double sum = 0;
            for (int k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }

        // Construir la matriz inferior L
        for (int j = i; j < n; j++) {
            if (i == j)
                L[i][i] = 1; // Elementos diagonales de L son 1
            else {
                double sum = 0;
                for (int k = 0; k < i; k++) {
                    sum += L[j][k] * U[k][i];
                }
                L[j][i] = (A[j][i] - sum) / U[i][i];
            }
        }
    }
}

int main() {
    vector<vector<double>> A = {
        {2, -1, -2},
        {-4, 6, 3},
        {-4, -2, 8}
    };

    vector<vector<double>> L, U;

    luFactorization(A, L, U);

    // Imprimir L
    cout << "L:" << endl;
    for (const auto& row : L) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Imprimir U
    cout << "U:" << endl;
    for (const auto& row : U) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
