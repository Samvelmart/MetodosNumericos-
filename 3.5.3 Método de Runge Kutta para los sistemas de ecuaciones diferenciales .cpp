#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// Definir un tipo para las funciones del sistema
using Func = function<double(double, const vector<double>&)>;

// Método RK4 aplicado a un sistema de ecuaciones
void rungeKutta4(double &t, vector<double> &z, double dt, const vector<Func> &funcs) {
    int n = z.size();
    vector<double> k1(n), k2(n), k3(n), k4(n), zTemp(n);

    // k1
    for (int i = 0; i < n; ++i) {
        k1[i] = dt * funcs[i](t, z);
    }

    // k2
    for (int i = 0; i < n; ++i) {
        zTemp[i] = z[i] + 0.5 * k1[i];
    }
    for (int i = 0; i < n; ++i) {
        k2[i] = dt * funcs[i](t + 0.5 * dt, zTemp);
    }

    // k3
    for (int i = 0; i < n; ++i) {
        zTemp[i] = z[i] + 0.5 * k2[i];
    }
    for (int i = 0; i < n; ++i) {
        k3[i] = dt * funcs[i](t + 0.5 * dt, zTemp);
    }

    // k4
    for (int i = 0; i < n; ++i) {
        zTemp[i] = z[i] + k3[i];
    }
    for (int i = 0; i < n; ++i) {
        k4[i] = dt * funcs[i](t + dt, zTemp);
    }

    // Combinar para obtener el próximo valor de z
    for (int i = 0; i < n; ++i) {
        z[i] += (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]) / 6.0;
    }

    // Incrementar el tiempo
    t += dt;
}

int main() {
    // Definir las funciones del sistema
    Func f1 = [](double t, const vector<double> &z) {
        return z[1]; // Ejemplo: dz1/dt = z2
    };
    Func f2 = [](double t, const vector<double> &z) {
        return -z[0]; // Ejemplo: dz2/dt = -z1
    };
    vector<Func> funcs = {f1, f2};

    // Condiciones iniciales
    double t = 0;
    vector<double> z = {1.0, 0.0}; // z1 = 1, z2 = 0 inicialmente
    double dt = 0.01; // Paso de tiempo

    // Ejecutar RK4
    for (int step = 0; step < 1000; ++step) {
        rungeKutta4(t, z, dt, funcs);
        cout << "Tiempo: " << t << " z1: " << z[0] << " z2: " << z[1] << endl;
    }

    return 0;
}
