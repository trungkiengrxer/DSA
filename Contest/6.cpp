#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long double a, b, c, x = 0.0;
        std::cin >> a >> b >> c;

        for (int i = 0; i < 1000; ++i) {
            double fx = a * x * x * x + b * x - c;
            double dfx = 3 * a * x * x + b;
            x = x - fx / dfx;
        }

        std::cout << std::fixed << std::setprecision(4) << x << "\n";
    }
}