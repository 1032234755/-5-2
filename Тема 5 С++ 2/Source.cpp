#include <iostream>
#include <vector>
#include <cmath>
#include "interpolator.h" // Подключите библиотеку для интерполяции

using namespace std;

int main() {
    vector<double> xi = { 0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI };
    vector<double> yi(xi.size());

    for (size_t i = 0; i < xi.size(); ++i) {
        yi[i] = cos(xi[i]);
    }

    NewtonInterpolator newton(xi, yi);

    double x_star = 0.25 * M_PI;
    double y_star = newton.interpolate(x_star);

    double y_exact = cos(x_star);
    double error = fabs(y_star - y_exact);

    cout << "Значение интерполяции в точке x* = " << x_star << ": " << y_star << endl;
    cout << "Точное значение функции в точке x* = " << x_star << ": " << y_exact << endl;
    cout << "Погрешность интерполяции: " << error << endl;

    return 0;
}
