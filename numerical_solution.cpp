#include <iostream>
#include <cmath>
using namespace std;

double dx_dt(double x, double t) {
    return sin(x * t);
}

double rk4(double x, double t, double h) {
    double k1 = h * dx_dt(x, t);
    double k2 = h * dx_dt(x + 0.5 * k1, t + 0.5 * h);
    double k3 = h * dx_dt(x + 0.5 * k2, t + 0.5 * h);
    double k4 = h * dx_dt(x + k3, t + h);
    return x + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
}

int main() {
    double t = 0;
    double x = 1;
    double h = (76.5 - t) / 100;

    // 4th order Runge-Kutta method iteration
    for (int i = 0; i < 100; i++) {
        x = rk4(x, t, h);
        t = t + h;
    }

    cout << "x(76.5) = " << x << endl;


    // Different initial conditions
    t = 0;
    x = 48;
    h = (76.5 - t) / 100;

    // 4th order Runge-Kutta method iteration
    for (int i = 0; i < 100; i++) {
        x = rk4(x, t, h);
        t = t + h;
    }

    cout << "x(76.5) = " << x << endl;

    return 0;
}
