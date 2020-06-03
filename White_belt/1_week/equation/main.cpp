#include <iostream>
#include <cmath>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;

    if (A == 0) {
        if (B != 0) {
            std::cout << -C / B;
        } else {
            return 0;
        }
    } else {
        double D = B * B - 4 * A * C;
        if (D < 0) {
            return 0;
        }
        double x_1 = (-B + sqrt(D)) / (2 * A);
        double x_2 = (-B - sqrt(D)) / (2 * A);
        if (x_1 == x_2) {
            std::cout << x_1;
        } else {
            std::cout << x_1 << " " << x_2;
        }
    }

    return 0;
}