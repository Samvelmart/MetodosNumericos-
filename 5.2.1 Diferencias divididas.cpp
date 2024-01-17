#include <iostream>
#include <vector>

using namespace std;

// Función para calcular las diferencias divididas
vector<vector<double>> dividedDifferences(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<vector<double>> table(n, vector<double>(n));
    
    // Inicializar la primera columna con los valores de y
    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

    // Calcular las diferencias divididas
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    return table;
}

int main() {
    vector<double> x = {1, 2, 3, 4}; // Puntos x
    vector<double> y = {1, 4, 9, 16}; // Puntos y (f(x))

    vector<vector<double>> table = dividedDifferences(x, y);

    // Imprimir la tabla de diferencias divididas
    for (const auto& row : table) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
