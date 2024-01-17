#include <iostream>
#include <vector>

using namespace std;

// Función para realizar la factorización LDL^T
void ldlFactorization(const vector<vector<double>>& A, vector<vector<double>>& L, vector<double>& D) {
    int n = A.size();

    // Inicializar L como matriz identidad y D como vector de ceros
    L = vector<vector<double>>(n, vector<double>(n, 0));
    D = vector<double>(n, 0);

    for (int i = 0; i < n; ++i) {
        L[i][i] = 1; // Diagonal de L es 1

        double sum = 0;
        for (int k = 0; k < i; ++k) {
            sum += L[i][k] * L[i][k] * D[k];
        }

        D[i] = A[i][i] - sum;

        for (int j = i + 1; j < n; ++j) {
            sum = 0;
            for (int k = 0; k < i; ++k) {
                sum += L[j][k] * L[i][k] * D[k];
            }
            L[j][i] = (A[j][i] - sum) / D[i];
        }
    }
}

int main() {
    vector<vector<double>> A = {
        {4, 12, -16},
        {12, 37, -43},
        {-16, -43, 98}
    };

    vector<vector<double>> L;
    vector<double> D;

    ldlFactorization(A, L, D);

    // Imprimir L
    cout << "L:" << endl;
    for (const auto& row : L) {
        for (double elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Imprimir D
    cout << "D:" << endl;
    for (double elem : D) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
