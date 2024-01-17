#include <iostream>
#include <vector>

using namespace std;

// Realiza la factorización de Crout de una matriz A
bool croutFactorization(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Inicializar L y U como matrices de ceros de tamaño n x n
    L = vector<vector<double>>(n, vector<double>(n, 0));
    U = vector<vector<double>>(n, vector<double>(n, 0));

    for (int i = 0; i < n; ++i) {
        U[i][i] = 1; // Diagonal de U es 1

        for (int j = i; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += L[j][k] * U[k][i];
            }
            L[j][i] = A[j][i] - sum;
        }

        for (int j = i + 1; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += L[i][k] * U[k][j];
            }
            if (L[i][i] == 0) {
                cout << "División por cero detectada!" << endl;
                return false;
            }
            U[i][j] = (A[i][j] - sum) / L[i][i];
        }
    }
    return true;
}

int main() {
    vector<vector<double>> A = {{6, 15, 55}, {15, 55, 225}, {55, 225, 979}};
    vector<vector<double>> L, U;

    if (croutFactorization(A, L, U)) {
        cout << "Factorización de Crout exitosa." << endl;
        cout << "L:" << endl;
        for (const auto& row : L) {
            for (double elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "U:" << endl;
        for (const auto& row : U) {
            for (double elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    } else {
        cout << "La factorización de Crout falló." << endl;
    }

    return 0;
}
