#include <iostream>
#include <vector>

using namespace std;

// Función para realizar la factorización LU
bool luFactorization(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    L = vector<vector<double>>(n, vector<double>(n, 0));
    U = vector<vector<double>>(n, vector<double>(n, 0));

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
                if (U[i][i] == 0) {
                    return false; // La matriz no es descomponible
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    return true;
}

int main() {
    vector<vector<double>> A = {{4, 3}, {6, 3}};
    vector<vector<double>> L, U;

    if (luFactorization(A, L, U)) {
        cout << "Factorización LU realizada con éxito." << endl;
        cout << "L:" << endl;
        for (auto& row : L) {
            for (auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << "U:" << endl;
        for (auto& row : U) {
            for (auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    } else {
        cout << "La matriz no puede ser descompuesta." << endl;
    }

    return 0;
}
